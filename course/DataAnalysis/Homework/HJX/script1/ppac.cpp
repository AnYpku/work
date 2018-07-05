#define ppac_cxx
#include "ppac.h"

void ppac::Loop()
//void ppac::Loop()
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

	// To read only selected branches
	fChain->SetBranchStatus("*",0);
	fChain->SetBranchStatus("PPACF8",1);

	Initial();			// Initialize user's data members

  //Long64_t nentries = 1000;
  Long64_t nentries = fChain->GetEntriesFast();
	cout << "nentries: " << nentries << endl;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
		nbytes += nb;
    // if (Cut(ientry) < 0) continue;
		Int_t step = nentries/100;
		if(jentry%step==0)	cout << "entry: " << jentry << endl;

		// Trajectory Construction
		Track();
				
		// Trajectory Drawing
		if (jentry%100==0) {
			if(gSystem->ProcessEvents()) break;
			cTrace->cd(1);
			hXTrace->Draw("colz");
			lTarget->Draw("same");
			lPPAC1->Draw("same");
			lPPAC2->Draw("same");
			lPPAC3->Draw("same");
		 
		  cTrace->cd(2);
			hYTrace->Draw("colz");
			lTarget->Draw("same");
			lPPAC1->Draw("same");
			lPPAC2->Draw("same");
			lPPAC3->Draw("same");

			cTrace->cd(3);
			hTargetDistribution->Draw("colz");
			gPad->SetLogz(1);
														  
			cTrace->cd(4);
			hRotatedTargetDistribution->Draw();

			cTrace->cd();
			cTrace->Modified();
			cTrace->Update();
			}
		}
		
	cTrace->SaveAs("trace.pdf");
}


void ppac::Initial() {
	hXTrace = NULL;
	hYTrace = NULL;
	hTargetDistribution = NULL;
	hRotatedTargetDistribution = NULL;
	cTrace = NULL;             
	lTarget = NULL;
	lPPAC1 = NULL;
	lPPAC2 = NULL;
	lPPAC3 = NULL;

	if(hXTrace==0) 
		hXTrace = new TH2F("hXTrace","x trace by ppac",2200,-2000,200,300,-150,150);
	else 
		hXTrace->Reset();
	if(hYTrace==0) 
		hYTrace = new TH2F("hYTrace","y trace by ppac",2200,-2000,200,300,-150,150);
	else 
		hYTrace->Reset();
	if(hTargetDistribution==0) 
		hTargetDistribution = new TH2F("hTargetDistribution","distribution on target",400,-200,200,400,-200,200);
	else 
		hTargetDistribution->Reset();
	if(hRotatedTargetDistribution==0) 
		hRotatedTargetDistribution = new TH3F("hRotatedTargetDistribution","distribution on rotated target",400,-200,200,400,-200,200,400,-200,200);
	else 
		hRotatedTargetDistribution->Reset();
	
	if(cTrace==0){
  	cTrace = new TCanvas();
		cTrace->Divide(2,2);
	}
	
	if(lTarget==0) lTarget = new TLine(0,-50,0,50);
	lTarget->SetLineWidth(2);
	if(lPPAC1==0) lPPAC1 = new TLine(-1736,-120,-1736,120);
	if(lPPAC2==0) lPPAC2 = new TLine(-1236,-120,-1236,120);
	if(lPPAC3==0) lPPAC3 = new TLine(-377,-50,-377,50);
}


void ppac::Track() {
 	// For PPAC Layer 1-5
	Double_t xx[5];
  Double_t xz[5];
  Double_t yy[5];
  Double_t yz[5];

	// For PPAC set 1-3
  Bool_t xflag[3];
  Bool_t yflag[3];
  for(int i=0;i<3;i++) {
    xflag[i] = false;			// 一套PPAC的任一层有x信号，则此套PPAC的flag=true
    yflag[i] = false;			// 一套PPAC的任一层有y信号，则此套PPAC的flag=true
  }

  Int_t xcnt = 0;					// 几层PPAC上有x信号
  Int_t ycnt = 0;					// 几层PPAC上有y信号
	Float_t cutx = 240/2;		// ppac 1-4 240mm*150mm
	Float_t cuty = 150/2;
	for(int i=0;i<5;i++){		// PPAC Layer i
		if(i==4) cutx = cuty = 100/2;		// ppac 5 100mm*100mm;
    if(PPACF8[i][0]>-cutx&&PPACF8[i][0]<cutx) {
      xx[xcnt] = PPACF8[i][0];	
      xz[xcnt] = PPACF8[i][2];
      xcnt++;
      xflag[i/2] = true;
    }
    if(PPACF8[i][1]>-cuty&&PPACF8[i][1]<cuty) {
      yy[ycnt] = PPACF8[i][1];
      yz[ycnt] = PPACF8[i][3];
      ycnt++;
      yflag[i/2] = true;
    }
  }

	Int_t cxflag=0;		//几套PPAC有x信号
	Int_t cyflag=0;		//几套PPAC有y信号
	for(int i=0;i<3;i++){
  	if(xflag[i]) cxflag++;
  	if(yflag[i]) cyflag++;
	}

	kx = bx = -999;						// If X Trace cannot be constructed
  if(cxflag>=2){
    TGraph *grXTrace = new TGraph(xcnt,xz,xx);
    TF1 *fXTrace = new TF1("fXTrace","pol1",-2000,0);
    grXTrace->Fit(fXTrace,"q+");
		
		kx = fXTrace->GetParameter(1);
		bx = fXTrace->GetParameter(0);
    SetTrace(hXTrace,fXTrace->GetParameter(1),fXTrace->GetParameter(0),-1800,0);

		targetX = fXTrace->Eval(0);		// x on target

		delete grXTrace;
    delete fXTrace;
  }

  ky = by = -999;						// If Y Trace cannot be constructed
	if(cyflag>=2){
    TGraph *grYTrace = new TGraph(ycnt,yz,yy);
    TF1 *fYTrace = new TF1("fYTrace","pol1",-2000,0);
    grYTrace->Fit(fYTrace,"q+");

		ky = fYTrace->GetParameter(1);
		by = fYTrace->GetParameter(0);
    SetTrace(hYTrace,fYTrace->GetParameter(1),fYTrace->GetParameter(0),-1800,0);

		targetY = fYTrace->Eval(0);	// y on target
    
		delete grYTrace;
    delete fYTrace;                                                       
  }
  
	hTargetDistribution->Fill(targetX,targetY);

	if(kx>-998&&ky>-998) {
		Double_t rotatedTargetPositionX = bx/(1+kx);
		Double_t rotatedTargetPositionY = bx*ky/(1+kx) + by;
		Double_t rotatedTargetPositionZ = -rotatedTargetPositionX;
		
		hRotatedTargetDistribution->Fill(rotatedTargetPositionX,rotatedTargetPositionY,rotatedTargetPositionZ);
	}
}


void ppac::SetTrace(TH2F *h,Double_t k,Double_t b,Int_t min,Int_t max){
  if(h==0) return;
  if(min>=max) return;

  for(int i=min;i<max;i++){
    h->Fill(i,(Int_t)(i*k+b));
  }
}

/*
void ppac::ResetVal()
{
	xl = -999;
	xr = -999;
	yd = -999;
	yu = -999;
	ta = -999;
}
*/

/*
void ppac::MappingPPAC()
{
	bool bppac[4], bppaca;
	Float_t pos[4];
	bppaca = F8PPACRawData[0][4]>0 && F8PPACRawData[0][4]<4000;
	for(int i=0;i<4;i++) {
		bppac[i] = F8PPACRawData[0][i]>0 && F8PPACRawData[0][i]<4000;
		bppac[i] *= bppaca;
		pos[i] = F8PPACRawData[0][i] - F8PPACRawData[0][4];
	}

	if(bppac[0] ) xl = pos[0];
	if(bppac[1] ) xr = pos[1];             
	if(bppac[2])  yd = pos[2];
	if(bppac[3])  yu = pos[3];
	if(bppaca)    ta = F8PPACRawData[0][4];
}
*/
