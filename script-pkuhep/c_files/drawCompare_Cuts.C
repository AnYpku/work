#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TCanvas.h"
#include "TAxis.h"


void drawCompare_Cuts( Int_t hist1D = 1,  Int_t hist1Dlog = 0,  Int_t hist2D = 0,  Int_t hist2Dlog = 0, Int_t hist3D = 0)
{
  TString f1Name = "/store/home/andy/outprivat_ZA.root";
  TString f2Name = "/store/home/andy/outofficial_ZA.root";
  TFile *f1 = TFile::Open(f1Name);
  TFile *f2   = TFile::Open(f2Name);

  Double_t npT,Mjj,photonet;
  Int_t nVtx;
  
  TString figsDir = "./"; 
    cout<<"root file is: "<<f1Name.Data()<<endl;
    cout<<"root file is: "<<f2Name.Data()<<endl;
  TTree *t1=(TTree *)f1->Get("demo");
  TTree *t2=(TTree *)f2->Get("demo");
  TH1D *h1;
  Int_t en1=t1->GetEntries();
  Int_t en2=t2->GetEntries();

  if(hist1D) 
     {
        const int maxHistNum = 5;
        TString histName[maxHistNum] = {"Mjj","npT","photonet","nVtx"};
        TString WeightName[3] = {"lumiWeight","pileupweight","scalfe"};
     
        for(int i=0; i<maxTH1DHistNum; i++)
           {
             cout<<"histogram is: "<<histName[i].Data()<<endl;
        

             TString Name      = histName[i].Data();
             TString treeName      = histName[i].Data();
             TString titleCan      = histName[i].Data();
             TString figName   = figsDir + Name + ".eps";
             t1->SetBranchAddress(Name,&)
             h1=new TH1D("h1",Name,bin,low,high);
             for(Int_t i;i<en1;i++)
                {
                  
                


                }

             TCanvas* canv = new TCanvas(titleCan, titleCan, 900, 600);
             Name->SetMinimum(0.0);
             NameData->GetYaxis()->SetTitleOffset(1.2);
             NameData->Draw();
             canvName->SaveAs(figName);
           }
      }  


}
