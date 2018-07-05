#include <TF1.h>
#include <TH1F.h>
#include <TGraph.h>
#include <TSpectrum.h>
#include <TString.h>
#include <TStyle.h>
#include <TMath.h>


#include <iostream>

using namespace std;

TH1F *h[32];  //32个histogram
TGraph *gr[32];
TSpectrum *s[32];  
TF1 *fit; //gaus拟合函数
TF1 *line; //能量刻度
TString infile = "../data.root";
TString outfile = "cali.root";
Double_t alphaPeak[32][6]; //3个峰道址
Double_t par[32][32]; //gaus拟合的参数
Double_t lpar[32][2]; //线性拟合的参数
Double_t lpare[32][2]; //线性拟合的误差
const Double_t ener[3]={5156,5486,5805};  //keV

void getADCHisto(TTree *tree);
void project(TTree *tree);
void fitPeak();
void energycali();

int main(){
  TFile *ipf = new TFile(infile); //打开data.root
  if(!ipf->IsOpen()){
    cout<<"cannot open input file:"<<infile<<endl;
    return 1;}
  TTree *ipt = (TTree*)ipf->Get("tree");
  if(ipt == 0){
    cout<<"cannot find input tree!"<<endl;
    return 1;}
  
  getADCHisto(ipt);
  
  project(ipt);
  fitPeak();
  energycali();
  TFile *opf = new TFile(outfile,"RECREATE");
  for(Int_t i=0;i<32;i++){
    if(h[i]!=0)  h[i]->Write();
    if(gr[i]!=0) gr[i]->Write();}
  opf->Close();
  
  return 0;
}



void getADCHisto(TTree *tree){
 for(Int_t i=0;i<32;i++){
  char hname[32];
  sprintf(hname,"h%d",i);
  h[i]=new TH1F(hname,hname,500,500,1000);
   }
  fit=new TF1("fit","gaus(0)+gaus(3)",0,1000);
  line=new TF1("line","pol1",0,1000);
}
               
void project(TTree *tree){
 for(Int_t i=0;i<32;i++){
 
   tree->Project(TString::Format("h%d",i),TString::Format("adc[4][%d]",i));
 }
}
     
void fitPeak(){
 ofstream out("caliPara.txt"); //存储gaus拟合的参数
 for(Int_t i=0;i<32;i++){
  s[i]=new TSpectrum(6,1);
  Int_t nfound=s[i]->Search(h[i],2,"",0.05);  //找到几个peak
   if(nfound!=3){
    cout<<"Ch No."<<i<<" found "<<nfound<<" peaks!"<<endl;
    continue;
    }
  Double_t *xpeaks = s[i]->GetPositionX();
  Int_t npeaks=0;
    for(Int_t p=0;p<nfound;p++){
      Float_t xp = xpeaks[p];  //第p+1个峰的横坐标
      Int_t bin = h[i]->GetXaxis()->FindBin(xp); //获得这个峰的bin值
      Float_t yp = h[i]->GetBinContent(bin);  //获得该bin的数目
      //alphaPeak[i][p] = bin;            

      fit->SetParameters(yp/5.,xp-7,2,yp,xp,2);
      fit->SetParLimits(1,xp-20,xp+20);
      fit->SetParLimits(4,xp-20,xp+20);

      if(p==0) h[i]->Fit(fit,"q+","",xp-10,xp+8);
      if(p==1) h[i]->Fit(fit,"q+","",xp-10,xp+8);
      if(p==2) h[i]->Fit(fit,"q+","",xp-10,xp+5);
      fit->GetParameters(&par[i][6*p]); //对于每个峰有6个参数，赋值  
      
      cout<<fit->GetParameter(0)<<"\t"<<fit->GetParameter(1)<<"\t"<<fit->GetParameter(2)<<"\t"<<fit->GetParameter(3)<<"\t"<<fit->GetParameter(4)<<"\t"<<fit->GetParameter(5)<<endl;
       
      alphaPeak[i][p]=TMath::Abs(fit->GetParameter(4));
      npeaks++;
       }
  cout<<"Ch No."<<i<<" fit "<<npeaks<<" peaks!"<<endl;
  out<<alphaPeak[i][0]<<"\t"<<alphaPeak[i][1]<<"\t"<<alphaPeak[i][2]<<endl; //将拟合参数道保存到文件中
 }
 out.close();
}

 
void energycali(){
    gStyle->SetOptFit(kTRUE);
    ofstream out("califl.txt");
    for(Int_t i=0;i<32;i++){
       Double_t peaks[3];  //每一个histo的peak
        for(Int_t p=0;p<3;p++){
           peaks[p]=alphaPeak[i][p];}
      //cout<<peaks[0]<<" "<<peaks[1]<<" "<<peaks[2]<<endl;
       gr[i] = new TGraph(3,peaks,ener); //注意前面是x
       //gr[i]=new TGraph(3);
       // for(Int_t k=0;k<3;k++){
       //      gr[i]->SetPoint(k,peaks[k],ener[k]);
        // }
       gr[i]->Fit(line);  //有引号
       line->GetParameters(&lpar[i][0]);
       memcpy(&lpare[i][0],line->GetParErrors(),sizeof(Double_t)*2);  //储存误差
      // cout<<line->GetChisquare()<<line->GetNDF()<<endl;
       out<<lpar[i][0]<<"\t"<<lpare[i][0]<<"\t"<<lpar[i][1]<<"\t"<<lpare[i][1]<<endl;
     }
    out.close();
}


