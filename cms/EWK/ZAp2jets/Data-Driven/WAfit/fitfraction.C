#include <string>
#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "RooRealVar.h"
#include "RooAddPdf.h"
using namespace RooFit;
//ofstream file3("./fractionfitResult/info_fit.txt");
TFile* fdataT = TFile::Open("./rootfiles/dataTrue_template.root");
TFile* fdataF = TFile::Open("./rootfiles/dataFake_template.root");
TFile* fmcT = TFile::Open("./rootfiles/mcTrue_template.root");
TFile* fmcF = TFile::Open("./rootfiles/mcFake_template.root");
TFile* fdata = TFile::Open("./rootfiles/waData_template.root");
TFile* fmc = TFile::Open("./rootfiles/waMC_template.root");
void fitf(float lowpt, float highpt){
//TString b="chiso5-12_";

	TH1F* hdata_ = (TH1F*)fdata->Get(Form("hdatawa_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hsieie = (TH1F*)fdata->Get(Form("hsieie_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hdf_ = (TH1F*)fdataF->Get(Form("h3_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hdt_ = (TH1F*)fdataT->Get(Form("h4_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hmf = (TH1F*)fmcF->Get(Form("h1_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hmt = (TH1F*)fmcT->Get(Form("h2_pt%0.f-%0.f",lowpt,highpt));
	TH1F* hmc = (TH1F*)fmc->Get(Form("hmcwa_pt%0.f-%0.f",lowpt,highpt));
         
        hdf_ -> Add(hmf,-1);
        hdt_ -> Add(hmt,-1);

       /* Double_t nFake=hdf->Integral();      
        Double_t nTrue=hdt->Integral();      
        Double_t nMax = hdata->GetSumOfWeights();
        Double_t nTrueStart = hmc->GetSumOfWeights();
        Double_t nFakeStart = nMax - nTrueStart;
        std::cout<<"nMax = "<<nMax<<"; nTrueStart = "<<nTrueStart<<"; nFakeStart = "<<nFakeStart<<std::endl;*/
    
//        hdf->Scale(6000/nFake);
//        hdt->Scale(nTrueStart/nTrue);

        Int_t nBins = 10;
        Double_t bins[11];
        for (Int_t i=0;i<11;i++){
                bins[i] = 0.005 + 0.0015*i;
        }
        TH1* hdata = hdata_->Rebin(nBins, "hdata", bins);
        TH1* hdt = hdt_->Rebin(nBins, "htrue", bins);
        TH1* hdf = hdf_->Rebin(nBins, "hfake_data", bins);
        for (Int_t i=0; i<nBins; i++){
                if (hdata->GetBinContent(i+1)<=0) hdata->SetBinContent(i+1,0.000000);
                if (hdt->GetBinContent(i+1)<=0) hdt->SetBinContent(i+1,0.000000);
                if (hdf->GetBinContent(i+1)<=0) hdf->SetBinContent(i+1,0.000000);
        }
    
        TObjArray *mc = new TObjArray(2);    
        mc->Add(hdf);
        mc->Add(hdt);
        TFractionFitter* fit = new TFractionFitter(hdata, mc,"V");

        fit->Constrain(0,0,1);
        fit->Constrain(1,0,1);
        fit->SetRangeX(1,nBins); // use only the first 15 bins in the fit
        Int_t status = fit->Fit();// perform the fit
        std::cout << "fit status: " << status << std::endl;
        if (status == 0) {                       // check on fit status
            TH1F* result = (TH1F*) fit->GetPlot();
            TCanvas *c1 = new TCanvas("c1","c1",600,600);
            c1->SetGrid();
            hdata->SetTitle(Form("Barrel region %0.f < pt < %0.f ",lowpt,highpt)); 
            hdata->SetMarkerColor(1);
            hdata->SetLineWidth(3); 
            hdata->SetLineColor(1);
            hdata->SetMarkerStyle(20);
            result->SetLineColor(kRed);
            hdata->Draw("Ep");
            result->Draw("same");
            auto mcp0 = (TH1F*)fit->GetMCPrediction(0);
            mcp0->SetLineColor(kBlue);
            mcp0->SetLineWidth(3);
            mcp0->SetLineStyle(1);
            auto mcp1 = (TH1F*)fit->GetMCPrediction(1);
            mcp1->SetLineColor(kGreen);
            mcp1->SetLineWidth(3);
            mcp1->SetLineStyle(2);
 
//            mcp0->Draw("same hist");
//            mcp1->Draw("same hist");
 
           /*Double_t fakeError, trueError, dataError, dataActualError;
 
            Double_t eff = hsieie->GetSumOfWeights()/hdt->GetSumOfWeights();
            Double_t trueValue = mcp1->IntegralAndError(0,nBins,trueError)*eff;
    
            Double_t dataValue = result->IntegralAndError(0,2,dataError);
            Double_t dataActualValue  = hdata->IntegralAndError(0,2,dataError);
            Double_t fakeValue = dataActualValue-trueValue;
                     fakeError = sqrt(dataError * dataError + trueError * trueError);
            Double_t rate = fakeValue/hdata->Integral(0,2);
            Double_t rateError = fakeError/dataActualValue+fakeValue*dataActualError/(dataActualValue*dataActualValue);*/
            Double_t p0, p1, errP0, errP1;
	    Double_t chi2=fit->GetChisquare();
	    Int_t Ndf=fit->GetNDF();
            double chi2ToNdf = chi2/Ndf;
            fit->GetResult( 0, p0, errP0);
            printf(" Parameter %d: fake, estim. %.3f +/- %.3f\n", 0, p0, errP0);
            fit->GetResult( 1, p1, errP1);
            printf(" Parameter %d: true , estim. %.3f +/- %.3f\n", 1, p1, errP1);
 
            ofstream myfile(TString("./fractionfitResult/txt/root_rate_")+Form("photon_pt%0.f_%0.f.txt",lowpt,highpt),ios::out);
 
            /*myfile <<"Fake Yields"<<fakeValue<<"+-"<<fakeError<<endl;
            myfile <<"Ture yields"<<trueValue<<"+-"<<trueError<<endl;
            myfile <<"Data yields"<<dataValue<<"+-"<<dataError<<endl;*/
            myfile <<"Fake Rate"<<p0<<"+-"<<errP0<<endl;
            myfile.close();
	    char c[200],c2[200],c3[200];
	    sprintf(c,"%f",chi2ToNdf);
	    sprintf(c2,"%f",p0);
	    sprintf(c3,"%f",errP0);
	    TString s="#chi^{2}/ndf = ";
	    TString s2="value = ";
	    TString s3="error = ";
	    TString chisquare=s + c;
	    TString v=s2 + c2;
	    TString e=s3 + c3;

	    TLatex *textchi2 = new TLatex(0.6, 0.5, chisquare);
	    textchi2->SetNDC();
	    textchi2->SetTextSize(0.05);
	    textchi2->SetLineWidth(1);
	    textchi2->Draw();
	    TLatex *textvalue = new TLatex(0.6, 0.4, v);
	    textvalue->SetNDC();
	    textvalue->SetTextSize(0.05);
	    textvalue->SetLineWidth(1);
	    textvalue->Draw();
	    TLatex *texterror = new TLatex(0.6, 0.3, e);
	    texterror->SetNDC();
	    texterror->SetTextSize(0.05);
	    texterror->SetLineWidth(1);
	    texterror->Draw();
            gPad->SetLogy(0);
            c1->Print(Form("./fractionfitResult/eps/pt%0.f_%0.fMB.eps",lowpt,highpt));

     }
}
