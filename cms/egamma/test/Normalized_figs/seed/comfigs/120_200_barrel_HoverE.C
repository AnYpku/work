void 120_200_barrel_HoverE()
{
//=========Macro generated from canvas: h_8/HoverE
//=========  (Thu Oct 24 10:54:31 2019) by ROOT version6.10/08
   TCanvas *h_8 = new TCanvas("h_8", "HoverE",0,45,900,600);
   gStyle->SetOptStat(0);
   h_8->Range(0,0,1,1);
   h_8->SetFillColor(0);
   h_8->SetBorderMode(0);
   h_8->SetBorderSize(2);
   h_8->SetGridx();
   h_8->SetGridy();
   h_8->SetTickx(1);
   h_8->SetTicky(1);
   h_8->SetLeftMargin(0.14);
   h_8->SetRightMargin(0.05);
   h_8->SetBottomMargin(0.3);
   h_8->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: HoverE_top
   TPad *HoverE_top = new TPad("HoverE_top", "top_pad",0,0.35,1,1);
   HoverE_top->Draw();
   HoverE_top->cd();
   HoverE_top->Range(-0.08641975,-0.005865922,0.5308642,1.167318);
   HoverE_top->SetFillColor(0);
   HoverE_top->SetBorderMode(0);
   HoverE_top->SetBorderSize(2);
   HoverE_top->SetGridx();
   HoverE_top->SetGridy();
   HoverE_top->SetTickx(1);
   HoverE_top->SetTicky(1);
   HoverE_top->SetLeftMargin(0.14);
   HoverE_top->SetRightMargin(0.05);
   HoverE_top->SetBottomMargin(0.005);
   HoverE_top->SetFrameBorderMode(0);
   HoverE_top->SetFrameBorderMode(0);
   
   TH1D *hadem_eghlt__52 = new TH1D("hadem_eghlt__52","L1 Seed, Z mass with 120_200 in the barrel region",50,0,0.5);
   hadem_eghlt__52->SetBinContent(0,0.2525281);
   hadem_eghlt__52->SetBinContent(1,1);
   hadem_eghlt__52->SetBinContent(51,0.4949836);
   hadem_eghlt__52->SetBinError(0,0.002239854);
   hadem_eghlt__52->SetBinError(1,0.004457229);
   hadem_eghlt__52->SetBinError(51,0.003135887);
   hadem_eghlt__52->SetEntries(87961);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hadem_eghlt__52->SetLineColor(ci);
   hadem_eghlt__52->SetLineStyle(5);
   hadem_eghlt__52->SetLineWidth(4);
   hadem_eghlt__52->GetXaxis()->SetLabelFont(42);
   hadem_eghlt__52->GetXaxis()->SetLabelSize(0.035);
   hadem_eghlt__52->GetXaxis()->SetTitleSize(0.035);
   hadem_eghlt__52->GetXaxis()->SetTitleFont(42);
   hadem_eghlt__52->GetYaxis()->SetLabelFont(42);
   hadem_eghlt__52->GetYaxis()->SetLabelSize(0.035);
   hadem_eghlt__52->GetYaxis()->SetTitleSize(0.035);
   hadem_eghlt__52->GetYaxis()->SetTitleOffset(0);
   hadem_eghlt__52->GetYaxis()->SetTitleFont(42);
   hadem_eghlt__52->GetZaxis()->SetLabelFont(42);
   hadem_eghlt__52->GetZaxis()->SetLabelSize(0.035);
   hadem_eghlt__52->GetZaxis()->SetTitleSize(0.035);
   hadem_eghlt__52->GetZaxis()->SetTitleFont(42);
   hadem_eghlt__52->Draw("hist");
   
   TH1D *hadem_ele__53 = new TH1D("hadem_ele__53","HoverE	120_200_barrel",50,0,0.5);
   hadem_ele__53->SetBinContent(0,0.006610867);
   hadem_ele__53->SetBinContent(1,0.6897146);
   hadem_ele__53->SetBinContent(2,0.1276185);
   hadem_ele__53->SetBinContent(3,0.06592472);
   hadem_ele__53->SetBinContent(4,0.0360206);
   hadem_ele__53->SetBinContent(5,0.02162616);
   hadem_ele__53->SetBinContent(6,0.01402654);
   hadem_ele__53->SetBinContent(7,0.01000253);
   hadem_ele__53->SetBinContent(8,0.007151234);
   hadem_ele__53->SetBinContent(9,0.005288694);
   hadem_ele__53->SetBinContent(10,0.003817057);
   hadem_ele__53->SetBinContent(11,0.002678838);
   hadem_ele__53->SetBinContent(12,0.002276438);
   hadem_ele__53->SetBinContent(13,0.001920026);
   hadem_ele__53->SetBinContent(14,0.001529122);
   hadem_ele__53->SetBinContent(15,0.001345168);
   hadem_ele__53->SetBinContent(16,0.0009657615);
   hadem_ele__53->SetBinContent(17,0.0009657615);
   hadem_ele__53->SetBinContent(18,0.0007013268);
   hadem_ele__53->SetBinContent(19,0.0007358183);
   hadem_ele__53->SetBinContent(20,0.0006668353);
   hadem_ele__53->SetBinContent(21,0.000505875);
   hadem_ele__53->SetBinContent(22,0.0004598864);
   hadem_ele__53->SetBinContent(23,0.0003794063);
   hadem_ele__53->SetBinContent(24,0.0002989262);
   hadem_ele__53->SetBinContent(25,0.0004368921);
   hadem_ele__53->SetBinContent(26,0.0002414404);
   hadem_ele__53->SetBinContent(27,0.0002069489);
   hadem_ele__53->SetBinContent(28,0.0002299432);
   hadem_ele__53->SetBinContent(29,0.0001839546);
   hadem_ele__53->SetBinContent(30,0.0001609602);
   hadem_ele__53->SetBinContent(31,0.0001379659);
   hadem_ele__53->SetBinContent(32,0.0001149716);
   hadem_ele__53->SetBinContent(33,0.0002759318);
   hadem_ele__53->SetBinContent(34,8.048012e-05);
   hadem_ele__53->SetBinContent(35,0.0001724574);
   hadem_ele__53->SetBinContent(36,0.0001954517);
   hadem_ele__53->SetBinContent(37,0.0001149716);
   hadem_ele__53->SetBinContent(38,8.048012e-05);
   hadem_ele__53->SetBinContent(39,6.898296e-05);
   hadem_ele__53->SetBinContent(40,0.0001149716);
   hadem_ele__53->SetBinContent(41,6.898296e-05);
   hadem_ele__53->SetBinContent(42,6.898296e-05);
   hadem_ele__53->SetBinContent(43,5.74858e-05);
   hadem_ele__53->SetBinContent(44,5.74858e-05);
   hadem_ele__53->SetBinContent(45,3.449148e-05);
   hadem_ele__53->SetBinContent(46,5.74858e-05);
   hadem_ele__53->SetBinContent(47,4.598864e-05);
   hadem_ele__53->SetBinContent(48,1.149716e-05);
   hadem_ele__53->SetBinContent(49,6.898296e-05);
   hadem_ele__53->SetBinContent(50,9.197728e-05);
   hadem_ele__53->SetBinContent(51,0.004690841);
   hadem_ele__53->SetBinError(0,0.0002756922);
   hadem_ele__53->SetBinError(1,0.002815983);
   hadem_ele__53->SetBinError(2,0.001211301);
   hadem_ele__53->SetBinError(3,0.0008706015);
   hadem_ele__53->SetBinError(4,0.0006435329);
   hadem_ele__53->SetBinError(5,0.0004986376);
   hadem_ele__53->SetBinError(6,0.0004015785);
   hadem_ele__53->SetBinError(7,0.0003391175);
   hadem_ele__53->SetBinError(8,0.0002867383);
   hadem_ele__53->SetBinError(9,0.0002465866);
   hadem_ele__53->SetBinError(10,0.0002094882);
   hadem_ele__53->SetBinError(11,0.0001754965);
   hadem_ele__53->SetBinError(12,0.0001617794);
   hadem_ele__53->SetBinError(13,0.0001485761);
   hadem_ele__53->SetBinError(14,0.0001325917);
   hadem_ele__53->SetBinError(15,0.0001243608);
   hadem_ele__53->SetBinError(16,0.0001053732);
   hadem_ele__53->SetBinError(17,0.0001053732);
   hadem_ele__53->SetBinError(18,8.979569e-05);
   hadem_ele__53->SetBinError(19,9.197728e-05);
   hadem_ele__53->SetBinError(20,8.755976e-05);
   hadem_ele__53->SetBinError(21,7.626353e-05);
   hadem_ele__53->SetBinError(22,7.271443e-05);
   hadem_ele__53->SetBinError(23,6.604616e-05);
   hadem_ele__53->SetBinError(24,5.862424e-05);
   hadem_ele__53->SetBinError(25,7.087326e-05);
   hadem_ele__53->SetBinError(26,5.268661e-05);
   hadem_ele__53->SetBinError(27,4.877832e-05);
   hadem_ele__53->SetBinError(28,5.141686e-05);
   hadem_ele__53->SetBinError(29,4.598864e-05);
   hadem_ele__53->SetBinError(30,4.301843e-05);
   hadem_ele__53->SetBinError(31,3.982733e-05);
   hadem_ele__53->SetBinError(32,3.635721e-05);
   hadem_ele__53->SetBinError(33,5.632435e-05);
   hadem_ele__53->SetBinError(34,3.041863e-05);
   hadem_ele__53->SetBinError(35,4.452831e-05);
   hadem_ele__53->SetBinError(36,4.740401e-05);
   hadem_ele__53->SetBinError(37,3.635721e-05);
   hadem_ele__53->SetBinError(38,3.041863e-05);
   hadem_ele__53->SetBinError(39,2.816218e-05);
   hadem_ele__53->SetBinError(40,3.635721e-05);
   hadem_ele__53->SetBinError(41,2.816218e-05);
   hadem_ele__53->SetBinError(42,2.816218e-05);
   hadem_ele__53->SetBinError(43,2.570843e-05);
   hadem_ele__53->SetBinError(44,2.570843e-05);
   hadem_ele__53->SetBinError(45,1.991367e-05);
   hadem_ele__53->SetBinError(46,2.570843e-05);
   hadem_ele__53->SetBinError(47,2.299432e-05);
   hadem_ele__53->SetBinError(48,1.149716e-05);
   hadem_ele__53->SetBinError(49,2.816218e-05);
   hadem_ele__53->SetBinError(50,3.251888e-05);
   hadem_ele__53->SetBinError(51,0.0002322313);
   hadem_ele__53->SetEntries(87961);

   ci = TColor::GetColor("#66ccff");
   hadem_ele__53->SetLineColor(ci);
   hadem_ele__53->SetLineWidth(3);
   hadem_ele__53->GetXaxis()->SetLabelFont(42);
   hadem_ele__53->GetXaxis()->SetLabelSize(0.035);
   hadem_ele__53->GetXaxis()->SetTitleSize(0.035);
   hadem_ele__53->GetXaxis()->SetTitleFont(42);
   hadem_ele__53->GetYaxis()->SetLabelFont(42);
   hadem_ele__53->GetYaxis()->SetLabelSize(0.035);
   hadem_ele__53->GetYaxis()->SetTitleSize(0.035);
   hadem_ele__53->GetYaxis()->SetTitleOffset(0);
   hadem_ele__53->GetYaxis()->SetTitleFont(42);
   hadem_ele__53->GetZaxis()->SetLabelFont(42);
   hadem_ele__53->GetZaxis()->SetLabelSize(0.035);
   hadem_ele__53->GetZaxis()->SetTitleSize(0.035);
   hadem_ele__53->GetZaxis()->SetTitleFont(42);
   hadem_ele__53->Draw("hist same");
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.08);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hadem_ele","reco ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66ccff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hadem_eghlt","HLT ele","lpf");
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
   HoverE_top->Modified();
   h_8->cd();
  
// ------------>Primitives in pad: HoverE_bottom
   TPad *HoverE_bottom = new TPad("HoverE_bottom", "bottom_pad",0,0.1,1,0.35);
   HoverE_bottom->Draw();
   HoverE_bottom->cd();
   HoverE_bottom->Range(-0.08641975,0.07142855,0.5308642,1.5);
   HoverE_bottom->SetFillColor(0);
   HoverE_bottom->SetBorderMode(0);
   HoverE_bottom->SetBorderSize(2);
   HoverE_bottom->SetGridx();
   HoverE_bottom->SetGridy();
   HoverE_bottom->SetTickx(1);
   HoverE_bottom->SetTicky(1);
   HoverE_bottom->SetLeftMargin(0.14);
   HoverE_bottom->SetRightMargin(0.05);
   HoverE_bottom->SetTopMargin(0);
   HoverE_bottom->SetBottomMargin(0.3);
   HoverE_bottom->SetFrameBorderMode(0);
   HoverE_bottom->SetFrameBorderMode(0);
   
   TH1D *hadem_eghlt__54 = new TH1D("hadem_eghlt__54","",50,0,0.5);
   hadem_eghlt__54->SetBinContent(0,38.19893);
   hadem_eghlt__54->SetBinContent(1,1.449875);
   hadem_eghlt__54->SetBinContent(51,105.5213);
   hadem_eghlt__54->SetBinError(0,1.628638);
   hadem_eghlt__54->SetBinError(1,0.008763812);
   hadem_eghlt__54->SetBinError(51,5.266682);
   hadem_eghlt__54->SetMinimum(0.5);
   hadem_eghlt__54->SetMaximum(1.5);
   hadem_eghlt__54->SetEntries(27370.01);
   hadem_eghlt__54->SetMarkerStyle(20);
   hadem_eghlt__54->GetXaxis()->SetTitle("HoverE");
   hadem_eghlt__54->GetXaxis()->CenterTitle(true);
   hadem_eghlt__54->GetXaxis()->SetLabelFont(42);
   hadem_eghlt__54->GetXaxis()->SetLabelSize(0.12);
   hadem_eghlt__54->GetXaxis()->SetTitleSize(0.3);
   hadem_eghlt__54->GetXaxis()->SetTitleOffset(0.4);
   hadem_eghlt__54->GetXaxis()->SetTitleFont(42);
   hadem_eghlt__54->GetYaxis()->SetTitle("HLT/Reco");
   hadem_eghlt__54->GetYaxis()->CenterTitle(true);
   hadem_eghlt__54->GetYaxis()->SetLabelFont(42);
   hadem_eghlt__54->GetYaxis()->SetLabelSize(0.1);
   hadem_eghlt__54->GetYaxis()->SetTitleSize(0.15);
   hadem_eghlt__54->GetYaxis()->SetTitleOffset(0.22);
   hadem_eghlt__54->GetYaxis()->SetTitleFont(42);
   hadem_eghlt__54->GetZaxis()->SetLabelFont(42);
   hadem_eghlt__54->GetZaxis()->SetLabelSize(0.035);
   hadem_eghlt__54->GetZaxis()->SetTitleSize(0.035);
   hadem_eghlt__54->GetZaxis()->SetTitleFont(42);
   hadem_eghlt__54->Draw("EP");
   TLine *line = new TLine(0,1,0.5,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   HoverE_bottom->Modified();
   h_8->cd();
   h_8->Modified();
   h_8->cd();
   h_8->SetSelected(h_8);
}
