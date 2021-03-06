void EleID_SF2D_altSignalModelpassingTight94XV2()
{
//=========Macro generated from canvas: canScaleFactor_altSignalModel/canScaleFactor: altSignalModel
//=========  (Thu Sep 19 11:55:31 2019) by ROOT version 6.12/07
   TCanvas *canScaleFactor_altSignalModel = new TCanvas("canScaleFactor_altSignalModel", "canScaleFactor: altSignalModel",0,0,1000,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   canScaleFactor_altSignalModel->SetHighLightColor(2);
   canScaleFactor_altSignalModel->Range(0,0,1,1);
   canScaleFactor_altSignalModel->SetFillColor(0);
   canScaleFactor_altSignalModel->SetBorderMode(0);
   canScaleFactor_altSignalModel->SetBorderSize(2);
   canScaleFactor_altSignalModel->SetTickx(1);
   canScaleFactor_altSignalModel->SetTicky(1);
   canScaleFactor_altSignalModel->SetLeftMargin(0.16);
   canScaleFactor_altSignalModel->SetRightMargin(0.02);
   canScaleFactor_altSignalModel->SetTopMargin(0.05);
   canScaleFactor_altSignalModel->SetBottomMargin(0.13);
   canScaleFactor_altSignalModel->SetFrameFillStyle(0);
   canScaleFactor_altSignalModel->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: canScaleFactor_altSignalModel_1
   TPad *canScaleFactor_altSignalModel_1 = new TPad("canScaleFactor_altSignalModel_1", "canScaleFactor_altSignalModel_1",0.01,0.01,0.49,0.99);
   canScaleFactor_altSignalModel_1->Draw();
   canScaleFactor_altSignalModel_1->cd();
   canScaleFactor_altSignalModel_1->Range(-142.8571,0.1193224,142.8571,0.4288975);
   canScaleFactor_altSignalModel_1->SetFillColor(0);
   canScaleFactor_altSignalModel_1->SetBorderMode(0);
   canScaleFactor_altSignalModel_1->SetBorderSize(2);
   canScaleFactor_altSignalModel_1->SetLogy();
   canScaleFactor_altSignalModel_1->SetTickx(1);
   canScaleFactor_altSignalModel_1->SetTicky(1);
   canScaleFactor_altSignalModel_1->SetLeftMargin(0.15);
   canScaleFactor_altSignalModel_1->SetRightMargin(0.15);
   canScaleFactor_altSignalModel_1->SetBottomMargin(0.13);
   canScaleFactor_altSignalModel_1->SetFrameFillStyle(0);
   canScaleFactor_altSignalModel_1->SetFrameBorderMode(0);
   canScaleFactor_altSignalModel_1->SetFrameFillStyle(0);
   canScaleFactor_altSignalModel_1->SetFrameBorderMode(0);
   Double_t xAxis9[13] = {-100, -60, -50, -40, -30, -20, 0, 20, 30, 40, 50, 60, 100}; 
   Double_t yAxis9[3] = {0, 1.444, 2.5}; 
   
   TH2F *h2_uncertaintiesEGamma_copy = new TH2F("h2_uncertaintiesEGamma_copy","e/#gamma absolute SF syst: altSignalModel ",12, xAxis9,2, yAxis9);
   h2_uncertaintiesEGamma_copy->SetBinError(15,0.0118082);
   h2_uncertaintiesEGamma_copy->SetBinError(16,0.003768877);
   h2_uncertaintiesEGamma_copy->SetBinError(17,0.006289924);
   h2_uncertaintiesEGamma_copy->SetBinError(18,0.003674655);
   h2_uncertaintiesEGamma_copy->SetBinError(19,0.008241758);
   h2_uncertaintiesEGamma_copy->SetBinError(20,0.005226698);
   h2_uncertaintiesEGamma_copy->SetBinError(21,0.005226698);
   h2_uncertaintiesEGamma_copy->SetBinError(22,0.008241758);
   h2_uncertaintiesEGamma_copy->SetBinError(23,0.003674655);
   h2_uncertaintiesEGamma_copy->SetBinError(24,0.006289924);
   h2_uncertaintiesEGamma_copy->SetBinError(25,0.003768877);
   h2_uncertaintiesEGamma_copy->SetBinError(26,0.0118082);
   h2_uncertaintiesEGamma_copy->SetBinError(29,0.01237683);
   h2_uncertaintiesEGamma_copy->SetBinError(30,0.004002434);
   h2_uncertaintiesEGamma_copy->SetBinError(31,0.00317965);
   h2_uncertaintiesEGamma_copy->SetBinError(32,0.009637343);
   h2_uncertaintiesEGamma_copy->SetBinError(33,0.00773237);
   h2_uncertaintiesEGamma_copy->SetBinError(34,0.006416264);
   h2_uncertaintiesEGamma_copy->SetBinError(35,0.006416264);
   h2_uncertaintiesEGamma_copy->SetBinError(36,0.00773237);
   h2_uncertaintiesEGamma_copy->SetBinError(37,0.009637343);
   h2_uncertaintiesEGamma_copy->SetBinError(38,0.00317965);
   h2_uncertaintiesEGamma_copy->SetBinError(39,0.004002434);
   h2_uncertaintiesEGamma_copy->SetBinError(40,0.01237683);
   h2_uncertaintiesEGamma_copy->SetMinimum(0);
   h2_uncertaintiesEGamma_copy->SetMaximum(0);
   h2_uncertaintiesEGamma_copy->SetEntries(72);
   h2_uncertaintiesEGamma_copy->SetDirectory(0);
   h2_uncertaintiesEGamma_copy->SetContour(20);
   h2_uncertaintiesEGamma_copy->SetContourLevel(0,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(1,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(2,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(3,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(4,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(5,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(6,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(7,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(8,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(9,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(10,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(11,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(12,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(13,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(14,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(15,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(16,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(17,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(18,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(19,0);
   
   TPaletteAxis *palette = new TPaletteAxis(101.4286,0.1595672,114.2857,0.39794,h2_uncertaintiesEGamma_copy);
   palette->SetLabelColor(1);
   palette->SetLabelFont(42);
   palette->SetLabelOffset(0.007);
   palette->SetLabelSize(0.05);
   palette->SetTitleOffset(1);
   palette->SetTitleSize(0.06);
   palette->SetFillColor(78);
   palette->SetFillStyle(1001);
   h2_uncertaintiesEGamma_copy->GetListOfFunctions()->Add(palette,"br");
   h2_uncertaintiesEGamma_copy->SetLineStyle(0);
   h2_uncertaintiesEGamma_copy->SetMarkerStyle(20);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitle("SuperCluster #eta");
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetLabelFont(42);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetLabelOffset(0.007);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetLabelSize(0.05);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitleSize(0.06);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitleOffset(0.9);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitleFont(42);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitle("p_{T} [GeV]");
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetLabelFont(42);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetLabelOffset(0.007);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetLabelSize(0.05);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitleSize(0.06);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitleOffset(1.25);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitleFont(42);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetLabelFont(42);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetLabelOffset(0.007);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetLabelSize(0.05);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetTitleSize(0.06);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetTitleFont(42);
   h2_uncertaintiesEGamma_copy->Draw("colz TEXT45");
   
   TPaveText *pt = new TPaveText(0.01,0.94,0.71,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(2);
   pt->SetFillColor(10);
   TText *pt_LaTex = pt->AddText("e/#gamma absolute SF syst: altSignalModel ");
   pt->Draw();
   canScaleFactor_altSignalModel_1->Modified();
   canScaleFactor_altSignalModel->cd();
  
// ------------>Primitives in pad: canScaleFactor_altSignalModel_2
   TPad *canScaleFactor_altSignalModel_2 = new TPad("canScaleFactor_altSignalModel_2", "canScaleFactor_altSignalModel_2",0.51,0.01,0.99,0.99);
   canScaleFactor_altSignalModel_2->Draw();
   canScaleFactor_altSignalModel_2->cd();
   canScaleFactor_altSignalModel_2->Range(-142.8571,0.1193224,142.8571,0.4288975);
   canScaleFactor_altSignalModel_2->SetFillColor(0);
   canScaleFactor_altSignalModel_2->SetBorderMode(0);
   canScaleFactor_altSignalModel_2->SetBorderSize(2);
   canScaleFactor_altSignalModel_2->SetLogy();
   canScaleFactor_altSignalModel_2->SetTickx(1);
   canScaleFactor_altSignalModel_2->SetTicky(1);
   canScaleFactor_altSignalModel_2->SetLeftMargin(0.15);
   canScaleFactor_altSignalModel_2->SetRightMargin(0.15);
   canScaleFactor_altSignalModel_2->SetBottomMargin(0.13);
   canScaleFactor_altSignalModel_2->SetFrameFillStyle(0);
   canScaleFactor_altSignalModel_2->SetFrameBorderMode(0);
   canScaleFactor_altSignalModel_2->SetFrameFillStyle(0);
   canScaleFactor_altSignalModel_2->SetFrameBorderMode(0);
   Double_t xAxis10[13] = {-100, -60, -50, -40, -30, -20, 0, 20, 30, 40, 50, 60, 100}; 
   Double_t yAxis10[3] = {0, 1.444, 2.5}; 
   
   TH2F *h2_uncertaintiesEGamma_copy = new TH2F("h2_uncertaintiesEGamma_copy","e/#gamma relative SF syst: altSignalModel ",12, xAxis10,2, yAxis10);
   h2_uncertaintiesEGamma_copy->SetBinError(15,0.0118082);
   h2_uncertaintiesEGamma_copy->SetBinError(16,0.003768877);
   h2_uncertaintiesEGamma_copy->SetBinError(17,0.006289924);
   h2_uncertaintiesEGamma_copy->SetBinError(18,0.003674655);
   h2_uncertaintiesEGamma_copy->SetBinError(19,0.008241758);
   h2_uncertaintiesEGamma_copy->SetBinError(20,0.005226698);
   h2_uncertaintiesEGamma_copy->SetBinError(21,0.005226698);
   h2_uncertaintiesEGamma_copy->SetBinError(22,0.008241758);
   h2_uncertaintiesEGamma_copy->SetBinError(23,0.003674655);
   h2_uncertaintiesEGamma_copy->SetBinError(24,0.006289924);
   h2_uncertaintiesEGamma_copy->SetBinError(25,0.003768877);
   h2_uncertaintiesEGamma_copy->SetBinError(26,0.0118082);
   h2_uncertaintiesEGamma_copy->SetBinError(29,0.01237683);
   h2_uncertaintiesEGamma_copy->SetBinError(30,0.004002434);
   h2_uncertaintiesEGamma_copy->SetBinError(31,0.00317965);
   h2_uncertaintiesEGamma_copy->SetBinError(32,0.009637343);
   h2_uncertaintiesEGamma_copy->SetBinError(33,0.00773237);
   h2_uncertaintiesEGamma_copy->SetBinError(34,0.006416264);
   h2_uncertaintiesEGamma_copy->SetBinError(35,0.006416264);
   h2_uncertaintiesEGamma_copy->SetBinError(36,0.00773237);
   h2_uncertaintiesEGamma_copy->SetBinError(37,0.009637343);
   h2_uncertaintiesEGamma_copy->SetBinError(38,0.00317965);
   h2_uncertaintiesEGamma_copy->SetBinError(39,0.004002434);
   h2_uncertaintiesEGamma_copy->SetBinError(40,0.01237683);
   h2_uncertaintiesEGamma_copy->SetMinimum(0);
   h2_uncertaintiesEGamma_copy->SetMaximum(1);
   h2_uncertaintiesEGamma_copy->SetEntries(72);
   h2_uncertaintiesEGamma_copy->SetDirectory(0);
   h2_uncertaintiesEGamma_copy->SetContour(20);
   h2_uncertaintiesEGamma_copy->SetContourLevel(0,0);
   h2_uncertaintiesEGamma_copy->SetContourLevel(1,0.05);
   h2_uncertaintiesEGamma_copy->SetContourLevel(2,0.1);
   h2_uncertaintiesEGamma_copy->SetContourLevel(3,0.15);
   h2_uncertaintiesEGamma_copy->SetContourLevel(4,0.2);
   h2_uncertaintiesEGamma_copy->SetContourLevel(5,0.25);
   h2_uncertaintiesEGamma_copy->SetContourLevel(6,0.3);
   h2_uncertaintiesEGamma_copy->SetContourLevel(7,0.35);
   h2_uncertaintiesEGamma_copy->SetContourLevel(8,0.4);
   h2_uncertaintiesEGamma_copy->SetContourLevel(9,0.45);
   h2_uncertaintiesEGamma_copy->SetContourLevel(10,0.5);
   h2_uncertaintiesEGamma_copy->SetContourLevel(11,0.55);
   h2_uncertaintiesEGamma_copy->SetContourLevel(12,0.6);
   h2_uncertaintiesEGamma_copy->SetContourLevel(13,0.65);
   h2_uncertaintiesEGamma_copy->SetContourLevel(14,0.7);
   h2_uncertaintiesEGamma_copy->SetContourLevel(15,0.75);
   h2_uncertaintiesEGamma_copy->SetContourLevel(16,0.8);
   h2_uncertaintiesEGamma_copy->SetContourLevel(17,0.85);
   h2_uncertaintiesEGamma_copy->SetContourLevel(18,0.9);
   h2_uncertaintiesEGamma_copy->SetContourLevel(19,0.95);
   
   palette = new TPaletteAxis(101.4286,0.1595672,114.2857,0.39794,h2_uncertaintiesEGamma_copy);
   palette->SetLabelColor(1);
   palette->SetLabelFont(42);
   palette->SetLabelOffset(0.007);
   palette->SetLabelSize(0.05);
   palette->SetTitleOffset(1);
   palette->SetTitleSize(0.06);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   palette->SetFillColor(ci);
   palette->SetFillStyle(1001);
   h2_uncertaintiesEGamma_copy->GetListOfFunctions()->Add(palette,"br");
   h2_uncertaintiesEGamma_copy->SetLineStyle(0);
   h2_uncertaintiesEGamma_copy->SetMarkerStyle(20);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitle("SuperCluster #eta");
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetLabelFont(42);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetLabelOffset(0.007);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetLabelSize(0.05);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitleSize(0.06);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitleOffset(0.9);
   h2_uncertaintiesEGamma_copy->GetXaxis()->SetTitleFont(42);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitle("p_{T} [GeV]");
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetLabelFont(42);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetLabelOffset(0.007);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetLabelSize(0.05);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitleSize(0.06);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitleOffset(1.25);
   h2_uncertaintiesEGamma_copy->GetYaxis()->SetTitleFont(42);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetLabelFont(42);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetLabelOffset(0.007);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetLabelSize(0.05);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetTitleSize(0.06);
   h2_uncertaintiesEGamma_copy->GetZaxis()->SetTitleFont(42);
   h2_uncertaintiesEGamma_copy->Draw("colz TEXT45");
   
   pt = new TPaveText(0.01,0.94,0.71,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(2);
   pt->SetFillColor(10);
   pt_LaTex = pt->AddText("e/#gamma relative SF syst: altSignalModel ");
   pt->Draw();
   canScaleFactor_altSignalModel_2->Modified();
   canScaleFactor_altSignalModel->cd();
   canScaleFactor_altSignalModel->Modified();
   canScaleFactor_altSignalModel->cd();
   canScaleFactor_altSignalModel->SetSelected(canScaleFactor_altSignalModel);
}
