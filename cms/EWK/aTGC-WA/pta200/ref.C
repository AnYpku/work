void ref()
{
//=========Macro generated from canvas: c1/cpw
//=========  (Wed Nov 14 15:22:08 2018) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "cpw",0,45,900,600);
   gStyle->SetOptFit(1);
   c1->Range(-89.9249,0.007049261,89.9249,0.1085243);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[16] = {
   -60,
   -20,
   -6,
   -2,
   -1,
   0,
   1,
   2,
   3,
   4,
   6,
   10,
   15,
   20,
   40,
   60};
   Double_t Graph0_fy1[16] = {
   0.0917,
   0.03179,
   0.02507,
   0.02405,
   0.02435,
   0.02407,
   0.02426,
   0.02408,
   0.02449,
   0.02433,
   0.02506,
   0.02591,
   0.02837,
   0.03144,
   0.0537,
   0.09156};
   TGraph *graph = new TGraph(16,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("cpw");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(24);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","cpw",100,-72,72);
   Graph_Graph1->SetMinimum(0.017285);
   Graph_Graph1->SetMaximum(0.098465);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("cpw");
   Graph_Graph1->GetXaxis()->CenterTitle(true);
   Graph_Graph1->GetXaxis()->SetLabelFont(22);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleOffset(0.6);
   Graph_Graph1->GetXaxis()->SetTitleFont(30);
   Graph_Graph1->GetYaxis()->SetTitle("cross section /pb");
   Graph_Graph1->GetYaxis()->CenterTitle(true);
   Graph_Graph1->GetYaxis()->SetLabelFont(22);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0.8);
   Graph_Graph1->GetYaxis()->SetTitleFont(30);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   
   TF1 *pol22 = new TF1("pol2","pol2",-72,72);
   pol22->SetFillColor(19);
   pol22->SetFillStyle(0);
   pol22->SetLineColor(2);
   pol22->SetLineWidth(2);
   pol22->SetLineStyle(2);
   pol22->SetChisquare(4.108837e-07);
   pol22->SetNDF(13);
   pol22->GetXaxis()->SetLabelFont(42);
   pol22->GetXaxis()->SetLabelSize(0.035);
   pol22->GetXaxis()->SetTitleSize(0.035);
   pol22->GetXaxis()->SetTitleFont(42);
   pol22->GetYaxis()->SetLabelFont(42);
   pol22->GetYaxis()->SetLabelSize(0.035);
   pol22->GetYaxis()->SetTitleSize(0.035);
   pol22->GetYaxis()->SetTitleOffset(0);
   pol22->GetYaxis()->SetTitleFont(42);
   pol22->SetParameter(0,0.02416605);
   pol22->SetParError(0,5.073734e-05);
   pol22->SetParLimits(0,0,0);
   pol22->SetParameter(1,-3.369576e-06);
   pol22->SetParError(1,1.806602e-06);
   pol22->SetParLimits(1,0,0);
   pol22->SetParameter(2,1.872167e-05);
   pol22->SetParError(2,3.746517e-08);
   pol22->SetParLimits(2,0,0);
   graph->GetListOfFunctions()->Add(pol22);
   
   TPaveStats *ptstats = new TPaveStats(0.3195991,0.7008696,0.6804009,0.9008696,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 4.109e-07 / 13");
   ptstats_LaTex = ptstats->AddText("p0       = 0.02417 #pm 5.074e-05 ");
   ptstats_LaTex = ptstats->AddText("p1       = -3.37e-06 #pm 1.807e-06 ");
   ptstats_LaTex = ptstats->AddText("p2       = 1.872e-05 #pm 3.747e-08 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   graph->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(graph->GetListOfFunctions());
   graph->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.4588196,0.94,0.5411804,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("cpw");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
