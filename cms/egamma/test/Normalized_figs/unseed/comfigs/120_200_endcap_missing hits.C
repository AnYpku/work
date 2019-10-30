void 120_200_endcap_missing hits()
{
//=========Macro generated from canvas: h_7/missing hits
//=========  (Thu Oct 24 10:54:36 2019) by ROOT version6.10/08
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
   missing hits_top->Range(-1.037037,-0.00542374,6.37037,1.079324);
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
   
   TH1D *hMHits_eghlt__103 = new TH1D("hMHits_eghlt__103","L1 Seed, Z mass with 120_200 in the endcap region",7,0,6);
   hMHits_eghlt__103->SetBinContent(0,0.1564598);
   hMHits_eghlt__103->SetBinContent(1,0.9246185);
   hMHits_eghlt__103->SetBinContent(2,0.07238047);
   hMHits_eghlt__103->SetBinContent(3,0.003001017);
   hMHits_eghlt__103->SetBinContent(8,0.06185148);
   hMHits_eghlt__103->SetBinError(0,0.001994778);
   hMHits_eghlt__103->SetBinError(1,0.00484925);
   hMHits_eghlt__103->SetBinError(2,0.001356763);
   hMHits_eghlt__103->SetBinError(3,0.000276266);
   hMHits_eghlt__103->SetBinError(8,0.001254204);
   hMHits_eghlt__103->SetEntries(47904);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hMHits_eghlt__103->SetLineColor(ci);
   hMHits_eghlt__103->SetLineStyle(5);
   hMHits_eghlt__103->SetLineWidth(4);
   hMHits_eghlt__103->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__103->GetXaxis()->SetLabelSize(0.035);
   hMHits_eghlt__103->GetXaxis()->SetTitleSize(0.035);
   hMHits_eghlt__103->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__103->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__103->GetYaxis()->SetLabelSize(0.035);
   hMHits_eghlt__103->GetYaxis()->SetTitleSize(0.035);
   hMHits_eghlt__103->GetYaxis()->SetTitleOffset(0);
   hMHits_eghlt__103->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__103->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__103->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__103->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__103->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__103->Draw("hist");
   
   TH1D *hMHits_ele__104 = new TH1D("hMHits_ele__104","missing hits	120_200_endcap",7,0,6);
   hMHits_ele__104->SetBinContent(0,0.04694979);
   hMHits_ele__104->SetBinContent(1,0.9218815);
   hMHits_ele__104->SetBinContent(2,0.07237);
   hMHits_ele__104->SetBinContent(3,0.003737623);
   hMHits_ele__104->SetBinContent(4,0.001092872);
   hMHits_ele__104->SetBinContent(5,0.0006994383);
   hMHits_ele__104->SetBinContent(6,0.0002185745);
   hMHits_ele__104->SetBinContent(8,0.0001092872);
   hMHits_ele__104->SetBinError(0,0.001013017);
   hMHits_ele__104->SetBinError(1,0.004488872);
   hMHits_ele__104->SetBinError(2,0.001257706);
   hMHits_ele__104->SetBinError(3,0.0002858232);
   hMHits_ele__104->SetBinError(4,0.0001545555);
   hMHits_ele__104->SetBinError(5,0.0001236444);
   hMHits_ele__104->SetBinError(6,6.911931e-05);
   hMHits_ele__104->SetBinError(8,4.887473e-05);
   hMHits_ele__104->SetEntries(47904);

   ci = TColor::GetColor("#66ccff");
   hMHits_ele__104->SetLineColor(ci);
   hMHits_ele__104->SetLineWidth(3);
   hMHits_ele__104->GetXaxis()->SetLabelFont(42);
   hMHits_ele__104->GetXaxis()->SetLabelSize(0.035);
   hMHits_ele__104->GetXaxis()->SetTitleSize(0.035);
   hMHits_ele__104->GetXaxis()->SetTitleFont(42);
   hMHits_ele__104->GetYaxis()->SetLabelFont(42);
   hMHits_ele__104->GetYaxis()->SetLabelSize(0.035);
   hMHits_ele__104->GetYaxis()->SetTitleSize(0.035);
   hMHits_ele__104->GetYaxis()->SetTitleOffset(0);
   hMHits_ele__104->GetYaxis()->SetTitleFont(42);
   hMHits_ele__104->GetZaxis()->SetLabelFont(42);
   hMHits_ele__104->GetZaxis()->SetLabelSize(0.035);
   hMHits_ele__104->GetZaxis()->SetTitleSize(0.035);
   hMHits_ele__104->GetZaxis()->SetTitleFont(42);
   hMHits_ele__104->Draw("hist same");
   
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
   
   TPaveText *pt = new TPaveText(0.2327617,0.9339967,0.7672383,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("L1 Seed, Z mass with 120_200 in the endcap region");
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
   
   TH1D *hMHits_eghlt__105 = new TH1D("hMHits_eghlt__105","",7,0,6);
   hMHits_eghlt__105->SetBinContent(0,3.332492);
   hMHits_eghlt__105->SetBinContent(1,1.002969);
   hMHits_eghlt__105->SetBinContent(2,1.000145);
   hMHits_eghlt__105->SetBinContent(3,0.8029213);
   hMHits_eghlt__105->SetBinContent(8,565.9534);
   hMHits_eghlt__105->SetBinError(0,0.08351854);
   hMHits_eghlt__105->SetBinError(1,0.00717774);
   hMHits_eghlt__105->SetBinError(2,0.02556527);
   hMHits_eghlt__105->SetBinError(3,0.09609103);
   hMHits_eghlt__105->SetBinError(8,253.3621);
   hMHits_eghlt__105->SetMinimum(0.5);
   hMHits_eghlt__105->SetMaximum(1.5);
   hMHits_eghlt__105->SetEntries(792.2485);
   hMHits_eghlt__105->SetMarkerStyle(20);
   hMHits_eghlt__105->GetXaxis()->SetTitle("missing hits");
   hMHits_eghlt__105->GetXaxis()->CenterTitle(true);
   hMHits_eghlt__105->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__105->GetXaxis()->SetLabelSize(0.12);
   hMHits_eghlt__105->GetXaxis()->SetTitleSize(0.3);
   hMHits_eghlt__105->GetXaxis()->SetTitleOffset(0.4);
   hMHits_eghlt__105->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__105->GetYaxis()->SetTitle("HLT/Reco");
   hMHits_eghlt__105->GetYaxis()->CenterTitle(true);
   hMHits_eghlt__105->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__105->GetYaxis()->SetLabelSize(0.1);
   hMHits_eghlt__105->GetYaxis()->SetTitleSize(0.15);
   hMHits_eghlt__105->GetYaxis()->SetTitleOffset(0.22);
   hMHits_eghlt__105->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__105->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__105->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__105->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__105->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__105->Draw("EP");
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
