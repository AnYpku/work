#include "CMSTDRStyle.h"
#include "CMS_lumi.C"
#include "TArrow.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH2.h"
#include "THStack.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TStyle.h"
#include <iostream>
using namespace std;

void cmsLumi(bool channel) {
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.04);
    latex.SetLineWidth(2);
    int beamcomenergytev = 13;
    latex.SetTextAlign(31);
    latex.SetTextAlign(11);
    latex.DrawLatex(0.18, 0.82, "Preliminary");
    latex.DrawLatex(0.18, 0.86, "CMS");
    latex.SetTextSize(0.03);
    latex.DrawLatex(0.76, 0.92, Form("35.9 fb^{-1} (%d TeV)", (beamcomenergytev)));
}

TH1D* unroll(TH2D* th2_in, Double_t* xbin, Double_t* ybin, Int_t xbins_in, Int_t ybins_in) {
    TH2D* th2    = th2_in;
    Int_t nbinsx = xbins_in;
    Int_t nbinsy = ybins_in;
    Int_t nbins  = nbinsx * nbinsy;

    TH1D* h1     = new TH1D("hist", "hist", nbins, 0, nbins);
    TH1D* h1_out = new TH1D("unrolled hist", "unrolled hist", nbins, 0, nbins);

    for (Int_t iy = 1; iy <= nbinsy; iy++) {
        for (Int_t ix = 1; ix <= nbinsx; ix++) {
            Double_t x_temp = 0.5 * (xbin[ix - 1] + xbin[ix]);
            Double_t y_temp = 0.5 * (ybin[iy - 1] + ybin[iy]);
            h1->SetBinContent(ix + (iy - 1) * nbinsx, th2->GetBinContent(th2->FindBin(x_temp, y_temp)));
            h1->SetBinError(ix + (iy - 1) * nbinsx, th2->GetBinError(th2->FindBin(x_temp, y_temp)));
            cout << "bin " << (ix + (iy - 1) * nbinsx) << ": " << h1->GetBinContent(ix + (iy - 1) * nbinsx) << endl;
        }
    }
    /*
	for(Int_t ii=1; ii<=nbins-2;ii++){
		if(ii<9){
			h1_out->SetBinContent(ii, h1->GetBinContent(ii));
			h1_out->SetBinError(ii,h1->GetBinError(ii));
		}
		if(ii==9){
			h1_out->SetBinContent(ii, h1->GetBinContent(ii)+h1->GetBinContent(ii+1)+h1->GetBinContent(ii+2));
			h1_out->SetBinError(ii,sqrt(h1->GetBinError(ii)*h1->GetBinError(ii)+h1->GetBinError(ii+1)*h1->GetBinError(ii+1)+h1->GetBinError(ii+2)*h1->GetBinError(ii+2)));
		}
		if(ii==10){
			h1_out->SetBinContent(ii, h1->GetBinContent(ii+2));
                        h1_out->SetBinError(ii,h1->GetBinError(ii+2));
		}
	}
*/
    for (Int_t ii = 1; ii <= nbins; ii++) {
        h1_out->SetBinContent(ii, h1->GetBinContent(ii));
        h1_out->SetBinError(ii, h1->GetBinError(ii));
        /*                if(ii==9){
                        h1_out->SetBinContent(ii, h1->GetBinContent(ii)+h1->GetBinContent(ii+1)+h1->GetBinContent(ii+2));
                        h1_out->SetBinError(ii,sqrt(h1->GetBinError(ii)*h1->GetBinError(ii)+h1->GetBinError(ii+1)*h1->GetBinError(ii+1)+h1->GetBinError(ii+2)*h1->GetBinError(ii+2)));
                }
                if(ii==10){
                        h1_out->SetBinContent(ii, h1->GetBinContent(ii+2));
                        h1_out->SetBinError(ii,h1->GetBinError(ii+2));
                }
*/
    }

    return h1_out;
}

void unrollmain() {
    setTDRStyle();
    TFile*             fout     = new TFile("aa.root", "RECREATE");
    Double_t           WA_scale = 1.0;
    std::ostringstream strs;
    std::string        lumivalue = strs.str();
    Double_t           lumi      = 35.857;
    //Double_t           mjj_bins[5] = {500, 800, 1200, 1700, 2000};
    Double_t mjj_bins[6] = {150, 400, 600, 800, 1000, 1500};
    //        Double_t mlla_bins[5]={90, 130, 170, 210, 240};
    //Double_t detajj_bins[4] = {30, 80, 130, 200};

    TFile* f_WAJJ     = TFile::Open("./jerc_met.root");
    TH2D*  central_2d = (TH2D*)f_WAJJ->Get("histo2");
    //	TH1D* t_WA=unroll(th2_WA, mjj_bins, mlla_bins, 4,4);
    TH1D* central = unroll(central_2d, mjj_bins, detajj_bins, 4, 3);
    central->SetMarkerColor(kBlack);
    central->SetLineColor(kBlack);
    central->SetLineWidth(2);

    //const char* name[9]  = {"500~800", "800~1200", "1200~2000", "500~800", "800~1200", "1200~2000", "500~800", "800~1200", "1200~2000"};
    const char* name[12] = {"500~800", "800~1200", "1200~1700", "1700~inf", "500~800", "800~1200", "1200~1700", "1700~inf", "500~800", "800~1200", "1200~1700", "1700~inf"};
    for (Int_t i = 1; i <= 12; i++) {
        central->GetXaxis()->SetBinLabel(i, name[i - 1]);
    }

    TH2D* jec_up_2d = (TH2D*)f_WAJJ->Get("histo3");
    //        TH1D* t_WAJJ=unroll(th2_WAJJ, mjj_bins, mlla_bins, 4,4);
    TH1D* jec_up = unroll(jec_up_2d, mjj_bins, detajj_bins, 4, 3);
    jec_up->SetMarkerColor(kRed);
    jec_up->SetLineColor(kRed);
    jec_up->SetMarkerStyle(21);
    //jec_up->SetLineStyle(2);
    jec_up->SetLineWidth(2);

    TH2D* jec_down_2d = (TH2D*)f_WAJJ->Get("histo4");
    //        TH1D* t_WAJJ=unroll(th2_WAJJ, mjj_bins, mlla_bins, 4,4);
    TH1D* jec_down = unroll(jec_down_2d, mjj_bins, detajj_bins, 4, 3);
    jec_down->SetMarkerColor(kBlue);
    jec_down->SetLineColor(kBlue);
    jec_down->SetMarkerStyle(21);
    //jec_down->SetLineStyle(2);
    jec_down->SetLineWidth(2);

    TH2D* jer_up_2d = (TH2D*)f_WAJJ->Get("histo5");
    //        TH1D* t_WAJJ=unroll(th2_WAJJ, mjj_bins, mlla_bins, 4,4);
    TH1D* jer_up = unroll(jer_up_2d, mjj_bins, detajj_bins, 4, 3);
    jer_up->SetMarkerColor(kRed);
    jer_up->SetLineColor(kRed);
    jer_up->SetMarkerStyle(21);
    //jer_up->SetLineStyle(2);
    jer_up->SetLineWidth(2);

    TH2D* jer_down_2d = (TH2D*)f_WAJJ->Get("histo6");
    //        TH1D* t_WAJJ=unroll(th2_WAJJ, mjj_bins, mlla_bins, 4,4);
    TH1D* jer_down = unroll(jer_down_2d, mjj_bins, detajj_bins, 4, 3);
    jer_down->SetMarkerColor(kBlue);
    jer_down->SetLineColor(kBlue);
    jer_down->SetMarkerStyle(21);
    //jer_down->SetLineStyle(2);
    jer_down->SetLineWidth(2);
    for (Int_t i = 1; i <= 12; i++) {
        jer_down->GetXaxis()->SetBinLabel(i, name[i - 1]);
    }

    TH2D* jec_sf_2d = (TH2D*)f_WAJJ->Get("jec_unc");
    //        TH1D* t_WAJJ=unroll(th2_WAJJ, mjj_bins, mlla_bins, 4,4);
    TH1D* jec_sf = unroll(jec_sf_2d, mjj_bins, detajj_bins, 4, 3);
    jec_sf->SetMarkerColor(kBlue);
    jec_sf->SetLineColor(kBlue);
    jec_sf->SetLineWidth(2);
    jec_sf->SetMarkerStyle(21);
    for (Int_t i = 1; i <= 12; i++) {
        jec_sf->GetXaxis()->SetBinLabel(i, name[i - 1]);
    }

    TH2D* jer_sf_2d = (TH2D*)f_WAJJ->Get("jer_unc");
    //        TH1D* t_WAJJ=unroll(th2_WAJJ, mjj_bins, mlla_bins, 4,4);
    TH1D* jer_sf = unroll(jer_sf_2d, mjj_bins, detajj_bins, 4, 3);
    jer_sf->SetMarkerColor(kBlue);
    jer_sf->SetLineColor(kBlue);
    jer_sf->SetMarkerStyle(21);
    jec_sf->SetLineWidth(2);
    for (Int_t i = 1; i <= 12; i++) {
        jer_sf->GetXaxis()->SetBinLabel(i, name[i - 1]);
    }

    /*
t_WA->Add(t_STop);
t_WA->Add(t_TTJets);
t_WA->Add(t_VV);
t_WA->Add(t_DY);
t_WA->Add(t_electronfaketophoton);
t_WA->Add(t_fakelep);
t_WA->Add(t_fakephoton);
cout<<"bkg  "<<t_WA->Integral();
*/
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

    TCanvas* c1 = new TCanvas("c1", "c1", 400, 400);
    c1->cd();
    TPad* fPad1 = new TPad("pad1", "", 0.00, 0.00, 0.99, 0.99);
    fPad1->Draw();
    CMS_lumi(fPad1, 4, 0, lumivalue);
    central->Draw("HIST");
    central->GetYaxis()->SetRangeUser(0.0000000000001, 40);
    central->SetStats(false);
    jec_up->Draw("HIST SAME");
    jec_up->SetStats(false);
    jec_down->Draw("HIST SAME");
    jer_down->SetStats(false);
    //jer_up->Draw("HIST SAME");
    jer_up->SetStats(false);
    jer_down->SetStats(false);
    //jer_down->Draw("HIST SAME");
    gStyle->SetOptStat(0);

    //jer_down->GetYaxis()->SetRange(0, 6);

    TLegend* leg1 = new TLegend(0.45, 0.72, 0.75, 0.88);
    leg1->SetMargin(0.4);
    leg1->AddEntry(central, "central", "l");
    leg1->AddEntry(jec_up, "jec_up", "l");
    leg1->AddEntry(jec_down, "jec_down", "l");
    //leg1->AddEntry(jer_up, "jer_up", "l");
    //leg1->AddEntry(jer_down, "jer_down", "l");
    leg1->Draw();
    TLatex latex1;
    latex1.SetTextAlign(12);
    latex1.SetTextSize(0.04);
    TArrow* line1 = new TArrow(jer_down->GetBinLowEdge(5), 0, jer_down->GetBinLowEdge(5), 2.5 * jer_down->GetMaximum(), 0.07, "");
    TArrow* line2 = new TArrow(jer_down->GetBinLowEdge(9), 0, jer_down->GetBinLowEdge(9), 2. * jer_down->GetMaximum(), 0.07, "");
    line1->SetLineColor(1);
    line1->SetLineWidth(3);
    line1->SetLineStyle(7);
    line2->SetLineColor(1);
    line2->SetLineWidth(3);
    line2->SetLineStyle(7);

    cmsLumi(0);

    latex1.DrawLatexNDC(0.15, 0.6, "#font[12]{M_{l#gamma} #in (30, 80)}");
    latex1.DrawLatexNDC(0.45, 0.6, "#font[12]{M_{l#gamma} #in (80, 130)}");
    latex1.DrawLatexNDC(0.75, 0.6, "#font[12]{M_{l#gamma} > 130}");

    line1->Draw();
    line2->Draw();

    TCanvas* c2 = new TCanvas("c2", "c2", 400, 400);
    c2->cd();
    TPad* fPad2 = new TPad("pad2", "", 0.00, 0.00, 0.99, 0.99);
    fPad2->Draw();
    CMS_lumi(fPad2, 4, 0, lumivalue);
    jec_sf->SetStats(false);
    jec_sf->Draw("HIST");
    TLegend* leg2 = new TLegend(0.62, 0.82, 0.87, 0.88);
    leg2->SetMargin(0.4);
    leg2->AddEntry(jer_sf, "jec_sf", "l");
    leg2->Draw();
    TLatex latex2;
    latex2.SetTextAlign(12);
    latex2.SetTextSize(0.04);
    TArrow* line3 = new TArrow(jec_sf->GetBinLowEdge(5), 0, jec_sf->GetBinLowEdge(5), 2.5 * jec_sf->GetMaximum(), 0.07, "");
    TArrow* line4 = new TArrow(jec_sf->GetBinLowEdge(9), 0, jec_sf->GetBinLowEdge(9), 2. * jec_sf->GetMaximum(), 0.07, "");
    line3->SetLineColor(1);
    line3->SetLineWidth(3);
    line3->SetLineStyle(7);
    line4->SetLineColor(1);
    line4->SetLineWidth(3);
    line4->SetLineStyle(7);

    cmsLumi(0);

    latex2.DrawLatexNDC(0.15, 0.5, "#font[12]{M_{l#gamma} #in (30, 80)}");
    latex2.DrawLatexNDC(0.45, 0.5, "#font[12]{M_{l#gamma} #in (80, 130)}");
    latex2.DrawLatexNDC(0.75, 0.5, "#font[12]{M_{l#gamma} > 130}");

    line3->Draw();
    line4->Draw();

    TCanvas* c3 = new TCanvas("c3", "c3", 400, 400);
    c3->cd();
    TPad* fPad3 = new TPad("pad3", "", 0.00, 0.00, 0.99, 0.99);
    fPad3->Draw();
    CMS_lumi(fPad3, 4, 0, lumivalue);
    jer_sf->Draw("HIST");
    jer_sf->SetStats(false);
    TLegend* leg3 = new TLegend(0.45, 0.82, 0.70, 0.88);
    leg3->SetMargin(0.4);
    leg3->AddEntry(jer_sf, "jer_sf", "l");
    leg3->Draw();
    TLatex latex3;
    latex3.SetTextAlign(12);
    latex3.SetTextSize(0.04);
    TArrow* line5 = new TArrow(jer_sf->GetBinLowEdge(5), 0, jer_sf->GetBinLowEdge(5), 2.5 * jer_sf->GetMaximum(), 0.07, "");
    TArrow* line6 = new TArrow(jer_sf->GetBinLowEdge(9), 0, jer_sf->GetBinLowEdge(9), 2. * jer_sf->GetMaximum(), 0.07, "");
    line5->SetLineColor(1);
    line5->SetLineWidth(3);
    line5->SetLineStyle(7);
    line6->SetLineColor(1);
    line6->SetLineWidth(3);
    line6->SetLineStyle(7);

    cmsLumi(0);

    latex3.DrawLatexNDC(0.15, 0.5, "#font[12]{M_{l#gamma} #in (30, 80)}");
    latex3.DrawLatexNDC(0.45, 0.5, "#font[12]{M_{l#gamma} #in (80, 130)}");
    latex3.DrawLatexNDC(0.75, 0.5, "#font[12]{M_{l#gamma} > 130}");

    line5->Draw();
    line6->Draw();

    fout->cd();
    c1->Write();
    c2->Write();
    c3->Write();
    fout->Close();

    c1->SaveAs("his_1D.pdf");
    c2->SaveAs("scale_jec.pdf");
    c3->SaveAs("scale_jer.pdf");
}
