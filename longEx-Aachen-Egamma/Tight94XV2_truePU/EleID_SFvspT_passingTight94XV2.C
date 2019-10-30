void EleID_SFvspT_passingTight94XV2()
{
//=========Macro generated from canvas: totopT/totopT
//=========  (Thu Sep 19 11:55:30 2019) by ROOT version 6.12/07
   TCanvas *totopT = new TCanvas("totopT", "totopT",0,0,800,800);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   totopT->SetHighLightColor(2);
   totopT->Range(0,0,1,1);
   totopT->SetFillColor(0);
   totopT->SetBorderMode(0);
   totopT->SetBorderSize(2);
   totopT->SetTickx(1);
   totopT->SetTicky(1);
   totopT->SetLeftMargin(0.12);
   totopT->SetRightMargin(0.02);
   totopT->SetTopMargin(0.055);
   totopT->SetFrameFillStyle(0);
   totopT->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: totopT_do
   TPad *totopT_do = new TPad("totopT_do", "totopT_do",0,0,1,0.45);
   totopT_do->Draw();
   totopT_do->cd();
   totopT_do->Range(0.7629344,0.424212,2.738481,1.125258);
   totopT_do->SetFillColor(0);
   totopT_do->SetBorderMode(0);
   totopT_do->SetBorderSize(0);
   totopT_do->SetLogx();
   totopT_do->SetTickx(1);
   totopT_do->SetTicky(1);
   totopT_do->SetLeftMargin(0.12);
   totopT_do->SetRightMargin(0.02);
   totopT_do->SetTopMargin(0.0075);
   totopT_do->SetBottomMargin(0.2222222);
   totopT_do->SetFrameFillStyle(0);
   totopT_do->SetFrameBorderMode(0);
   totopT_do->SetFrameFillStyle(0);
   totopT_do->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1001[2] = {
   0.722,
   1.972};
   Double_t Graph0_fy1001[2] = {
   0.6868132,
   0.7440476};
   Double_t Graph0_fex1001[2] = {
   0.722,
   0.528};
   Double_t Graph0_fey1001[2] = {
   0.00806824,
   0.007514527};
   TGraphErrors *gre = new TGraphErrors(2,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
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
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,10,500);
   Graph_Graph1001->SetMinimum(0.58);
   Graph_Graph1001->SetMaximum(1.12);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->SetLineStyle(0);
   Graph_Graph1001->SetMarkerStyle(20);
   Graph_Graph1001->GetXaxis()->SetTitle("p_{T}  [GeV]");
   Graph_Graph1001->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1001->GetXaxis()->SetNoExponent();
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1002[2] = {
   0.722,
   1.972};
   Double_t Graph1_fy1002[2] = {
   0.6944444,
   0.7716049};
   Double_t Graph1_fex1002[2] = {
   0.722,
   0.528};
   Double_t Graph1_fey1002[2] = {
   0.003257263,
   0.009450205};
   gre = new TGraphErrors(2,Graph1_fx1002,Graph1_fy1002,Graph1_fex1002,Graph1_fey1002);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,10,500);
   Graph_Graph1002->SetMinimum(0.58);
   Graph_Graph1002->SetMaximum(1.12);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);
   Graph_Graph1002->SetLineStyle(0);
   Graph_Graph1002->SetMarkerStyle(20);
   Graph_Graph1002->GetXaxis()->SetTitle("p_{T}  [GeV]");
   Graph_Graph1002->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1002->GetXaxis()->SetNoExponent();
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("p");
   
   Double_t Graph2_fx1003[2] = {
   0.722,
   1.972};
   Double_t Graph2_fy1003[2] = {
   0.7032349,
   0.7949126};
   Double_t Graph2_fex1003[2] = {
   0.722,
   0.528};
   Double_t Graph2_fey1003[2] = {
   0.006049472,
   0.002513785};
   gre = new TGraphErrors(2,Graph2_fx1003,Graph2_fy1003,Graph2_fex1003,Graph2_fey1003);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#993333");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#993333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,10,500);
   Graph_Graph1003->SetMinimum(0.58);
   Graph_Graph1003->SetMaximum(1.12);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);
   Graph_Graph1003->SetLineStyle(0);
   Graph_Graph1003->SetMarkerStyle(20);
   Graph_Graph1003->GetXaxis()->SetTitle("p_{T}  [GeV]");
   Graph_Graph1003->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1003->GetXaxis()->SetNoExponent();
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   gre->Draw("p");
   
   Double_t Graph3_fx1004[2] = {
   0.722,
   1.972};
   Double_t Graph3_fy1004[2] = {
   0.7122507,
   0.8169935};
   Double_t Graph3_fex1004[2] = {
   0.722,
   0.528};
   Double_t Graph3_fey1004[2] = {
   0.00225238,
   0.002001284};
   gre = new TGraphErrors(2,Graph3_fx1004,Graph3_fy1004,Graph3_fex1004,Graph3_fey1004);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0066cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,10,500);
   Graph_Graph1004->SetMinimum(0.58);
   Graph_Graph1004->SetMaximum(1.12);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);
   Graph_Graph1004->SetLineStyle(0);
   Graph_Graph1004->SetMarkerStyle(20);
   Graph_Graph1004->GetXaxis()->SetTitle("p_{T}  [GeV]");
   Graph_Graph1004->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1004->GetXaxis()->SetNoExponent();
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   gre->Draw("p");
   
   Double_t Graph4_fx1005[2] = {
   0.722,
   1.972};
   Double_t Graph4_fy1005[2] = {
   0.7267442,
   0.8665511};
   Double_t Graph4_fex1005[2] = {
   0.722,
   0.528};
   Double_t Graph4_fey1005[2] = {
   0.007894476,
   0.002122679};
   gre = new TGraphErrors(2,Graph4_fx1005,Graph4_fy1005,Graph4_fex1005,Graph4_fey1005);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0033cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0033cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,10,500);
   Graph_Graph1005->SetMinimum(0.58);
   Graph_Graph1005->SetMaximum(1.12);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);
   Graph_Graph1005->SetLineStyle(0);
   Graph_Graph1005->SetMarkerStyle(20);
   Graph_Graph1005->GetXaxis()->SetTitle("p_{T}  [GeV]");
   Graph_Graph1005->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1005->GetXaxis()->SetNoExponent();
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   gre->Draw("p");
   
   Double_t Graph5_fx1006[2] = {
   0.722,
   1.972};
   Double_t Graph5_fy1006[2] = {
   0.9325236,
   0.9913917};
   Double_t Graph5_fex1006[2] = {
   0.722,
   0.528};
   Double_t Graph5_fey1006[2] = {
   0.00437299,
   0.004649047};
   gre = new TGraphErrors(2,Graph5_fx1006,Graph5_fy1006,Graph5_fex1006,Graph5_fey1006);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1006 = new TH1F("Graph_Graph1006","Graph",100,10,500);
   Graph_Graph1006->SetMinimum(0.58);
   Graph_Graph1006->SetMaximum(1.12);
   Graph_Graph1006->SetDirectory(0);
   Graph_Graph1006->SetStats(0);
   Graph_Graph1006->SetLineStyle(0);
   Graph_Graph1006->SetMarkerStyle(20);
   Graph_Graph1006->GetXaxis()->SetTitle("p_{T}  [GeV]");
   Graph_Graph1006->GetXaxis()->SetMoreLogLabels();
   Graph_Graph1006->GetXaxis()->SetNoExponent();
   Graph_Graph1006->GetXaxis()->SetLabelFont(42);
   Graph_Graph1006->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1006->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1006->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1006->GetXaxis()->SetTitleFont(42);
   Graph_Graph1006->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1006->GetYaxis()->SetLabelFont(42);
   Graph_Graph1006->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1006->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1006->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1006->GetYaxis()->SetTitleFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelFont(42);
   Graph_Graph1006->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1006->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1006->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1006->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1006);
   
   gre->Draw("p");
   TLine *line = new TLine(10,1,500,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   totopT_do->Modified();
   totopT->cd();
  
// ------------>Primitives in pad: totopT_up
   TPad *totopT_up = new TPad("totopT_up", "totopT_up",0,0.45,1,1);
   totopT_up->Draw();
   totopT_up->cd();
   totopT_up->Range(0.7629344,0.4767227,2.738481,0.9136975);
   totopT_up->SetFillColor(0);
   totopT_up->SetBorderMode(0);
   totopT_up->SetBorderSize(0);
   totopT_up->SetLogx();
   totopT_up->SetTickx(1);
   totopT_up->SetTicky(1);
   totopT_up->SetLeftMargin(0.12);
   totopT_up->SetRightMargin(0.02);
   totopT_up->SetBottomMargin(0.0075);
   totopT_up->SetFrameFillStyle(0);
   totopT_up->SetFrameBorderMode(0);
   totopT_up->SetFrameFillStyle(0);
   totopT_up->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1007[2] = {
   0.722,
   1.972};
   Double_t Graph0_fy1007[2] = {
   0.5,
   0.5};
   Double_t Graph0_fex1007[2] = {
   0.722,
   0.528};
   Double_t Graph0_fey1007[2] = {
   0.005873679,
   0.005049762};
   gre = new TGraphErrors(2,Graph0_fx1007,Graph0_fy1007,Graph0_fex1007,Graph0_fey1007);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#999999");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","Graph",100,10,500);
   Graph_Graph1007->SetMinimum(0.48);
   Graph_Graph1007->SetMaximum(0.87);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);
   Graph_Graph1007->SetLineStyle(0);
   Graph_Graph1007->SetMarkerStyle(20);
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1007->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1008[2] = {
   0.722,
   1.972};
   Double_t Graph1_fy1008[2] = {
   0.5,
   0.5};
   Double_t Graph1_fex1008[2] = {
   0.722,
   0.528};
   Double_t Graph1_fey1008[2] = {
   0.002345229,
   0.006123733};
   gre = new TGraphErrors(2,Graph1_fx1008,Graph1_fy1008,Graph1_fex1008,Graph1_fey1008);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1008 = new TH1F("Graph_Graph1008","Graph",100,10,500);
   Graph_Graph1008->SetMinimum(0.48);
   Graph_Graph1008->SetMaximum(0.87);
   Graph_Graph1008->SetDirectory(0);
   Graph_Graph1008->SetStats(0);
   Graph_Graph1008->SetLineStyle(0);
   Graph_Graph1008->SetMarkerStyle(20);
   Graph_Graph1008->GetXaxis()->SetLabelFont(42);
   Graph_Graph1008->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1008->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1008->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1008->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1008->GetXaxis()->SetTitleFont(42);
   Graph_Graph1008->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1008->GetYaxis()->SetLabelFont(42);
   Graph_Graph1008->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1008->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1008->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1008->GetYaxis()->SetTitleFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelFont(42);
   Graph_Graph1008->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1008->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1008->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1008->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1008);
   
   gre->Draw("p");
   
   Double_t Graph2_fx1009[2] = {
   0.722,
   1.972};
   Double_t Graph2_fy1009[2] = {
   0.5,
   0.5};
   Double_t Graph2_fex1009[2] = {
   0.722,
   0.528};
   Double_t Graph2_fey1009[2] = {
   0.004301174,
   0.00158117};
   gre = new TGraphErrors(2,Graph2_fx1009,Graph2_fy1009,Graph2_fex1009,Graph2_fey1009);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#993333");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#993333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1009 = new TH1F("Graph_Graph1009","Graph",100,10,500);
   Graph_Graph1009->SetMinimum(0.48);
   Graph_Graph1009->SetMaximum(0.87);
   Graph_Graph1009->SetDirectory(0);
   Graph_Graph1009->SetStats(0);
   Graph_Graph1009->SetLineStyle(0);
   Graph_Graph1009->SetMarkerStyle(20);
   Graph_Graph1009->GetXaxis()->SetLabelFont(42);
   Graph_Graph1009->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1009->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1009->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1009->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1009->GetXaxis()->SetTitleFont(42);
   Graph_Graph1009->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1009->GetYaxis()->SetLabelFont(42);
   Graph_Graph1009->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1009->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1009->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1009->GetYaxis()->SetTitleFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelFont(42);
   Graph_Graph1009->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1009->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1009->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1009->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1009);
   
   gre->Draw("p");
   
   Double_t Graph3_fx1010[2] = {
   0.722,
   1.972};
   Double_t Graph3_fy1010[2] = {
   0.5,
   0.5};
   Double_t Graph3_fex1010[2] = {
   0.722,
   0.528};
   Double_t Graph3_fey1010[2] = {
   0.00158117,
   0.001224786};
   gre = new TGraphErrors(2,Graph3_fx1010,Graph3_fy1010,Graph3_fex1010,Graph3_fey1010);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0066cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1010 = new TH1F("Graph_Graph1010","Graph",100,10,500);
   Graph_Graph1010->SetMinimum(0.48);
   Graph_Graph1010->SetMaximum(0.87);
   Graph_Graph1010->SetDirectory(0);
   Graph_Graph1010->SetStats(0);
   Graph_Graph1010->SetLineStyle(0);
   Graph_Graph1010->SetMarkerStyle(20);
   Graph_Graph1010->GetXaxis()->SetLabelFont(42);
   Graph_Graph1010->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1010->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1010->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1010->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1010->GetXaxis()->SetTitleFont(42);
   Graph_Graph1010->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1010->GetYaxis()->SetLabelFont(42);
   Graph_Graph1010->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1010->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1010->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1010->GetYaxis()->SetTitleFont(42);
   Graph_Graph1010->GetZaxis()->SetLabelFont(42);
   Graph_Graph1010->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1010->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1010->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1010);
   
   gre->Draw("p");
   
   Double_t Graph4_fx1011[2] = {
   0.722,
   1.972};
   Double_t Graph4_fy1011[2] = {
   0.5,
   0.5};
   Double_t Graph4_fex1011[2] = {
   0.722,
   0.528};
   Double_t Graph4_fey1011[2] = {
   0.005431399,
   0.001224786};
   gre = new TGraphErrors(2,Graph4_fx1011,Graph4_fy1011,Graph4_fex1011,Graph4_fey1011);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0033cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0033cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1011 = new TH1F("Graph_Graph1011","Graph",100,10,500);
   Graph_Graph1011->SetMinimum(0.48);
   Graph_Graph1011->SetMaximum(0.87);
   Graph_Graph1011->SetDirectory(0);
   Graph_Graph1011->SetStats(0);
   Graph_Graph1011->SetLineStyle(0);
   Graph_Graph1011->SetMarkerStyle(20);
   Graph_Graph1011->GetXaxis()->SetLabelFont(42);
   Graph_Graph1011->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1011->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1011->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1011->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1011->GetXaxis()->SetTitleFont(42);
   Graph_Graph1011->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1011->GetYaxis()->SetLabelFont(42);
   Graph_Graph1011->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1011->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1011->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1011->GetYaxis()->SetTitleFont(42);
   Graph_Graph1011->GetZaxis()->SetLabelFont(42);
   Graph_Graph1011->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1011->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1011->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1011->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1011);
   
   gre->Draw("p");
   
   Double_t Graph5_fx1012[2] = {
   0.722,
   1.972};
   Double_t Graph5_fy1012[2] = {
   0.691,
   0.691};
   Double_t Graph5_fex1012[2] = {
   0.722,
   0.528};
   Double_t Graph5_fey1012[2] = {
   0.003240386,
   0.003240386};
   gre = new TGraphErrors(2,Graph5_fx1012,Graph5_fy1012,Graph5_fex1012,Graph5_fey1012);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1012 = new TH1F("Graph_Graph1012","Graph",100,10,500);
   Graph_Graph1012->SetMinimum(0.48);
   Graph_Graph1012->SetMaximum(0.87);
   Graph_Graph1012->SetDirectory(0);
   Graph_Graph1012->SetStats(0);
   Graph_Graph1012->SetLineStyle(0);
   Graph_Graph1012->SetMarkerStyle(20);
   Graph_Graph1012->GetXaxis()->SetLabelFont(42);
   Graph_Graph1012->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1012->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1012->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1012->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1012->GetXaxis()->SetTitleFont(42);
   Graph_Graph1012->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1012->GetYaxis()->SetLabelFont(42);
   Graph_Graph1012->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1012->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1012->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1012->GetYaxis()->SetTitleFont(42);
   Graph_Graph1012->GetZaxis()->SetLabelFont(42);
   Graph_Graph1012->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1012->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1012->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1012->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1012);
   
   gre->Draw("p");
   totopT_up->Modified();
   totopT->cd();
   
   TLegend *leg = new TLegend(0.5,0.8,0.95,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph5","0.000 #leq | #eta | #leq  20.000","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","20.000 #leq | #eta | #leq  30.000","PL");

   ci = TColor::GetColor("#999999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","30.000 #leq | #eta | #leq  40.000","PL");

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2","40.000 #leq | #eta | #leq  50.000","PL");

   ci = TColor::GetColor("#993333");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#993333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph3","50.000 #leq | #eta | #leq  60.000","PL");

   ci = TColor::GetColor("#0066cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0066cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph4","60.000 #leq | #eta | #leq  100.000","PL");

   ci = TColor::GetColor("#0033cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0033cc");
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
   totopT->Modified();
   totopT->cd();
   totopT->SetSelected(totopT);
}
