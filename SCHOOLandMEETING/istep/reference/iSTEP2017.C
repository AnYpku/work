/*
 * this demo shows beginners how to open, read, write a ROOT file,
 * how to fit a histrogam.
 */
void iSTEP2017(Int_t fOpt = 0)
{
	gRandom->SetSeed(1);

	if(fOpt == 0 )
		generate("demo.root");
	if(fOpt == 1)
	{
		TTree* pData = open_and_fetch("demo.root", "data");
		TH1* pHist = plot(pData, "obs");
	}
	if(fOpt == 2)
	{
		TTree* pData = open_and_fetch("demo.root", "data");
		TH1* pHist = plot(pData, "obs");
		fitTo(pHist);
	}
}
/*
 * generate a ROOT file
 */
void generate(const char* pFileName, Int_t nEvents= 10000)
{

	assert(pFileName !=0);
	Int_t   nSig= 0;
	Int_t   is_sig;
	Float_t signal;

	TFile* lpFile = new TFile(pFileName, "RECREATE");
	TTree* lpTree = new TTree("data", "a simulated sample");
	lpTree->Branch("obs", &signal, "obs/F");
	lpTree->Branch("sig", &is_sig, "sig/I");

	TF1* fbkg = new TF1("bkg", "pol1", 0, 100);
	fbkg->SetParameter(0, 50);
	fbkg->SetParameter(1, 10);

	for(Int_t i=0; i< nEvents;++i){
		is_sig = 0;
		if(gRandom->Rndm() < 0.8){
			signal = 100. - fbkg->GetRandom();
		}else{
			signal = gRandom->Gaus(50, 2.);
			is_sig = 1; ++ nSig;
		}
		lpTree->Fill();
	}

	lpTree->Write();
	lpFile->Close();
	std::cout<<"nubmer of signal = "<<nSig<<", number of background = "<<(nEvents-nSig)<<std::endl;
	std::cout<<"generate done."<<std::endl;
}
/*
 * open an existed ROOT file and fetch a TTree, given their names.
 */

TTree* open_and_fetch(const char* pFileName
		, const char* pTreeName)
{
	assert(pFileName !=0);
	assert(pTreeName !=0);
	TFile* lpTemp = TFile::Open(pFileName);
	TTree* lpTree(0);
	if(lpTemp&& lpTemp->IsOpen())
		lpTree = (TTree*)lpTemp->Get(pTreeName);
	if(!lpTree)
		std::cerr<<"ERROR, fail to fecth #"<<pTreeName<<std::endl;

	return lpTree;
}

/*
 * plot a histogram with a variable, given a TTree
 */
TH1* plot(TTree* lpTree
		, const char* pVarName
		, const char* pCut="")
{
	assert(lpTree !=0);
	assert(pVarName !=0);

	lpTree->Draw(pVarName, TCut(pCut), "e");
	TH1* pHist = (TH1*)gROOT->FindObject("htemp");
	pHist->SetMarkerStyle(20);
	pHist->SetMarkerColor(kBlack);
	pHist->SetLineColor(kBlack);
	return pHist;
}

/*
 *fit a histogram with a model, given a histogram
 */
void fitTo(TH1* pHist)
{
	TF1* fmodel = new TF1("model", "gaus(0)+pol1(3)", 0, 100);
	fmodel->SetParameter(0, 100.);
	fmodel->SetParameter(1, 40.);
	fmodel->SetParameter(2, 5.);
	fmodel->SetParameter(3, 5.);
	fmodel->SetParameter(4, -1.);

	gStyle->SetOptFit(1);
	pHist->Fit(fmodel, "RML");
	fmodel->SetLineColor(kBlack);
	fmodel->Draw("same");

	TF1* fSig = new TF1("fSig", "gaus", 0, 100);
	TF1* fBkg = new TF1("fBkg", "pol1", 0, 100);
	fSig->SetParameter(0, fmodel->GetParameter(0));
	fSig->SetParameter(1, fmodel->GetParameter(1));
	fSig->SetParameter(2, fmodel->GetParameter(2));
	fSig->SetParError(0, fmodel->GetParError(0));
	fSig->SetParError(1, fmodel->GetParError(1));
	fSig->SetParError(2, fmodel->GetParError(2));

	fBkg->SetParameter(0, fmodel->GetParameter(3));
	fBkg->SetParameter(1, fmodel->GetParameter(4));
	fBkg->SetParError(0, fmodel->GetParError(3));
	fBkg->SetParError(1, fmodel->GetParError(4));

	fSig->SetLineColor(kRed);
	fBkg->SetLineColor(kBlue);
	fSig->Draw("same");
	fBkg->Draw("same");

	Float_t nSig = fSig->Integral(0, 100);
	Float_t nSigErr = fSig->IntegralError(0, 100);
	Float_t nBkg = fBkg->Integral(0, 100);
	Float_t nBkgErr = fBkg->IntegralError(0, 100);
	std::cout<<"signal = "<<nSig<<" +- "<<nSigErr<<", bkg = "<<nBkg<<" +- "<<nBkgErr<<std::endl;
}
