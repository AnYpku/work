#include <string>
#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "RooRealVar.h"
#include "RooAddPdf.h"
using namespace RooFit;
TFile* fdataT = TFile::Open("./rootfiles/dataTrue_template.root");
TFile* fdataF = TFile::Open("./rootfiles/dataFake_template.root");
TFile* fmcT = TFile::Open("./rootfiles/mcTrue_template.root");
TFile* fmcF = TFile::Open("./rootfiles/mcFake_template.root");
TFile* fdata = TFile::Open("./rootfiles/waData_template.root");
TFile* fmc = TFile::Open("./rootfiles/waMC_template.root");
void fit(float lowpt, float highpt){
//TString b="chiso5-12_";
	TFile *f0 = new TFile(Form("./rootfiles/fdata_%0.f_%0.f.root",lowpt,highpt));
	TTree *tree_datawa = (TTree*)f0->Get("tree_datawa");

	TH1F* hdata_ = (TH1F*)fdata->Get(Form("hdatawa_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hsieie = (TH1F*)fdata->Get(Form("hsieie_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hdf_ = (TH1F*)fdataF->Get(Form("h3_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hdt_ = (TH1F*)fdataT->Get(Form("h4_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hmt = (TH1F*)fmcT->Get(Form("h2_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hmf = (TH1F*)fmcF->Get(Form("h1_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hmc = (TH1F*)fmc->Get(Form("hmcwa_pt%0.f-%0.f",lowpt,highpt));
        hdf_ -> Add(hmf,-1);
        hdt_ -> Add(hmt,-1);
       
	Int_t nBins = 10;
        Double_t bins[11];
	for (Int_t i=0;i<11;i++){
//		bins[i] = 0.005 + 0.0015*i;
		bins[i] = 0.00 + 0.002*i;
	}
	TH1* hdata = hdata_->Rebin(nBins, "hdata", bins);
	TH1* hdt = hdt_->Rebin(nBins, "htrue", bins);
        TH1* hdf = hdf_->Rebin(nBins, "hfake_data", bins);
        for (Int_t i=0; i<nBins; i++){
                if (hdata->GetBinContent(i+1)<=0) hdata->SetBinContent(i+1,0.000000);
                if (hdt->GetBinContent(i+1)<=0) hdt->SetBinContent(i+1,0.000000);
                if (hdf->GetBinContent(i+1)<=0) hdf->SetBinContent(i+1,0.000000);
        }

 
        //nBins = hdf->GetNbinsX();
        //varMin = hdf->GetBinLowEdge(1);
        //varMax = hdf->GetBinLowEdge(nBins)+hdf->GetBinWidth(nBins);
 
        Double_t nMax = hdata->GetSumOfWeights();//Get total
        Double_t nTrueStart = hmc->GetSumOfWeights();//Get total
        Double_t nFakeStart = nMax - nTrueStart;//Get total
        std::cout<<"nMax = "<<nMax<<" nTrueStart = "<<nTrueStart<<" nFakeStart = "<<nFakeStart<<std::endl;
 
        RooRealVar sieie("sieie","sieie",0.002, 0.02);
        RooArgList argList;
        argList.add(sieie);
        RooArgSet argSet;
        argSet.add(sieie);

        RooDataHist dataHist("hist", "data set converted to hist", sieie, hdata);
       //RooDataSet* dataTree = new RooDataSet("dataTree","dataTree",tree_datawa,sieie);

        RooDataHist trueDataHist("trueDataHist","true RooDataHist", sieie, hdt);
        RooHistPdf trueHistPdf("trueHistPdf","trueHistPdf", sieie, trueDataHist);

        RooDataHist fakeDataHist("fakeDataHist", "fake RooDataHist", sieie, hdf);
        RooHistPdf fakeHistPdf("fakeHistPdf","fakeHistPdf", sieie, fakeDataHist);
 
        RooRealVar rooNTrue("nTrue","nTrue",0.5*nMax,0,nMax);//0.2*nMax,*nMax);//1931.46
        RooRealVar rooNFake("nFake","nFake",0.5*nMax,0*nMax,nMax);//0.5*nMax,1*nMax);//7622.54
 
        RooAddPdf fullPdf("fitModel","fit model",RooArgList(trueHistPdf,fakeHistPdf),RooArgList(rooNTrue,rooNFake));
        std::cout<<"fullPdf.getNorm()="<<fullPdf.getNorm()<<std::endl;
        std::cout<<"dataHist.sumEntries()="<<dataHist.sumEntries()<<std::endl;

        fullPdf.fitTo(dataHist,SumW2Error(kFALSE),Extended(kTRUE));
        RooChi2Var chi2("chi2","chi2",fullPdf,dataHist);
        Double_t chi2ToNDF = chi2.getVal()/(nBins-2);

//get nFake values from fit
        Double_t nFakeFromFitVal = rooNFake.getVal();
        Double_t nFakeFromFitErr = rooNFake.getError();
    
        Double_t nTrueFromFitVal = rooNTrue.getVal();
        Double_t nTrueFromFitErr = rooNTrue.getError();
    
       // add eff for true and fake
       // Double_t eff = eff=hTruePassed->GetBinContent(1)/hTrueTot->GetBinContent(1);
        Double_t eff = hsieie->GetSumOfWeights()/nTrueFromFitVal;
        Double_t nTrueYieldsVal = nTrueFromFitVal * eff;
        Double_t nTrueYieldsErr = nTrueFromFitErr * eff;
        Double_t nDataFullSelErr=0;
        Double_t nFakeYieldsVal = hdata->IntegralAndError(1,nBins,nDataFullSelErr)-nTrueYieldsVal;
        Double_t nFakeYieldsErr = sqrt(nDataFullSelErr * nDataFullSelErr + nTrueYieldsErr * nTrueYieldsErr);
	//  std::cout<<"nDataFullSelErr = "<<nDataFullSelErr<<std::endl;

	double FakeRateVal = nFakeYieldsVal/nMax;
	double FakeRateErr = nFakeYieldsErr/nMax+nFakeYieldsVal*nDataFullSelErr/(nMax*nMax);
	std::cout<<"FakeRateErr = "<<FakeRateErr<<std::endl;
	//OutPut file
	/*RooArgSet *params = (RooArgSet*)fullPdf.getParameters(*dataTree) ;
	params->Print("v") ;
	params->writeToFile(TString("./fitresult/txt/parms_")+Form("photon_pt%0.f_%0.f.txt",lowpt,highpt)) ;*/
 
	ofstream myfile(TString("./fitresult/txt/rate_")+Form("photon_pt%0.f_%0.f.txt",lowpt,highpt),ios::out);
 
	myfile <<"Fake fit"<<nFakeFromFitVal<<"+-"<<nFakeFromFitErr<<endl;
	myfile <<"True fit"<<nTrueFromFitVal<<"+-"<<nTrueFromFitErr<<endl;
	myfile <<"chi2/ndf="<<chi2ToNDF<<endl;
	myfile <<"Fake Yields"<<nFakeYieldsVal<<"+-"<<nFakeYieldsErr<<endl;
	myfile <<"Ture yields"<<nTrueYieldsVal<<"+-"<<nTrueYieldsErr<<endl;
	myfile <<"Data yields"<<nMax<<"+-"<<nDataFullSelErr<<endl;
	myfile <<"Fake Rate"<<FakeRateVal<<"+-"<<FakeRateErr<<endl;  
	myfile.close();
     //================================plot===================================
	RooPlot* xframe = sieie.frame(Title(Form("Barrel region, %0.f GeV < photon      PT < %0.f GeV ",lowpt,highpt)),Bins(10));
	//dataTree->plotOn(xframe);
	dataHist.plotOn(xframe);
	fullPdf.plotOn(xframe,Name("sum"),LineColor(kRed));
	fullPdf.plotOn(xframe,Components("trueHistPdf"), Name("true"),LineColor(kGreen),LineStyle(9));
	fullPdf.plotOn(xframe, Components("fakeHistPdf"),Name("fake"),LineColor(kBlue),LineStyle(9));
	//fullPdf.paramOn(xframe);
 
     TCanvas *c1 = new TCanvas("c1","c1",600,600);
     xframe->GetXaxis()->SetTitle("#sigma_{i#etai#eta}") ;
     xframe->GetYaxis()->SetTitleOffset(1.4) ;
     xframe->Draw();
     gPad->SetLogy(0);
     hdata->SetLineColor(kRed);
     //  hdata->SetLineStyle(2);
     hdata->SetLineWidth(3);
     hdf->SetLineColor(kBlue);
     hdf->SetLineStyle(5);
     hdf->SetLineWidth(3);
     hdt->SetLineColor(kGreen+2);
     hdt->SetLineStyle(kDashed);
     hdt->SetLineWidth(3);
 
     TLegend *leg = new TLegend(0.55,0.6659582,0.88,0.850488,NULL,"brNDC");
     leg->SetFillColor(10);
     leg->AddEntry(hdata,"WA Data","L");
     leg->AddEntry(hdt,"Ture photons","L");
     leg->AddEntry(hdf,"Fake photons","L");
     leg->Draw("same");
     c1->Print(Form("./fitresult/eps/tempfit_%0.f_%0.fEB.eps",lowpt,highpt));
     std::cout<<"chi2/ndf="<<chi2ToNDF<<std::endl;
}
