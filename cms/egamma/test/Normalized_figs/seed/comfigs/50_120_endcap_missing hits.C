void 50_120_endcap_missing hits()
{
//=========Macro generated from canvas: h_7/missing hits
//=========  (Thu Oct 24 10:54:33 2019) by ROOT version6.10/08
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
   missing hits_top->Range(-1.037037,-0.005409208,6.37037,1.076432);
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
   
   TH1D *hMHits_eghlt__76 = new TH1D("hMHits_eghlt__76"," L1 Seed, Z mass with 50_120 in the endcap region",7,0,6);
   hMHits_eghlt__76->SetBinContent(0,0.4178738);
   hMHits_eghlt__76->SetBinContent(1,0.9221412);
   hMHits_eghlt__76->SetBinContent(2,0.074785);
   hMHits_eghlt__76->SetBinContent(3,0.003073804);
   hMHits_eghlt__76->SetBinContent(8,0.08881332);
   hMHits_eghlt__76->SetBinError(0,0.003696551);
   hMHits_eghlt__76->SetBinError(1,0.005491271);
   hMHits_eghlt__76->SetBinError(2,0.001563801);
   hMHits_eghlt__76->SetBinError(3,0.0003170387);
   hMHits_eghlt__76->SetBinError(8,0.001704171);
   hMHits_eghlt__76->SetEntries(46076);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hMHits_eghlt__76->SetLineColor(ci);
   hMHits_eghlt__76->SetLineStyle(5);
   hMHits_eghlt__76->SetLineWidth(4);
   hMHits_eghlt__76->GetXaxis()->SetTitle("missing hits");
   hMHits_eghlt__76->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__76->GetXaxis()->SetLabelSize(0.035);
   hMHits_eghlt__76->GetXaxis()->SetTitleSize(0.035);
   hMHits_eghlt__76->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__76->GetYaxis()->SetTitle("yields");
   hMHits_eghlt__76->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__76->GetYaxis()->SetLabelSize(0.035);
   hMHits_eghlt__76->GetYaxis()->SetTitleSize(0.035);
   hMHits_eghlt__76->GetYaxis()->SetTitleOffset(0);
   hMHits_eghlt__76->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__76->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__76->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__76->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__76->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__76->Draw("hist");
   
   TH1D *hMHits_ele__77 = new TH1D("hMHits_ele__77","missing hits	50_120_endcap",7,0,6);
   hMHits_ele__77->SetBinContent(0,0.05524001);
   hMHits_ele__77->SetBinContent(1,0.9202776);
   hMHits_ele__77->SetBinContent(2,0.07289758);
   hMHits_ele__77->SetBinContent(3,0.004328509);
   hMHits_ele__77->SetBinContent(4,0.001511543);
   hMHits_ele__77->SetBinContent(5,0.0006641627);
   hMHits_ele__77->SetBinContent(6,0.0003206303);
   hMHits_ele__77->SetBinError(0,0.001124774);
   hMHits_ele__77->SetBinError(1,0.004590898);
   hMHits_ele__77->SetBinError(2,0.001292096);
   hMHits_ele__77->SetBinError(3,0.0003148527);
   hMHits_ele__77->SetBinError(4,0.000186058);
   hMHits_ele__77->SetBinError(5,0.0001233319);
   hMHits_ele__77->SetBinError(6,8.569204e-05);
   hMHits_ele__77->SetEntries(46076);

   ci = TColor::GetColor("#66ccff");
   hMHits_ele__77->SetLineColor(ci);
   hMHits_ele__77->SetLineWidth(3);
   hMHits_ele__77->GetXaxis()->SetLabelFont(42);
   hMHits_ele__77->GetXaxis()->SetLabelSize(0.035);
   hMHits_ele__77->GetXaxis()->SetTitleSize(0.035);
   hMHits_ele__77->GetXaxis()->SetTitleFont(42);
   hMHits_ele__77->GetYaxis()->SetLabelFont(42);
   hMHits_ele__77->GetYaxis()->SetLabelSize(0.035);
   hMHits_ele__77->GetYaxis()->SetTitleSize(0.035);
   hMHits_ele__77->GetYaxis()->SetTitleOffset(0);
   hMHits_ele__77->GetYaxis()->SetTitleFont(42);
   hMHits_ele__77->GetZaxis()->SetLabelFont(42);
   hMHits_ele__77->GetZaxis()->SetLabelSize(0.035);
   hMHits_ele__77->GetZaxis()->SetTitleSize(0.035);
   hMHits_ele__77->GetZaxis()->SetTitleFont(42);
   hMHits_ele__77->Draw("hist same");
   
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
   
   TPaveText *pt = new TPaveText(0.2355457,0.9339967,0.7644543,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText(" L1 Seed, Z mass with 50_120 in the endcap region");
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
   
   TH1D *hMHits_eghlt__78 = new TH1D("hMHits_eghlt__78","",7,0,6);
   hMHits_eghlt__78->SetBinContent(0,7.564695);
   hMHits_eghlt__78->SetBinContent(1,1.002025);
   hMHits_eghlt__78->SetBinContent(2,1.025891);
   hMHits_eghlt__78->SetBinContent(3,0.71013);
   hMHits_eghlt__78->SetBinError(0,0.1679374);
   hMHits_eghlt__78->SetBinError(1,0.007784074);
   hMHits_eghlt__78->SetBinError(2,0.02812183);
   hMHits_eghlt__78->SetBinError(3,0.08962647);
   hMHits_eghlt__78->SetMinimum(0.5);
   hMHits_eghlt__78->SetMaximum(1.5);
   hMHits_eghlt__78->SetEntries(843.8336);
   hMHits_eghlt__78->SetMarkerStyle(20);
   hMHits_eghlt__78->GetXaxis()->SetTitle("missing hits");
   hMHits_eghlt__78->GetXaxis()->CenterTitle(true);
   hMHits_eghlt__78->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__78->GetXaxis()->SetLabelSize(0.12);
   hMHits_eghlt__78->GetXaxis()->SetTitleSize(0.3);
   hMHits_eghlt__78->GetXaxis()->SetTitleOffset(0.4);
   hMHits_eghlt__78->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__78->GetYaxis()->SetTitle("HLT/Reco");
   hMHits_eghlt__78->GetYaxis()->CenterTitle(true);
   hMHits_eghlt__78->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__78->GetYaxis()->SetLabelSize(0.1);
   hMHits_eghlt__78->GetYaxis()->SetTitleSize(0.15);
   hMHits_eghlt__78->GetYaxis()->SetTitleOffset(0.22);
   hMHits_eghlt__78->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__78->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__78->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__78->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__78->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__78->Draw("EP");
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
