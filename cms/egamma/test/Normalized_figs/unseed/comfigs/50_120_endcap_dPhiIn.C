void 50_120_endcap_dPhiIn()
{
//=========Macro generated from canvas: h_5/dPhiIn
//=========  (Thu Oct 24 10:54:33 2019) by ROOT version6.10/08
   TCanvas *h_5 = new TCanvas("h_5", "dPhiIn",0,45,900,600);
   gStyle->SetOptStat(0);
   h_5->Range(0,0,1,1);
   h_5->SetFillColor(0);
   h_5->SetBorderMode(0);
   h_5->SetBorderSize(2);
   h_5->SetGridx();
   h_5->SetGridy();
   h_5->SetTickx(1);
   h_5->SetTicky(1);
   h_5->SetLeftMargin(0.14);
   h_5->SetRightMargin(0.05);
   h_5->SetBottomMargin(0.3);
   h_5->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: dPhiIn_top
   TPad *dPhiIn_top = new TPad("dPhiIn_top", "top_pad",0,0.35,1,1);
   dPhiIn_top->Draw();
   dPhiIn_top->cd();
   dPhiIn_top->Range(-0.008641975,-0.001103546,0.05308642,0.2196058);
   dPhiIn_top->SetFillColor(0);
   dPhiIn_top->SetBorderMode(0);
   dPhiIn_top->SetBorderSize(2);
   dPhiIn_top->SetGridx();
   dPhiIn_top->SetGridy();
   dPhiIn_top->SetTickx(1);
   dPhiIn_top->SetTicky(1);
   dPhiIn_top->SetLeftMargin(0.14);
   dPhiIn_top->SetRightMargin(0.05);
   dPhiIn_top->SetBottomMargin(0.005);
   dPhiIn_top->SetFrameBorderMode(0);
   dPhiIn_top->SetFrameBorderMode(0);
   
   TH1D *hphiin_eghlt__70 = new TH1D("hphiin_eghlt__70"," L1 Seed, Z mass with 50_120 in the endcap region",40,0,0.05);
   hphiin_eghlt__70->SetBinContent(0,0.4268631);
   hphiin_eghlt__70->SetBinContent(1,0.1881284);
   hphiin_eghlt__70->SetBinContent(2,0.1531216);
   hphiin_eghlt__70->SetBinContent(3,0.1206868);
   hphiin_eghlt__70->SetBinContent(4,0.09246083);
   hphiin_eghlt__70->SetBinContent(5,0.07599292);
   hphiin_eghlt__70->SetBinContent(6,0.05899055);
   hphiin_eghlt__70->SetBinContent(7,0.04743294);
   hphiin_eghlt__70->SetBinContent(8,0.04038481);
   hphiin_eghlt__70->SetBinContent(9,0.03410495);
   hphiin_eghlt__70->SetBinContent(10,0.02795871);
   hphiin_eghlt__70->SetBinContent(11,0.0230484);
   hphiin_eghlt__70->SetBinContent(12,0.01833851);
   hphiin_eghlt__70->SetBinContent(13,0.01406287);
   hphiin_eghlt__70->SetBinContent(14,0.01316097);
   hphiin_eghlt__70->SetBinContent(15,0.01112336);
   hphiin_eghlt__70->SetBinContent(16,0.008918729);
   hphiin_eghlt__70->SetBinContent(17,0.007716204);
   hphiin_eghlt__70->SetBinContent(18,0.006947924);
   hphiin_eghlt__70->SetBinContent(19,0.00691452);
   hphiin_eghlt__70->SetBinContent(20,0.005611785);
   hphiin_eghlt__70->SetBinContent(21,0.004709891);
   hphiin_eghlt__70->SetBinContent(22,0.00450947);
   hphiin_eghlt__70->SetBinContent(23,0.003807997);
   hphiin_eghlt__70->SetBinContent(24,0.003774593);
   hphiin_eghlt__70->SetBinContent(25,0.003340348);
   hphiin_eghlt__70->SetBinContent(26,0.003173331);
   hphiin_eghlt__70->SetBinContent(27,0.002906103);
   hphiin_eghlt__70->SetBinContent(28,0.002171226);
   hphiin_eghlt__70->SetBinContent(29,0.002104419);
   hphiin_eghlt__70->SetBinContent(30,0.00143635);
   hphiin_eghlt__70->SetBinContent(31,0.00143635);
   hphiin_eghlt__70->SetBinContent(32,0.001903998);
   hphiin_eghlt__70->SetBinContent(33,0.00153656);
   hphiin_eghlt__70->SetBinContent(34,0.001202525);
   hphiin_eghlt__70->SetBinContent(35,0.001269332);
   hphiin_eghlt__70->SetBinContent(36,0.001135718);
   hphiin_eghlt__70->SetBinContent(37,0.001336139);
   hphiin_eghlt__70->SetBinContent(38,0.001135718);
   hphiin_eghlt__70->SetBinContent(39,0.001102315);
   hphiin_eghlt__70->SetBinContent(40,0.000901894);
   hphiin_eghlt__70->SetBinContent(41,0.1122357);
   hphiin_eghlt__70->SetBinError(0,0.003776071);
   hphiin_eghlt__70->SetBinError(1,0.002506819);
   hphiin_eghlt__70->SetBinError(2,0.002261591);
   hphiin_eghlt__70->SetBinError(3,0.002007824);
   hphiin_eghlt__70->SetBinError(4,0.001757417);
   hphiin_eghlt__70->SetBinError(5,0.001593244);
   hphiin_eghlt__70->SetBinError(6,0.001403741);
   hphiin_eghlt__70->SetBinError(7,0.00125874);
   hphiin_eghlt__70->SetBinError(8,0.001161462);
   hphiin_eghlt__70->SetBinError(9,0.001067344);
   hphiin_eghlt__70->SetBinError(10,0.0009663945);
   hphiin_eghlt__70->SetBinError(11,0.0008774377);
   hphiin_eghlt__70->SetBinError(12,0.0007826686);
   hphiin_eghlt__70->SetBinError(13,0.0006853821);
   hphiin_eghlt__70->SetBinError(14,0.0006630402);
   hphiin_eghlt__70->SetBinError(15,0.0006095563);
   hphiin_eghlt__70->SetBinError(16,0.0005458174);
   hphiin_eghlt__70->SetBinError(17,0.000507689);
   hphiin_eghlt__70->SetBinError(18,0.0004817518);
   hphiin_eghlt__70->SetBinError(19,0.0004805924);
   hphiin_eghlt__70->SetBinError(20,0.0004329586);
   hphiin_eghlt__70->SetBinError(21,0.0003966444);
   hphiin_eghlt__70->SetBinError(22,0.0003881134);
   hphiin_eghlt__70->SetBinError(23,0.0003566516);
   hphiin_eghlt__70->SetBinError(24,0.0003550839);
   hphiin_eghlt__70->SetBinError(25,0.0003340348);
   hphiin_eghlt__70->SetBinError(26,0.0003255769);
   hphiin_eghlt__70->SetBinError(27,0.0003115669);
   hphiin_eghlt__70->SetBinError(28,0.0002693075);
   hphiin_eghlt__70->SetBinError(29,0.0002651319);
   hphiin_eghlt__70->SetBinError(30,0.0002190413);
   hphiin_eghlt__70->SetBinError(31,0.0002190413);
   hphiin_eghlt__70->SetBinError(32,0.0002521907);
   hphiin_eghlt__70->SetBinError(33,0.0002265534);
   hphiin_eghlt__70->SetBinError(34,0.0002004209);
   hphiin_eghlt__70->SetBinError(35,0.0002059129);
   hphiin_eghlt__70->SetBinError(36,0.0001947741);
   hphiin_eghlt__70->SetBinError(37,0.0002112622);
   hphiin_eghlt__70->SetBinError(38,0.0001947741);
   hphiin_eghlt__70->SetBinError(39,0.0001918884);
   hphiin_eghlt__70->SetBinError(40,0.0001735696);
   hphiin_eghlt__70->SetBinError(41,0.00193625);
   hphiin_eghlt__70->SetEntries(46076);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hphiin_eghlt__70->SetLineColor(ci);
   hphiin_eghlt__70->SetLineStyle(5);
   hphiin_eghlt__70->SetLineWidth(4);
   hphiin_eghlt__70->GetXaxis()->SetTitle("dPhiIn");
   hphiin_eghlt__70->GetXaxis()->SetLabelFont(42);
   hphiin_eghlt__70->GetXaxis()->SetLabelSize(0.035);
   hphiin_eghlt__70->GetXaxis()->SetTitleSize(0.035);
   hphiin_eghlt__70->GetXaxis()->SetTitleFont(42);
   hphiin_eghlt__70->GetYaxis()->SetTitle("yields");
   hphiin_eghlt__70->GetYaxis()->SetLabelFont(42);
   hphiin_eghlt__70->GetYaxis()->SetLabelSize(0.035);
   hphiin_eghlt__70->GetYaxis()->SetTitleSize(0.035);
   hphiin_eghlt__70->GetYaxis()->SetTitleOffset(0);
   hphiin_eghlt__70->GetYaxis()->SetTitleFont(42);
   hphiin_eghlt__70->GetZaxis()->SetLabelFont(42);
   hphiin_eghlt__70->GetZaxis()->SetLabelSize(0.035);
   hphiin_eghlt__70->GetZaxis()->SetTitleSize(0.035);
   hphiin_eghlt__70->GetZaxis()->SetTitleFont(42);
   hphiin_eghlt__70->Draw("hist");
   
   TH1D *hPhiIn_ele__71 = new TH1D("hPhiIn_ele__71","dPhiIn	50_120_endcap",40,0,0.05);
   hPhiIn_ele__71->SetBinContent(0,1.085703);
   hPhiIn_ele__71->SetBinContent(1,0.1604312);
   hPhiIn_ele__71->SetBinContent(2,0.134969);
   hPhiIn_ele__71->SetBinContent(3,0.1093605);
   hPhiIn_ele__71->SetBinContent(4,0.08999561);
   hPhiIn_ele__71->SetBinContent(5,0.07082581);
   hPhiIn_ele__71->SetBinContent(6,0.06150919);
   hPhiIn_ele__71->SetBinContent(7,0.04916833);
   hPhiIn_ele__71->SetBinContent(8,0.04116872);
   hPhiIn_ele__71->SetBinContent(9,0.03468124);
   hPhiIn_ele__71->SetBinContent(10,0.02999854);
   hPhiIn_ele__71->SetBinContent(11,0.02580362);
   hPhiIn_ele__71->SetBinContent(12,0.0231696);
   hPhiIn_ele__71->SetBinContent(13,0.01702356);
   hPhiIn_ele__71->SetBinContent(14,0.01531633);
   hPhiIn_ele__71->SetBinContent(15,0.0138042);
   hPhiIn_ele__71->SetBinContent(16,0.01112141);
   hPhiIn_ele__71->SetBinContent(17,0.01077996);
   hPhiIn_ele__71->SetBinContent(18,0.0109263);
   hPhiIn_ele__71->SetBinContent(19,0.008633725);
   hPhiIn_ele__71->SetBinContent(20,0.006780157);
   hPhiIn_ele__71->SetBinContent(21,0.006682601);
   hPhiIn_ele__71->SetBinContent(22,0.00619482);
   hPhiIn_ele__71->SetBinContent(23,0.005999707);
   hPhiIn_ele__71->SetBinContent(24,0.005316814);
   hPhiIn_ele__71->SetBinContent(25,0.006048485);
   hPhiIn_ele__71->SetBinContent(26,0.004438808);
   hPhiIn_ele__71->SetBinContent(27,0.004487586);
   hPhiIn_ele__71->SetBinContent(28,0.003414468);
   hPhiIn_ele__71->SetBinContent(29,0.003902249);
   hPhiIn_ele__71->SetBinContent(30,0.003170577);
   hPhiIn_ele__71->SetBinContent(31,0.002877908);
   hPhiIn_ele__71->SetBinContent(32,0.002487684);
   hPhiIn_ele__71->SetBinContent(33,0.003121799);
   hPhiIn_ele__71->SetBinContent(34,0.002682796);
   hPhiIn_ele__71->SetBinContent(35,0.002292571);
   hPhiIn_ele__71->SetBinContent(36,0.001999902);
   hPhiIn_ele__71->SetBinContent(37,0.002487684);
   hPhiIn_ele__71->SetBinContent(38,0.002780352);
   hPhiIn_ele__71->SetBinContent(39,0.002536462);
   hPhiIn_ele__71->SetBinContent(40,0.001609678);
   hPhiIn_ele__71->SetBinContent(41,0.161797);
   hPhiIn_ele__71->SetBinError(0,0.007277262);
   hPhiIn_ele__71->SetBinError(1,0.002797415);
   hPhiIn_ele__71->SetBinError(2,0.00256584);
   hPhiIn_ele__71->SetBinError(3,0.002309632);
   hPhiIn_ele__71->SetBinError(4,0.002095189);
   hPhiIn_ele__71->SetBinError(5,0.001858696);
   hPhiIn_ele__71->SetBinError(6,0.001732138);
   hPhiIn_ele__71->SetBinError(7,0.001548657);
   hPhiIn_ele__71->SetBinError(8,0.001417086);
   hPhiIn_ele__71->SetBinError(9,0.001300648);
   hPhiIn_ele__71->SetBinError(10,0.001209658);
   hPhiIn_ele__71->SetBinError(11,0.001121896);
   hPhiIn_ele__71->SetBinError(12,0.001063094);
   hPhiIn_ele__71->SetBinError(13,0.0009112503);
   hPhiIn_ele__71->SetBinError(14,0.0008643503);
   hPhiIn_ele__71->SetBinError(15,0.0008205748);
   hPhiIn_ele__71->SetBinError(16,0.0007365333);
   hPhiIn_ele__71->SetBinError(17,0.0007251387);
   hPhiIn_ele__71->SetBinError(18,0.0007300439);
   hPhiIn_ele__71->SetBinError(19,0.0006489505);
   hPhiIn_ele__71->SetBinError(20,0.0005750854);
   hPhiIn_ele__71->SetBinError(21,0.0005709331);
   hPhiIn_ele__71->SetBinError(22,0.0005497014);
   hPhiIn_ele__71->SetBinError(23,0.0005409754);
   hPhiIn_ele__71->SetBinError(24,0.0005092584);
   hPhiIn_ele__71->SetBinError(25,0.00054317);
   hPhiIn_ele__71->SetBinError(26,0.0004653135);
   hPhiIn_ele__71->SetBinError(27,0.0004678632);
   hPhiIn_ele__71->SetBinError(28,0.0004081069);
   hPhiIn_ele__71->SetBinError(29,0.0004362847);
   hPhiIn_ele__71->SetBinError(30,0.0003932617);
   hPhiIn_ele__71->SetBinError(31,0.0003746718);
   hPhiIn_ele__71->SetBinError(32,0.0003483454);
   hPhiIn_ele__71->SetBinError(33,0.0003902249);
   hPhiIn_ele__71->SetBinError(34,0.0003617481);
   hPhiIn_ele__71->SetBinError(35,0.0003344059);
   hPhiIn_ele__71->SetBinError(36,0.0003123323);
   hPhiIn_ele__71->SetBinError(37,0.0003483454);
   hPhiIn_ele__71->SetBinError(38,0.0003682666);
   hPhiIn_ele__71->SetBinError(39,0.0003517439);
   hPhiIn_ele__71->SetBinError(40,0.0002802089);
   hPhiIn_ele__71->SetBinError(41,0.002809297);
   hPhiIn_ele__71->SetEntries(46076);

   ci = TColor::GetColor("#66ccff");
   hPhiIn_ele__71->SetLineColor(ci);
   hPhiIn_ele__71->SetLineWidth(3);
   hPhiIn_ele__71->GetXaxis()->SetLabelFont(42);
   hPhiIn_ele__71->GetXaxis()->SetLabelSize(0.035);
   hPhiIn_ele__71->GetXaxis()->SetTitleSize(0.035);
   hPhiIn_ele__71->GetXaxis()->SetTitleFont(42);
   hPhiIn_ele__71->GetYaxis()->SetLabelFont(42);
   hPhiIn_ele__71->GetYaxis()->SetLabelSize(0.035);
   hPhiIn_ele__71->GetYaxis()->SetTitleSize(0.035);
   hPhiIn_ele__71->GetYaxis()->SetTitleOffset(0);
   hPhiIn_ele__71->GetYaxis()->SetTitleFont(42);
   hPhiIn_ele__71->GetZaxis()->SetLabelFont(42);
   hPhiIn_ele__71->GetZaxis()->SetLabelSize(0.035);
   hPhiIn_ele__71->GetZaxis()->SetTitleSize(0.035);
   hPhiIn_ele__71->GetZaxis()->SetTitleFont(42);
   hPhiIn_ele__71->Draw("hist same");
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.08);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hPhiIn_ele","reco ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66ccff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hphiin_eghlt","HLT ele","lpf");
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
   dPhiIn_top->Modified();
   h_5->cd();
  
// ------------>Primitives in pad: dPhiIn_bottom
   TPad *dPhiIn_bottom = new TPad("dPhiIn_bottom", "bottom_pad",0,0.1,1,0.35);
   dPhiIn_bottom->Draw();
   dPhiIn_bottom->cd();
   dPhiIn_bottom->Range(-0.008641975,0.07142855,0.05308642,1.5);
   dPhiIn_bottom->SetFillColor(0);
   dPhiIn_bottom->SetBorderMode(0);
   dPhiIn_bottom->SetBorderSize(2);
   dPhiIn_bottom->SetGridx();
   dPhiIn_bottom->SetGridy();
   dPhiIn_bottom->SetTickx(1);
   dPhiIn_bottom->SetTicky(1);
   dPhiIn_bottom->SetLeftMargin(0.14);
   dPhiIn_bottom->SetRightMargin(0.05);
   dPhiIn_bottom->SetTopMargin(0);
   dPhiIn_bottom->SetBottomMargin(0.3);
   dPhiIn_bottom->SetFrameBorderMode(0);
   dPhiIn_bottom->SetFrameBorderMode(0);
   
   TH1D *hphiin_eghlt__72 = new TH1D("hphiin_eghlt__72","",40,0,0.05);
   hphiin_eghlt__72->SetBinContent(0,0.3931674);
   hphiin_eghlt__72->SetBinContent(1,1.172642);
   hphiin_eghlt__72->SetBinContent(2,1.134494);
   hphiin_eghlt__72->SetBinContent(3,1.103568);
   hphiin_eghlt__72->SetBinContent(4,1.027393);
   hphiin_eghlt__72->SetBinContent(5,1.072955);
   hphiin_eghlt__72->SetBinContent(6,0.9590525);
   hphiin_eghlt__72->SetBinContent(7,0.9647051);
   hphiin_eghlt__72->SetBinContent(8,0.9809585);
   hphiin_eghlt__72->SetBinContent(9,0.9833835);
   hphiin_eghlt__72->SetBinContent(10,0.9320026);
   hphiin_eghlt__72->SetBinContent(11,0.8932236);
   hphiin_eghlt__72->SetBinContent(12,0.7914901);
   hphiin_eghlt__72->SetBinContent(13,0.8260825);
   hphiin_eghlt__72->SetBinContent(14,0.8592773);
   hphiin_eghlt__72->SetBinContent(15,0.805795);
   hphiin_eghlt__72->SetBinContent(16,0.8019424);
   hphiin_eghlt__72->SetBinContent(17,0.7157914);
   hphiin_eghlt__72->SetBinContent(18,0.6358901);
   hphiin_eghlt__72->SetBinContent(19,0.8008734);
   hphiin_eghlt__72->SetBinContent(20,0.8276777);
   hphiin_eghlt__72->SetBinContent(21,0.7047991);
   hphiin_eghlt__72->SetBinContent(22,0.7279421);
   hphiin_eghlt__72->SetBinContent(23,0.6346971);
   hphiin_eghlt__72->SetBinContent(24,0.7099352);
   hphiin_eghlt__72->SetBinContent(25,0.5522619);
   hphiin_eghlt__72->SetBinContent(26,0.7149061);
   hphiin_eghlt__72->SetBinContent(27,0.6475871);
   hphiin_eghlt__72->SetBinContent(28,0.6358901);
   hphiin_eghlt__72->SetBinContent(29,0.5392837);
   hphiin_eghlt__72->SetBinContent(30,0.4530247);
   hphiin_eghlt__72->SetBinContent(31,0.499095);
   hphiin_eghlt__72->SetBinContent(32,0.76537);
   hphiin_eghlt__72->SetBinContent(33,0.4922034);
   hphiin_eghlt__72->SetBinContent(34,0.4482358);
   hphiin_eghlt__72->SetBinContent(35,0.5536719);
   hphiin_eghlt__72->SetBinContent(36,0.5678869);
   hphiin_eghlt__72->SetBinContent(37,0.5371018);
   hphiin_eghlt__72->SetBinContent(38,0.40848);
   hphiin_eghlt__72->SetBinContent(39,0.4345876);
   hphiin_eghlt__72->SetBinContent(40,0.5602948);
   hphiin_eghlt__72->SetBinContent(41,0.6936822);
   hphiin_eghlt__72->SetBinError(0,0.004363645);
   hphiin_eghlt__72->SetBinError(1,0.0257341);
   hphiin_eghlt__72->SetBinError(2,0.02731169);
   hphiin_eghlt__72->SetBinError(3,0.02966954);
   hphiin_eghlt__72->SetBinError(4,0.03087784);
   hphiin_eghlt__72->SetBinError(5,0.0360402);
   hphiin_eghlt__72->SetBinError(6,0.03535865);
   hphiin_eghlt__72->SetBinError(7,0.03973237);
   hphiin_eghlt__72->SetBinError(8,0.04400082);
   hphiin_eghlt__72->SetBinError(9,0.04803405);
   hphiin_eghlt__72->SetBinError(10,0.04949942);
   hphiin_eghlt__72->SetBinError(11,0.05161901);
   hphiin_eghlt__72->SetBinError(12,0.04959781);
   hphiin_eghlt__72->SetBinError(13,0.05980191);
   hphiin_eghlt__72->SetBinError(14,0.06500354);
   hphiin_eghlt__72->SetBinError(15,0.06514778);
   hphiin_eghlt__72->SetBinError(16,0.07231406);
   hphiin_eghlt__72->SetBinError(17,0.06735248);
   hphiin_eghlt__72->SetBinError(18,0.06123057);
   hphiin_eghlt__72->SetBinError(19,0.08198939);
   hphiin_eghlt__72->SetBinError(20,0.09490048);
   hphiin_eghlt__72->SetBinError(21,0.08455083);
   hphiin_eghlt__72->SetBinError(22,0.08998678);
   hphiin_eghlt__72->SetBinError(23,0.08251553);
   hphiin_eghlt__72->SetBinError(24,0.09531094);
   hphiin_eghlt__72->SetBinError(25,0.07422637);
   hphiin_eghlt__72->SetBinError(26,0.1048632);
   hphiin_eghlt__72->SetBinError(27,0.09684365);
   hphiin_eghlt__72->SetBinError(28,0.1095326);
   hphiin_eghlt__72->SetBinError(29,0.09083853);
   hphiin_eghlt__72->SetBinError(30,0.08905183);
   hphiin_eghlt__72->SetBinError(31,0.1000744);
   hphiin_eghlt__72->SetBinError(32,0.1475234);
   hphiin_eghlt__72->SetBinError(33,0.09514195);
   hphiin_eghlt__72->SetBinError(34,0.09609365);
   hphiin_eghlt__72->SetBinError(35,0.1207873);
   hphiin_eghlt__72->SetBinError(36,0.1317228);
   hphiin_eghlt__72->SetBinError(37,0.1134389);
   hphiin_eghlt__72->SetBinError(38,0.08851454);
   hphiin_eghlt__72->SetBinError(39,0.09672265);
   hphiin_eghlt__72->SetBinError(40,0.1453963);
   hphiin_eghlt__72->SetBinError(41,0.01697887);
   hphiin_eghlt__72->SetMinimum(0.5);
   hphiin_eghlt__72->SetMaximum(1.5);
   hphiin_eghlt__72->SetEntries(3200.632);
   hphiin_eghlt__72->SetMarkerStyle(20);
   hphiin_eghlt__72->GetXaxis()->SetTitle("dPhiIn");
   hphiin_eghlt__72->GetXaxis()->CenterTitle(true);
   hphiin_eghlt__72->GetXaxis()->SetLabelFont(42);
   hphiin_eghlt__72->GetXaxis()->SetLabelSize(0.12);
   hphiin_eghlt__72->GetXaxis()->SetTitleSize(0.3);
   hphiin_eghlt__72->GetXaxis()->SetTitleOffset(0.4);
   hphiin_eghlt__72->GetXaxis()->SetTitleFont(42);
   hphiin_eghlt__72->GetYaxis()->SetTitle("HLT/Reco");
   hphiin_eghlt__72->GetYaxis()->CenterTitle(true);
   hphiin_eghlt__72->GetYaxis()->SetLabelFont(42);
   hphiin_eghlt__72->GetYaxis()->SetLabelSize(0.1);
   hphiin_eghlt__72->GetYaxis()->SetTitleSize(0.15);
   hphiin_eghlt__72->GetYaxis()->SetTitleOffset(0.22);
   hphiin_eghlt__72->GetYaxis()->SetTitleFont(42);
   hphiin_eghlt__72->GetZaxis()->SetLabelFont(42);
   hphiin_eghlt__72->GetZaxis()->SetLabelSize(0.035);
   hphiin_eghlt__72->GetZaxis()->SetTitleSize(0.035);
   hphiin_eghlt__72->GetZaxis()->SetTitleFont(42);
   hphiin_eghlt__72->Draw("EP");
   TLine *line = new TLine(0,1,0.05,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   dPhiIn_bottom->Modified();
   h_5->cd();
   h_5->Modified();
   h_5->cd();
   h_5->SetSelected(h_5);
}
