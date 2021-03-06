void 120_200_barrel_nrgy()
{
//=========Macro generated from canvas: h_2/nrgy
//=========  (Thu Oct 24 10:54:30 2019) by ROOT version6.10/08
   TCanvas *h_2 = new TCanvas("h_2", "nrgy",0,45,900,600);
   gStyle->SetOptStat(0);
   h_2->Range(0,0,1,1);
   h_2->SetFillColor(0);
   h_2->SetBorderMode(0);
   h_2->SetBorderSize(2);
   h_2->SetGridx();
   h_2->SetGridy();
   h_2->SetTickx(1);
   h_2->SetTicky(1);
   h_2->SetLeftMargin(0.14);
   h_2->SetRightMargin(0.05);
   h_2->SetBottomMargin(0.3);
   h_2->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: nrgy_top
   TPad *nrgy_top = new TPad("nrgy_top", "top_pad",0,0.35,1,1);
   nrgy_top->Draw();
   nrgy_top->cd();
   nrgy_top->Range(-69.1358,-0.0008562091,424.6914,0.1703856);
   nrgy_top->SetFillColor(0);
   nrgy_top->SetBorderMode(0);
   nrgy_top->SetBorderSize(2);
   nrgy_top->SetGridx();
   nrgy_top->SetGridy();
   nrgy_top->SetTickx(1);
   nrgy_top->SetTicky(1);
   nrgy_top->SetLeftMargin(0.14);
   nrgy_top->SetRightMargin(0.05);
   nrgy_top->SetBottomMargin(0.005);
   nrgy_top->SetFrameBorderMode(0);
   nrgy_top->SetFrameBorderMode(0);
   
   TH1D *hnrgy_eghlt__34 = new TH1D("hnrgy_eghlt__34","L1 Seed, Z mass with 120_200 in the barrel region",40,0,400);
   hnrgy_eghlt__34->SetBinContent(0,0.169036);
   hnrgy_eghlt__34->SetBinContent(1,0.002047954);
   hnrgy_eghlt__34->SetBinContent(2,0.003776746);
   hnrgy_eghlt__34->SetBinContent(3,0.01537295);
   hnrgy_eghlt__34->SetBinContent(4,0.05989601);
   hnrgy_eghlt__34->SetBinContent(5,0.09350107);
   hnrgy_eghlt__34->SetBinContent(6,0.1275051);
   hnrgy_eghlt__34->SetBinContent(7,0.1459633);
   hnrgy_eghlt__34->SetBinContent(8,0.1270263);
   hnrgy_eghlt__34->SetBinContent(9,0.1052569);
   hnrgy_eghlt__34->SetBinContent(10,0.08033565);
   hnrgy_eghlt__34->SetBinContent(11,0.06210354);
   hnrgy_eghlt__34->SetBinContent(12,0.04726252);
   hnrgy_eghlt__34->SetBinContent(13,0.03635783);
   hnrgy_eghlt__34->SetBinContent(14,0.0257989);
   hnrgy_eghlt__34->SetBinContent(15,0.01849808);
   hnrgy_eghlt__34->SetBinContent(16,0.01258029);
   hnrgy_eghlt__34->SetBinContent(17,0.009082809);
   hnrgy_eghlt__34->SetBinContent(18,0.006755589);
   hnrgy_eghlt__34->SetBinContent(19,0.004707635);
   hnrgy_eghlt__34->SetBinContent(20,0.003324601);
   hnrgy_eghlt__34->SetBinContent(21,0.002726173);
   hnrgy_eghlt__34->SetBinContent(22,0.00183518);
   hnrgy_eghlt__34->SetBinContent(23,0.0016623);
   hnrgy_eghlt__34->SetBinContent(24,0.001356437);
   hnrgy_eghlt__34->SetBinContent(25,0.001143663);
   hnrgy_eghlt__34->SetBinContent(26,0.0006649201);
   hnrgy_eghlt__34->SetBinContent(27,0.0005319361);
   hnrgy_eghlt__34->SetBinContent(28,0.0004920409);
   hnrgy_eghlt__34->SetBinContent(29,0.0003856537);
   hnrgy_eghlt__34->SetBinContent(30,0.0003457585);
   hnrgy_eghlt__34->SetBinContent(31,0.0003590569);
   hnrgy_eghlt__34->SetBinContent(32,0.0002127744);
   hnrgy_eghlt__34->SetBinContent(33,0.0001728792);
   hnrgy_eghlt__34->SetBinContent(34,0.0001462824);
   hnrgy_eghlt__34->SetBinContent(35,0.0001595808);
   hnrgy_eghlt__34->SetBinContent(36,0.000132984);
   hnrgy_eghlt__34->SetBinContent(37,0.0001595808);
   hnrgy_eghlt__34->SetBinContent(38,0.0001063872);
   hnrgy_eghlt__34->SetBinContent(39,0.0001196856);
   hnrgy_eghlt__34->SetBinContent(40,0.000132984);
   hnrgy_eghlt__34->SetBinContent(41,0.0007048154);
   hnrgy_eghlt__34->SetBinError(0,0.001499303);
   hnrgy_eghlt__34->SetBinError(1,0.0001650288);
   hnrgy_eghlt__34->SetBinError(2,0.0002241087);
   hnrgy_eghlt__34->SetBinError(3,0.0004521457);
   hnrgy_eghlt__34->SetBinError(4,0.0008924804);
   hnrgy_eghlt__34->SetBinError(5,0.001115085);
   hnrgy_eghlt__34->SetBinError(6,0.001302157);
   hnrgy_eghlt__34->SetBinError(7,0.001393226);
   hnrgy_eghlt__34->SetBinError(8,0.001299711);
   hnrgy_eghlt__34->SetBinError(9,0.00118311);
   hnrgy_eghlt__34->SetBinError(10,0.001033603);
   hnrgy_eghlt__34->SetBinError(11,0.0009087783);
   hnrgy_eghlt__34->SetBinError(12,0.0007927901);
   hnrgy_eghlt__34->SetBinError(13,0.0006953424);
   hnrgy_eghlt__34->SetBinError(14,0.0005857339);
   hnrgy_eghlt__34->SetBinError(15,0.0004959787);
   hnrgy_eghlt__34->SetBinError(16,0.0004090205);
   hnrgy_eghlt__34->SetBinError(17,0.000347544);
   hnrgy_eghlt__34->SetBinError(18,0.0002997308);
   hnrgy_eghlt__34->SetBinError(19,0.000250208);
   hnrgy_eghlt__34->SetBinError(20,0.0002102662);
   hnrgy_eghlt__34->SetBinError(21,0.0001904042);
   hnrgy_eghlt__34->SetBinError(22,0.0001562209);
   hnrgy_eghlt__34->SetBinError(23,0.0001486807);
   hnrgy_eghlt__34->SetBinError(24,0.0001343073);
   hnrgy_eghlt__34->SetBinError(25,0.0001233243);
   hnrgy_eghlt__34->SetBinError(26,9.403391e-05);
   hnrgy_eghlt__34->SetBinError(27,8.410648e-05);
   hnrgy_eghlt__34->SetBinError(28,8.089103e-05);
   hnrgy_eghlt__34->SetBinError(29,7.161409e-05);
   hnrgy_eghlt__34->SetBinError(30,6.780882e-05);
   hnrgy_eghlt__34->SetBinError(31,6.910053e-05);
   hnrgy_eghlt__34->SetBinError(32,5.319361e-05);
   hnrgy_eghlt__34->SetBinError(33,4.794807e-05);
   hnrgy_eghlt__34->SetBinError(34,4.410581e-05);
   hnrgy_eghlt__34->SetBinError(35,4.606702e-05);
   hnrgy_eghlt__34->SetBinError(36,4.205324e-05);
   hnrgy_eghlt__34->SetBinError(37,4.606702e-05);
   hnrgy_eghlt__34->SetBinError(38,3.761356e-05);
   hnrgy_eghlt__34->SetBinError(39,3.989521e-05);
   hnrgy_eghlt__34->SetBinError(40,4.205324e-05);
   hnrgy_eghlt__34->SetBinError(41,9.681383e-05);
   hnrgy_eghlt__34->SetEntries(87961);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hnrgy_eghlt__34->SetLineColor(ci);
   hnrgy_eghlt__34->SetLineStyle(5);
   hnrgy_eghlt__34->SetLineWidth(4);
   hnrgy_eghlt__34->GetXaxis()->SetLabelFont(42);
   hnrgy_eghlt__34->GetXaxis()->SetLabelSize(0.035);
   hnrgy_eghlt__34->GetXaxis()->SetTitleSize(0.035);
   hnrgy_eghlt__34->GetXaxis()->SetTitleFont(42);
   hnrgy_eghlt__34->GetYaxis()->SetLabelFont(42);
   hnrgy_eghlt__34->GetYaxis()->SetLabelSize(0.035);
   hnrgy_eghlt__34->GetYaxis()->SetTitleSize(0.035);
   hnrgy_eghlt__34->GetYaxis()->SetTitleOffset(0);
   hnrgy_eghlt__34->GetYaxis()->SetTitleFont(42);
   hnrgy_eghlt__34->GetZaxis()->SetLabelFont(42);
   hnrgy_eghlt__34->GetZaxis()->SetLabelSize(0.035);
   hnrgy_eghlt__34->GetZaxis()->SetTitleSize(0.035);
   hnrgy_eghlt__34->GetZaxis()->SetTitleFont(42);
   hnrgy_eghlt__34->Draw("hist");
   
   TH1D *hclusNrgy_ele__35 = new TH1D("hclusNrgy_ele__35","nrgy	120_200_barrel",40,0,400);
   hclusNrgy_ele__35->SetBinContent(0,0.006584145);
   hclusNrgy_ele__35->SetBinContent(1,0.00933231);
   hclusNrgy_ele__35->SetBinContent(2,0.02815724);
   hclusNrgy_ele__35->SetBinContent(3,0.04883718);
   hclusNrgy_ele__35->SetBinContent(4,0.07307829);
   hclusNrgy_ele__35->SetBinContent(5,0.0957621);
   hclusNrgy_ele__35->SetBinContent(6,0.121217);
   hclusNrgy_ele__35->SetBinContent(7,0.1331486);
   hclusNrgy_ele__35->SetBinContent(8,0.1167856);
   hclusNrgy_ele__35->SetBinContent(9,0.09501781);
   hclusNrgy_ele__35->SetBinContent(10,0.07334165);
   hclusNrgy_ele__35->SetBinContent(11,0.05492895);
   hclusNrgy_ele__35->SetBinContent(12,0.04229884);
   hclusNrgy_ele__35->SetBinContent(13,0.03103136);
   hclusNrgy_ele__35->SetBinContent(14,0.02141279);
   hclusNrgy_ele__35->SetBinContent(15,0.01527522);
   hclusNrgy_ele__35->SetBinContent(16,0.01053463);
   hclusNrgy_ele__35->SetBinContent(17,0.007316989);
   hclusNrgy_ele__35->SetBinContent(18,0.005358922);
   hclusNrgy_ele__35->SetBinContent(19,0.003847431);
   hclusNrgy_ele__35->SetBinContent(20,0.002748165);
   hclusNrgy_ele__35->SetBinContent(21,0.002095476);
   hclusNrgy_ele__35->SetBinContent(22,0.001568744);
   hclusNrgy_ele__35->SetBinContent(23,0.001362632);
   hclusNrgy_ele__35->SetBinContent(24,0.001213773);
   hclusNrgy_ele__35->SetBinContent(25,0.0007900974);
   hclusNrgy_ele__35->SetBinContent(26,0.0006870413);
   hclusNrgy_ele__35->SetBinContent(27,0.0004694782);
   hclusNrgy_ele__35->SetBinContent(28,0.0003435206);
   hclusNrgy_ele__35->SetBinContent(29,0.0002862672);
   hclusNrgy_ele__35->SetBinContent(30,0.0003091686);
   hclusNrgy_ele__35->SetBinContent(31,0.0003206193);
   hclusNrgy_ele__35->SetBinContent(32,0.000183211);
   hclusNrgy_ele__35->SetBinContent(33,0.0001488589);
   hclusNrgy_ele__35->SetBinContent(34,0.0001259576);
   hclusNrgy_ele__35->SetBinContent(35,0.0001488589);
   hclusNrgy_ele__35->SetBinContent(36,0.0001145069);
   hclusNrgy_ele__35->SetBinContent(37,0.0001145069);
   hclusNrgy_ele__35->SetBinContent(38,0.0001374083);
   hclusNrgy_ele__35->SetBinContent(39,6.870413e-05);
   hclusNrgy_ele__35->SetBinContent(40,8.015481e-05);
   hclusNrgy_ele__35->SetBinContent(41,0.0006297878);
   hclusNrgy_ele__35->SetBinError(0,0.0002745778);
   hclusNrgy_ele__35->SetBinError(1,0.0003268966);
   hclusNrgy_ele__35->SetBinError(2,0.0005678202);
   hclusNrgy_ele__35->SetBinError(3,0.0007478097);
   hclusNrgy_ele__35->SetBinError(4,0.0009147659);
   hclusNrgy_ele__35->SetBinError(5,0.001047159);
   hclusNrgy_ele__35->SetBinError(6,0.001178142);
   hclusNrgy_ele__35->SetBinError(7,0.001234764);
   hclusNrgy_ele__35->SetBinError(8,0.001156406);
   hclusNrgy_ele__35->SetBinError(9,0.001043082);
   hclusNrgy_ele__35->SetBinError(10,0.0009164128);
   hclusNrgy_ele__35->SetBinError(11,0.000793079);
   hclusNrgy_ele__35->SetBinError(12,0.0006959532);
   hclusNrgy_ele__35->SetBinError(13,0.000596096);
   hclusNrgy_ele__35->SetBinError(14,0.0004951678);
   hclusNrgy_ele__35->SetBinError(15,0.0004182245);
   hclusNrgy_ele__35->SetBinError(16,0.0003473166);
   hclusNrgy_ele__35->SetBinError(17,0.0002894556);
   hclusNrgy_ele__35->SetBinError(18,0.0002477162);
   hclusNrgy_ele__35->SetBinError(19,0.0002098946);
   hclusNrgy_ele__35->SetBinError(20,0.0001773933);
   hclusNrgy_ele__35->SetBinError(21,0.000154902);
   hclusNrgy_ele__35->SetBinError(22,0.0001340269);
   hclusNrgy_ele__35->SetBinError(23,0.0001249123);
   hclusNrgy_ele__35->SetBinError(24,0.000117892);
   hclusNrgy_ele__35->SetBinError(25,9.511655e-05);
   hclusNrgy_ele__35->SetBinError(26,8.869664e-05);
   hclusNrgy_ele__35->SetBinError(27,7.332018e-05);
   hclusNrgy_ele__35->SetBinError(28,6.2718e-05);
   hclusNrgy_ele__35->SetBinError(29,5.725344e-05);
   hclusNrgy_ele__35->SetBinError(30,5.949952e-05);
   hclusNrgy_ele__35->SetBinError(31,6.059134e-05);
   hclusNrgy_ele__35->SetBinError(32,4.580275e-05);
   hclusNrgy_ele__35->SetBinError(33,4.128604e-05);
   hclusNrgy_ele__35->SetBinError(34,3.797763e-05);
   hclusNrgy_ele__35->SetBinError(35,4.128604e-05);
   hclusNrgy_ele__35->SetBinError(36,3.621025e-05);
   hclusNrgy_ele__35->SetBinError(37,3.621025e-05);
   hclusNrgy_ele__35->SetBinError(38,3.966635e-05);
   hclusNrgy_ele__35->SetBinError(39,2.804834e-05);
   hclusNrgy_ele__35->SetBinError(40,3.029567e-05);
   hclusNrgy_ele__35->SetBinError(41,8.492057e-05);
   hclusNrgy_ele__35->SetEntries(87961);

   ci = TColor::GetColor("#66ccff");
   hclusNrgy_ele__35->SetLineColor(ci);
   hclusNrgy_ele__35->SetLineWidth(3);
   hclusNrgy_ele__35->GetXaxis()->SetLabelFont(42);
   hclusNrgy_ele__35->GetXaxis()->SetLabelSize(0.035);
   hclusNrgy_ele__35->GetXaxis()->SetTitleSize(0.035);
   hclusNrgy_ele__35->GetXaxis()->SetTitleFont(42);
   hclusNrgy_ele__35->GetYaxis()->SetLabelFont(42);
   hclusNrgy_ele__35->GetYaxis()->SetLabelSize(0.035);
   hclusNrgy_ele__35->GetYaxis()->SetTitleSize(0.035);
   hclusNrgy_ele__35->GetYaxis()->SetTitleOffset(0);
   hclusNrgy_ele__35->GetYaxis()->SetTitleFont(42);
   hclusNrgy_ele__35->GetZaxis()->SetLabelFont(42);
   hclusNrgy_ele__35->GetZaxis()->SetLabelSize(0.035);
   hclusNrgy_ele__35->GetZaxis()->SetTitleSize(0.035);
   hclusNrgy_ele__35->GetZaxis()->SetTitleFont(42);
   hclusNrgy_ele__35->Draw("hist same");
   
   TLegend *leg = new TLegend(0.6,0.6,0.9,0.9,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextSize(0.08);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("hclusNrgy_ele","reco ele","lpf");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66ccff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hnrgy_eghlt","HLT ele","lpf");
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
   nrgy_top->Modified();
   h_2->cd();
  
// ------------>Primitives in pad: nrgy_bottom
   TPad *nrgy_bottom = new TPad("nrgy_bottom", "bottom_pad",0,0.1,1,0.35);
   nrgy_bottom->Draw();
   nrgy_bottom->cd();
   nrgy_bottom->Range(-69.1358,0.07142855,424.6914,1.5);
   nrgy_bottom->SetFillColor(0);
   nrgy_bottom->SetBorderMode(0);
   nrgy_bottom->SetBorderSize(2);
   nrgy_bottom->SetGridx();
   nrgy_bottom->SetGridy();
   nrgy_bottom->SetTickx(1);
   nrgy_bottom->SetTicky(1);
   nrgy_bottom->SetLeftMargin(0.14);
   nrgy_bottom->SetRightMargin(0.05);
   nrgy_bottom->SetTopMargin(0);
   nrgy_bottom->SetBottomMargin(0.3);
   nrgy_bottom->SetFrameBorderMode(0);
   nrgy_bottom->SetFrameBorderMode(0);
   
   TH1D *hnrgy_eghlt__36 = new TH1D("hnrgy_eghlt__36","",40,0,400);
   hnrgy_eghlt__36->SetBinContent(0,25.67319);
   hnrgy_eghlt__36->SetBinContent(1,0.2194477);
   hnrgy_eghlt__36->SetBinContent(2,0.1341306);
   hnrgy_eghlt__36->SetBinContent(3,0.3147797);
   hnrgy_eghlt__36->SetBinContent(4,0.8196142);
   hnrgy_eghlt__36->SetBinContent(5,0.9763891);
   hnrgy_eghlt__36->SetBinContent(6,1.051875);
   hnrgy_eghlt__36->SetBinContent(7,1.096243);
   hnrgy_eghlt__36->SetBinContent(8,1.087689);
   hnrgy_eghlt__36->SetBinContent(9,1.107759);
   hnrgy_eghlt__36->SetBinContent(10,1.095362);
   hnrgy_eghlt__36->SetBinContent(11,1.130616);
   hnrgy_eghlt__36->SetBinContent(12,1.117348);
   hnrgy_eghlt__36->SetBinContent(13,1.171648);
   hnrgy_eghlt__36->SetBinContent(14,1.204836);
   hnrgy_eghlt__36->SetBinContent(15,1.210986);
   hnrgy_eghlt__36->SetBinContent(16,1.194184);
   hnrgy_eghlt__36->SetBinContent(17,1.241331);
   hnrgy_eghlt__36->SetBinContent(18,1.260625);
   hnrgy_eghlt__36->SetBinContent(19,1.223579);
   hnrgy_eghlt__36->SetBinContent(20,1.209753);
   hnrgy_eghlt__36->SetBinContent(21,1.30098);
   hnrgy_eghlt__36->SetBinContent(22,1.16984);
   hnrgy_eghlt__36->SetBinContent(23,1.219919);
   hnrgy_eghlt__36->SetBinContent(24,1.117538);
   hnrgy_eghlt__36->SetBinContent(25,1.447496);
   hnrgy_eghlt__36->SetBinContent(26,0.9678024);
   hnrgy_eghlt__36->SetBinContent(27,1.133037);
   hnrgy_eghlt__36->SetBinContent(28,1.432347);
   hnrgy_eghlt__36->SetBinContent(29,1.347181);
   hnrgy_eghlt__36->SetBinContent(30,1.118349);
   hnrgy_eghlt__36->SetBinContent(31,1.119886);
   hnrgy_eghlt__36->SetBinContent(32,1.161363);
   hnrgy_eghlt__36->SetBinContent(33,1.161363);
   hnrgy_eghlt__36->SetBinContent(34,1.161363);
   hnrgy_eghlt__36->SetBinContent(35,1.072027);
   hnrgy_eghlt__36->SetBinContent(36,1.161363);
   hnrgy_eghlt__36->SetBinContent(37,1.393635);
   hnrgy_eghlt__36->SetBinContent(38,0.7742419);
   hnrgy_eghlt__36->SetBinContent(39,1.742044);
   hnrgy_eghlt__36->SetBinContent(40,1.65909);
   hnrgy_eghlt__36->SetBinContent(41,1.119131);
   hnrgy_eghlt__36->SetBinError(0,1.094594);
   hnrgy_eghlt__36->SetBinError(1,0.01928207);
   hnrgy_eghlt__36->SetBinError(2,0.008406248);
   hnrgy_eghlt__36->SetBinError(3,0.01043778);
   hnrgy_eghlt__36->SetBinError(4,0.0159502);
   hnrgy_eghlt__36->SetBinError(5,0.01579825);
   hnrgy_eghlt__36->SetBinError(6,0.01482962);
   hnrgy_eghlt__36->SetBinError(7,0.01458899);
   hnrgy_eghlt__36->SetBinError(8,0.01548721);
   hnrgy_eghlt__36->SetBinError(9,0.01740464);
   hnrgy_eghlt__36->SetBinError(10,0.01964529);
   hnrgy_eghlt__36->SetBinError(11,0.02324224);
   hnrgy_eghlt__36->SetBinError(12,0.02625369);
   hnrgy_eghlt__36->SetBinError(13,0.0317594);
   hnrgy_eghlt__36->SetBinError(14,0.03904531);
   hnrgy_eghlt__36->SetBinError(15,0.04640673);
   hnrgy_eghlt__36->SetBinError(16,0.05529522);
   hnrgy_eghlt__36->SetBinError(17,0.06831919);
   hnrgy_eghlt__36->SetBinError(18,0.08077108);
   hnrgy_eghlt__36->SetBinError(19,0.0931934);
   hnrgy_eghlt__36->SetBinError(20,0.1093249);
   hnrgy_eghlt__36->SetBinError(21,0.1323074);
   hnrgy_eghlt__36->SetBinError(22,0.1410889);
   hnrgy_eghlt__36->SetBinError(23,0.1562419);
   hnrgy_eghlt__36->SetBinError(24,0.1550033);
   hnrgy_eghlt__36->SetBinError(25,0.2339426);
   hnrgy_eghlt__36->SetBinError(26,0.18532);
   hnrgy_eghlt__36->SetBinError(27,0.2518052);
   hnrgy_eghlt__36->SetBinError(28,0.3519041);
   hnrgy_eghlt__36->SetBinError(29,0.3676663);
   hnrgy_eghlt__36->SetBinError(30,0.3072889);
   hnrgy_eghlt__36->SetBinError(31,0.3020606);
   hnrgy_eghlt__36->SetBinError(32,0.4106038);
   hnrgy_eghlt__36->SetBinError(33,0.455524);
   hnrgy_eghlt__36->SetBinError(34,0.4952068);
   hnrgy_eghlt__36->SetBinError(35,0.4291543);
   hnrgy_eghlt__36->SetBinError(36,0.5193772);
   hnrgy_eghlt__36->SetBinError(37,0.596719);
   hnrgy_eghlt__36->SetBinError(38,0.3533915);
   hnrgy_eghlt__36->SetBinError(39,0.9181379);
   hnrgy_eghlt__36->SetBinError(40,0.8176084);
   hnrgy_eghlt__36->SetBinError(41,0.2154139);
   hnrgy_eghlt__36->SetMinimum(0.5);
   hnrgy_eghlt__36->SetMaximum(1.5);
   hnrgy_eghlt__36->SetEntries(522.638);
   hnrgy_eghlt__36->SetMarkerStyle(20);
   hnrgy_eghlt__36->GetXaxis()->SetTitle("nrgy");
   hnrgy_eghlt__36->GetXaxis()->CenterTitle(true);
   hnrgy_eghlt__36->GetXaxis()->SetLabelFont(42);
   hnrgy_eghlt__36->GetXaxis()->SetLabelSize(0.12);
   hnrgy_eghlt__36->GetXaxis()->SetTitleSize(0.3);
   hnrgy_eghlt__36->GetXaxis()->SetTitleOffset(0.4);
   hnrgy_eghlt__36->GetXaxis()->SetTitleFont(42);
   hnrgy_eghlt__36->GetYaxis()->SetTitle("HLT/Reco");
   hnrgy_eghlt__36->GetYaxis()->CenterTitle(true);
   hnrgy_eghlt__36->GetYaxis()->SetLabelFont(42);
   hnrgy_eghlt__36->GetYaxis()->SetLabelSize(0.1);
   hnrgy_eghlt__36->GetYaxis()->SetTitleSize(0.15);
   hnrgy_eghlt__36->GetYaxis()->SetTitleOffset(0.22);
   hnrgy_eghlt__36->GetYaxis()->SetTitleFont(42);
   hnrgy_eghlt__36->GetZaxis()->SetLabelFont(42);
   hnrgy_eghlt__36->GetZaxis()->SetLabelSize(0.035);
   hnrgy_eghlt__36->GetZaxis()->SetTitleSize(0.035);
   hnrgy_eghlt__36->GetZaxis()->SetTitleFont(42);
   hnrgy_eghlt__36->Draw("EP");
   TLine *line = new TLine(0,1,400,1);

   ci = TColor::GetColor("#ff0000");
   line->SetLineColor(ci);
   line->SetLineWidth(2);
   line->Draw();
   nrgy_bottom->Modified();
   h_2->cd();
   h_2->Modified();
   h_2->cd();
   h_2->SetSelected(h_2);
}
