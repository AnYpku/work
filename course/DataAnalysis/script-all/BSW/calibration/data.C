#define data_cxx
#include "data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH2D.h>

void data::Loop()
{
//   In a ROOT session, you can do:
//      root> .L data.C
//      root> data t
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
   //TCanvas *c = new TCanvas("c","c",1200,600);
   //c->Divide(2,1);
   TH2D *cali1 = new TH2D("cali1","energy calibration1",32,0,32,1000,0,1000);
   TH1D * cali10 = new TH1D("cali10","energy distribution",1000,0,1000);
   TH2D *cali2 = new TH2D("cali1","energy calibration2",32,0,32,600,0,6);
   TH1D * cali20 = new TH1D("cali20","energy calibration distribution",600,0,6);
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
 //     mapping(cali,cali1);
      for(int j=0;j<32;j++){
        madc[4][j]=linearfit[j][0]+linearfit[j][1]*adc[4][j];
        cali1->Fill(j,adc[4][j]);
        cali10->Fill(adc[4][j]);
        cali2->Fill(j,madc[4][j]);
        cali20->Fill(madc[4][j]);
        }
      // if (Cut(ientry) < 0) continue;
   }
   TCanvas *c = new TCanvas("c","c",1200,600);
   c->Divide(2,1);
   c->cd(1);
   cali1->Draw("colz");
   c->cd(2);
   cali2->Draw("colz");
   c->SaveAs("draw.root");
   c->Close();
   delete cali1;
   delete cali2;  

   TCanvas *c1 = new TCanvas("c1","c1",1200,600);
   c1->Divide(2,1);
   c1->cd(1);
   cali10->Draw("");
   c1->cd(2);
   cali20->Draw("");
   c1->SaveAs("draw1.root");
   c1->Close();
   delete cali10;
   delete cali20;

   return 0;

 }

/*void data::mapping(TH2D *h1, TH2D *h2){
      for(int j=0;j<32;j++){
        madc[4][j]=linearfit[j][0]+linearfit[j][1]*adc[4][j];
        h1->Fill(j,adc[4][j]);
	h2->Fill(j,madc[4][j]);
        }

*/

