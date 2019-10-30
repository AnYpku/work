void fit()
{
TTree* pData = open_and_fetch("sscc_rec_mjj.root", "tree");
		TH1* pHist = plot(pData, "mj1j3");
                fitTo(pHist);
}
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
void fitTo(TH1* pHist)
{
	TF1* fmodel = new TF1("model", "gaus(1)+pol1(3)", 0, 200);
	fmodel->SetParameter(0, 1893.);
	fmodel->SetParameter(1, 125.);
	fmodel->SetParameter(2, 1.);
	fmodel->SetParameter(3, 80.);
	fmodel->SetParameter(4, 125.);
       // fmodel->SetParameter(5, 0.1);
	gStyle->SetOptFit(1);
	pHist->Fit(fmodel, "RML");
	//fmodel->SetLineColor(kGreen);
	//fmodel->Draw("same");

	TF1* fSig = new TF1("fSig", "gaus", 0, 1000);
	TF1* fBkg = new TF1("fBkg", "pol1", 0, 1000);
	fSig->SetParameter(0, fmodel->GetParameter(0));
	fSig->SetParameter(1, fmodel->GetParameter(1));
	fSig->SetParameter(2, fmodel->GetParameter(2));
	fSig->SetParError(0, fmodel->GetParError(0));
	fSig->SetParError(1, fmodel->GetParError(1));
	fSig->SetParError(2, fmodel->GetParError(2));

	fBkg->SetParameter(0, fmodel->GetParameter(3));
	fBkg->SetParameter(1, fmodel->GetParameter(4));
      //  fBkg->SetParameter(2, fmodel->GetParameter(5));
	fBkg->SetParError(0, fmodel->GetParError(3));
	fBkg->SetParError(1, fmodel->GetParError(4));
       // fBkg->SetParError(2, fmodel->GetParError(5));

	fSig->SetLineColor(kRed);
	fBkg->SetLineColor(kBlue);
        fmodel->SetLineColor(kGreen);
	
	fSig->Draw("same");
	fBkg->Draw("same");
        fmodel->Draw("same");
	Float_t nSig = fSig->Integral(115, 135);
	Float_t nSigErr = fSig->IntegralError(0, 100);
	Float_t nBkg = fBkg->Integral(115, 135);
	Float_t nBkgErr = fBkg->IntegralError(0, 100);
	std::cout<<"signal = "<<nSig<<" +- "<<nSigErr<<", bkg = "<<nBkg<<" +- "<<nBkgErr<<std::endl;
}     
