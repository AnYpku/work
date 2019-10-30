#include "TH1.h"
#include "TFile.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TStyle.h"
#include <iostream>
#include "TLegend.h"
#include "THStack.h"
#include "CMSTDRStyle.h"
#include "CMS_lumi.C"
using namespace std;
TString name="_content";
void cmsLumi(bool channel); 
TH1D* unroll(TH2D* th2_in,Double_t* xbin, Double_t* ybin,  Int_t xbins_in, Int_t ybins_in,char *hname);
void cmsLumi(bool channel) 
{
        TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);
        latex.SetLineWidth(2);
        float lumiel=35.8;
        float lumimu=35.8;
        int beamcomenergytev=13;
        latex.SetTextAlign(31); 
        latex.SetTextAlign(11);
        latex.DrawLatex(0.18,0.82,"Preliminary");
        latex.DrawLatex(0.18,0.86,"CMS");
        latex.SetTextSize(0.03);
        latex.DrawLatex(0.76,0.92,Form("35.866 fb^{-1} (%d TeV)", (beamcomenergytev)));
}

TH1D* unroll(TH2D* th2_in,Double_t* xbin, Double_t* ybin,  Int_t xbins_in, Int_t ybins_in,char *hname)//,char* htitle)
{
	TH2D* th2 = th2_in;
	Int_t nbinsx =xbins_in;//2D histo的bin的数量,x
	Int_t nbinsy =ybins_in;////2D histo的bin的数量,y
	Int_t nbins = nbinsx*nbinsy;// 2d histo一共被分为多少区域

    TH1D* h1_out= new TH1D(hname, "", nbins, 0, nbins);
	for(Int_t iy=1; iy<=nbinsy; iy++){
		for(Int_t ix=1; ix<=nbinsx; ix++){
			Double_t x_temp = 0.5*(xbin[ix-1]+xbin[ix]);//取一个bin两个端点的均值,x direction,得到the BinContent
			Double_t y_temp = 0.5*(ybin[iy-1]+ybin[iy]);////取一个bin两个端点的均值,y direction
			   h1_out->SetBinContent(ix+(iy-1)*nbinsx,th2->GetBinContent(th2->FindBin(x_temp, y_temp)));//void SetBinContent(Int_t bin, Double_t content),the FindBin function can return Global bin number corresponding to x,y
			   h1_out->SetBinError(ix+(iy-1)*nbinsx,th2->GetBinError(th2->FindBin(x_temp, y_temp)));
               cout<<"ix = "<<ix<<", iy = "<<iy<<"; bin = "<<ix+(iy-1)*nbinsx<<", BinContent"<<th2->GetBinContent(th2->FindBin(x_temp, y_temp))<<endl;
		}
    }
    return h1_out;
}

int unroll(){
	setTDRStyle();
	gStyle->SetPadBorderMode(0);
    gStyle->SetOptStat(0);
	gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetAxisColor(1, "XYZ");
    gStyle->SetStripDecimals(kTRUE);
    gStyle->SetTickLength(0.03, "XYZ");
    gStyle->SetNdivisions(510, "XYZ");

	TFile* fout = new TFile("dd.root","RECREATE");
	Double_t ZA_scale= 0.98;
	std::ostringstream strs;
	std::string lumivalue = strs.str();
	Double_t lumi=35.866;
	Double_t mjj_bins[4]={500, 800, 1200, 2000};
    Double_t detajj_bins[4]={2.5,4.5,6,6.5};
	const char *name[9]={"Mjj 500~800","Mjj 800~1200","Mjj 1200~2000","Mjj 500~800","Mjj 800~1200","Mjj 1200~2000","Mjj 500~800","Mjj 800~1200","Mjj 1200~2000"};

	TFile* f_ZA=TFile::Open("./th2-histo.root");
	TH2D* th2_ZA[57];
	TH1D* t_ZA[57];
    TCanvas* cc[57];
    TLegend *ll[57];
    for(Int_t i=0;i<57;i++){
        ll[i] = new TLegend(0.55,0.4,0.8,0.9);
//        cc[i] = new TCanvas(Form("cc_%d",i),Form("Mjj vs deltajj %d",i+1),900,600);
        th2_ZA[i]=(TH2D*)f_ZA->Get(Form("th2_%d",i));
        t_ZA[i]= unroll(th2_ZA[i], mjj_bins, detajj_bins, 3,3,Form("hist_%d",i+1));//Form("%d central scale pdf variable",i+1));
        ofstream file2(Form("content-hist_%d",i+1));
    cout<<"***************************histo "<<i+1<< " has been created*********************"<<endl;
        t_ZA[i]->SetLineWidth(3);
        t_ZA[i]->SetLineColor(i+1);
        for(Int_t j=1;j<=9;j++){ t_ZA[i]->GetXaxis()->SetBinLabel(j,name[j-1]);}
        t_ZA[i]->Scale(lumi*ZA_scale);
//        t_ZA[i]->Draw("HIST");
//        t_ZA[i]->DrawNormalized("HIST");
        ll[i]->AddEntry(t_ZA[i],Form("%d central scale pdf variable",i+1));
//        ll[i]->Draw();
//        cc[i]->Print(Form("tmp-hist2d_%d.eps",i+1));
        for(Int_t k=0;k<57;k++){
        file2<<t_ZA[i]->GetBinContent(k+1)<<endl;}
      }
     TCanvas* c1 = new TCanvas("c1","Mjj vs deltajj",900,600);
     c1->SetFrameFillColor(41);
     TLegend *l2 = new TLegend(0.55,0.4,0.8,0.9);
     t_ZA[0]->SetTitle("Mjj vs detajj");
     t_ZA[0]->SetLineWidth(3);
     t_ZA[0]->Draw("HIST");
     t_ZA[0]->SetLineStyle(7);
     t_ZA[0]->SetLineColor(kRed);
     t_ZA[0]->GetXaxis()->SetTitle("mjj(GeV)");
     t_ZA[0]->GetXaxis()->SetTitleSize(0.065);
     t_ZA[0]->GetXaxis()->SetTitleFont(12);

     for(Int_t i=1;i<57;i++){
 //         t_ZA[i]->SetFillColor(kMagenta);
 //         t_ZA[i]->SetMarkerColor(kMagenta);
          t_ZA[i]->SetLineColor(kBlue);
          t_ZA[i]->SetLineWidth(1);
          t_ZA[i]->SetLineStyle(1);
          for(Int_t j=1;j<=9;j++){ t_ZA[i]->GetXaxis()->SetBinLabel(j,name[j-1]);}
          //t_ZA[i]->Draw("HIST,SAME");
          t_ZA[i]->Draw("HIST,SAME");
         // delete t_ZA[i];
         // delete cc[i];
       }
       t_ZA[0]->Draw("HIST,SAME");
       l2->AddEntry(t_ZA[0],"central CT14 pdf value");
       l2->AddEntry(t_ZA[2],"other CT14 values");
       l2->SetTextSize(0.04347826);
       l2->SetTextFont(22);
       l2->Draw();
       c1->Print("tmp-hist-2d.eps");
       c1->Print("CT14_2dhist.pdf");

//	TH1D* t_ZA=unroll(th2_ZA, mjj_bins, detajj_bins, 3,3);
//    for(Int_t i=0;i<103;i++){
//	  t_ZA[i]->SetFillColor(i+1);
//	  t_ZA[i]->SetMarkerColor(i+1);
//	  t_ZA[i]->SetLineColor(i+1);
//	  t_ZA[i]->Scale(lumi*ZA_scale);  
//    }
	THStack* hs = new THStack("hs", "");
    TLegend *l1 = new TLegend(0.55,0.4,0.8,0.9);
    for(Int_t i=0;i<57;i++){
	   hs->Add(t_ZA[i]);
       l1->AddEntry(t_ZA[i],Form("%d central scale pdf variations",i+1));
      }

//    TCanvas* c = new TCanvas("c","Mjj vs deltajj",800,600);
//    c->cd();
//	TPad* fPad1 = new TPad("pad1", "", 0.00, 0.00, 0.99, 0.99);
//	fPad1->Draw();
//	CMS_lumi(fPad1, 4, 0, lumivalue);
//    c->SetFrameFillColor(41);
//    hs->Draw("HIST");
//    hs->GetYaxis()->SetTitleOffset(0.8);
//    hs->GetYaxis()->SetTitle("Events /bin");
//    for(Int_t i=1;i<=103;i++){ hs->GetXaxis()->SetBinLabel(i,name[i-1]);}
//    l1->Draw();
//    c->Print("tmp.eps");

	
	cmsLumi(0);

	fout->cd();
    c1->Write();
    for(Int_t i=0;i<57;i++){
	t_ZA[i]->Write();
//    cc[i]->Write();
    }
	fout->Close();
return 0;


}
