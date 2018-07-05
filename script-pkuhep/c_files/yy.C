#include <memory>
#include <fstream>
#include <ostream>
#include <iostream>
#include <stdio.h>
#include "TAxis.h"
#include <TH1.h>
#include <TH2.h>
#include <THStack.h>
#include <TGraph.h>
#include <TGraphErrors.h> 
#include <TGraphAsymmErrors.h>
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TPaveStats.h"
#include "TProfile.h"
#include "TStyle.h"   
#include "TString.h"
#include "TVector2.h"
#include "TEfficiency.h"    

#define PI 3.1415926536
using namespace std;
     
void yy() 
{
     TFile *file1 = new TFile("1.root","R"); 
     file1->cd("");
     TH1F* h1= (TH1F*) pTSim->Clone();
     TH1F* h2= (TH1F*) pTSim_matchedB->Clone();

     TFile *file2 = new TFile("12.root","R"); 
     file2->cd("");
     TH1F* k1= (TH1F*) pTSim->Clone();
     TH1F* k2= (TH1F*) pTSim_matchedB->Clone();


     if(TEfficiency::CheckConsistency(*h2,*h1))
        {
        hR1 = new TEfficiency(*h2,*h1);
        }

     if(TEfficiency::CheckConsistency(*k2,*k1))
        {
        hK1 = new TEfficiency(*k2,*k1);
        }


     TCanvas *cr1 = new TCanvas("cr1","",700,500);
     cr1->SetLogy();
     hR1->SetLineWidth(1);
     hR1->SetMarkerStyle(20);
     hK1->SetLineWidth(1);
     hK1->SetMarkerStyle(20);
     hR1->SetLineColor(kBlue);
     hK1->SetLineColor(kRed);
     hR1->Draw("AP");
     hK1->Draw("same");
     TLegend *lr1 = new TLegend(0.6,0.2,0.8,0.4);
     lr1->SetBorderSize(1);
     lr1->SetFillColor(0);
     lr1->AddEntry(hR1,"CSC","l");
     lr1->AddEntry(hK1,"CSC+GEM","l");
     lr1->Draw();
     cr1->SaveAs("new.png");




}
