void EleID_SFvseta_passingTight94XV2()
{
//=========Macro generated from canvas: totoeta/totoeta
//=========  (Thu Sep 19 11:55:30 2019) by ROOT version 6.12/07
   TCanvas *totoeta = new TCanvas("totoeta", "totoeta",0,0,800,800);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   totoeta->SetHighLightColor(2);
   totoeta->Range(0,0,1,1);
   totoeta->SetFillColor(0);
   totoeta->SetBorderMode(0);
   totoeta->SetBorderSize(2);
   totoeta->SetTickx(1);
   totoeta->SetTicky(1);
   totoeta->SetLeftMargin(0.12);
   totoeta->SetRightMargin(0.02);
   totoeta->SetTopMargin(0.055);
   totoeta->SetFrameFillStyle(0);
   totoeta->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: totoeta_do
   TPad *totoeta_do = new TPad("totoeta_do", "totoeta_do",0,0,1,0.45);
   totoeta_do->Draw();
   totoeta_do->cd();
   totoeta_do->Range(-3.325581,0.424212,2.72093,1.125258);
   totoeta_do->SetFillColor(0);
   totoeta_do->SetBorderMode(0);
   totoeta_do->SetBorderSize(0);
   totoeta_do->SetTickx(1);
   totoeta_do->SetTicky(1);
   totoeta_do->SetLeftMargin(0.12);
   totoeta_do->SetRightMargin(0.02);
   totoeta_do->SetTopMargin(0.0075);
   totoeta_do->SetBottomMargin(0.2222222);
   totoeta_do->SetFrameFillStyle(0);
   totoeta_do->SetFrameBorderMode(0);
   totoeta_do->SetFrameFillStyle(0);
   totoeta_do->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1013[12] = {
   80,
   -35,
   10,
   -10,
   25,
   35,
   -45,
   -80,
   45,
   -55,
   -25,
   55};
   Double_t Graph0_fy1013[12] = {
   0.8665511,
   0.7716049,
   0.9913917,
   0.9913917,
   0.7440476,
   0.7716049,
   0.7949126,
   0.8665511,
   0.7949126,
   0.8169935,
   0.7440476,
   0.8169935};
   Double_t Graph0_fex1013[12] = {
   20,
   5,
   10,
   10,
   5,
   5,
   5,
   20,
   5,
   5,
   5,
   5};
   Double_t Graph0_fey1013[12] = {
   0.01237683,
   0.009637343,
   0.006416264,
   0.006416264,
   0.00773237,
   0.009637343,
   0.00317965,
   0.01237683,
   0.00317965,
   0.004002434,
   0.00773237,
   0.004002434};
   TGraphErrors *gre = new TGraphErrors(12,Graph0_fx1013,Graph0_fy1013,Graph0_fex1013,Graph0_fey1013);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#999999");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1013 = new TH1F("Graph_Graph1013","Graph",100,-2.6,2.6);
   Graph_Graph1013->SetMinimum(0.58);
   Graph_Graph1013->SetMaximum(1.12);
   Graph_Graph1013->SetDirectory(0);
   Graph_Graph1013->SetStats(0);
   Graph_Graph1013->SetLineStyle(0);
   Graph_Graph1013->SetMarkerStyle(20);
   Graph_Graph1013->GetXaxis()->SetTitle("SuperCluster #eta");
   Graph_Graph1013->GetXaxis()->SetNoExponent();
   Graph_Graph1013->GetXaxis()->SetLabelFont(42);
   Graph_Graph1013->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1013->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1013->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1013->GetXaxis()->SetTitleFont(42);
   Graph_Graph1013->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1013->GetYaxis()->SetLabelFont(42);
   Graph_Graph1013->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1013->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1013->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1013->GetYaxis()->SetTitleFont(42);
   Graph_Graph1013->GetZaxis()->SetLabelFont(42);
   Graph_Graph1013->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1013->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1013->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1013->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1013);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1014[12] = {
   80,
   -35,
   10,
   -10,
   25,
   35,
   -45,
   -80,
   45,
   -55,
   -25,
   55};
   Double_t Graph1_fy1014[12] = {
   0.7267442,
   0.6944444,
   0.9325236,
   0.9325236,
   0.6868132,
   0.6944444,
   0.7032349,
   0.7267442,
   0.7032349,
   0.7122507,
   0.6868132,
   0.7122507};
   Double_t Graph1_fex1014[12] = {
   20,
   5,
   10,
   10,
   5,
   5,
   5,
   20,
   5,
   5,
   5,
   5};
   Double_t Graph1_fey1014[12] = {
   0.0118082,
   0.003674655,
   0.005226698,
   0.005226698,
   0.008241758,
   0.003674655,
   0.006289924,
   0.0118082,
   0.006289924,
   0.003768877,
   0.008241758,
   0.003768877};
   gre = new TGraphErrors(12,Graph1_fx1014,Graph1_fy1014,Graph1_fex1014,Graph1_fey1014);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1014 = new TH1F("Graph_Graph1014","Graph",100,-2.6,2.6);
   Graph_Graph1014->SetMinimum(0.58);
   Graph_Graph1014->SetMaximum(1.12);
   Graph_Graph1014->SetDirectory(0);
   Graph_Graph1014->SetStats(0);
   Graph_Graph1014->SetLineStyle(0);
   Graph_Graph1014->SetMarkerStyle(20);
   Graph_Graph1014->GetXaxis()->SetTitle("SuperCluster #eta");
   Graph_Graph1014->GetXaxis()->SetNoExponent();
   Graph_Graph1014->GetXaxis()->SetLabelFont(42);
   Graph_Graph1014->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1014->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1014->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1014->GetXaxis()->SetTitleFont(42);
   Graph_Graph1014->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1014->GetYaxis()->SetLabelFont(42);
   Graph_Graph1014->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1014->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1014->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1014->GetYaxis()->SetTitleFont(42);
   Graph_Graph1014->GetZaxis()->SetLabelFont(42);
   Graph_Graph1014->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1014->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1014->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1014->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1014);
   
   gre->Draw("p");
   TLine *line = new TLine(-2.6,1,2.6,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   totoeta_do->Modified();
   totoeta->cd();
  
// ------------>Primitives in pad: totoeta_up
   TPad *totoeta_up = new TPad("totoeta_up", "totoeta_up",0,0.45,1,1);
   totoeta_up->Draw();
   totoeta_up->cd();
   totoeta_up->Range(-3.325581,0.4767227,2.72093,0.9136975);
   totoeta_up->SetFillColor(0);
   totoeta_up->SetBorderMode(0);
   totoeta_up->SetBorderSize(0);
   totoeta_up->SetTickx(1);
   totoeta_up->SetTicky(1);
   totoeta_up->SetLeftMargin(0.12);
   totoeta_up->SetRightMargin(0.02);
   totoeta_up->SetBottomMargin(0.0075);
   totoeta_up->SetFrameFillStyle(0);
   totoeta_up->SetFrameBorderMode(0);
   totoeta_up->SetFrameFillStyle(0);
   totoeta_up->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1015[12] = {
   80,
   -35,
   10,
   -10,
   25,
   35,
   -45,
   -80,
   45,
   -55,
   -25,
   55};
   Double_t Graph0_fy1015[12] = {
   0.5,
   0.5,
   0.691,
   0.691,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t Graph0_fex1015[12] = {
   20,
   5,
   10,
   10,
   5,
   5,
   5,
   20,
   5,
   5,
   5,
   5};
   Double_t Graph0_fey1015[12] = {
   0.007141428,
   0.006244998,
   0.004472136,
   0.004472136,
   0.005196152,
   0.006244998,
   0.002,
   0.007141428,
   0.002,
   0.00244949,
   0.005196152,
   0.00244949};
   gre = new TGraphErrors(12,Graph0_fx1015,Graph0_fy1015,Graph0_fex1015,Graph0_fey1015);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#999999");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1015 = new TH1F("Graph_Graph1015","Graph",100,-2.6,2.6);
   Graph_Graph1015->SetMinimum(0.48);
   Graph_Graph1015->SetMaximum(0.87);
   Graph_Graph1015->SetDirectory(0);
   Graph_Graph1015->SetStats(0);
   Graph_Graph1015->SetLineStyle(0);
   Graph_Graph1015->SetMarkerStyle(20);
   Graph_Graph1015->GetXaxis()->SetLabelFont(42);
   Graph_Graph1015->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1015->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1015->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1015->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1015->GetXaxis()->SetTitleFont(42);
   Graph_Graph1015->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1015->GetYaxis()->SetLabelFont(42);
   Graph_Graph1015->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1015->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1015->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1015->GetYaxis()->SetTitleFont(42);
   Graph_Graph1015->GetZaxis()->SetLabelFont(42);
   Graph_Graph1015->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1015->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1015->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1015->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1015);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1016[12] = {
   80,
   -35,
   10,
   -10,
   25,
   35,
   -45,
   -80,
   45,
   -55,
   -25,
   55};
   Double_t Graph1_fy1016[12] = {
   0.577,
   0.648,
   0.697,
   0.697,
   0.672,
   0.648,
   0.629,
   0.577,
   0.629,
   0.612,
   0.672,
   0.612};
   Double_t Graph1_fex1016[12] = {
   20,
   5,
   10,
   10,
   5,
   5,
   5,
   20,
   5,
   5,
   5,
   5};
   Double_t Graph1_fey1016[12] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   gre = new TGraphErrors(12,Graph1_fx1016,Graph1_fy1016,Graph1_fex1016,Graph1_fey1016);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#999999");
   gre->SetLineColor(ci);
   gre->SetLineStyle(2);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0);
   gre->Draw("ez");
   
   Double_t Graph2_fx1017[12] = {
   80,
   -35,
   10,
   -10,
   25,
   35,
   -45,
   -80,
   45,
   -55,
   -25,
   55};
   Double_t Graph2_fy1017[12] = {
   0.5,
   0.5,
   0.691,
   0.691,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5,
   0.5};
   Double_t Graph2_fex1017[12] = {
   20,
   5,
   10,
   10,
   5,
   5,
   5,
   20,
   5,
   5,
   5,
   5};
   Double_t Graph2_fey1017[12] = {
   0.008124038,
   0.002645751,
   0.003872983,
   0.003872983,
   0.006,
   0.002645751,
   0.004472136,
   0.008124038,
   0.004472136,
   0.002645751,
   0.006,
   0.002645751};
   gre = new TGraphErrors(12,Graph2_fx1017,Graph2_fy1017,Graph2_fex1017,Graph2_fey1017);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1017 = new TH1F("Graph_Graph1017","Graph",100,-2.6,2.6);
   Graph_Graph1017->SetMinimum(0.48);
   Graph_Graph1017->SetMaximum(0.87);
   Graph_Graph1017->SetDirectory(0);
   Graph_Graph1017->SetStats(0);
   Graph_Graph1017->SetLineStyle(0);
   Graph_Graph1017->SetMarkerStyle(20);
   Graph_Graph1017->GetXaxis()->SetLabelFont(42);
   Graph_Graph1017->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1017->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1017->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1017->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1017->GetXaxis()->SetTitleFont(42);
   Graph_Graph1017->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1017->GetYaxis()->SetLabelFont(42);
   Graph_Graph1017->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1017->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1017->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1017->GetYaxis()->SetTitleFont(42);
   Graph_Graph1017->GetZaxis()->SetLabelFont(42);
   Graph_Graph1017->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1017->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1017->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1017->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1017);
   
   gre->Draw("p");
   
   Double_t Graph3_fx1018[12] = {
   80,
   -35,
   10,
   -10,
   25,
   35,
   -45,
   -80,
   45,
   -55,
   -25,
   55};
   Double_t Graph3_fy1018[12] = {
   0.688,
   0.72,
   0.741,
   0.741,
   0.728,
   0.72,
   0.711,
   0.688,
   0.711,
   0.702,
   0.728,
   0.702};
   Double_t Graph3_fex1018[12] = {
   20,
   5,
   10,
   10,
   5,
   5,
   5,
   20,
   5,
   5,
   5,
   5};
   Double_t Graph3_fey1018[12] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   gre = new TGraphErrors(12,Graph3_fx1018,Graph3_fy1018,Graph3_fex1018,Graph3_fey1018);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineStyle(2);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0);
   gre->Draw("ez");
   totoeta_up->Modified();
   totoeta->cd();
   
   TLegend *leg = new TLegend(0.5,0.8,0.95,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph2","  0 #leq p_{T} #leq    1 GeV","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","  1 #leq p_{T} #leq    2 GeV","PL");

   ci = TColor::GetColor("#999999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(0.98,0.956,"+52.2 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.033);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1587,0.915425,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(61);
   tex->SetTextSize(0.04125);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1587,0.865925,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.03135);
   tex->SetLineWidth(2);
   tex->Draw();
   totoeta->Modified();
   totoeta->cd();
   totoeta->SetSelected(totoeta);
}
