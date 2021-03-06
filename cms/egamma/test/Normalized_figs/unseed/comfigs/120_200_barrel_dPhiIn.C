void 120_200_barrel_dPhiIn()
{
//=========Macro generated from canvas: h_5/dPhiIn
//=========  (Thu Oct 24 10:54:31 2019) by ROOT version6.10/08
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
   dPhiIn_top->Range(-0.008641975,-0.002068666,0.05308642,0.4116646);
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
   
   TH1D *hphiin_eghlt__43 = new TH1D("hphiin_eghlt__43","L1 Seed, Z mass with 120_200 in the barrel region",40,0,0.05);
   hphiin_eghlt__43->SetBinContent(0,0.1819106);
   hphiin_eghlt__43->SetBinContent(1,0.3526583);
   hphiin_eghlt__43->SetBinContent(2,0.200186);
   hphiin_eghlt__43->SetBinContent(3,0.1172952);
   hphiin_eghlt__43->SetBinContent(4,0.08);
   hphiin_eghlt__43->SetBinContent(5,0.05690161);
   hphiin_eghlt__43->SetBinContent(6,0.04108766);
   hphiin_eghlt__43->SetBinContent(7,0.02988193);
   hphiin_eghlt__43->SetBinContent(8,0.02271199);
   hphiin_eghlt__43->SetBinContent(9,0.01741682);
   hphiin_eghlt__43->SetBinContent(10,0.01355277);
   hphiin_eghlt__43->SetBinContent(11,0.009516995);
   hphiin_eghlt__43->SetBinContent(12,0.008529517);
   hphiin_eghlt__43->SetBinContent(13,0.006711986);
   hphiin_eghlt__43->SetBinContent(14,0.005423971);
   hphiin_eghlt__43->SetBinContent(15,0.004336315);
   hphiin_eghlt__43->SetBinContent(16,0.003949911);
   hphiin_eghlt__43->SetBinContent(17,0.003391771);
   hphiin_eghlt__43->SetBinContent(18,0.003105546);
   hphiin_eghlt__43->SetBinContent(19,0.002418605);
   hphiin_eghlt__43->SetBinContent(20,0.002275492);
   hphiin_eghlt__43->SetBinContent(21,0.001903399);
   hphiin_eghlt__43->SetBinContent(22,0.00168873);
   hphiin_eghlt__43->SetBinContent(23,0.001531306);
   hphiin_eghlt__43->SetBinContent(24,0.00145975);
   hphiin_eghlt__43->SetBinContent(25,0.001373882);
   hphiin_eghlt__43->SetBinContent(26,0.001259392);
   hphiin_eghlt__43->SetBinContent(27,0.0010161);
   hphiin_eghlt__43->SetBinContent(28,0.0009302326);
   hphiin_eghlt__43->SetBinContent(29,0.0008586762);
   hphiin_eghlt__43->SetBinContent(30,0.0007728086);
   hphiin_eghlt__43->SetBinContent(31,0.0006296959);
   hphiin_eghlt__43->SetBinContent(32,0.0006010733);
   hphiin_eghlt__43->SetBinContent(33,0.000686941);
   hphiin_eghlt__43->SetBinContent(34,0.0006726297);
   hphiin_eghlt__43->SetBinContent(35,0.0008014311);
   hphiin_eghlt__43->SetBinContent(36,0.000529517);
   hphiin_eghlt__43->SetBinContent(37,0.0005152057);
   hphiin_eghlt__43->SetBinContent(38,0.0006153846);
   hphiin_eghlt__43->SetBinContent(39,0.0004436494);
   hphiin_eghlt__43->SetBinContent(40,0.0003577818);
   hphiin_eghlt__43->SetBinContent(41,0.07692308);
   hphiin_eghlt__43->SetBinError(0,0.001613497);
   hphiin_eghlt__43->SetBinError(1,0.00224655);
   hphiin_eghlt__43->SetBinError(2,0.001692606);
   hphiin_eghlt__43->SetBinError(3,0.001295625);
   hphiin_eghlt__43->SetBinError(4,0.001070001);
   hphiin_eghlt__43->SetBinError(5,0.0009024047);
   hphiin_eghlt__43->SetBinError(6,0.0007668224);
   hphiin_eghlt__43->SetBinError(7,0.0006539483);
   hphiin_eghlt__43->SetBinError(8,0.0005701205);
   hphiin_eghlt__43->SetBinError(9,0.0004992562);
   hphiin_eghlt__43->SetBinError(10,0.0004404059);
   hphiin_eghlt__43->SetBinError(11,0.0003690532);
   hphiin_eghlt__43->SetBinError(12,0.0003493826);
   hphiin_eghlt__43->SetBinError(13,0.0003099307);
   hphiin_eghlt__43->SetBinError(14,0.0002786107);
   hphiin_eghlt__43->SetBinError(15,0.0002491148);
   hphiin_eghlt__43->SetBinError(16,0.0002377567);
   hphiin_eghlt__43->SetBinError(17,0.0002203192);
   hphiin_eghlt__43->SetBinError(18,0.0002108182);
   hphiin_eghlt__43->SetBinError(19,0.0001860465);
   hphiin_eghlt__43->SetBinError(20,0.0001804582);
   hphiin_eghlt__43->SetBinError(21,0.0001650456);
   hphiin_eghlt__43->SetBinError(22,0.0001554602);
   hphiin_eghlt__43->SetBinError(23,0.0001480369);
   hphiin_eghlt__43->SetBinError(24,0.0001445367);
   hphiin_eghlt__43->SetBinError(25,0.0001402212);
   hphiin_eghlt__43->SetBinError(26,0.0001342516);
   hphiin_eghlt__43->SetBinError(27,0.0001205889);
   hphiin_eghlt__43->SetBinError(28,0.0001153811);
   hphiin_eghlt__43->SetBinError(29,0.0001108546);
   hphiin_eghlt__43->SetBinError(30,0.0001051659);
   hphiin_eghlt__43->SetBinError(31,9.493023e-05);
   hphiin_eghlt__43->SetBinError(32,9.274763e-05);
   hphiin_eghlt__43->SetBinError(33,9.915139e-05);
   hphiin_eghlt__43->SetBinError(34,9.811312e-05);
   hphiin_eghlt__43->SetBinError(35,0.0001070957);
   hphiin_eghlt__43->SetBinError(36,8.705206e-05);
   hphiin_eghlt__43->SetBinError(37,8.586762e-05);
   hphiin_eghlt__43->SetBinError(38,9.384527e-05);
   hphiin_eghlt__43->SetBinError(39,7.968178e-05);
   hphiin_eghlt__43->SetBinError(40,7.155635e-05);
   hphiin_eghlt__43->SetBinError(41,0.001049222);
   hphiin_eghlt__43->SetEntries(87961);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3366ff");
   hphiin_eghlt__43->SetLineColor(ci);
   hphiin_eghlt__43->SetLineStyle(5);
   hphiin_eghlt__43->SetLineWidth(4);
   hphiin_eghlt__43->GetXaxis()->SetLabelFont(42);
   hphiin_eghlt__43->GetXaxis()->SetLabelSize(0.035);
   hphiin_eghlt__43->GetXaxis()->SetTitleSize(0.035);
   hphiin_eghlt__43->GetXaxis()->SetTitleFont(42);
   hphiin_eghlt__43->GetYaxis()->SetLabelFont(42);
   hphiin_eghlt__43->GetYaxis()->SetLabelSize(0.035);
   hphiin_eghlt__43->GetYaxis()->SetTitleSize(0.035);
   hphiin_eghlt__43->GetYaxis()->SetTitleOffset(0);
   hphiin_eghlt__43->GetYaxis()->SetTitleFont(42);
   hphiin_eghlt__43->GetZaxis()->SetLabelFont(42);
   hphiin_eghlt__43->GetZaxis()->SetLabelSize(0.035);
   hphiin_eghlt__43->GetZaxis()->SetTitleSize(0.035);
   hphiin_eghlt__43->GetZaxis()->SetTitleFont(42);
   hphiin_eghlt__43->Draw("hist");
   
   TH1D *hPhiIn_ele__44 = new TH1D("hPhiIn_ele__44","dPhiIn	120_200_barrel",40,0,0.05);
   hPhiIn_ele__44->SetBinContent(0,0.9731683);
   hPhiIn_ele__44->SetBinContent(1,0.3090298);
   hPhiIn_ele__44->SetBinContent(2,0.1944047);
   hPhiIn_ele__44->SetBinContent(3,0.1194906);
   hPhiIn_ele__44->SetBinContent(4,0.08106754);
   hPhiIn_ele__44->SetBinContent(5,0.05957832);
   hPhiIn_ele__44->SetBinContent(6,0.04171437);
   hPhiIn_ele__44->SetBinContent(7,0.03391528);
   hPhiIn_ele__44->SetBinContent(8,0.02647396);
   hPhiIn_ele__44->SetBinContent(9,0.02074986);
   hPhiIn_ele__44->SetBinContent(10,0.01583667);
   hPhiIn_ele__44->SetBinContent(11,0.01259302);
   hPhiIn_ele__44->SetBinContent(12,0.01125739);
   hPhiIn_ele__44->SetBinContent(13,0.008466896);
   hPhiIn_ele__44->SetBinContent(14,0.006892769);
   hPhiIn_ele__44->SetBinContent(15,0.006201107);
   hPhiIn_ele__44->SetBinContent(16,0.005533295);
   hPhiIn_ele__44->SetBinContent(17,0.004293074);
   hPhiIn_ele__44->SetBinContent(18,0.004340775);
   hPhiIn_ele__44->SetBinContent(19,0.003267506);
   hPhiIn_ele__44->SetBinContent(20,0.003315207);
   hPhiIn_ele__44->SetBinContent(21,0.003100553);
   hPhiIn_ele__44->SetBinContent(22,0.002647396);
   hPhiIn_ele__44->SetBinContent(23,0.002981301);
   hPhiIn_ele__44->SetBinContent(24,0.002671246);
   hPhiIn_ele__44->SetBinContent(25,0.002408891);
   hPhiIn_ele__44->SetBinContent(26,0.001526426);
   hPhiIn_ele__44->SetBinContent(27,0.001836482);
   hPhiIn_ele__44->SetBinContent(28,0.001597977);
   hPhiIn_ele__44->SetBinContent(29,0.001550277);
   hPhiIn_ele__44->SetBinContent(30,0.001311773);
   hPhiIn_ele__44->SetBinContent(31,0.001287922);
   hPhiIn_ele__44->SetBinContent(32,0.001240221);
   hPhiIn_ele__44->SetBinContent(33,0.001335623);
   hPhiIn_ele__44->SetBinContent(34,0.001097119);
   hPhiIn_ele__44->SetBinContent(35,0.000930166);
   hPhiIn_ele__44->SetBinContent(36,0.001049418);
   hPhiIn_ele__44->SetBinContent(37,0.0008109139);
   hPhiIn_ele__44->SetBinContent(38,0.0007393627);
   hPhiIn_ele__44->SetBinContent(39,0.0007393627);
   hPhiIn_ele__44->SetBinContent(40,0.0007155123);
   hPhiIn_ele__44->SetBinContent(41,0.1247376);
   hPhiIn_ele__44->SetBinError(0,0.004817724);
   hPhiIn_ele__44->SetBinError(1,0.002714864);
   hPhiIn_ele__44->SetBinError(2,0.002153284);
   hPhiIn_ele__44->SetBinError(3,0.001688164);
   hPhiIn_ele__44->SetBinError(4,0.001390501);
   hPhiIn_ele__44->SetBinError(5,0.001192043);
   hPhiIn_ele__44->SetBinError(6,0.0009974491);
   hPhiIn_ele__44->SetBinError(7,0.000899385);
   hPhiIn_ele__44->SetBinError(8,0.0007946161);
   hPhiIn_ele__44->SetBinError(9,0.000703486);
   hPhiIn_ele__44->SetBinError(10,0.0006145821);
   hPhiIn_ele__44->SetBinError(11,0.0005480407);
   hPhiIn_ele__44->SetBinError(12,0.0005181635);
   hPhiIn_ele__44->SetBinError(13,0.0004493762);
   hPhiIn_ele__44->SetBinError(14,0.000405457);
   hPhiIn_ele__44->SetBinError(15,0.0003845763);
   hPhiIn_ele__44->SetBinError(16,0.0003632786);
   hPhiIn_ele__44->SetBinError(17,0.0003199868);
   hPhiIn_ele__44->SetBinError(18,0.0003217596);
   hPhiIn_ele__44->SetBinError(19,0.0002791619);
   hPhiIn_ele__44->SetBinError(20,0.0002811922);
   hPhiIn_ele__44->SetBinError(21,0.0002719365);
   hPhiIn_ele__44->SetBinError(22,0.0002512797);
   hPhiIn_ele__44->SetBinError(23,0.0002666557);
   hPhiIn_ele__44->SetBinError(24,0.000252409);
   hPhiIn_ele__44->SetBinError(25,0.0002396937);
   hPhiIn_ele__44->SetBinError(26,0.0001908033);
   hPhiIn_ele__44->SetBinError(27,0.0002092865);
   hPhiIn_ele__44->SetBinError(28,0.000195224);
   hPhiIn_ele__44->SetBinError(29,0.0001922882);
   hPhiIn_ele__44->SetBinError(30,0.0001768794);
   hPhiIn_ele__44->SetBinError(31,0.000175264);
   hPhiIn_ele__44->SetBinError(32,0.0001719878);
   hPhiIn_ele__44->SetBinError(33,0.0001784801);
   hPhiIn_ele__44->SetBinError(34,0.0001617614);
   hPhiIn_ele__44->SetBinError(35,0.0001489458);
   hPhiIn_ele__44->SetBinError(36,0.0001582057);
   hPhiIn_ele__44->SetBinError(37,0.0001390706);
   hPhiIn_ele__44->SetBinError(38,0.0001327935);
   hPhiIn_ele__44->SetBinError(39,0.0001327935);
   hPhiIn_ele__44->SetBinError(40,0.0001306341);
   hPhiIn_ele__44->SetBinError(41,0.001724832);
   hPhiIn_ele__44->SetEntries(87961);

   ci = TColor::GetColor("#66ccff");
   hPhiIn_ele__44->SetLineColor(ci);
   hPhiIn_ele__44->SetLineWidth(3);
   hPhiIn_ele__44->GetXaxis()->SetLabelFont(42);
   hPhiIn_ele__44->GetXaxis()->SetLabelSize(0.035);
   hPhiIn_ele__44->GetXaxis()->SetTitleSize(0.035);
   hPhiIn_ele__44->GetXaxis()->SetTitleFont(42);
   hPhiIn_ele__44->GetYaxis()->SetLabelFont(42);
   hPhiIn_ele__44->GetYaxis()->SetLabelSize(0.035);
   hPhiIn_ele__44->GetYaxis()->SetTitleSize(0.035);
   hPhiIn_ele__44->GetYaxis()->SetTitleOffset(0);
   hPhiIn_ele__44->GetYaxis()->SetTitleFont(42);
   hPhiIn_ele__44->GetZaxis()->SetLabelFont(42);
   hPhiIn_ele__44->GetZaxis()->SetLabelSize(0.035);
   hPhiIn_ele__44->GetZaxis()->SetTitleSize(0.035);
   hPhiIn_ele__44->GetZaxis()->SetTitleFont(42);
   hPhiIn_ele__44->Draw("hist same");
   
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
   
   TPaveText *pt = new TPaveText(0.2405568,0.9339967,0.7594432,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("L1 Seed, Z mass with 120_200 in the barrel region");
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
   
   TH1D *hphiin_eghlt__45 = new TH1D("hphiin_eghlt__45","",40,0,0.05);
   hphiin_eghlt__45->SetBinContent(0,0.1869261);
   hphiin_eghlt__45->SetBinContent(1,1.141179);
   hphiin_eghlt__45->SetBinContent(2,1.029739);
   hphiin_eghlt__45->SetBinContent(3,0.9816271);
   hphiin_eghlt__45->SetBinContent(4,0.9868314);
   hphiin_eghlt__45->SetBinContent(5,0.9550723);
   hphiin_eghlt__45->SetBinContent(6,0.9849761);
   hphiin_eghlt__45->SetBinContent(7,0.8810757);
   hphiin_eghlt__45->SetBinContent(8,0.8578992);
   hphiin_eghlt__45->SetBinContent(9,0.8393704);
   hphiin_eghlt__45->SetBinContent(10,0.8557841);
   hphiin_eghlt__45->SetBinContent(11,0.7557359);
   hphiin_eghlt__45->SetBinContent(12,0.7576813);
   hphiin_eghlt__45->SetBinContent(13,0.7927328);
   hphiin_eghlt__45->SetBinContent(14,0.7869075);
   hphiin_eghlt__45->SetBinContent(15,0.6992808);
   hphiin_eghlt__45->SetBinContent(16,0.7138442);
   hphiin_eghlt__45->SetBinContent(17,0.7900565);
   hphiin_eghlt__45->SetBinContent(18,0.7154358);
   hphiin_eghlt__45->SetBinContent(19,0.7401989);
   hphiin_eghlt__45->SetBinContent(20,0.68638);
   hphiin_eghlt__45->SetBinContent(21,0.6138901);
   hphiin_eghlt__45->SetBinContent(22,0.6378835);
   hphiin_eghlt__45->SetBinContent(23,0.5136368);
   hphiin_eghlt__45->SetBinContent(24,0.5464677);
   hphiin_eghlt__45->SetBinContent(25,0.5703378);
   hphiin_eghlt__45->SetBinContent(26,0.825059);
   hphiin_eghlt__45->SetBinContent(27,0.5532863);
   hphiin_eghlt__45->SetBinContent(28,0.5821312);
   hphiin_eghlt__45->SetBinContent(29,0.5538858);
   hphiin_eghlt__45->SetBinContent(30,0.5891331);
   hphiin_eghlt__45->SetBinContent(31,0.4889239);
   hphiin_eghlt__45->SetBinContent(32,0.4846501);
   hphiin_eghlt__45->SetBinContent(33,0.5143225);
   hphiin_eghlt__45->SetBinContent(34,0.6130873);
   hphiin_eghlt__45->SetBinContent(35,0.8616001);
   hphiin_eghlt__45->SetBinContent(36,0.5045816);
   hphiin_eghlt__45->SetBinContent(37,0.6353396);
   hphiin_eghlt__45->SetBinContent(38,0.8323176);
   hphiin_eghlt__45->SetBinContent(39,0.6000429);
   hphiin_eghlt__45->SetBinContent(40,0.5000358);
   hphiin_eghlt__45->SetBinContent(41,0.6166789);
   hphiin_eghlt__45->SetBinError(0,0.00189875);
   hphiin_eghlt__45->SetBinError(1,0.01238374);
   hphiin_eghlt__45->SetBinError(2,0.01434904);
   hphiin_eghlt__45->SetBinError(3,0.01760404);
   hphiin_eghlt__45->SetBinError(4,0.02146432);
   hphiin_eghlt__45->SetBinError(5,0.0243839);
   hphiin_eghlt__45->SetBinError(6,0.02987688);
   hphiin_eghlt__45->SetBinError(7,0.03029366);
   hphiin_eghlt__45->SetBinError(8,0.0335681);
   hphiin_eghlt__45->SetBinError(9,0.03726576);
   hphiin_eghlt__45->SetBinError(10,0.04331646);
   hphiin_eghlt__45->SetBinError(11,0.04405168);
   hphiin_eghlt__45->SetBinError(12,0.04668508);
   hphiin_eghlt__45->SetBinError(13,0.05576861);
   hphiin_eghlt__45->SetBinError(14,0.06145304);
   hphiin_eghlt__45->SetBinError(15,0.05911502);
   hphiin_eghlt__45->SetBinError(16,0.06358237);
   hphiin_eghlt__45->SetBinError(17,0.07811164);
   hphiin_eghlt__45->SetBinError(18,0.07191038);
   hphiin_eghlt__45->SetBinError(19,0.08509529);
   hphiin_eghlt__45->SetBinError(20,0.07970156);
   hphiin_eghlt__45->SetBinError(21,0.07571309);
   hphiin_eghlt__45->SetBinError(22,0.08434447);
   hphiin_eghlt__45->SetBinError(23,0.06764772);
   hphiin_eghlt__45->SetBinError(24,0.07479323);
   hphiin_eghlt__45->SetBinError(25,0.08129597);
   hphiin_eghlt__45->SetBinError(26,0.1355425);
   hphiin_eghlt__45->SetBinError(27,0.09103455);
   hphiin_eghlt__45->SetBinError(28,0.1013477);
   hphiin_eghlt__45->SetBinError(29,0.09916146);
   hphiin_eghlt__45->SetBinError(30,0.1128622);
   hphiin_eghlt__45->SetBinError(31,0.09929584);
   hphiin_eghlt__45->SetBinError(32,0.1005463);
   hphiin_eghlt__45->SetBinError(33,0.1011667);
   hphiin_eghlt__45->SetBinError(34,0.1271557);
   hphiin_eghlt__45->SetBinError(35,0.1796972);
   hphiin_eghlt__45->SetBinError(36,0.1125503);
   hphiin_eghlt__45->SetBinError(37,0.1519372);
   hphiin_eghlt__45->SetBinError(38,0.1961055);
   hphiin_eghlt__45->SetBinError(39,0.1524111);
   hphiin_eghlt__45->SetBinError(40,0.1354103);
   hphiin_eghlt__45->SetBinError(41,0.01197773);
   hphiin_eghlt__45->SetMinimum(0.5);
   hphiin_eghlt__45->SetMaximum(1.5);
   hphiin_eghlt__45->SetEntries(2506.407);
   hphiin_eghlt__45->SetMarkerStyle(20);
   hphiin_eghlt__45->GetXaxis()->SetTitle("dPhiIn");
   hphiin_eghlt__45->GetXaxis()->CenterTitle(true);
   hphiin_eghlt__45->GetXaxis()->SetLabelFont(42);
   hphiin_eghlt__45->GetXaxis()->SetLabelSize(0.12);
   hphiin_eghlt__45->GetXaxis()->SetTitleSize(0.3);
   hphiin_eghlt__45->GetXaxis()->SetTitleOffset(0.4);
   hphiin_eghlt__45->GetXaxis()->SetTitleFont(42);
   hphiin_eghlt__45->GetYaxis()->SetTitle("HLT/Reco");
   hphiin_eghlt__45->GetYaxis()->CenterTitle(true);
   hphiin_eghlt__45->GetYaxis()->SetLabelFont(42);
   hphiin_eghlt__45->GetYaxis()->SetLabelSize(0.1);
   hphiin_eghlt__45->GetYaxis()->SetTitleSize(0.15);
   hphiin_eghlt__45->GetYaxis()->SetTitleOffset(0.22);
   hphiin_eghlt__45->GetYaxis()->SetTitleFont(42);
   hphiin_eghlt__45->GetZaxis()->SetLabelFont(42);
   hphiin_eghlt__45->GetZaxis()->SetLabelSize(0.035);
   hphiin_eghlt__45->GetZaxis()->SetTitleSize(0.035);
   hphiin_eghlt__45->GetZaxis()->SetTitleFont(42);
   hphiin_eghlt__45->Draw("EP");
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
