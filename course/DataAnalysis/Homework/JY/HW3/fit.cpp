//*************************************
// Find and fit the alpha source peaks 
// open the data file 
// root [] .L fit.cpp 
// root [] main
// root [] .q
// two files: califl.txt and save.root 
// will be generated
// Author: JingLi 
// Email: lijinger02@126.com
// 2015/06/08
// ************************************

#include <TROOT.h>
#include <TH1F.h>
#include <TGraph.h>
#include <TSpectrum.h>
#include <TF1.h>
#include <TTree.h>
#include <TFile.h>

#include <fstream>
#include <iostream>
using namespace std;

// For createHisto
TH1F *h[32];
TF1 *fPeaks;
TF1 *fLine;
// For readpar
Double_t abin[32];
// For fit
TSpectrum *sp[32];

TGraph *gr[32];
Double_t par[32][32];
Double_t lpar[32][2];
Double_t lpare[32][2];


void createHisto() {
  for(int i=0;i<32;i++){
    char hname[32];
    sprintf(hname,"h%d",i);
    h[i] = new TH1F(hname,hname,500,500,1000);
  }
  fPeaks = new TF1("fPeaks","gaus(0)+gaus(3)",0,4000);
  fLine = new TF1("fLine","pol1",0,4000);
}


void readpar() {
  memset(abin,0,sizeof(Double_t)*32);
  ifstream in("bins.txt");
  if(!in.good()){
    cout<<"cannot open the file of calibration!"<<endl;
    return;
  }
  Int_t cnt=0;
  while(1){
    Double_t i, bin;
    in>>i>>bin;
    if(!in.good()) break;
    abin[Int_t(i)] = bin;
    cnt++;
  }
  in.close();
}


void project(){
  for(int i=0;i<32;i++){
    tree->Project(TString::Format("h%d",i),TString::Format("adc[4][%d]",i));
  }
}


void sort(Int_t n,Double_t *x){
  Double_t *tmp = new Double_t[n];
  Int_t *index = new Int_t[n];
  TMath::Sort(n,x,index,0);
  for(int i=0;i<n;i++){
    tmp[i] = x[index[i]];
  }
  memcpy(x,tmp,sizeof(Double_t)*n);
}


void fit(){
  for(int i=0;i<32;i++){
    sp[i] = new TSpectrum(6,1);
		
		// find peaks
    Int_t nfound = sp[i]->Search(h[i],2,"",0.05);
    if(nfound!=3) {
      cout << "Ch No. " << i << " found " << nfound << " peaks!" << endl;
      continue;
    }

    Double_t* xpeaks = sp[i]->GetPositionX();
    Int_t npeaks=0;
    for(int p=0;p<nfound;p++){
      Float_t xp = xpeaks[p];
      Int_t bbin = h[i]->GetXaxis()->FindBin(xp);
      Float_t yp = h[i]->GetBinContent(bbin);

      fPeaks->SetParameters(yp/5.,xp-5,2,yp,xp,2);
      fPeaks->SetParLimits(1,xp-20,xp+20);
      fPeaks->SetParLimits(4,xp-20,xp+20);

      h[i]->Fit(fPeaks,"q+","",xp-20,xp+20);
      fPeaks->GetParameters(&par[i][6*p]);
      Double_t tmppar[6];
      Int_t fcnt=0;
      while(1){
        memcpy(tmppar,&par[i][6*p],sizeof(Double_t)*6);
        h[i]->Fit(fPeaks,"q+","",tmppar[1]-20,tmppar[4]+TMath::Abs(tmppar[5]*2));
				fPeaks->GetParameters(&par[i][6*p]);
				if(TMath::Abs(tmppar[1]-par[i][6*p+1])<0.01&&TMath::Abs(tmppar[4]-par[i][6*p+4])<0.01) break;
				fcnt++;
				if(fcnt>20) break;
      }
      npeaks++;
    }
    
    const Double_t ener[4] = {5.156,5.486,5.805,25.423};
    Double_t *bin = new Double_t[npeaks+1];
    for(int p=0;p<npeaks;p++){
      bin[p] = TMath::Abs(par[i][6*p+4]);
    }
    sort(npeaks,bin);
    if(abin[i]>0) {
      bin[npeaks] = abin[i];
      gr[i] = new TGraph(npeaks+1,bin,ener);
    }
    else 
    gr[i] = new TGraph(npeaks,bin,ener);
    gr[i]->Fit(fLine);
    fLine->GetParameters(&lpar[i][0]);
    memcpy(&lpare[i][0],fLine->GetParErrors(),sizeof(Double_t)*2);

    cout<<"Finish fitting ch : "<<i<<endl;
  }
}

void record(){
  ofstream out("califl.txt");
  for(int i=0;i<32;i++){
    out << lpar[i][0] << "\t" <<lpare[i][0] << "\t" << lpar[i][1] << "\t" << lpare[i][1] <<endl;
  }
  out.close();
  TFile *file=new TFile("save.root","RECREATE");
  for(int i=0;i<32;i++){
    if(h[i]!=0) h[i]->Write();
    if(gr[i]!=0) gr[i]->Write();
  }
  file->Close();
}

int main(){
  createHisto();
  readpar();
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus("adc",1);
  project();
  fit();
  record();
}
