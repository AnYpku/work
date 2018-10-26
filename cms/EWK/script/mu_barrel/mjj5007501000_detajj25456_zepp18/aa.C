{
//=========Macro generated from canvas: /
//=========  (Fri Sep 14 07:41:38 2018) by ROOT version5.34/18
   TCanvas * = new TCanvas("", "",0,0,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   ->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.15);
   c1->SetRightMargin(0.05);
   c1->SetBottomMargin(0.13);
   c1->SetFrameFillStyle(0);
   c1->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "",0,0,0.99,0.99);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-1.6875,-5.465453,9.5625,36.57649);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetTickx(1);
   pad1->SetTicky(1);
   pad1->SetLeftMargin(0.15);
   pad1->SetRightMargin(0.05);
   pad1->SetBottomMargin(0.13);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameFillStyle(0);
   pad1->SetFrameBorderMode(0);
   
   THStack *hs = new THStack();
   hs->SetName("hs");
   hs->SetTitle("");
   
   TH1F *hs_stack_1 = new TH1F("hs_stack_1","",9,0,9);
   hs_stack_1->SetMinimum(0);
   hs_stack_1->SetMaximum(32.79272);
   hs_stack_1->SetDirectory(0);
   hs_stack_1->SetStats(0);
   hs_stack_1->SetLineStyle(0);
   hs_stack_1->SetLineWidth(2);
   hs_stack_1->SetMarkerStyle(20);
   hs_stack_1->GetXaxis()->SetBinLabel(1,"Mjj 500~750");
   hs_stack_1->GetXaxis()->SetBinLabel(2,"Mjj 750~1000");
   hs_stack_1->GetXaxis()->SetBinLabel(3,"Mjj 1000~2000");
   hs_stack_1->GetXaxis()->SetBinLabel(4,"Mjj 500~750");
   hs_stack_1->GetXaxis()->SetBinLabel(5,"Mjj 750~1000");
   hs_stack_1->GetXaxis()->SetBinLabel(6,"Mjj 1000~2000");
   hs_stack_1->GetXaxis()->SetBinLabel(7,"Mjj 500~750");
   hs_stack_1->GetXaxis()->SetBinLabel(8,"Mjj 750~1000");
   hs_stack_1->GetXaxis()->SetBinLabel(9,"Mjj 1000~2000");
   hs_stack_1->GetXaxis()->SetLabelFont(42);
   hs_stack_1->GetXaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetXaxis()->SetTitleSize(0.06);
   hs_stack_1->GetXaxis()->SetTitleOffset(0.9);
   hs_stack_1->GetXaxis()->SetTitleFont(42);
   hs_stack_1->GetYaxis()->SetTitle("Events /bin");
   hs_stack_1->GetYaxis()->SetLabelFont(42);
   hs_stack_1->GetYaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetYaxis()->SetTitleSize(0.06);
   hs_stack_1->GetYaxis()->SetTitleOffset(0.8);
   hs_stack_1->GetYaxis()->SetTitleFont(42);
   hs_stack_1->GetZaxis()->SetLabelFont(42);
   hs_stack_1->GetZaxis()->SetLabelOffset(0.007);
   hs_stack_1->GetZaxis()->SetTitleSize(0.06);
   hs_stack_1->GetZaxis()->SetTitleFont(42);
   hs->SetHistogram(hs_stack_1);
   
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetBinContent(1,0.1802961);
   unrolled hist->SetBinError(1,0.1802961);
   unrolled hist->SetEntries(9);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#00ff00");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(20);
   unrolled hist->GetXaxis()->SetBinLabel(1,"Mjj 500~750");
   unrolled hist->GetXaxis()->SetBinLabel(2,"Mjj 750~1000");
   unrolled hist->GetXaxis()->SetBinLabel(3,"Mjj 1000~2000");
   unrolled hist->GetXaxis()->SetBinLabel(4,"Mjj 500~750");
   unrolled hist->GetXaxis()->SetBinLabel(5,"Mjj 750~1000");
   unrolled hist->GetXaxis()->SetBinLabel(6,"Mjj 1000~2000");
   unrolled hist->GetXaxis()->SetBinLabel(7,"Mjj 500~750");
   unrolled hist->GetXaxis()->SetBinLabel(8,"Mjj 750~1000");
   unrolled hist->GetXaxis()->SetBinLabel(9,"Mjj 1000~2000");
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetBinContent(1,0.9455628);
   unrolled hist->SetBinContent(2,0.590825);
   unrolled hist->SetBinContent(3,0.05422567);
   unrolled hist->SetBinContent(4,0.1680295);
   unrolled hist->SetBinContent(5,0.0884086);
   unrolled hist->SetBinContent(6,0.2897538);
   unrolled hist->SetBinContent(7,0.04746371);
   unrolled hist->SetBinContent(8,0.05438872);
   unrolled hist->SetBinContent(9,-0.01690277);
   unrolled hist->SetBinError(1,0.3089362);
   unrolled hist->SetBinError(2,0.1739046);
   unrolled hist->SetBinError(3,0.114604);
   unrolled hist->SetBinError(4,0.1361718);
   unrolled hist->SetBinError(5,0.1280358);
   unrolled hist->SetBinError(6,0.1251712);
   unrolled hist->SetBinError(7,0.03449135);
   unrolled hist->SetBinError(8,0.03847438);
   unrolled hist->SetBinError(9,0.07123608);
   unrolled hist->SetEntries(9);

   ci = TColor::GetColor("#00ffff");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#00ffff");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#00ffff");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(20);
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetBinContent(1,1.124019);
   unrolled hist->SetBinContent(4,0.8099607);
   unrolled hist->SetBinContent(5,0.423986);
   unrolled hist->SetBinContent(6,0.3923088);
   unrolled hist->SetBinContent(9,0.4169635);
   unrolled hist->SetBinError(1,0.6569704);
   unrolled hist->SetBinError(4,0.5799044);
   unrolled hist->SetBinError(5,0.423986);
   unrolled hist->SetBinError(6,0.3923088);
   unrolled hist->SetBinError(9,0.4169635);
   unrolled hist->SetEntries(9);

   ci = TColor::GetColor("#6666cc");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#6666cc");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#6666cc");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(20);
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetEntries(9);

   ci = TColor::GetColor("#000099");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#000099");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(20);
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetBinContent(1,6.468317);
   unrolled hist->SetBinContent(2,0.686581);
   unrolled hist->SetBinContent(4,5.969469);
   unrolled hist->SetBinContent(5,6.362809);
   unrolled hist->SetBinContent(6,1.692039);
   unrolled hist->SetBinContent(8,0.466594);
   unrolled hist->SetBinContent(9,4.885785);
   unrolled hist->SetBinError(1,1.683983);
   unrolled hist->SetBinError(2,0.5158529);
   unrolled hist->SetBinError(4,1.537771);
   unrolled hist->SetBinError(5,1.65138);
   unrolled hist->SetBinError(6,0.8561126);
   unrolled hist->SetBinError(8,0.466594);
   unrolled hist->SetBinError(9,1.467361);
   unrolled hist->SetEntries(9);

   ci = TColor::GetColor("#ffff00");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(20);
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetBinContent(1,16.7008);
   unrolled hist->SetBinContent(2,4.174328);
   unrolled hist->SetBinContent(3,1.88493);
   unrolled hist->SetBinContent(4,17.09961);
   unrolled hist->SetBinContent(5,4.707516);
   unrolled hist->SetBinContent(6,2.535031);
   unrolled hist->SetBinContent(7,0.7994786);
   unrolled hist->SetBinContent(8,2.437294);
   unrolled hist->SetBinContent(9,4.481764);
   unrolled hist->SetBinError(1,1.415008);
   unrolled hist->SetBinError(2,0.6734647);
   unrolled hist->SetBinError(3,0.4766243);
   unrolled hist->SetBinError(4,1.589261);
   unrolled hist->SetBinError(5,0.9738597);
   unrolled hist->SetBinError(6,0.5913942);
   unrolled hist->SetBinError(7,0.3178585);
   unrolled hist->SetBinError(8,0.6982234);
   unrolled hist->SetBinError(9,0.9424086);
   unrolled hist->SetEntries(9);

   ci = TColor::GetColor("#ff00ff");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#ff00ff");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#ff00ff");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(20);
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   
   TH1D *unrolled hist = new TH1D("unrolled hist","unrolled hist",9,0,9);
   unrolled hist->SetBinContent(1,5.812164);
   unrolled hist->SetBinContent(2,3.879045);
   unrolled hist->SetBinContent(3,6.412584);
   unrolled hist->SetBinContent(4,0.9935993);
   unrolled hist->SetBinContent(5,1.782143);
   unrolled hist->SetBinContent(6,7.865113);
   unrolled hist->SetBinContent(7,0.01430418);
   unrolled hist->SetBinContent(8,0.04849102);
   unrolled hist->SetBinContent(9,2.585736);
   unrolled hist->SetBinError(1,0.2725817);
   unrolled hist->SetBinError(2,0.2238318);
   unrolled hist->SetBinError(3,0.2877778);
   unrolled hist->SetBinError(4,0.1125985);
   unrolled hist->SetBinError(5,0.1517759);
   unrolled hist->SetBinError(6,0.3176351);
   unrolled hist->SetBinError(7,0.01430418);
   unrolled hist->SetBinError(8,0.02350286);
   unrolled hist->SetBinError(9,0.1812325);
   unrolled hist->SetEntries(9);

   ci = TColor::GetColor("#ff3333");
   unrolled hist->SetFillColor(ci);

   ci = TColor::GetColor("#ff3333");
   unrolled hist->SetLineColor(ci);
   unrolled hist->SetLineStyle(0);
   unrolled hist->SetLineWidth(2);

   ci = TColor::GetColor("#ff3333");
   unrolled hist->SetMarkerColor(ci);
   unrolled hist->SetMarkerStyle(21);
   unrolled hist->GetXaxis()->SetLabelFont(42);
   unrolled hist->GetXaxis()->SetLabelOffset(0.007);
   unrolled hist->GetXaxis()->SetTitleSize(0.06);
   unrolled hist->GetXaxis()->SetTitleOffset(0.9);
   unrolled hist->GetXaxis()->SetTitleFont(42);
   unrolled hist->GetYaxis()->SetLabelFont(42);
   unrolled hist->GetYaxis()->SetLabelOffset(0.007);
   unrolled hist->GetYaxis()->SetTitleSize(0.06);
   unrolled hist->GetYaxis()->SetTitleOffset(1.1);
   unrolled hist->GetYaxis()->SetTitleFont(42);
   unrolled hist->GetZaxis()->SetLabelFont(42);
   unrolled hist->GetZaxis()->SetLabelOffset(0.007);
   unrolled hist->GetZaxis()->SetTitleSize(0.06);
   unrolled hist->GetZaxis()->SetTitleFont(42);
   hs->Add(unrolled hist,"");
   hs->Draw("hist");
   
   TLegend *leg = new TLegend(0.82,0.7,0.95,0.88,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(19);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("unrolled hist","ZA_sig","lpf");

   ci = TColor::GetColor("#ff3333");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff3333");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff3333");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("unrolled hist","ZA","lpf");

   ci = TColor::GetColor("#ff00ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff00ff");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff00ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("unrolled hist","non-prompt","lpf");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ffff00");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("unrolled hist","WA","lpf");

   ci = TColor::GetColor("#000099");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#000099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("unrolled hist","VV","lpf");

   ci = TColor::GetColor("#6666cc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#6666cc");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#6666cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("unrolled hist","TTA","lpf");

   ci = TColor::GetColor("#00ffff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ffff");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ffff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("unrolled hist","ST","lpf");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.18,0.82,"Preliminary");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.18,0.86,"CMS");
tex->SetNDC();
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.76,0.92,"35.862 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextSize(0.03);
   tex->SetLineWidth(2);
   tex->Draw();
   pad1->Modified();
   ->cd();
   c1->Modified();
   ->cd();
   ->SetSelected();
}
