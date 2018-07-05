#define ppac_cxx
#include "ppac.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <TPave.h>

using namespace std;

void ppac::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ppac.C
//      root> ppac t
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

	 fChain->SetBranchStatus("*",0);
	 fChain->SetBranchStatus("PPACF8",1);

	 TCanvas *c = new TCanvas("c","c",400,400);
	 TH2F*  htar = new TH2F("htar","Distribution on Target",100,-50,50,100,-50,50);

	 TFile* opf = new TFile("run87PPACF8.root","recreate");
	 TTree* opt = new TTree("t1","t1");

	 Float_t PPACF8Pos[5][5]; //存储原始PPAC位置信息,x,y,xz,yz,ta
	 Bool_t PPACFlag[5][3]; //每个PPAC x,y,anode是否有效
	 //below, [0] and [1] for the 1st dimension means x and y, respectively
	 Int_t cnt[2]; //每个event中x,y有效PPAC数
	 Bool_t ValidEvent[2]; //该event是否可用于x,y径迹重建
	 Float_t FitFactor[2][3]; //拟合系数a,b,chi2 for x and y
	 Float_t Target[2]; //径迹打在靶上的位置
	 Bool_t  InTarget; //this event in target or not

	 opt->Branch("PPACF8Pos",PPACF8Pos,"PPACF8Pos[5][5]/F");
	 opt->Branch("PPACFlag",PPACFlag,"PPACFlag[5][3]/O");
	 opt->Branch("cnt",cnt,"NumOfValidPPAC[2]/I");
	 opt->Branch("ValidEvent",ValidEvent,"ValidEvent[2]/O");
	 opt->Branch("FitFactor",FitFactor,"FitFactor[2][3]/F");
	 opt->Branch("Target",Target,"Target[2]/F");
	 opt->Branch("InTarget",&InTarget,"InTarget/O");

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

	 cnt[0] = 0; cnt[1] = 0;
	 ValidEvent[0] = false; ValidEvent[1] = false; //initial

			for(Int_t i=0;i<4;i++) {
				for(Int_t j=0;j<5;j++) PPACF8Pos[i][j]=PPACF8[i][j];
					if(TMath::Abs(PPACF8Pos[i][0])<=120) {
						PPACFlag[i][0]=true;
						cnt[0]++;}
					else PPACFlag[i][0]=false;
					if(TMath::Abs(PPACF8Pos[i][1])<=75) {
						PPACFlag[i][1]=true;
						cnt[1]++;}
					else PPACFlag[i][1]=false;
					if(PPACF8Pos[i][4]>0) PPACFlag[i][2]=true;
					else PPACFlag[i][2]=false;
			}

			// i=4 the third single PPAC
			for(Int_t j=0;j<5;j++)	PPACF8Pos[4][j]=PPACF8[4][j];
				if(TMath::Abs(PPACF8Pos[4][0])<=50) {
					PPACFlag[4][0]=true;
					cnt[0]++;}
				else PPACFlag[4][0]=false;
				if(TMath::Abs(PPACF8Pos[4][1])<=50) {
					PPACFlag[4][1]=true;
					cnt[1]++;}
				else PPACFlag[4][1]=false;
				if(PPACF8Pos[4][4]>0) PPACFlag[4][2]=true;
				else PPACFlag[4][2]=false;

	 for(Int_t i=0;i<2;i++) {
	 
	 if((cnt[i]<2)||((cnt[i]==2)&&((PPACFlag[0][i]&&PPACFlag[1][i])||(PPACFlag[2][i]&&PPACFlag[3][i])))) {
		// 如果只有两个PPAC有效，则它们不能同时是01或23
	 		ValidEvent[i] = false;
			FitFactor[i][0] = -1000; FitFactor[i][1] = -1000; FitFactor[i][2] = -1000;
	 }

	 else {
	  //其他情况（cnt>2或在两套不同PPAC上）该event有效
	 		ValidEvent[i] = true;
			Int_t num = cnt[i];
			Float_t xory[num], z[num];
		  Int_t j=0;
	 		for(Int_t m=0;m<5;m++) {
				if(PPACFlag[m][i]) {
					xory[j] = PPACF8[m][i];
					z[j] = PPACF8[m][i+2];
					j++;
				}
			}
			TGraph* gr = new TGraph(num,z,xory);
			TF1 *f = new TF1("f","[0]+[1]*x",-2000,0);
//			TF1 *fx = new TF1("fx","pol1",-2000,0);
			gr->Fit(f,"q+");

			FitFactor[i][0] = f->GetParameter(0);
			FitFactor[i][1] = f->GetParameter(1); //xx=xa+xb*xz
			FitFactor[i][2] = f->GetChisquare();
			
			delete gr;
			delete f;
	 }
	}
			//rotate the target
			if(ValidEvent[0]&&ValidEvent[1]) {
		  	Float_t xa = FitFactor[0][0]; Float_t xb = FitFactor[0][1];
		  	Float_t ya = FitFactor[1][0]; Float_t yb = FitFactor[1][1];
				Target[0] = xa/(1+xb);
				Target[1] = ya-xa*yb/(1+xb);
			}
			else {Target[0] = -1000; Target[1] = -1000;}

			InTarget = (TMath::Abs(Target[0])<14.144)&&(TMath::Abs(Target[1])<12.5);

	 opt->Fill();
	 htar->Fill(Target[0],Target[1]);


	 if(jentry%10000==0) 
	 	cout<<"Processing Event "<<jentry<<"/"<<nentries<<endl;

   }

	 opt->Write();
	 opf->Close();
	 	
	 c->cd();
	 htar->Draw("colz");
	 drawpave(-14.14,-12.5,14.14,12.5,1);
	 	 
}

void ppac::drawpave(Double_t x1,Double_t y1,Double_t x2,Double_t y2,Double_t iColor){
  TPave *pave = new TPave(x1,y1,x2,y2,1,"br");
  pave->SetFillColor(2);
  pave->SetFillStyle(2);
  pave->SetLineWidth(2);
  pave->SetLineColor(iColor);
  pave->Draw();
}
