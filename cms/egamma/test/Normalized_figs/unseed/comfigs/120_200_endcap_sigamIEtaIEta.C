void 120_200_endcap_sigamIEtaIEta()
{
//=========Macro generated from canvas: h_6/sigamIEtaIEta
//=========  (Thu Oct 24 10:54:36 2019) by ROOT version6.10/08
   TCanvas *h_6 = new TCanvas("h_6", "sigamIEtaIEta",0,45,900,600);
   gStyle->SetOptStat(0);
   h_6->Range(0,0,1,1);
   h_6->SetFillColor(0);
   h_6->SetBorderMode(0);
   h_6->SetBorderSize(2);
   h_6->SetGridx();
   h_6->SetGridy();
   h_6->SetTickx(1);
   h_6->SetTicky(1);
   h_6->SetLeftMargin(0.14);
   h_6->SetRightMargin(0.05);
   h_6->SetBottomMargin(0.3);
   h_6->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: sigamIEtaIEta_top
   TPad *sigamIEtaIEta_top = new TPad("sigamIEtaIEta_top", "top_pad",0,0.35,1,1);
   sigamIEtaIEta_top->Draw();
   sigamIEtaIEta_top->cd();
   sigamIEtaIEta_top->Range(-0.01037037,-0.001700795,0.0637037,0.3384582);
   sigamIEtaIEta_top->SetFillColor(0);
   sigamIEtaIEta_top->SetBorderMode(0);
   sigamIEtaIEta_top->SetBorderSize(2);
   sigamIEtaIEta_top->SetGridx();
   sigamIEtaIEta_top->SetGridy();
   sigamIEtaIEta_top->SetTickx(1);
   sigamIEtaIEta_top->SetTicky(1);
   sigamIEtaIEta_top->SetLeftMargin(0.14);
   sigamIEtaIEta_top->SetRightMargin(0.05);
   sigamIEtaIEta_top->SetBottomMargin(0.005);
   sigamIEtaIEta_top->SetFrameBorderMode(0);
   sigamIEtaIEta_top->SetFrameBorderMode(0);
   
   TH1D *hsieie_eghlt__100 = new TH1D("hsieie_eghlt__100","L1 Seed, Z mass with 120_200 in the endcap region",40,0,0.06);
   hsieie_eghlt__100->SetBinContent(0,0.1475264);
   hsieie_eghlt__100->SetBinContent(2,2.398024e-05);
   hsieie_eghlt__100->SetBinContent(7,4.796048e-05);
   hsieie_eghlt__100->SetBinContent(8,0.0001199012);
   hsieie_eghlt__100->SetBinContent(9,7.194072e-05);
   hsieie_eghlt__100->SetBinContent(10,9.592096e-05);
   hsieie_eghlt__100->SetBinContent(11,0.0005275653);
   hsieie_eghlt__100->SetBinContent(12,0.001582696);
   hsieie_eghlt__100->SetBinContent(13,0.006426704);
   hsieie_eghlt__100->SetBinContent(14,0.03484329);
   hsieie_eghlt__100->SetBinContent(15,0.1494209);
   hsieie_eghlt__100->SetBinContent(16,0.2899451);
   hsieie_eghlt__100->SetBinContent(17,0.2895134);
   hsieie_eghlt__100->SetBinContent(18,0.138366);
   hsieie_eghlt__100->SetBinContent(19,0.03791276);
   hsieie_eghlt__100->SetBinContent(20,0.01434018);
   hsieie_eghlt__100->SetBinContent(21,0.009232393);
   hsieie_eghlt__100->SetBinContent(22,0.006282823);
   hsieie_eghlt__100->SetBinContent(23,0.00501187);
   hsieie_eghlt__100->SetBinContent(24,0.003525095);
   hsieie_eghlt__100->SetBinContent(25,0.002757728);
   hsieie_eghlt__100->SetBinContent(26,0.002398024);
   hsieie_eghlt__100->SetBinContent(27,0.001438814);
   hsieie_eghlt__100->SetBinContent(28,0.001270953);
   hsieie_eghlt__100->SetBinContent(29,0.0008872689);
   hsieie_eghlt__100->SetBinContent(30,0.001199012);
   hsieie_eghlt__100->SetBinContent(31,0.0005515455);
   hsieie_eghlt__100->SetBinContent(32,0.0003597036);
   hsieie_eghlt__100->SetBinContent(33,0.0004556246);
   hsieie_eghlt__100->SetBinContent(34,0.0004556246);
   hsieie_eghlt__100->SetBinContent(35,0.0002637826);
   hsieie_eghlt__100->SetBinContent(36,0.0001438814);
   hsieie_eghlt__100->SetBinContent(37,0.0002398024);
   hsieie_eghlt__100->SetBinContent(38,0.0002158222);
   hsieie_eghlt__100->SetBinContent(40,7.194072e-05);
   hsieie_eghlt__100->SetBinContent(41,0.001222992);
   hsieie_eghlt__100->SetBinError(0,0.001880883);
   hsieie_eghlt__100->SetBinError(2,2.398024e-05);
   hsieie_eghlt__100->SetBinError(7,3.391318e-05);
   hsieie_eghlt__100->SetBinError(8,5.362145e-05);
   hsieie_eghlt__100->SetBinError(9,4.153499e-05);
   hsieie_eghlt__100->SetBinError(10,4.796048e-05);
   hsieie_eghlt__100->SetBinError(11,0.0001124773);
   hsieie_eghlt__100->SetBinError(12,0.0001948164);
   hsieie_eghlt__100->SetBinError(13,0.0003925735);
   hsieie_eghlt__100->SetBinError(14,0.0009140845);
   hsieie_eghlt__100->SetBinError(15,0.001892921);
   hsieie_eghlt__100->SetBinError(16,0.002636845);
   hsieie_eghlt__100->SetBinError(17,0.002634882);
   hsieie_eghlt__100->SetBinError(18,0.001821551);
   hsieie_eghlt__100->SetBinError(19,0.0009534973);
   hsieie_eghlt__100->SetBinError(20,0.0005864137);
   hsieie_eghlt__100->SetBinError(21,0.0004705263);
   hsieie_eghlt__100->SetBinError(22,0.0003881541);
   hsieie_eghlt__100->SetBinError(23,0.0003466783);
   hsieie_eghlt__100->SetBinError(24,0.000290745);
   hsieie_eghlt__100->SetBinError(25,0.0002571594);
   hsieie_eghlt__100->SetBinError(26,0.0002398024);
   hsieie_eghlt__100->SetBinError(27,0.0001857501);
   hsieie_eghlt__100->SetBinError(28,0.0001745788);
   hsieie_eghlt__100->SetBinError(29,0.0001458661);
   hsieie_eghlt__100->SetBinError(30,0.0001695659);
   hsieie_eghlt__100->SetBinError(31,0.0001150052);
   hsieie_eghlt__100->SetBinError(32,9.287507e-05);
   hsieie_eghlt__100->SetBinError(33,0.0001045274);
   hsieie_eghlt__100->SetBinError(34,0.0001045274);
   hsieie_eghlt__100->SetBinError(35,7.953346e-05);
   hsieie_eghlt__100->SetBinError(36,5.873935e-05);
   hsieie_eghlt__100->SetBinError(37,7.583218e-05);
   hsieie_eghlt__100->SetBinError(38,7.194072e-05);
   hsieie_eghlt__100->SetBinError(40,4.153499e-05);
   hsieie_eghlt__100->SetBinError(41,0.0001712532);
   hsieie_eghlt__100->SetEntries(47904);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hsieie_eghlt__100->SetLineColor(ci);
   hsieie_eghlt__100->SetLineStyle(5);
   hsieie_eghlt__100->SetLineWidth(4);
   hsieie_eghlt__100->GetXaxis()->SetLabelFont(42);
   hsieie_eghlt__100->GetXaxis()->SetLabelSize(0.035);
   hsieie_eghlt__100->GetXaxis()->SetTitleSize(0.035);
   hsieie_eghlt__100->GetXaxis()->SetTitleFont(42);
   hsieie_eghlt__100->GetYaxis()->SetLabelFont(42);
   hsieie_eghlt__100->GetYaxis()->SetLabelSize(0.035);
   hsieie_eghlt__100->GetYaxis()->SetTitleSize(0.035);
   hsieie_eghlt__100->GetYaxis()->SetTitleOffset(0);
   hsieie_eghlt__100->GetYaxis()->SetTitleFont(42);
   hsieie_eghlt__100->GetZaxis()->SetLabelFont(42);
   hsieie_eghlt__100->GetZaxis()->SetLabelSize(0.035);
   hsieie_eghlt__100->GetZaxis()->SetTitleSize(0.035);
   hsieie_eghlt__100->GetZaxis()->SetTitleFont(42);
   hsieie_eghlt__100->Draw("hist");
   
   TH1D *hsieie_ele__101 = new TH1D("hsieie_ele__101","sigamIEtaIEta	120_200_endcap",40,0,0.06);
   hsieie_ele__101->SetBinContent(0,0.00946339);
   hsieie_ele__101->SetBinContent(1,0.001180289);
   hsieie_ele__101->SetBinContent(2,8.430637e-05);
   hsieie_ele__101->SetBinContent(3,2.107659e-05);
   hsieie_ele__101->SetBinContent(4,4.215318e-05);
   hsieie_ele__101->SetBinContent(5,0.0002739957);
   hsieie_ele__101->SetBinContent(6,0.001138136);
   hsieie_ele__101->SetBinContent(7,0.0008219871);
   hsieie_ele__101->SetBinContent(8,0.0003793787);
   hsieie_ele__101->SetBinContent(9,0.0003583021);
   hsieie_ele__101->SetBinContent(10,0.0005058382);
   hsieie_ele__101->SetBinContent(11,0.0009273701);
   hsieie_ele__101->SetBinContent(12,0.002191966);
   hsieie_ele__101->SetBinContent(13,0.007081735);
   hsieie_ele__101->SetBinContent(14,0.03488176);
   hsieie_ele__101->SetBinContent(15,0.1422881);
   hsieie_ele__101->SetBinContent(16,0.2725414);
   hsieie_ele__101->SetBinContent(17,0.2742697);
   hsieie_ele__101->SetBinContent(18,0.1372297);
   hsieie_ele__101->SetBinContent(19,0.04388147);
   hsieie_ele__101->SetBinContent(20,0.02065506);
   hsieie_ele__101->SetBinContent(21,0.01382624);
   hsieie_ele__101->SetBinContent(22,0.00940016);
   hsieie_ele__101->SetBinContent(23,0.008135565);
   hsieie_ele__101->SetBinContent(24,0.006365131);
   hsieie_ele__101->SetBinContent(25,0.004952999);
   hsieie_ele__101->SetBinContent(26,0.003983476);
   hsieie_ele__101->SetBinContent(27,0.002592421);
   hsieie_ele__101->SetBinContent(28,0.002339502);
   hsieie_ele__101->SetBinContent(29,0.001770434);
   hsieie_ele__101->SetBinContent(30,0.00179151);
   hsieie_ele__101->SetBinContent(31,0.00105383);
   hsieie_ele__101->SetBinContent(32,0.0007166041);
   hsieie_ele__101->SetBinContent(33,0.0006533744);
   hsieie_ele__101->SetBinContent(34,0.0005269148);
   hsieie_ele__101->SetBinContent(35,0.0004004553);
   hsieie_ele__101->SetBinContent(36,0.0001896893);
   hsieie_ele__101->SetBinContent(37,0.0002107659);
   hsieie_ele__101->SetBinContent(38,0.0002107659);
   hsieie_ele__101->SetBinContent(39,6.322978e-05);
   hsieie_ele__101->SetBinContent(40,6.322978e-05);
   hsieie_ele__101->SetBinContent(41,0.0001896893);
   hsieie_ele__101->SetBinError(0,0.000446605);
   hsieie_ele__101->SetBinError(1,0.0001577228);
   hsieie_ele__101->SetBinError(2,4.215318e-05);
   hsieie_ele__101->SetBinError(3,2.107659e-05);
   hsieie_ele__101->SetBinError(4,2.98068e-05);
   hsieie_ele__101->SetBinError(5,7.599273e-05);
   hsieie_ele__101->SetBinError(6,0.0001548807);
   hsieie_ele__101->SetBinError(7,0.0001316233);
   hsieie_ele__101->SetBinError(8,8.942041e-05);
   hsieie_ele__101->SetBinError(9,8.690102e-05);
   hsieie_ele__101->SetBinError(10,0.0001032538);
   hsieie_ele__101->SetBinError(11,0.0001398063);
   hsieie_ele__101->SetBinError(12,0.0002149399);
   hsieie_ele__101->SetBinError(13,0.0003863403);
   hsieie_ele__101->SetBinError(14,0.0008574314);
   hsieie_ele__101->SetBinError(15,0.001731747);
   hsieie_ele__101->SetBinError(16,0.002396715);
   hsieie_ele__101->SetBinError(17,0.002404303);
   hsieie_ele__101->SetBinError(18,0.001700686);
   hsieie_ele__101->SetBinError(19,0.0009617025);
   hsieie_ele__101->SetBinError(20,0.0006598017);
   hsieie_ele__101->SetBinError(21,0.0005398242);
   hsieie_ele__101->SetBinError(22,0.0004451105);
   hsieie_ele__101->SetBinError(23,0.0004140893);
   hsieie_ele__101->SetBinError(24,0.0003662721);
   hsieie_ele__101->SetBinError(25,0.000323098);
   hsieie_ele__101->SetBinError(26,0.0002897552);
   hsieie_ele__101->SetBinError(27,0.0002337507);
   hsieie_ele__101->SetBinError(28,0.0002220557);
   hsieie_ele__101->SetBinError(29,0.0001931702);
   hsieie_ele__101->SetBinError(30,0.0001943166);
   hsieie_ele__101->SetBinError(31,0.000149034);
   hsieie_ele__101->SetBinError(32,0.0001228966);
   hsieie_ele__101->SetBinError(33,0.0001173495);
   hsieie_ele__101->SetBinError(34,0.000105383);
   hsieie_ele__101->SetBinError(35,9.187074e-05);
   hsieie_ele__101->SetBinError(36,6.322978e-05);
   hsieie_ele__101->SetBinError(37,6.665004e-05);
   hsieie_ele__101->SetBinError(38,6.665004e-05);
   hsieie_ele__101->SetBinError(39,3.650573e-05);
   hsieie_ele__101->SetBinError(40,3.650573e-05);
   hsieie_ele__101->SetBinError(41,6.322978e-05);
   hsieie_ele__101->SetEntries(47904);

   ci = TColor::GetColor("#66ccff");
   hsieie_ele__101->SetLineColor(ci);
   hsieie_ele__101->SetLineWidth(3);
   hsieie_ele__101->GetXaxis()->SetLabelFont(42);
   hsieie_ele__101->GetXaxis()->SetLabelSize(0.035);
   hsieie_ele__101->GetXaxis()->SetTitleSize(0.035);
   hsieie_ele__101->GetXaxis()->SetTitleFont(42);
   hsieie_ele__101->GetYaxis()->SetLabelFont(42);
   hsieie_ele__101->GetYaxis()->SetLabelSize(0.035);
   hsieie_ele__101->GetYaxis()->SetTitleSize(0.035);
   hsieie_ele__101->GetYaxis()->SetTitleOffset(0);
   hsieie_ele__101->GetYaxis()->SetTitleFont(42);
   hsieie_ele__101->GetZaxis()->SetLabelFont(42);
   hsieie_ele__101->GetZaxis()->SetLabelSize(0.035);
   hsieie_ele__101->GetZaxis()->SetTitleSize(0.035);
   hsieie_ele__101->GetZaxis()->SetTitleFont(42);
   hsieie_ele__101->Draw("hist same");
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.08);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hsieie_ele","reco ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66ccff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hsieie_eghlt","HLT ele","lpf");
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
   sigamIEtaIEta_top->Modified();
   h_6->cd();
  
// ------------>Primitives in pad: sigamIEtaIEta_bottom
   TPad *sigamIEtaIEta_bottom = new TPad("sigamIEtaIEta_bottom", "bottom_pad",0,0.1,1,0.35);
   sigamIEtaIEta_bottom->Draw();
   sigamIEtaIEta_bottom->cd();
   sigamIEtaIEta_bottom->Range(-0.01037037,0.07142855,0.0637037,1.5);
   sigamIEtaIEta_bottom->SetFillColor(0);
   sigamIEtaIEta_bottom->SetBorderMode(0);
   sigamIEtaIEta_bottom->SetBorderSize(2);
   sigamIEtaIEta_bottom->SetGridx();
   sigamIEtaIEta_bottom->SetGridy();
   sigamIEtaIEta_bottom->SetTickx(1);
   sigamIEtaIEta_bottom->SetTicky(1);
   sigamIEtaIEta_bottom->SetLeftMargin(0.14);
   sigamIEtaIEta_bottom->SetRightMargin(0.05);
   sigamIEtaIEta_bottom->SetTopMargin(0);
   sigamIEtaIEta_bottom->SetBottomMargin(0.3);
   sigamIEtaIEta_bottom->SetFrameBorderMode(0);
   sigamIEtaIEta_bottom->SetFrameBorderMode(0);
   
   TH1D *hsieie_eghlt__102 = new TH1D("hsieie_eghlt__102","",40,0,0.06);
   hsieie_eghlt__102->SetBinContent(0,15.58917);
   hsieie_eghlt__102->SetBinContent(2,0.2844416);
   hsieie_eghlt__102->SetBinContent(7,0.058347);
   hsieie_eghlt__102->SetBinContent(8,0.3160462);
   hsieie_eghlt__102->SetBinContent(9,0.2007823);
   hsieie_eghlt__102->SetBinContent(10,0.1896277);
   hsieie_eghlt__102->SetBinContent(11,0.5688832);
   hsieie_eghlt__102->SetBinContent(12,0.7220441);
   hsieie_eghlt__102->SetBinContent(13,0.9075042);
   hsieie_eghlt__102->SetBinContent(14,0.9988971);
   hsieie_eghlt__102->SetBinContent(15,1.050129);
   hsieie_eghlt__102->SetBinContent(16,1.063857);
   hsieie_eghlt__102->SetBinContent(17,1.055579);
   hsieie_eghlt__102->SetBinContent(18,1.00828);
   hsieie_eghlt__102->SetBinContent(19,0.8639812);
   hsieie_eghlt__102->SetBinContent(20,0.6942698);
   hsieie_eghlt__102->SetBinContent(21,0.667744);
   hsieie_eghlt__102->SetBinContent(22,0.668374);
   hsieie_eghlt__102->SetBinContent(23,0.6160445);
   hsieie_eghlt__102->SetBinContent(24,0.5538135);
   hsieie_eghlt__102->SetBinContent(25,0.5567793);
   hsieie_eghlt__102->SetBinContent(26,0.6019928);
   hsieie_eghlt__102->SetBinContent(27,0.555008);
   hsieie_eghlt__102->SetBinContent(28,0.5432579);
   hsieie_eghlt__102->SetBinContent(29,0.501159);
   hsieie_eghlt__102->SetBinContent(30,0.6692744);
   hsieie_eghlt__102->SetBinContent(31,0.5233726);
   hsieie_eghlt__102->SetBinContent(32,0.5019558);
   hsieie_eghlt__102->SetBinContent(33,0.6973407);
   hsieie_eghlt__102->SetBinContent(34,0.8647025);
   hsieie_eghlt__102->SetBinContent(35,0.6587069);
   hsieie_eghlt__102->SetBinContent(36,0.758511);
   hsieie_eghlt__102->SetBinContent(37,1.137766);
   hsieie_eghlt__102->SetBinContent(38,1.02399);
   hsieie_eghlt__102->SetBinContent(40,1.137766);
   hsieie_eghlt__102->SetBinContent(41,6.447343);
   hsieie_eghlt__102->SetBinError(0,0.7620731);
   hsieie_eghlt__102->SetBinError(2,0.3180154);
   hsieie_eghlt__102->SetBinError(7,0.04230222);
   hsieie_eghlt__102->SetBinError(8,0.1597693);
   hsieie_eghlt__102->SetBinError(9,0.1257348);
   hsieie_eghlt__102->SetBinError(10,0.1024107);
   hsieie_eghlt__102->SetBinError(11,0.1485448);
   hsieie_eghlt__102->SetBinError(12,0.1136317);
   hsieie_eghlt__102->SetBinError(13,0.07432417);
   hsieie_eghlt__102->SetBinError(14,0.03591116);
   hsieie_eghlt__102->SetBinError(15,0.01844806);
   hsieie_eghlt__102->SetBinError(16,0.01345851);
   hsieie_eghlt__102->SetBinError(17,0.0133386);
   hsieie_eghlt__102->SetBinError(18,0.01822999);
   hsieie_eghlt__102->SetBinError(19,0.02882149);
   hsieie_eghlt__102->SetBinError(20,0.03602617);
   hsieie_eghlt__102->SetBinError(21,0.04286996);
   hsieie_eghlt__102->SetBinError(22,0.05202572);
   hsieie_eghlt__102->SetBinError(23,0.05290586);
   hsieie_eghlt__102->SetBinError(24,0.05569607);
   hsieie_eghlt__102->SetBinError(25,0.06336279);
   hsieie_eghlt__102->SetBinError(26,0.07444051);
   hsieie_eghlt__102->SetBinError(27,0.08739702);
   hsieie_eghlt__102->SetBinError(28,0.09070444);
   hsieie_eghlt__102->SetBinError(29,0.09888439);
   hsieie_eghlt__102->SetBinError(30,0.1192825);
   hsieie_eghlt__102->SetBinError(31,0.1318632);
   hsieie_eghlt__102->SetBinError(32,0.1555888);
   hsieie_eghlt__102->SetBinError(33,0.203176);
   hsieie_eghlt__102->SetBinError(34,0.263176);
   hsieie_eghlt__102->SetBinError(35,0.2495627);
   hsieie_eghlt__102->SetBinError(36,0.3997704);
   hsieie_eghlt__102->SetBinError(37,0.5088246);
   hsieie_eghlt__102->SetBinError(38,0.4704909);
   hsieie_eghlt__102->SetBinError(40,0.9289824);
   hsieie_eghlt__102->SetBinError(41,2.331042);
   hsieie_eghlt__102->SetMinimum(0.5);
   hsieie_eghlt__102->SetMaximum(1.5);
   hsieie_eghlt__102->SetEntries(272.7148);
   hsieie_eghlt__102->SetMarkerStyle(20);
   hsieie_eghlt__102->GetXaxis()->SetTitle("sigamIEtaIEta");
   hsieie_eghlt__102->GetXaxis()->CenterTitle(true);
   hsieie_eghlt__102->GetXaxis()->SetLabelFont(42);
   hsieie_eghlt__102->GetXaxis()->SetLabelSize(0.12);
   hsieie_eghlt__102->GetXaxis()->SetTitleSize(0.3);
   hsieie_eghlt__102->GetXaxis()->SetTitleOffset(0.4);
   hsieie_eghlt__102->GetXaxis()->SetTitleFont(42);
   hsieie_eghlt__102->GetYaxis()->SetTitle("HLT/Reco");
   hsieie_eghlt__102->GetYaxis()->CenterTitle(true);
   hsieie_eghlt__102->GetYaxis()->SetLabelFont(42);
   hsieie_eghlt__102->GetYaxis()->SetLabelSize(0.1);
   hsieie_eghlt__102->GetYaxis()->SetTitleSize(0.15);
   hsieie_eghlt__102->GetYaxis()->SetTitleOffset(0.22);
   hsieie_eghlt__102->GetYaxis()->SetTitleFont(42);
   hsieie_eghlt__102->GetZaxis()->SetLabelFont(42);
   hsieie_eghlt__102->GetZaxis()->SetLabelSize(0.035);
   hsieie_eghlt__102->GetZaxis()->SetTitleSize(0.035);
   hsieie_eghlt__102->GetZaxis()->SetTitleFont(42);
   hsieie_eghlt__102->Draw("EP");
   TLine *line = new TLine(0,1,0.06,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   sigamIEtaIEta_bottom->Modified();
   h_6->cd();
   h_6->Modified();
   h_6->cd();
   h_6->SetSelected(h_6);
}
