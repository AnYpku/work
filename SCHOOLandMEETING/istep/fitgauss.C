#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "TRandom.h"

using namespace RooFit;

void fitgauss(){
    TFile *f1 = new TFile("creategauss.root","RECREATE");
    TCanvas *c1 = new TCanvas("c1","c1",1000,1000);
    TRandom r0(0);
    TH1F  *h1 = new TH1F("h1","Histo from a Gaussian",100,-5,5);
    for (int i=0;i<10000;i++){
        double x1=r0.Gaus();
        h1->Fill(x1);
    }
    h1->Draw();
    f1->Write();
    TFile* f2=new TFile("fitgauss.root","recreate");
    TCanvas* c=new TCanvas("c","fitgauss",1000,1000);
    TH1* h2=(TH1* )f1->Get("h1");
    gStyle->SetPadLeftMargin(0.17);
    gStyle->SetPadBottomMargin(0.17);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetPadTopMargin(0.10);
    RooRealVar x("x","bins",-5,5);
    RooDataHist data("data","data",x,h2); 
    RooPlot* frame=x.frame(Name("xframe"),Title("fitgauss"));
    data.plotOn(frame);
    RooRealVar mean("mean","mean",0);
    RooRealVar width("width","width",0);
    RooRealVar sigma("sigma","sigma",1);
    RooVoigtian fitgauss("fitgauss","fitgauss",x,mean,width,sigma);
    fitgauss.fitTo(data,Range(-5,5));
    fitgauss.plotOn(frame,LineColor(kGreen));
    data.statOn(frame,Layout(0.57,0.99,0.8));
    frame->Draw();
    f2->Write();
}
