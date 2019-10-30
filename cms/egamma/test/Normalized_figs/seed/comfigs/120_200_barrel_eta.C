void 120_200_barrel_eta()
{
//=========Macro generated from canvas: h_1/eta
//=========  (Thu Oct 24 10:54:30 2019) by ROOT version6.10/08
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
   eta_top->Range(-0.4320988,-0.002111288,2.654321,0.4201464);
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
   Double_t xAxis4[7] = {0, 0.5, 1, 1.4442, 1.566, 2, 2.5}; 
   
   TH1D *heta_eghlt__31 = new TH1D("heta_eghlt__31","L1 Seed, Z mass with 120_200 in the barrel region",6, xAxis4);
   heta_eghlt__31->SetBinContent(0,1.341319);
   heta_eghlt__31->SetBinContent(1,0.3599244);
   heta_eghlt__31->SetBinContent(2,0.3497298);
   heta_eghlt__31->SetBinContent(3,0.2868855);
   heta_eghlt__31->SetBinContent(4,0.0034603);
   heta_eghlt__31->SetBinError(0,0.005975182);
   heta_eghlt__31->SetBinError(1,0.003095215);
   heta_eghlt__31->SetBinError(2,0.003051065);
   heta_eghlt__31->SetBinError(3,0.002763373);
   heta_eghlt__31->SetBinError(4,0.0003034884);
   heta_eghlt__31->SetEntries(87961);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   heta_eghlt__31->SetLineColor(ci);
   heta_eghlt__31->SetLineStyle(5);
   heta_eghlt__31->SetLineWidth(4);
   heta_eghlt__31->GetXaxis()->SetLabelFont(42);
   heta_eghlt__31->GetXaxis()->SetLabelSize(0.035);
   heta_eghlt__31->GetXaxis()->SetTitleSize(0.035);
   heta_eghlt__31->GetXaxis()->SetTitleFont(42);
   heta_eghlt__31->GetYaxis()->SetLabelFont(42);
   heta_eghlt__31->GetYaxis()->SetLabelSize(0.035);
   heta_eghlt__31->GetYaxis()->SetTitleSize(0.035);
   heta_eghlt__31->GetYaxis()->SetTitleOffset(0);
   heta_eghlt__31->GetYaxis()->SetTitleFont(42);
   heta_eghlt__31->GetZaxis()->SetLabelFont(42);
   heta_eghlt__31->GetZaxis()->SetLabelSize(0.035);
   heta_eghlt__31->GetZaxis()->SetTitleSize(0.035);
   heta_eghlt__31->GetZaxis()->SetTitleFont(42);
   heta_eghlt__31->Draw("hist");
   Double_t xAxis5[7] = {0, 0.5, 1, 1.4442, 1.566, 2, 2.5}; 
   
   TH1D *hdetEta_ele__32 = new TH1D("hdetEta_ele__32","eta	120_200_barrel",6, xAxis5);
   hdetEta_ele__32->SetBinContent(0,1.016183);
   hdetEta_ele__32->SetBinContent(1,0.3580892);
   hdetEta_ele__32->SetBinContent(2,0.3466969);
   hdetEta_ele__32->SetBinContent(3,0.2885665);
   hdetEta_ele__32->SetBinContent(4,0.004103058);
   hdetEta_ele__32->SetBinContent(5,0.001329482);
   hdetEta_ele__32->SetBinContent(6,0.001214872);
   hdetEta_ele__32->SetBinContent(7,6.876633e-05);
   hdetEta_ele__32->SetBinError(0,0.004826288);
   hdetEta_ele__32->SetBinError(1,0.002864989);
   hdetEta_ele__32->SetBinError(2,0.002819047);
   hdetEta_ele__32->SetBinError(3,0.002571877);
   hdetEta_ele__32->SetBinError(4,0.0003066769);
   hdetEta_ele__32->SetBinError(5,0.0001745696);
   hdetEta_ele__32->SetBinError(6,0.0001668755);
   hdetEta_ele__32->SetBinError(7,3.970226e-05);
   hdetEta_ele__32->SetEntries(87961);

   ci = TColor::GetColor("#66ccff");
   hdetEta_ele__32->SetLineColor(ci);
   hdetEta_ele__32->SetLineWidth(3);
   hdetEta_ele__32->GetXaxis()->SetLabelFont(42);
   hdetEta_ele__32->GetXaxis()->SetLabelSize(0.035);
   hdetEta_ele__32->GetXaxis()->SetTitleSize(0.035);
   hdetEta_ele__32->GetXaxis()->SetTitleFont(42);
   hdetEta_ele__32->GetYaxis()->SetLabelFont(42);
   hdetEta_ele__32->GetYaxis()->SetLabelSize(0.035);
   hdetEta_ele__32->GetYaxis()->SetTitleSize(0.035);
   hdetEta_ele__32->GetYaxis()->SetTitleOffset(0);
   hdetEta_ele__32->GetYaxis()->SetTitleFont(42);
   hdetEta_ele__32->GetZaxis()->SetLabelFont(42);
   hdetEta_ele__32->GetZaxis()->SetLabelSize(0.035);
   hdetEta_ele__32->GetZaxis()->SetTitleSize(0.035);
   hdetEta_ele__32->GetZaxis()->SetTitleFont(42);
   hdetEta_ele__32->Draw("hist same");
   
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
   
   TPaveText *pt = new TPaveText(0.2405568,0.9339967,0.7594432,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("L1 Seed, Z mass with 120_200 in the barrel region");
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
   Double_t xAxis6[7] = {0, 0.5, 1, 1.4442, 1.566, 2, 2.5}; 
   
   TH1D *heta_eghlt__33 = new TH1D("heta_eghlt__33","",6, xAxis6);
   heta_eghlt__33->SetBinContent(0,1.319958);
   heta_eghlt__33->SetBinContent(1,1.005125);
   heta_eghlt__33->SetBinContent(2,1.008748);
   heta_eghlt__33->SetBinContent(3,0.9941747);
   heta_eghlt__33->SetBinContent(4,0.8433466);
   heta_eghlt__33->SetBinError(0,0.008595093);
   heta_eghlt__33->SetBinError(1,0.01180608);
   heta_eghlt__33->SetBinError(2,0.01203014);
   heta_eghlt__33->SetBinError(3,0.01304666);
   heta_eghlt__33->SetBinError(4,0.09718229);
   heta_eghlt__33->SetMinimum(0.5);
   heta_eghlt__33->SetMaximum(1.5);
   heta_eghlt__33->SetEntries(1498.5);
   heta_eghlt__33->SetMarkerStyle(20);
   heta_eghlt__33->GetXaxis()->SetTitle("eta");
   heta_eghlt__33->GetXaxis()->CenterTitle(true);
   heta_eghlt__33->GetXaxis()->SetLabelFont(42);
   heta_eghlt__33->GetXaxis()->SetLabelSize(0.12);
   heta_eghlt__33->GetXaxis()->SetTitleSize(0.3);
   heta_eghlt__33->GetXaxis()->SetTitleOffset(0.4);
   heta_eghlt__33->GetXaxis()->SetTitleFont(42);
   heta_eghlt__33->GetYaxis()->SetTitle("HLT/Reco");
   heta_eghlt__33->GetYaxis()->CenterTitle(true);
   heta_eghlt__33->GetYaxis()->SetLabelFont(42);
   heta_eghlt__33->GetYaxis()->SetLabelSize(0.1);
   heta_eghlt__33->GetYaxis()->SetTitleSize(0.15);
   heta_eghlt__33->GetYaxis()->SetTitleOffset(0.22);
   heta_eghlt__33->GetYaxis()->SetTitleFont(42);
   heta_eghlt__33->GetZaxis()->SetLabelFont(42);
   heta_eghlt__33->GetZaxis()->SetLabelSize(0.035);
   heta_eghlt__33->GetZaxis()->SetTitleSize(0.035);
   heta_eghlt__33->GetZaxis()->SetTitleFont(42);
   heta_eghlt__33->Draw("EP");
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
