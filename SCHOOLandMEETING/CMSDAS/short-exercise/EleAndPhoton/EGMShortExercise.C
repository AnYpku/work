#define EGMShortExercise_cxx
#include "EGMShortExercise.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TLorentzVector.h>



void EGMShortExercise::Loop()
{
//   In a ROOT session, you can do:
//      root> .L EGMShortExercise.C
//      root> EGMShortExercise t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TFile* outputFile = new TFile("Out_data_tight_pixel.root","RECREATE");
   TH1F* h_diphoMass = new TH1F("h_diphoMass_data_tight_pixel", "diphoMass", 500, 0, 500);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      int pho1_index,pho2_index;
      double maxPt_1st=0,maxPt_2nd=0;
      for(int ipho=0; ipho< phoE->size();ipho++) {
         if((*phoEt)[ipho]>maxPt_1st) {
            maxPt_1st= (*phoEt)[ipho];
            pho1_index=ipho;
          }
       }// find photon having max Et
      for(int ipho=0; ipho< phoE->size();ipho++) {
        if(ipho==pho1_index)continue;
        if((*phoEt)[ipho]>maxPt_2nd) {
             maxPt_2nd= (*phoEt)[ipho];
             pho2_index=ipho;
           }
       } //find photon having second max Et
     TLorentzVector pho1;
     TLorentzVector pho2;
     pho1.SetPtEtaPhiM((*phoEt)[pho1_index], (*phoEta)[pho1_index],(*phoPhi)[pho1_index],0);
     pho2.SetPtEtaPhiM((*phoEt)[pho2_index], (*phoEta)[pho2_index],(*phoPhi)[pho2_index],0);
     double diphotonMass = (pho1+pho2).M();
     if ( ((*phoIDbit)[pho1_index] & 4)== 4) {
        if ( ((*phoIDbit)[pho2_index] & 4)== 4) {
            if ( ( (*phohasPixelSeed)[pho1_index]) == 0 ){
                if ( ( (*phohasPixelSeed)[pho2_index]) == 0 ){
                        h_diphoMass->Fill(diphotonMass);
                   }
              }
         }
      }

   }
   h_diphoMass->Write();
   outputFile->Close();

}
