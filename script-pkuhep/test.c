{
#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>
  gStyle->SetOptStat(00);
  Double_t xlow=-1,xhigh=500;
  Int_t xbins=200;
  TBranch *b_npT;
  TCut mycut;
  TString b="npt",

  TFile *f1 = new TFile("p1.root");
//  f1->cd("treeDumper");
  TTree* t1= (TTree*)f1->Get("demo");
  TH1F *h1 =new TH1F("private",b,xbins,xlow,xhigh);
  TH1F *h3 =new TH1F("s1","scalef",xbins,xlow,xhigh);
  TH1F *h4 =new TH1F("l1","lumiWeight",xbins,xlow,xhigh);
  TH1F *h5 =new TH1F("p1","pilupWeight",xbins,xlow,xhigh);
  t1->Project("private",b);
  t1->Project("l1","lumiWeight");
  t1->Project("p1","pileupWeight");
  t1->Project("s1","scalef");
  
  TH1F *hh;
  hh->Multiply()  
  
  TFile *f2 = new TFile("ps.root"); 
//  f2->cd("treeDumper");
  TTree* t2= (TTree*)f2->Get("demo");
  TH1F *h2 =new TH1F("standard","",xbins,xlow,xhigh);
  t2->Project("standard",b);

  TCanvas *c1 =new TCanvas("c1",b,0,0,900,600);   
  c1.cd();
  
    h1->SetLineColor(2);
    h1->SetMarkerStyle(20);
    h1->SetMarkerSize(1);
    h1->SetLineWidth(2);

    h2->SetLineColor(3);
    h2->SetMarkerStyle(20);
    h2->SetMarkerSize(1);
    h2->SetLineWidth(2);

//    h2->Scale(h1->GetMaximum()/h2->GetMaximum());

    TLegend *lg1 = new TLegend(0.5,0.7,0.7,0.9);
    lg1->AddEntry(h1,"private","l");
    lg1->AddEntry(h2,"standard sample","l");
   
    h1->Draw();
    h2->Draw("same");
    lg1->Draw();
    c1->cd();
    c1->Update();
    c1->Print(b+".eps");
}
