#define ppac_cxx
#include "ppac.h"

void ppac::Loop(TTree *fopt)
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
	BranchOpt(fopt);	// Set the out put tree

  //Long64_t nentries = 10000;
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

		//ResetVal();			// Initialize variables
		//MappingPPAC();	// Calculate variable with raw data
		ExtractData();	// Extract PPAC8Data from ipt to opt
		
		// Trajectory Construction
		Track(numberOfValidTraceX,numberOfValidTraceY);
				
		// Trajectory Drawing
		//if (jentry%100==0) {
		if (jentry%nentries==0) {
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
			//hRotatedTargetDistribution->Draw("colz");
			//gPad->SetLogz(1);

			cTrace->cd();
			cTrace->Modified();
			cTrace->Update();
			}

			fopt->Fill();
		}
	
	hXTrace->Write();
	hYTrace->Write();
	hTargetDistribution->Write();
	hRotatedTargetDistribution->Write();
	hRotatedTargetDistribution->Write();
	lTarget->Write();
	lPPAC1->Write();
	lPPAC2->Write();
	lPPAC3->Write();

	cTrace->Write();
	cTrace->SaveAs("trace.pdf");

	cout << "numberOfValidTraceX=" << numberOfValidTraceX << endl
			 << "numberOfValidTraceY=" << numberOfValidTraceY << endl;
}


void ppac::Initial() {
	numberOfValidTraceX = 0;
	numberOfValidTraceY = 0;

	hXTrace = NULL;
	hYTrace = NULL;
	hTargetDistribution = NULL;
	hRotatedTargetDistribution = NULL;
	cTrace = NULL;             
	lTarget = NULL;
	lPPAC1 = NULL;
	lPPAC2 = NULL;
	lPPAC3 = NULL;

	targetPosition[2] = 0;

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
		//hRotatedTargetDistribution = new TH2F("hRotatedTargetDistribution","distribution on rotated target",400,-200,200,400,-200,200);
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


void ppac::BranchOpt(TTree *fopt) {
	if(fopt==0) return;

	//fopt->Branch("xl",&xl,"xl/D");
	//fopt->Branch("xr",&xr,"xr/D");
	//fopt->Branch("yd",&yd,"yd/D");
	//fopt->Branch("yu",&yu,"yu/D");
	//fopt->Branch("ta",&ta,"ta/D");

  fopt->Branch("PPAC1Position",PPAC1Position,"PPAC1Position[2][4]/F");
  fopt->Branch("PPAC2Position",PPAC2Position,"PPAC2Position[2][4]/F");
  fopt->Branch("PPAC3Position",PPAC3Position,"PPAC3Position[4]/F");
  fopt->Branch("targetPosition",targetPosition,"targetPosition[3]/F");
  fopt->Branch("rotatedTargetPosition",rotatedTargetPosition,"rotatedTargetPosition[3]/F");
}


void ppac::Track(Long64_t &fnumberOfValidTraceX,Long64_t &fnumberOfValidTraceY) {
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

	targetPosition[0] = -999;	// If X Trace cannot be constructed
	kx = bx = -999;						// If X Trace cannot be constructed
  if(cxflag>=2){
    TGraph *grXTrace = new TGraph(xcnt,xz,xx);
    TF1 *fXTrace = new TF1("fXTrace","pol1",-2000,0);
    grXTrace->Fit(fXTrace,"q+");
		
		kx = fXTrace->GetParameter(1);
		bx = fXTrace->GetParameter(0);
    SetTrace(hXTrace,fXTrace->GetParameter(1),fXTrace->GetParameter(0),-1800,0);

		fnumberOfValidTraceX++;
		    
		targetX = fXTrace->Eval(0);		// x on target

		targetPosition[0] = targetX;
    
		delete grXTrace;
    delete fXTrace;
  }

	targetPosition[1] = -999;	// If Y Trace cannot be constructed
  ky = by = -999;						// If Y Trace cannot be constructed
	if(cyflag>=2){
    TGraph *grYTrace = new TGraph(ycnt,yz,yy);
    TF1 *fYTrace = new TF1("fYTrace","pol1",-2000,0);
    grYTrace->Fit(fYTrace,"q+");

		ky = fYTrace->GetParameter(1);
		by = fYTrace->GetParameter(0);
    SetTrace(hYTrace,fYTrace->GetParameter(1),fYTrace->GetParameter(0),-1800,0);

		fnumberOfValidTraceY++;
    
		targetY = fYTrace->Eval(0);	// y on target

		targetPosition[1] = targetY;
    
		delete grYTrace;
    delete fYTrace;                                                       
  }
  
	hTargetDistribution->Fill(targetX,targetY);

	for(int i=0;i<3;i++)
		rotatedTargetPosition[i] = -999;
	if(kx>-998&&ky>-998) {
		rotatedTargetPosition[0] = bx/(1+kx);
		rotatedTargetPosition[1] = bx*ky/(1+kx) + by;
		rotatedTargetPosition[2] = -rotatedTargetPosition[0];
		
		hRotatedTargetDistribution->Fill(rotatedTargetPosition[0],rotatedTargetPosition[1],rotatedTargetPosition[2]);
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


void ppac::ExtractData() {
	// copy PPAC xyz position to ppac.root
  PPAC1Position[0][0] = PPACF8[0][0];
  PPAC1Position[0][1] = PPACF8[0][1];
  PPAC1Position[0][2] = PPACF8[0][2];
  PPAC1Position[0][3] = PPACF8[0][3];
  PPAC1Position[1][0] = PPACF8[1][0];
  PPAC1Position[1][1] = PPACF8[1][1];
  PPAC1Position[1][2] = PPACF8[1][2];
  PPAC1Position[1][3] = PPACF8[1][3];
  PPAC2Position[0][0] = PPACF8[2][0];
  PPAC2Position[0][1] = PPACF8[2][1];
  PPAC2Position[0][2] = PPACF8[2][2];
  PPAC2Position[0][3] = PPACF8[2][3];
  PPAC2Position[1][0] = PPACF8[3][0];
  PPAC2Position[1][1] = PPACF8[3][1];
  PPAC2Position[1][2] = PPACF8[3][2];
  PPAC2Position[1][3] = PPACF8[3][3];
  PPAC3Position[0] = PPACF8[4][0];
  PPAC3Position[1] = PPACF8[4][1];
  PPAC3Position[2] = PPACF8[4][2];
  PPAC3Position[3] = PPACF8[4][3];
}
