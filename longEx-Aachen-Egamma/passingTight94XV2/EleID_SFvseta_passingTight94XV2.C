void EleID_SFvseta_passingTight94XV2()
{
//=========Macro generated from canvas: totoeta/totoeta
//=========  (Thu Sep 19 12:40:27 2019) by ROOT version 6.12/07
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
   totoeta_do->Range(-3.325581,0.5530617,2.72093,1.124284);
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
   
   Double_t Graph0_fx1011[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph0_fy1011[10] = {
   0.9593909,
   0.9455782,
   1.140481,
   0.9384615,
   1.00624,
   0.9585253,
   0.9430052,
   1.007692,
   1.155268,
   0.9974747};
   Double_t Graph0_fex1011[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph0_fey1011[10] = {
   0.03484652,
   0.01903319,
   0.0239227,
   0.01707969,
   0.01886644,
   0.01705346,
   0.01932904,
   0.01860521,
   0.0239227,
   0.03467053};
   TGraphErrors *gre = new TGraphErrors(10,Graph0_fx1011,Graph0_fy1011,Graph0_fex1011,Graph0_fey1011);
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
   
   TH1F *Graph_Graph1011 = new TH1F("Graph_Graph1011","Graph",100,-2.6,2.6);
   Graph_Graph1011->SetMinimum(0.68);
   Graph_Graph1011->SetMaximum(1.12);
   Graph_Graph1011->SetDirectory(0);
   Graph_Graph1011->SetStats(0);
   Graph_Graph1011->SetLineStyle(0);
   Graph_Graph1011->SetMarkerStyle(20);
   Graph_Graph1011->GetXaxis()->SetTitle("SuperCluster #eta");
   Graph_Graph1011->GetXaxis()->SetNoExponent();
   Graph_Graph1011->GetXaxis()->SetLabelFont(42);
   Graph_Graph1011->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1011->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1011->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1011->GetXaxis()->SetTitleFont(42);
   Graph_Graph1011->GetYaxis()->SetTitle("Data / MC ");
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
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1012[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph1_fy1012[10] = {
   1.0053,
   0.9519231,
   1.086438,
   0.9522581,
   1,
   0.9587097,
   0.9583333,
   1.009162,
   1.093611,
   1.02439};
   Double_t Graph1_fex1012[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph1_fey1012[10] = {
   0.009432048,
   0.003945441,
   0.01820684,
   0.002326162,
   0.003816068,
   0.002326162,
   0.00398928,
   0.003816068,
   0.01815274,
   0.009300591};
   gre = new TGraphErrors(10,Graph1_fx1012,Graph1_fy1012,Graph1_fex1012,Graph1_fey1012);
   gre->SetName("Graph1");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1012 = new TH1F("Graph_Graph1012","Graph",100,-2.6,2.6);
   Graph_Graph1012->SetMinimum(0.68);
   Graph_Graph1012->SetMaximum(1.12);
   Graph_Graph1012->SetDirectory(0);
   Graph_Graph1012->SetStats(0);
   Graph_Graph1012->SetLineStyle(0);
   Graph_Graph1012->SetMarkerStyle(20);
   Graph_Graph1012->GetXaxis()->SetTitle("SuperCluster #eta");
   Graph_Graph1012->GetXaxis()->SetNoExponent();
   Graph_Graph1012->GetXaxis()->SetLabelFont(42);
   Graph_Graph1012->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1012->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1012->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1012->GetXaxis()->SetTitleFont(42);
   Graph_Graph1012->GetYaxis()->SetTitle("Data / MC ");
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
   
   Double_t Graph2_fx1013[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph2_fy1013[10] = {
   1.004975,
   0.9555273,
   1.040107,
   0.9541616,
   1.00123,
   0.9588875,
   0.9652062,
   0.997552,
   1.060729,
   1.025559};
   Double_t Graph2_fex1013[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph2_fey1013[10] = {
   0.0137755,
   0.004962039,
   0.02483179,
   0.005536055,
   0.00608825,
   0.005441354,
   0.005032377,
   0.006058442,
   0.02506636,
   0.01326937};
   gre = new TGraphErrors(10,Graph2_fx1013,Graph2_fy1013,Graph2_fex1013,Graph2_fey1013);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#993333");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#993333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1013 = new TH1F("Graph_Graph1013","Graph",100,-2.6,2.6);
   Graph_Graph1013->SetMinimum(0.68);
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
   
   gre->Draw("p");
   
   Double_t Graph3_fx1014[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph3_fy1014[10] = {
   1.0919,
   0.9663963,
   1.009569,
   0.9608063,
   0.9886105,
   0.9828767,
   1,
   1,
   1.034022,
   0.9781022};
   Double_t Graph3_fex1014[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph3_fey1014[10] = {
   0.06792242,
   0.02383194,
   0.03059607,
   0.01451724,
   0.01691258,
   0.01493864,
   0.02457224,
   0.01721106,
   0.03155667,
   0.06205346};
   gre = new TGraphErrors(10,Graph3_fx1014,Graph3_fy1014,Graph3_fex1014,Graph3_fey1014);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0066cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1014 = new TH1F("Graph_Graph1014","Graph",100,-2.6,2.6);
   Graph_Graph1014->SetMinimum(0.68);
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
   
   Double_t Graph4_fx1015[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph4_fy1015[10] = {
   1.091045,
   0.9477778,
   1.098888,
   1.03555,
   0.9785177,
   0.9626068,
   0.9898305,
   1.005537,
   0.9573304,
   0.8848561};
   Double_t Graph4_fex1015[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph4_fey1015[10] = {
   0.2104769,
   0.03752982,
   0.08507524,
   0.03167194,
   0.04400263,
   0.02609332,
   0.03831408,
   0.04823398,
   0.07315397,
   0.1713012};
   gre = new TGraphErrors(10,Graph4_fx1015,Graph4_fy1015,Graph4_fex1015,Graph4_fey1015);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0033cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0033cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1015 = new TH1F("Graph_Graph1015","Graph",100,-2.6,2.6);
   Graph_Graph1015->SetMinimum(0.68);
   Graph_Graph1015->SetMaximum(1.12);
   Graph_Graph1015->SetDirectory(0);
   Graph_Graph1015->SetStats(0);
   Graph_Graph1015->SetLineStyle(0);
   Graph_Graph1015->SetMarkerStyle(20);
   Graph_Graph1015->GetXaxis()->SetTitle("SuperCluster #eta");
   Graph_Graph1015->GetXaxis()->SetNoExponent();
   Graph_Graph1015->GetXaxis()->SetLabelFont(42);
   Graph_Graph1015->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1015->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1015->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1015->GetXaxis()->SetTitleFont(42);
   Graph_Graph1015->GetYaxis()->SetTitle("Data / MC ");
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
   
   gre->Draw("p");
   
   Double_t Graph5_fx1016[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph5_fy1016[10] = {
   1.104265,
   0.9836066,
   1.228916,
   0.9669031,
   0.9912281,
   1.009547,
   1.002755,
   1.015284,
   1.206587,
   1.248848};
   Double_t Graph5_fex1016[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph5_fey1016[10] = {
   0.1048561,
   0.0410348,
   0.04317853,
   0.02182764,
   0.053177,
   0.02203602,
   0.0414827,
   0.05294478,
   0.04305682,
   0.1019569};
   gre = new TGraphErrors(10,Graph5_fx1016,Graph5_fy1016,Graph5_fex1016,Graph5_fey1016);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1016 = new TH1F("Graph_Graph1016","Graph",100,-2.6,2.6);
   Graph_Graph1016->SetMinimum(0.68);
   Graph_Graph1016->SetMaximum(1.12);
   Graph_Graph1016->SetDirectory(0);
   Graph_Graph1016->SetStats(0);
   Graph_Graph1016->SetLineStyle(0);
   Graph_Graph1016->SetMarkerStyle(20);
   Graph_Graph1016->GetXaxis()->SetTitle("SuperCluster #eta");
   Graph_Graph1016->GetXaxis()->SetNoExponent();
   Graph_Graph1016->GetXaxis()->SetLabelFont(42);
   Graph_Graph1016->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1016->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1016->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1016->GetXaxis()->SetTitleFont(42);
   Graph_Graph1016->GetYaxis()->SetTitle("Data / MC ");
   Graph_Graph1016->GetYaxis()->SetLabelFont(42);
   Graph_Graph1016->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1016->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1016->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1016->GetYaxis()->SetTitleFont(42);
   Graph_Graph1016->GetZaxis()->SetLabelFont(42);
   Graph_Graph1016->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1016->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1016->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1016->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1016);
   
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
   totoeta_up->Range(-3.325581,0.17,2.72093,1.503333);
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
   
   Double_t Graph0_fx1017[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph0_fy1017[10] = {
   0.378,
   0.556,
   0.617,
   0.61,
   0.645,
   0.624,
   0.546,
   0.655,
   0.625,
   0.395};
   Double_t Graph0_fex1017[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph0_fey1017[10] = {
   0.01372953,
   0.01119151,
   0.01294218,
   0.0111018,
   0.01209339,
   0.0111018,
   0.01119151,
   0.01209339,
   0.01294218,
   0.01372953};
   gre = new TGraphErrors(10,Graph0_fx1017,Graph0_fy1017,Graph0_fex1017,Graph0_fey1017);
   gre->SetName("Graph0");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#999999");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1017 = new TH1F("Graph_Graph1017","Graph",100,-2.6,2.6);
   Graph_Graph1017->SetMinimum(0.18);
   Graph_Graph1017->SetMaximum(1.37);
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
   
   gre->Draw("ap");
   
   Double_t Graph1_fx1018[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph1_fy1018[10] = {
   0.394,
   0.588,
   0.541,
   0.65,
   0.641,
   0.651,
   0.579,
   0.65,
   0.541,
   0.396};
   Double_t Graph1_fex1018[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph1_fey1018[10] = {
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
   gre = new TGraphErrors(10,Graph1_fx1018,Graph1_fy1018,Graph1_fex1018,Graph1_fey1018);
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
   
   Double_t Graph2_fx1019[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph2_fy1019[10] = {
   0.569,
   0.693,
   0.729,
   0.738,
   0.764,
   0.743,
   0.69,
   0.771,
   0.736,
   0.588};
   Double_t Graph2_fex1019[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph2_fey1019[10] = {
   0.005338539,
   0.002872281,
   0.01221679,
   0.001802776,
   0.002915476,
   0.001802776,
   0.002872281,
   0.002915476,
   0.01221679,
   0.005338539};
   gre = new TGraphErrors(10,Graph2_fx1019,Graph2_fy1019,Graph2_fex1019,Graph2_fey1019);
   gre->SetName("Graph2");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1019 = new TH1F("Graph_Graph1019","Graph",100,-2.6,2.6);
   Graph_Graph1019->SetMinimum(0.18);
   Graph_Graph1019->SetMaximum(1.37);
   Graph_Graph1019->SetDirectory(0);
   Graph_Graph1019->SetStats(0);
   Graph_Graph1019->SetLineStyle(0);
   Graph_Graph1019->SetMarkerStyle(20);
   Graph_Graph1019->GetXaxis()->SetLabelFont(42);
   Graph_Graph1019->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1019->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1019->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1019->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1019->GetXaxis()->SetTitleFont(42);
   Graph_Graph1019->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1019->GetYaxis()->SetLabelFont(42);
   Graph_Graph1019->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1019->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1019->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1019->GetYaxis()->SetTitleFont(42);
   Graph_Graph1019->GetZaxis()->SetLabelFont(42);
   Graph_Graph1019->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1019->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1019->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1019->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1019);
   
   gre->Draw("p");
   
   Double_t Graph3_fx1020[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph3_fy1020[10] = {
   0.566,
   0.728,
   0.671,
   0.775,
   0.764,
   0.775,
   0.72,
   0.764,
   0.673,
   0.574};
   Double_t Graph3_fex1020[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph3_fey1020[10] = {
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
   gre = new TGraphErrors(10,Graph3_fx1020,Graph3_fy1020,Graph3_fex1020,Graph3_fey1020);
   gre->SetName("Graph3");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);
   gre->SetLineStyle(2);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0);
   gre->Draw("ez");
   
   Double_t Graph4_fx1021[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph4_fy1021[10] = {
   0.606,
   0.752,
   0.778,
   0.791,
   0.814,
   0.793,
   0.749,
   0.815,
   0.786,
   0.642};
   Double_t Graph4_fex1021[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph4_fey1021[10] = {
   0.008306624,
   0.003905125,
   0.01857418,
   0.00458939,
   0.004949747,
   0.0045,
   0.003905125,
   0.004949747,
   0.01857418,
   0.008306624};
   gre = new TGraphErrors(10,Graph4_fx1021,Graph4_fy1021,Graph4_fex1021,Graph4_fey1021);
   gre->SetName("Graph4");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#993333");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#993333");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1021 = new TH1F("Graph_Graph1021","Graph",100,-2.6,2.6);
   Graph_Graph1021->SetMinimum(0.18);
   Graph_Graph1021->SetMaximum(1.37);
   Graph_Graph1021->SetDirectory(0);
   Graph_Graph1021->SetStats(0);
   Graph_Graph1021->SetLineStyle(0);
   Graph_Graph1021->SetMarkerStyle(20);
   Graph_Graph1021->GetXaxis()->SetLabelFont(42);
   Graph_Graph1021->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1021->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1021->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1021->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1021->GetXaxis()->SetTitleFont(42);
   Graph_Graph1021->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1021->GetYaxis()->SetLabelFont(42);
   Graph_Graph1021->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1021->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1021->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1021->GetYaxis()->SetTitleFont(42);
   Graph_Graph1021->GetZaxis()->SetLabelFont(42);
   Graph_Graph1021->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1021->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1021->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1021->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1021);
   
   gre->Draw("p");
   
   Double_t Graph5_fx1022[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph5_fy1022[10] = {
   0.603,
   0.787,
   0.748,
   0.829,
   0.813,
   0.827,
   0.776,
   0.817,
   0.741,
   0.626};
   Double_t Graph5_fex1022[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph5_fey1022[10] = {
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
   gre = new TGraphErrors(10,Graph5_fx1022,Graph5_fy1022,Graph5_fex1022,Graph5_fey1022);
   gre->SetName("Graph5");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#993333");
   gre->SetLineColor(ci);
   gre->SetLineStyle(2);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0);
   gre->Draw("ez");
   
   Double_t Graph6_fx1023[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph6_fy1023[10] = {
   0.701,
   0.834,
   0.844,
   0.858,
   0.868,
   0.861,
   0.837,
   0.876,
   0.851,
   0.67};
   Double_t Graph6_fex1023[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph6_fey1023[10] = {
   0.04360619,
   0.02056696,
   0.02557831,
   0.01296389,
   0.01484924,
   0.01308625,
   0.02056696,
   0.01507689,
   0.02597114,
   0.04250662};
   gre = new TGraphErrors(10,Graph6_fx1023,Graph6_fy1023,Graph6_fex1023,Graph6_fey1023);
   gre->SetName("Graph6");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0066cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1023 = new TH1F("Graph_Graph1023","Graph",100,-2.6,2.6);
   Graph_Graph1023->SetMinimum(0.18);
   Graph_Graph1023->SetMaximum(1.37);
   Graph_Graph1023->SetDirectory(0);
   Graph_Graph1023->SetStats(0);
   Graph_Graph1023->SetLineStyle(0);
   Graph_Graph1023->SetMarkerStyle(20);
   Graph_Graph1023->GetXaxis()->SetLabelFont(42);
   Graph_Graph1023->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1023->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1023->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1023->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1023->GetXaxis()->SetTitleFont(42);
   Graph_Graph1023->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1023->GetYaxis()->SetLabelFont(42);
   Graph_Graph1023->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1023->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1023->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1023->GetYaxis()->SetTitleFont(42);
   Graph_Graph1023->GetZaxis()->SetLabelFont(42);
   Graph_Graph1023->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1023->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1023->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1023->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1023);
   
   gre->Draw("p");
   
   Double_t Graph7_fx1024[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph7_fy1024[10] = {
   0.642,
   0.863,
   0.836,
   0.893,
   0.878,
   0.876,
   0.837,
   0.876,
   0.823,
   0.685};
   Double_t Graph7_fex1024[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph7_fey1024[10] = {
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
   gre = new TGraphErrors(10,Graph7_fx1024,Graph7_fy1024,Graph7_fex1024,Graph7_fey1024);
   gre->SetName("Graph7");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0066cc");
   gre->SetLineColor(ci);
   gre->SetLineStyle(2);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0);
   gre->Draw("ez");
   
   Double_t Graph8_fx1025[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph8_fy1025[10] = {
   0.731,
   0.853,
   0.889,
   0.903,
   0.911,
   0.901,
   0.876,
   0.908,
   0.875,
   0.707};
   Double_t Graph8_fex1025[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph8_fey1025[10] = {
   0.1410195,
   0.03377684,
   0.06882587,
   0.02761793,
   0.04096645,
   0.02442335,
   0.03390796,
   0.04355528,
   0.06686273,
   0.1368697};
   gre = new TGraphErrors(10,Graph8_fx1025,Graph8_fy1025,Graph8_fex1025,Graph8_fey1025);
   gre->SetName("Graph8");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0033cc");
   gre->SetLineColor(ci);
   gre->SetLineWidth(2);

   ci = TColor::GetColor("#0033cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1025 = new TH1F("Graph_Graph1025","Graph",100,-2.6,2.6);
   Graph_Graph1025->SetMinimum(0.18);
   Graph_Graph1025->SetMaximum(1.37);
   Graph_Graph1025->SetDirectory(0);
   Graph_Graph1025->SetStats(0);
   Graph_Graph1025->SetLineStyle(0);
   Graph_Graph1025->SetMarkerStyle(20);
   Graph_Graph1025->GetXaxis()->SetLabelFont(42);
   Graph_Graph1025->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1025->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1025->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1025->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1025->GetXaxis()->SetTitleFont(42);
   Graph_Graph1025->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1025->GetYaxis()->SetLabelFont(42);
   Graph_Graph1025->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1025->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1025->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1025->GetYaxis()->SetTitleFont(42);
   Graph_Graph1025->GetZaxis()->SetLabelFont(42);
   Graph_Graph1025->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1025->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1025->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1025->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1025);
   
   gre->Draw("p");
   
   Double_t Graph9_fx1026[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph9_fy1026[10] = {
   0.67,
   0.9,
   0.809,
   0.872,
   0.931,
   0.936,
   0.885,
   0.903,
   0.914,
   0.799};
   Double_t Graph9_fex1026[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph9_fey1026[10] = {
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
   gre = new TGraphErrors(10,Graph9_fx1026,Graph9_fy1026,Graph9_fex1026,Graph9_fey1026);
   gre->SetName("Graph9");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);

   ci = TColor::GetColor("#0033cc");
   gre->SetLineColor(ci);
   gre->SetLineStyle(2);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0);
   gre->Draw("ez");
   
   Double_t Graph10_fx1027[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph10_fy1027[10] = {
   0.233,
   0.36,
   0.408,
   0.409,
   0.452,
   0.423,
   0.364,
   0.465,
   0.403,
   0.271};
   Double_t Graph10_fex1027[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph10_fey1027[10] = {
   0.02212465,
   0.01501874,
   0.01433527,
   0.009233093,
   0.02424871,
   0.009233093,
   0.01505822,
   0.02424871,
   0.01438098,
   0.02212465};
   gre = new TGraphErrors(10,Graph10_fx1027,Graph10_fy1027,Graph10_fex1027,Graph10_fey1027);
   gre->SetName("Graph10");
   gre->SetTitle("Graph");
   gre->SetFillStyle(1000);
   gre->SetLineWidth(2);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1027 = new TH1F("Graph_Graph1027","Graph",100,-2.6,2.6);
   Graph_Graph1027->SetMinimum(0.18);
   Graph_Graph1027->SetMaximum(1.37);
   Graph_Graph1027->SetDirectory(0);
   Graph_Graph1027->SetStats(0);
   Graph_Graph1027->SetLineStyle(0);
   Graph_Graph1027->SetMarkerStyle(20);
   Graph_Graph1027->GetXaxis()->SetLabelFont(42);
   Graph_Graph1027->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1027->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1027->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1027->GetXaxis()->SetTitleOffset(0.9);
   Graph_Graph1027->GetXaxis()->SetTitleFont(42);
   Graph_Graph1027->GetYaxis()->SetTitle("Data efficiency");
   Graph_Graph1027->GetYaxis()->SetLabelFont(42);
   Graph_Graph1027->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1027->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1027->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1027->GetYaxis()->SetTitleFont(42);
   Graph_Graph1027->GetZaxis()->SetLabelFont(42);
   Graph_Graph1027->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1027->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph1027->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1027->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1027);
   
   gre->Draw("p");
   
   Double_t Graph11_fx1028[10] = {
   1.505,
   -1.122,
   2.25,
   -0.4,
   1.783,
   0.4,
   1.122,
   -1.783,
   -2.25,
   -1.505};
   Double_t Graph11_fy1028[10] = {
   0.211,
   0.366,
   0.332,
   0.423,
   0.456,
   0.419,
   0.363,
   0.458,
   0.334,
   0.217};
   Double_t Graph11_fex1028[10] = {
   0.061,
   0.322,
   0.25,
   0.4,
   0.217,
   0.4,
   0.322,
   0.217,
   0.25,
   0.061};
   Double_t Graph11_fey1028[10] = {
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
   gre = new TGraphErrors(10,Graph11_fx1028,Graph11_fy1028,Graph11_fex1028,Graph11_fey1028);
   gre->SetName("Graph11");
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
   TLegendEntry *entry=leg->AddEntry("Graph10"," 10 #leq p_{T} #leq   20 GeV","PL");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0"," 20 #leq p_{T} #leq   35 GeV","PL");

   ci = TColor::GetColor("#999999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#999999");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph2"," 35 #leq p_{T} #leq   50 GeV","PL");

   ci = TColor::GetColor("#cc0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph4"," 50 #leq p_{T} #leq  100 GeV","PL");

   ci = TColor::GetColor("#993333");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#993333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph6","100 #leq p_{T} #leq  200 GeV","PL");

   ci = TColor::GetColor("#0066cc");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0066cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph8","200 #leq p_{T} #leq  500 GeV","PL");

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
   totoeta->Modified();
   totoeta->cd();
   totoeta->SetSelected(totoeta);
}
