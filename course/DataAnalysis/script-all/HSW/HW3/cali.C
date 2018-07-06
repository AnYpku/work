#define cali_cxx
#include "cali.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void cali::Loop()
{
//   In a ROOT session, you can do:
//      root> .L cali.C
//      root> cali t
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
   Double_t lpar[32][4];
   ifstream infile;
   infile.open("califl.txt");
   for(Int_t i=0;i<32;i++)  //行循环
    {   for(Int_t j=0;j<4;j++)  //列循环
         {  infile>>lpar[i][j];
         }
     }
   infile.close();

   Double_t caliE[32];
   Int_t ch[32];
   TFile *file= new TFile("calien.root","recreate");  
   TTree *tree = new TTree("tree","tree");
   tree->Branch("caliE",caliE,"caliE[32]/D");
   ctree->Branch("ch",ch,"ch[32]/I");
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      fChain->SetBranchStatus("*",0);
      fChain->SetBranchStatus("adc",1);
      for(Int_t i=0;i<32;i++){
           caliE[i]=lpar[i][0]+lpar[i][2]*adc[4][i];
           ch[i]=i;
           tree->Fill();
       }
     
   }
  tree->Write();
  file->Close();
}
