#define com_cxx
#include "com.h"
#include <TH2.h>
#include <TLine.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLegend.h"
#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;
void com::Loop(TString name,TString title)
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   bool laj,laj_hlt;
   gStyle->SetOptStat(0);
   TH1D* h1 = new TH1D(name+"_"+title,title,20,60,120);
   TH1D* h1_hlt = new TH1D(name+"_"+title+"_hlt",title,20,60,120);
   h1->Sumw2();
   h1_hlt->Sumw2();
   TCanvas*c1 = new TCanvas(name+"_"+title,title,600,500);
   h1->SetLineColor(1);
   h1->SetTitle(name+"-"+title);
   h1_hlt->SetLineColor(2);
   TLegend* l1 = new TLegend(0.1,0.7,0.3,0.9);
   l1->AddEntry(h1,"no hlt");
   l1->AddEntry(h1_hlt,"with hlt");
   Long64_t nbytes = 0, nb = 0;
   double b;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      laj= lep == 13 && ptlep1 > 20. && ptlep2 > 20. && fabs(etalep1) < 2.4 && fabs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep > 70. && massVlep < 110.  && drla2>0.7 && drla>0.7 && photonet > 20.&& fabs(photoneta) < 1.4442 && jet1pt> 30 && fabs(jet1eta)< 4.7 && jet2pt > 30 && fabs(jet2eta)<4.7&& drj1a>0.5 &&drj2a>0.5 && drj1l>0.5 && drj2l>0.5 && Mjj > 150&&Mjj<400;
      if(name.Contains("MuonB")==1)
      laj_hlt = lep == 13 &&  (HLT_Mu1>0/*|| HLT_Mu2>0*/) && ptlep1 > 20. && ptlep2 > 20. && fabs(etalep1) < 2.4 && fabs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep > 70. && massVlep < 110.  && drla2>0.7 && drla>0.7 && photonet > 20.&& fabs(photoneta) < 1.4442 && jet1pt> 30 && fabs(jet1eta)< 4.7 && jet2pt > 30 && fabs(jet2eta)<4.7&& drj1a>0.5 &&drj2a>0.5 && drj1l>0.5 && drj2l>0.5 && Mjj > 150 && Mjj<400;
      else
      laj_hlt = lep == 13 &&  (HLT_Mu1>0|| HLT_Mu2>0) && ptlep1 > 20. && ptlep2 > 20. && fabs(etalep1) < 2.4 && fabs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep > 70. && massVlep < 110.  && drla2>0.7 && drla>0.7 && photonet > 20.&& fabs(photoneta) < 1.4442 && jet1pt> 30 && fabs(jet1eta)< 4.7 && jet2pt > 30 && fabs(jet2eta)<4.7&& drj1a>0.5 &&drj2a>0.5 && drj1l>0.5 && drj2l>0.5 && Mjj > 150 && Mjj<400;
    
      if(laj) h1->Fill(massVlep);
      if(laj_hlt) h1_hlt->Fill(massVlep);
   }
   TH1D*h3=(TH1D*)h1_hlt->Clone();
   TLine* line = new TLine(60,1.,120,1);
   h3->Divide(h1);
   h3->SetMarkerStyle(22);
   h3->SetMarkerColor(kBlue+1);
   h3->SetLineColor(kBlue+1);
   h3->Sumw2();
   h3->SetTitle("");
   l1->AddEntry(h3,"with hlt/no hlt");
   TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
   top_pad->Draw();
   top_pad->cd();
   top_pad->SetGrid();
   top_pad->SetBottomMargin(0.2);

   h1->Draw("hist");
   h1_hlt->Draw("hist same");
   l1->Draw();
   double r = h1_hlt->GetSumOfWeights()/h1->GetSumOfWeights();
   std::cout<<r<<std::endl;
   TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
   bottom_pad->Draw();
   bottom_pad->cd();
   bottom_pad->SetGrid();
   bottom_pad->SetTopMargin(0.1);
   h3->Draw("PE");
//   h3->GetXaxis()->SetTitle( title[i] +" [GeV] ");
//   h3->GetYaxis()->SetTitle("K factor ");
//   h3->GetXaxis()->CenterTitle();
//   h3->GetYaxis()->CenterTitle();
   h3->GetXaxis()->SetTitleOffset(0.9);
   h3->GetYaxis()->SetTitleOffset(0.22);
   h3->GetXaxis()->SetTitleSize(0.15);
   h3->GetYaxis()->SetTitleSize(0.15);
   h3->GetXaxis()->SetLabelSize(0.12);
   h3->GetYaxis()->SetLabelSize(0.1);
   h3->SetMaximum(1.35);
   h3->SetMinimum(0.7);
   line->SetLineColor(kRed);
   line->Draw();
   c1->SaveAs("./"+name+".eps");
//   c1->SaveAs("./"+name+".C");
   delete l1;
   delete c1;
   delete h1;
   delete h1_hlt;
}
