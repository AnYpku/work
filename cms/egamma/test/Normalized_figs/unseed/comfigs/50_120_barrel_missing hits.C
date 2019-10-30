void 50_120_barrel_missing hits()
{
//=========Macro generated from canvas: h_7/missing hits
//=========  (Thu Oct 24 10:54:29 2019) by ROOT version6.10/08
   TCanvas *h_7 = new TCanvas("h_7", "missing hits",0,45,900,600);
   gStyle->SetOptStat(0);
   h_7->Range(0,0,1,1);
   h_7->SetFillColor(0);
   h_7->SetBorderMode(0);
   h_7->SetBorderSize(2);
   h_7->SetGridx();
   h_7->SetGridy();
   h_7->SetTickx(1);
   h_7->SetTicky(1);
   h_7->SetLeftMargin(0.14);
   h_7->SetRightMargin(0.05);
   h_7->SetBottomMargin(0.3);
   h_7->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: missing hits_top
   TPad *missing hits_top = new TPad("missing hits_top", "top_pad",0,0.35,1,1);
   missing hits_top->Draw();
   missing hits_top->cd();
   missing hits_top->Range(-1.037037,-0.005408871,6.37037,1.076365);
   missing hits_top->SetFillColor(0);
   missing hits_top->SetBorderMode(0);
   missing hits_top->SetBorderSize(2);
   missing hits_top->SetGridx();
   missing hits_top->SetGridy();
   missing hits_top->SetTickx(1);
   missing hits_top->SetTicky(1);
   missing hits_top->SetLeftMargin(0.14);
   missing hits_top->SetRightMargin(0.05);
   missing hits_top->SetBottomMargin(0.005);
   missing hits_top->SetFrameBorderMode(0);
   missing hits_top->SetFrameBorderMode(0);
   
   TH1D *hMHits_eghlt__22 = new TH1D("hMHits_eghlt__22"," L1 Seed, Z mass with 50_120 in the barrel region",7,0,6);
   hMHits_eghlt__22->SetBinContent(0,0.4832186);
   hMHits_eghlt__22->SetBinContent(1,0.9220837);
   hMHits_eghlt__22->SetBinContent(2,0.07776744);
   hMHits_eghlt__22->SetBinContent(3,0.0001488372);
   hMHits_eghlt__22->SetBinContent(8,0.06874419);
   hMHits_eghlt__22->SetBinError(0,0.002998352);
   hMHits_eghlt__22->SetBinError(1,0.004141865);
   hMHits_eghlt__22->SetBinError(2,0.001202845);
   hMHits_eghlt__22->SetBinError(3,5.26219e-05);
   hMHits_eghlt__22->SetBinError(8,0.001130912);
   hMHits_eghlt__22->SetEntries(83418);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hMHits_eghlt__22->SetLineColor(ci);
   hMHits_eghlt__22->SetLineStyle(5);
   hMHits_eghlt__22->SetLineWidth(4);
   hMHits_eghlt__22->GetXaxis()->SetTitle("missing hits");
   hMHits_eghlt__22->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__22->GetXaxis()->SetLabelSize(0.035);
   hMHits_eghlt__22->GetXaxis()->SetTitleSize(0.035);
   hMHits_eghlt__22->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__22->GetYaxis()->SetTitle("yields");
   hMHits_eghlt__22->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__22->GetYaxis()->SetLabelSize(0.035);
   hMHits_eghlt__22->GetYaxis()->SetTitleSize(0.035);
   hMHits_eghlt__22->GetYaxis()->SetTitleOffset(0);
   hMHits_eghlt__22->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__22->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__22->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__22->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__22->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__22->Draw("hist");
   
   TH1D *hMHits_ele__23 = new TH1D("hMHits_ele__23","missing hits	50_120_barrel",7,0,6);
   hMHits_ele__23->SetBinContent(0,0.06473847);
   hMHits_ele__23->SetBinContent(1,0.9174559);
   hMHits_ele__23->SetBinContent(2,0.07373701);
   hMHits_ele__23->SetBinContent(3,0.005373599);
   hMHits_ele__23->SetBinContent(4,0.002808057);
   hMHits_ele__23->SetBinContent(5,0.0006126669);
   hMHits_ele__23->SetBinContent(6,1.276389e-05);
   hMHits_ele__23->SetBinError(0,0.0009090187);
   hMHits_ele__23->SetBinError(1,0.003422033);
   hMHits_ele__23->SetBinError(2,0.0009701399);
   hMHits_ele__23->SetBinError(3,0.0002618932);
   hMHits_ele__23->SetBinError(4,0.0001893191);
   hMHits_ele__23->SetBinError(5,8.843085e-05);
   hMHits_ele__23->SetBinError(6,1.276389e-05);
   hMHits_ele__23->SetEntries(83418);

   ci = TColor::GetColor("#66ccff");
   hMHits_ele__23->SetLineColor(ci);
   hMHits_ele__23->SetLineWidth(3);
   hMHits_ele__23->GetXaxis()->SetLabelFont(42);
   hMHits_ele__23->GetXaxis()->SetLabelSize(0.035);
   hMHits_ele__23->GetXaxis()->SetTitleSize(0.035);
   hMHits_ele__23->GetXaxis()->SetTitleFont(42);
   hMHits_ele__23->GetYaxis()->SetLabelFont(42);
   hMHits_ele__23->GetYaxis()->SetLabelSize(0.035);
   hMHits_ele__23->GetYaxis()->SetTitleSize(0.035);
   hMHits_ele__23->GetYaxis()->SetTitleOffset(0);
   hMHits_ele__23->GetYaxis()->SetTitleFont(42);
   hMHits_ele__23->GetZaxis()->SetLabelFont(42);
   hMHits_ele__23->GetZaxis()->SetLabelSize(0.035);
   hMHits_ele__23->GetZaxis()->SetTitleSize(0.035);
   hMHits_ele__23->GetZaxis()->SetTitleFont(42);
   hMHits_ele__23->Draw("hist same");
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.08);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hMHits_ele","reco ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66ccff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hMHits_eghlt","HLT ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#3366ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(5);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2433408,0.9339967,0.7566592,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText(" L1 Seed, Z mass with 50_120 in the barrel region");
   pt->Draw();
   missing hits_top->Modified();
   h_7->cd();
  
// ------------>Primitives in pad: missing hits_bottom
   TPad *missing hits_bottom = new TPad("missing hits_bottom", "bottom_pad",0,0.1,1,0.35);
   missing hits_bottom->Draw();
   missing hits_bottom->cd();
   missing hits_bottom->Range(-1.037037,0.07142855,6.37037,1.5);
   missing hits_bottom->SetFillColor(0);
   missing hits_bottom->SetBorderMode(0);
   missing hits_bottom->SetBorderSize(2);
   missing hits_bottom->SetGridx();
   missing hits_bottom->SetGridy();
   missing hits_bottom->SetTickx(1);
   missing hits_bottom->SetTicky(1);
   missing hits_bottom->SetLeftMargin(0.14);
   missing hits_bottom->SetRightMargin(0.05);
   missing hits_bottom->SetTopMargin(0);
   missing hits_bottom->SetBottomMargin(0.3);
   missing hits_bottom->SetFrameBorderMode(0);
   missing hits_bottom->SetFrameBorderMode(0);
   
   TH1D *hMHits_eghlt__24 = new TH1D("hMHits_eghlt__24","",7,0,6);
   hMHits_eghlt__24->SetBinContent(0,7.464165);
   hMHits_eghlt__24->SetBinContent(1,1.005044);
   hMHits_eghlt__24->SetBinContent(2,1.05466);
   hMHits_eghlt__24->SetBinContent(3,0.02769786);
   hMHits_eghlt__24->SetBinError(0,0.1145846);
   hMHits_eghlt__24->SetBinError(1,0.005868031);
   hMHits_eghlt__24->SetBinError(2,0.02141594);
   hMHits_eghlt__24->SetBinError(3,0.009885277);
   hMHits_eghlt__24->SetMinimum(0.5);
   hMHits_eghlt__24->SetMaximum(1.5);
   hMHits_eghlt__24->SetEntries(7375.222);
   hMHits_eghlt__24->SetMarkerStyle(20);
   hMHits_eghlt__24->GetXaxis()->SetTitle("missing hits");
   hMHits_eghlt__24->GetXaxis()->CenterTitle(true);
   hMHits_eghlt__24->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__24->GetXaxis()->SetLabelSize(0.12);
   hMHits_eghlt__24->GetXaxis()->SetTitleSize(0.3);
   hMHits_eghlt__24->GetXaxis()->SetTitleOffset(0.4);
   hMHits_eghlt__24->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__24->GetYaxis()->SetTitle("HLT/Reco");
   hMHits_eghlt__24->GetYaxis()->CenterTitle(true);
   hMHits_eghlt__24->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__24->GetYaxis()->SetLabelSize(0.1);
   hMHits_eghlt__24->GetYaxis()->SetTitleSize(0.15);
   hMHits_eghlt__24->GetYaxis()->SetTitleOffset(0.22);
   hMHits_eghlt__24->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__24->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__24->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__24->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__24->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__24->Draw("EP");
   TLine *line = new TLine(0,1,6,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   missing hits_bottom->Modified();
   h_7->cd();
   h_7->Modified();
   h_7->cd();
   h_7->SetSelected(h_7);
}
