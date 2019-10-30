#include "ExRootClasses.cc"
#include "ExRootFactory.cc"
#include "ExRootFilter.cc"
#include "ExRootLHEFReader.cc"
#include "ExRootProgressBar.cc"
//#include "ExRootStream.cc"
#include "ExRootTreeBranch.cc"
#include "ExRootTreeReader.cc"
#include "ExRootTreeWriter.cc"
#include "ExRootUtilities.cc"
#include "ExRootXDRReader.cc"
void test2(){
R__LOAD_LIBRARY(libExRootAnalysis.so)

 float inix= 0.0;
 float finx= 200.0;
 float nbin= 200.0;

TString IFile1 = "ppll_nlo.root";
TChain chain("LHEF");
chain.Add(IFile1); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
 Long64_t numberOfEntries = treeReader->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent = treeReader->UseBranch("Event");
 TClonesArray *branchParticle = treeReader->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h1= new TH1F("1_Mjj","test histogram",nbin,inix,finx);
 h1->Sumw2();
 TLorentzVector J1, J2, JJ;
for(int i=0; i<=numberOfEntries-1; i++)
{
////*****************************************************************
    J1.SetPtEtaPhiE(0.,0.,0.,0.);
    J2.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader->ReadEntry(i);
    TRootLHEFEvent *event=(TRootLHEFEvent*) branchEvent->At(0);
    int np=event->Nparticles;
    for(int j=2; j<np; j++){
      TRootLHEFParticle *particle1=(TRootLHEFParticle*) branchParticle->At(j);
      //if((abs(particle1->PID)<6 || (particle1->PID)==21) ) {
          if(J1.E()>0){
          J2.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
             }
          else{  
          J1.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
             }
       // }
     }
     JJ=J1+J2;
    h1->Fill(JJ.M(), 1300.6/float(numberOfEntries)); 
////*****************************************************************
}
      TCanvas *c1= new TCanvas("c1","test graph",750,500);
      gStyle->SetOptStat(0);
      gStyle->SetPadGridX(1);
      gStyle->SetPadGridY(1);
      gStyle->SetPadTickX(1);
      gStyle->SetPadTickY(1);
      gStyle->SetAxisColor(1, "XYZ");
      gStyle->SetStripDecimals(kTRUE);
      gStyle->SetTickLength(0.03, "XYZ");

//      h1->GetXaxis()->SetTitle("M_{jj} [GeV] ");
      h1->GetYaxis()->SetTitle("#sigma (fb) # bin");
      h1->GetXaxis()->CenterTitle();
      h1->GetYaxis()->CenterTitle();
      h1->SetStats(kFALSE);
      h1->SetLineColor(kBlack);
      h1->SetLineWidth(3);
      h1->SetMarkerStyle(20);
      h1->GetXaxis()->SetTitleOffset(0.6);
      h1->GetYaxis()->SetTitleOffset(0.8);
      h1->Draw("HIST");


      TLegend *l1 = new TLegend(0.65,0.65,0.78,0.82);
      l1->SetBorderSize(1);
      l1->SetFillColor(0);
      l1->AddEntry(h1,"MG");
      l1->Draw();
      c1->SaveAs("comparemjj2.pdf");
 
}
