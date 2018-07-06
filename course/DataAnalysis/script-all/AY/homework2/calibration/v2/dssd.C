#define dssd_cxx
#include "dssd.h"
#include <TROOT.h>
#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TGraph.h>
#include <TSpectrum.h>
#include <TFitResult.h>
#include <TMultiGraph.h>
#include <TF1.h>
#include <TH2D.h>
#include <TH1F.h>
#include <iostream>
#include <TCanvas.h>
#include <fstream>
using namespace std;


void dssd::Loop()
{
   TH2D *cali1 = new TH2D("cali1","",32,0,32,1000,0,1000);
   TH2D *cali2 = new TH2D("cali2","",32,0,32,400,3,6);
   int row=0;
   ifstream inFile;
   inFile.open("./cali.txt");
   while(getline(inFile,tmp,'\n')){
    row++;
   }
   inFile.close();
   ifstream inFile1;
   inFile1.open("./cali.txt");
   for(int i=0;i<row;i++){
    inFile1>>linearfit[i][0]>>linearfit[i][1]>>linearfit[i][2]>>linearfit[i][3];
    cout<<" "<<linearfit[i][0]<<" "<<linearfit[i][1]<<endl;
    }
   inFile1.close();
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      for(int j=0;j<32;j++){
        Double_t tmp=linearfit[j][0]+linearfit[j][1]*adc[4][j];//madc[4][j]
        cali1->Fill(j,adc[4][j]);
        cali2->Fill(j,tmp);
        }
   }
   he=cali2->ProjectionY();

   TCanvas *c3 = new TCanvas("c3","c3",1800,600);
   
   c3->Divide(3,1);
   c3->cd(1);
   cali2->Draw("colz");
   //gPad->SetLogz(1);
   c3->cd(2);
   he->Draw();
   c3->cd(3);
   he->Draw();
   gPad->SetLogy(1);
   c3->SaveAs("draw.root");
   c3->SaveAs("draw.eps");
   c3->Close();
   delete cali1;
   delete cali2;  
}

// create 32 histograms for adc[4][*]
 void dssd::createHisto(TTree *tree){
   for(int i=0;i<32;i++){
     char hname[16];
     sprintf(hname,"h%d",i);
     h[i]=new TH1F(hname,hname,250,700,950);
   }
   he=new TH1D("he","merge 32 ch",500,0,6);
   fit=new TF1("fit","gaus(0)+gaus(3)",0,4000);
   line=new TF1("ln","pol1",0,4000);
 }

 // read adc[4][*] to histogram
 void dssd::project(TTree *tree){
   for(int i=0;i<32;i++){
     tree->Project(TString::Format("h%d",i),TString::Format("adc[4][%d]",i));
   }
 }

// fit histogram and find xbins 
 void dssd::fitpeak(){
 grtest =new TMultiGraph();
 grtest1=new TGraph(32);
 grtest2=new TGraph(32);
 grtest3=new TGraph(32);
   for(int i=0;i<32;i++){
     sp[i]=new TSpectrum(6,1); //consider there are 6 peaks, and set resoluion=1
     Int_t nfound = sp[i]->Search(h[i],2,"",0.05); //0.05:peaks with amplitude less than threshold*higst_peak are discareded
     if(nfound!=3) {
       cout<<"Ch No. "<<i<<" found "<<nfound<<" peaks!"<<endl;
       continue;
     }
    Double_t *xpeaks = sp[i]->GetPositionX();
    Int_t npeaks=0;
    for(int p=0;p<nfound;p++){
      Float_t xp = xpeaks[p];
      Int_t bbin = h[i]->GetXaxis()->FindBin(xp); //定位xp处的bin值
      Float_t yp = h[i]->GetBinContent(bbin);   //定位xp出bin的计数

      fit->SetParameters(yp/5.,xp-5,2,yp,xp,2);
      fit->SetParLimits(1,xp-20,xp+10);
      fit->SetParLimits(4,xp-7,xp+7);
      fit->SetParLimits(2,0.5,6);
      fit->SetParLimits(5,0.5,6);

      h[i]->Fit(fit,"Nq+","",xp-20,xp+20);
      fit->GetParameters(&par[i][6*p]);
      Double_t tmppar[6];
      Int_t fcnt=0;
      while(1){
        memcpy(tmppar,&par[i][6*p],sizeof(Double_t)*6);
        h[i]->Fit(fit,"Nq+","",tmppar[1]-TMath::Abs(tmppar[1]),tmppar[4]+TMath::Abs(tmppar[5]*3));//再次fit,以寻求最佳的参数值
        gStyle->SetOptFit(1111);
	fit->GetParameters(&par[i][6*p]);
	if(TMath::Abs(tmppar[1]-par[i][6*p+1])<0.01&&TMath::Abs(tmppar[4]-par[i][6*p+4])<0.01) break;
	fcnt++;
	if(fcnt>20) break;
      }
      h[i]->Fit(fit,"q+","",tmppar[1]-TMath::Abs(tmppar[1]),tmppar[4]+TMath::Abs(tmppar[5]*3));
      npeaks++;
      xbin[p]=par[i][6*p+4];
      
    }
    
    const Double_t ener[4]={5.156,5.486,5.805};



    gr[i]=new TGraph(npeaks,xbin,ener);//xbin xpeaks
    gr[i]->Fit(line);
    gr[i]->Draw("AP");
    gr[i]->SetMarkerStyle(20);
    gr[i]->SetMarkerSize(1.0); 
    gr[i]->SetMarkerColor(kGreen);
    gStyle->SetOptFit(1);
    line->GetParameters(&lpar[i][0]);


    grtest1->SetPoint(i,i,par[i][6*0+4]*lpar[i][1]+lpar[i][0]);
    grtest2->SetPoint(i,i,par[i][6*1+4]*lpar[i][1]+lpar[i][0]);
    grtest3->SetPoint(i,i,par[i][6*2+4]*lpar[i][1]+lpar[i][0]);

    memcpy(&lpare[i][0],line->GetParErrors(),sizeof(Double_t)*2);
    cout<<"Finish fitting ch : "<<i<<endl;
  }
    grtest1->Draw();
    grtest1->SetMarkerStyle(20);
    grtest1->SetMarkerSize(1.0); 
    grtest1->SetMarkerColor(kGreen);

    grtest2->Draw();
    grtest2->SetMarkerStyle(20);
    grtest2->SetMarkerSize(1.0); 
    grtest2->SetMarkerColor(kGreen);

    grtest3->Draw();
    grtest3->SetMarkerStyle(20);
    grtest3->SetMarkerSize(1.0); 
    grtest3->SetMarkerColor(kGreen);

    grtest->Add(grtest1);
    grtest->Add(grtest2);
    grtest->Add(grtest3);
      
    grtest->Draw();

 }

 // save information of energy calibrtion
 void dssd::record(){
   ofstream out("cali.txt");
   for(int i=0;i<32;i++){
     out<<lpar[i][0]<<"\t"<<lpar[i][1]<<"\t"<<lpare[i][0]<<"\t"<<lpare[i][1]<<endl;
   }
   out.close();
   file=new TFile("cali.root","RECREATE");
   tree=new TTree("tree","RECREATE");
   tree->Branch("parpeaks",&par);
   for(int i=0;i<32;i++){
     if(h[i]!=0) h[i]->Write();
     //if(gr[i]!=0) gr[i]->Write();
   }
   grtest->Write();
   tree->Fill();
   file->Write();
   file->Close();
 }

