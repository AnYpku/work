void 120_200_endcap_eta()
{
//=========Macro generated from canvas: h_1/eta
//=========  (Thu Oct 24 10:54:34 2019) by ROOT version6.10/08
   TCanvas *h_1 = new TCanvas("h_1", "eta",0,45,900,600);
   gStyle->SetOptStat(0);
   h_1->Range(0,0,1,1);
   h_1->SetFillColor(0);
   h_1->SetBorderMode(0);
   h_1->SetBorderSize(2);
   h_1->SetGridx();
   h_1->SetGridy();
   h_1->SetTickx(1);
   h_1->SetTicky(1);
   h_1->SetLeftMargin(0.14);
   h_1->SetRightMargin(0.05);
   h_1->SetBottomMargin(0.3);
   h_1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: eta_top
   TPad *eta_top = new TPad("eta_top", "top_pad",0,0.35,1,1);
   eta_top->Draw();
   eta_top->cd();
   eta_top->Range(-0.4320988,-0.002950982,2.654321,0.5872455);
   eta_top->SetFillColor(0);
   eta_top->SetBorderMode(0);
   eta_top->SetBorderSize(2);
   eta_top->SetGridx();
   eta_top->SetGridy();
   eta_top->SetTickx(1);
   eta_top->SetTicky(1);
   eta_top->SetLeftMargin(0.14);
   eta_top->SetRightMargin(0.05);
   eta_top->SetBottomMargin(0.005);
   eta_top->SetFrameBorderMode(0);
   eta_top->SetFrameBorderMode(0);
   Double_t xAxis10[7] = {0, 0.5, 1, 1.4442, 1.566, 2, 2.5}; 
   
   TH1D *heta_eghlt__85 = new TH1D("heta_eghlt__85","L1 Seed, Z mass with 120_200 in the endcap region",6, xAxis10);
   heta_eghlt__85->SetBinContent(0,1.315351);
   heta_eghlt__85->SetBinContent(4,0.003773767);
   heta_eghlt__85->SetBinContent(5,0.493154);
   heta_eghlt__85->SetBinContent(6,0.5030722);
   heta_eghlt__85->SetBinContent(7,0.002322318);
   heta_eghlt__85->SetBinError(0,0.007977397);
   heta_eghlt__85->SetBinError(4,0.000427295);
   heta_eghlt__85->SetBinError(5,0.004884629);
   heta_eghlt__85->SetBinError(6,0.004933504);
   heta_eghlt__85->SetBinError(7,0.0003351978);
   heta_eghlt__85->SetEntries(47904);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   heta_eghlt__85->SetLineColor(ci);
   heta_eghlt__85->SetLineStyle(5);
   heta_eghlt__85->SetLineWidth(4);
   heta_eghlt__85->GetXaxis()->SetLabelFont(42);
   heta_eghlt__85->GetXaxis()->SetLabelSize(0.035);
   heta_eghlt__85->GetXaxis()->SetTitleSize(0.035);
   heta_eghlt__85->GetXaxis()->SetTitleFont(42);
   heta_eghlt__85->GetYaxis()->SetLabelFont(42);
   heta_eghlt__85->GetYaxis()->SetLabelSize(0.035);
   heta_eghlt__85->GetYaxis()->SetTitleSize(0.035);
   heta_eghlt__85->GetYaxis()->SetTitleOffset(0);
   heta_eghlt__85->GetYaxis()->SetTitleFont(42);
   heta_eghlt__85->GetZaxis()->SetLabelFont(42);
   heta_eghlt__85->GetZaxis()->SetLabelSize(0.035);
   heta_eghlt__85->GetZaxis()->SetTitleSize(0.035);
   heta_eghlt__85->GetZaxis()->SetTitleFont(42);
   heta_eghlt__85->Draw("hist");
   Double_t xAxis11[7] = {0, 0.5, 1, 1.4442, 1.566, 2, 2.5}; 
   
   TH1D *hdetEta_ele__86 = new TH1D("hdetEta_ele__86","eta	120_200_endcap",6, xAxis11);
   hdetEta_ele__86->SetBinContent(0,1.036013);
   hdetEta_ele__86->SetBinContent(1,0.001065462);
   hdetEta_ele__86->SetBinContent(2,0.001363791);
   hdetEta_ele__86->SetBinContent(3,0.00196045);
   hdetEta_ele__86->SetBinContent(4,0.004304466);
   hdetEta_ele__86->SetBinContent(5,0.4835066);
   hdetEta_ele__86->SetBinContent(6,0.5077992);
   hdetEta_ele__86->SetBinContent(7,0.005583021);
   hdetEta_ele__86->SetBinError(0,0.006644794);
   hdetEta_ele__86->SetBinError(1,0.0002130924);
   hdetEta_ele__86->SetBinError(2,0.0002410865);
   hdetEta_ele__86->SetBinError(3,0.0002890526);
   hdetEta_ele__86->SetBinError(4,0.0004283104);
   hdetEta_ele__86->SetBinError(5,0.004539418);
   hdetEta_ele__86->SetBinError(6,0.004652056);
   hdetEta_ele__86->SetBinError(7,0.0004877908);
   hdetEta_ele__86->SetEntries(47904);

   ci = TColor::GetColor("#66ccff");
   hdetEta_ele__86->SetLineColor(ci);
   hdetEta_ele__86->SetLineWidth(3);
   hdetEta_ele__86->GetXaxis()->SetLabelFont(42);
   hdetEta_ele__86->GetXaxis()->SetLabelSize(0.035);
   hdetEta_ele__86->GetXaxis()->SetTitleSize(0.035);
   hdetEta_ele__86->GetXaxis()->SetTitleFont(42);
   hdetEta_ele__86->GetYaxis()->SetLabelFont(42);
   hdetEta_ele__86->GetYaxis()->SetLabelSize(0.035);
   hdetEta_ele__86->GetYaxis()->SetTitleSize(0.035);
   hdetEta_ele__86->GetYaxis()->SetTitleOffset(0);
   hdetEta_ele__86->GetYaxis()->SetTitleFont(42);
   hdetEta_ele__86->GetZaxis()->SetLabelFont(42);
   hdetEta_ele__86->GetZaxis()->SetLabelSize(0.035);
   hdetEta_ele__86->GetZaxis()->SetTitleSize(0.035);
   hdetEta_ele__86->GetZaxis()->SetTitleFont(42);
   hdetEta_ele__86->Draw("hist same");
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.08);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hdetEta_ele","reco ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66ccff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("heta_eghlt","HLT ele","lpf");
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
   eta_top->Modified();
   h_1->cd();
  
// ------------>Primitives in pad: eta_bottom
   TPad *eta_bottom = new TPad("eta_bottom", "bottom_pad",0,0.1,1,0.35);
   eta_bottom->Draw();
   eta_bottom->cd();
   eta_bottom->Range(-0.4320988,0.07142855,2.654321,1.5);
   eta_bottom->SetFillColor(0);
   eta_bottom->SetBorderMode(0);
   eta_bottom->SetBorderSize(2);
   eta_bottom->SetGridx();
   eta_bottom->SetGridy();
   eta_bottom->SetTickx(1);
   eta_bottom->SetTicky(1);
   eta_bottom->SetLeftMargin(0.14);
   eta_bottom->SetRightMargin(0.05);
   eta_bottom->SetTopMargin(0);
   eta_bottom->SetBottomMargin(0.3);
   eta_bottom->SetFrameBorderMode(0);
   eta_bottom->SetFrameBorderMode(0);
   Double_t xAxis12[7] = {0, 0.5, 1, 1.4442, 1.566, 2, 2.5}; 
   
   TH1D *heta_eghlt__87 = new TH1D("heta_eghlt__87","",6, xAxis12);
   heta_eghlt__87->SetBinContent(0,1.269629);
   heta_eghlt__87->SetBinContent(4,0.8767097);
   heta_eghlt__87->SetBinContent(5,1.019953);
   heta_eghlt__87->SetBinContent(6,0.9906913);
   heta_eghlt__87->SetBinContent(7,0.4159609);
   heta_eghlt__87->SetBinError(0,0.01120726);
   heta_eghlt__87->SetBinError(4,0.1321522);
   heta_eghlt__87->SetBinError(5,0.01391969);
   heta_eghlt__87->SetBinError(6,0.01329522);
   heta_eghlt__87->SetBinError(7,0.07018152);
   heta_eghlt__87->SetMinimum(0.5);
   heta_eghlt__87->SetMaximum(1.5);
   heta_eghlt__87->SetEntries(467.4485);
   heta_eghlt__87->SetMarkerStyle(20);
   heta_eghlt__87->GetXaxis()->SetTitle("eta");
   heta_eghlt__87->GetXaxis()->CenterTitle(true);
   heta_eghlt__87->GetXaxis()->SetLabelFont(42);
   heta_eghlt__87->GetXaxis()->SetLabelSize(0.12);
   heta_eghlt__87->GetXaxis()->SetTitleSize(0.3);
   heta_eghlt__87->GetXaxis()->SetTitleOffset(0.4);
   heta_eghlt__87->GetXaxis()->SetTitleFont(42);
   heta_eghlt__87->GetYaxis()->SetTitle("HLT/Reco");
   heta_eghlt__87->GetYaxis()->CenterTitle(true);
   heta_eghlt__87->GetYaxis()->SetLabelFont(42);
   heta_eghlt__87->GetYaxis()->SetLabelSize(0.1);
   heta_eghlt__87->GetYaxis()->SetTitleSize(0.15);
   heta_eghlt__87->GetYaxis()->SetTitleOffset(0.22);
   heta_eghlt__87->GetYaxis()->SetTitleFont(42);
   heta_eghlt__87->GetZaxis()->SetLabelFont(42);
   heta_eghlt__87->GetZaxis()->SetLabelSize(0.035);
   heta_eghlt__87->GetZaxis()->SetTitleSize(0.035);
   heta_eghlt__87->GetZaxis()->SetTitleFont(42);
   heta_eghlt__87->Draw("EP");
   TLine *line = new TLine(0,1,2.5,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   eta_bottom->Modified();
   h_1->cd();
   h_1->Modified();
   h_1->cd();
   h_1->SetSelected(h_1);
}
