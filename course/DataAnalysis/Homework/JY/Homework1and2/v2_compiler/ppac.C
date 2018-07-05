#define ppac_cxx
#include "ppac.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <TPave.h>

void ppac::Loop(TTree *opt)
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();

	 fChain->SetBranchStatus("*",0);
	 fChain->SetBranchStatus("PPACF8",1);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      ResetVal();//initialize variables.
      TrackPPAC();//calculate variables with raw data. 
      opt->Fill(); //fill tree branch.

			if(jentry%10000==0) 
			 cout<<"Processing Event "<<jentry<<"/"<<nentries<<endl;

   }
 }

void ppac::BranchOpt(TTree *t)
{
	 t->Branch("PPACF8Pos",PPACF8Pos,"PPACF8Pos[5][5]/F");
	 t->Branch("PPACFlag",PPACFlag,"PPACFlag[5][3]/O");
	 t->Branch("cnt",cnt,"NumOfValidPPAC[2]/I");
	 t->Branch("ValidEvent",ValidEvent,"ValidEvent[2]/O");
	 t->Branch("FitFactor",FitFactor,"FitFactor[2][3]/F");
	 t->Branch("Target",Target,"Target[2]/F");
	 t->Branch("InTarget",&InTarget,"InTarget/O");
}

void ppac::TrackPPAC()
{
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
      for(Int_t j=0;j<5;j++)  PPACF8Pos[4][j]=PPACF8[4][j];
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

   if((cnt[i]<2)||((cnt[i]==2)&&((PPACFlag[0][i]&&PPACFlag[1][i])||(PPACFlag[2][i]
&&PPACFlag[3][i])))) {
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
//      TF1 *fx = new TF1("fx","pol1",-2000,0);
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
 }

void ppac::ResetVal()
{
	 for(Int_t i=0;i<5;i++) {
	 	for(Int_t j=0;j<3;j++) {
	 		PPACFlag[i][j]=false;
			}
		}
	 cnt[0] = 0; cnt[1] = 0;
	 ValidEvent[0] = false; ValidEvent[1] = false;
	 
	 for(Int_t i=0;i<2;i++) {
	 		FitFactor[i][0]=-1000; FitFactor[i][1]=-1000; FitFactor[i][2]=-1000;
			Target[i] = -1000;
	 }

	 InTarget = false;
}

