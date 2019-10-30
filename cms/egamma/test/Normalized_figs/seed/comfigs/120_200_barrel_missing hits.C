void 120_200_barrel_missing hits()
{
//=========Macro generated from canvas: h_7/missing hits
//=========  (Thu Oct 24 10:54:31 2019) by ROOT version6.10/08
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
   missing hits_top->Range(-1.037037,-0.005412686,6.37037,1.077124);
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
   
   TH1D *hMHits_eghlt__49 = new TH1D("hMHits_eghlt__49","L1 Seed, Z mass with 120_200 in the barrel region",7,0,6);
   hMHits_eghlt__49->SetBinContent(0,0.1793186);
   hMHits_eghlt__49->SetBinContent(1,0.922734);
   hMHits_eghlt__49->SetBinContent(2,0.07712492);
   hMHits_eghlt__49->SetBinContent(3,0.0001410736);
   hMHits_eghlt__49->SetBinContent(8,0.06157861);
   hMHits_eghlt__49->SetBinError(0,0.001590507);
   hMHits_eghlt__49->SetBinError(1,0.003607955);
   hMHits_eghlt__49->SetBinError(2,0.001043086);
   hMHits_eghlt__49->SetBinError(3,4.461138e-05);
   hMHits_eghlt__49->SetBinError(8,0.0009320469);
   hMHits_eghlt__49->SetEntries(87961);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hMHits_eghlt__49->SetLineColor(ci);
   hMHits_eghlt__49->SetLineStyle(5);
   hMHits_eghlt__49->SetLineWidth(4);
   hMHits_eghlt__49->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__49->GetXaxis()->SetLabelSize(0.035);
   hMHits_eghlt__49->GetXaxis()->SetTitleSize(0.035);
   hMHits_eghlt__49->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__49->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__49->GetYaxis()->SetLabelSize(0.035);
   hMHits_eghlt__49->GetYaxis()->SetTitleSize(0.035);
   hMHits_eghlt__49->GetYaxis()->SetTitleOffset(0);
   hMHits_eghlt__49->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__49->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__49->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__49->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__49->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__49->Draw("hist");
   
   TH1D *hMHits_ele__50 = new TH1D("hMHits_ele__50","missing hits	120_200_barrel",7,0,6);
   hMHits_ele__50->SetBinContent(0,0.05590368);
   hMHits_ele__50->SetBinContent(1,0.9174229);
   hMHits_ele__50->SetBinContent(2,0.07403006);
   hMHits_ele__50->SetBinContent(3,0.005353885);
   hMHits_ele__50->SetBinContent(4,0.002592913);
   hMHits_ele__50->SetBinContent(5,0.000588207);
   hMHits_ele__50->SetBinContent(6,1.200423e-05);
   hMHits_ele__50->SetBinError(0,0.0008191949);
   hMHits_ele__50->SetBinError(1,0.003318577);
   hMHits_ele__50->SetBinError(2,0.0009426948);
   hMHits_ele__50->SetBinError(3,0.0002535138);
   hMHits_ele__50->SetBinError(4,0.0001764254);
   hMHits_ele__50->SetBinError(5,8.402958e-05);
   hMHits_ele__50->SetBinError(6,1.200423e-05);
   hMHits_ele__50->SetEntries(87961);

   ci = TColor::GetColor("#66ccff");
   hMHits_ele__50->SetLineColor(ci);
   hMHits_ele__50->SetLineWidth(3);
   hMHits_ele__50->GetXaxis()->SetLabelFont(42);
   hMHits_ele__50->GetXaxis()->SetLabelSize(0.035);
   hMHits_ele__50->GetXaxis()->SetTitleSize(0.035);
   hMHits_ele__50->GetXaxis()->SetTitleFont(42);
   hMHits_ele__50->GetYaxis()->SetLabelFont(42);
   hMHits_ele__50->GetYaxis()->SetLabelSize(0.035);
   hMHits_ele__50->GetYaxis()->SetTitleSize(0.035);
   hMHits_ele__50->GetYaxis()->SetTitleOffset(0);
   hMHits_ele__50->GetYaxis()->SetTitleFont(42);
   hMHits_ele__50->GetZaxis()->SetLabelFont(42);
   hMHits_ele__50->GetZaxis()->SetLabelSize(0.035);
   hMHits_ele__50->GetZaxis()->SetTitleSize(0.035);
   hMHits_ele__50->GetZaxis()->SetTitleFont(42);
   hMHits_ele__50->Draw("hist same");
   
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
   
   TPaveText *pt = new TPaveText(0.2405568,0.9339967,0.7594432,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("L1 Seed, Z mass with 120_200 in the barrel region");
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
   
   TH1D *hMHits_eghlt__51 = new TH1D("hMHits_eghlt__51","",7,0,6);
   hMHits_eghlt__51->SetBinContent(0,3.207635);
   hMHits_eghlt__51->SetBinContent(1,1.005789);
   hMHits_eghlt__51->SetBinContent(2,1.041805);
   hMHits_eghlt__51->SetBinContent(3,0.02634976);
   hMHits_eghlt__51->SetBinError(0,0.05494358);
   hMHits_eghlt__51->SetBinError(1,0.005357503);
   hMHits_eghlt__51->SetBinError(2,0.01935261);
   hMHits_eghlt__51->SetBinError(3,0.008425422);
   hMHits_eghlt__51->SetMinimum(0.5);
   hMHits_eghlt__51->SetMaximum(1.5);
   hMHits_eghlt__51->SetEntries(9070.257);
   hMHits_eghlt__51->SetMarkerStyle(20);
   hMHits_eghlt__51->GetXaxis()->SetTitle("missing hits");
   hMHits_eghlt__51->GetXaxis()->CenterTitle(true);
   hMHits_eghlt__51->GetXaxis()->SetLabelFont(42);
   hMHits_eghlt__51->GetXaxis()->SetLabelSize(0.12);
   hMHits_eghlt__51->GetXaxis()->SetTitleSize(0.3);
   hMHits_eghlt__51->GetXaxis()->SetTitleOffset(0.4);
   hMHits_eghlt__51->GetXaxis()->SetTitleFont(42);
   hMHits_eghlt__51->GetYaxis()->SetTitle("HLT/Reco");
   hMHits_eghlt__51->GetYaxis()->CenterTitle(true);
   hMHits_eghlt__51->GetYaxis()->SetLabelFont(42);
   hMHits_eghlt__51->GetYaxis()->SetLabelSize(0.1);
   hMHits_eghlt__51->GetYaxis()->SetTitleSize(0.15);
   hMHits_eghlt__51->GetYaxis()->SetTitleOffset(0.22);
   hMHits_eghlt__51->GetYaxis()->SetTitleFont(42);
   hMHits_eghlt__51->GetZaxis()->SetLabelFont(42);
   hMHits_eghlt__51->GetZaxis()->SetLabelSize(0.035);
   hMHits_eghlt__51->GetZaxis()->SetTitleSize(0.035);
   hMHits_eghlt__51->GetZaxis()->SetTitleFont(42);
   hMHits_eghlt__51->Draw("EP");
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
