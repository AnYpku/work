void sieie_0515()
{
//=========Macro generated from canvas: c1/Zjets and leading photon
//=========  (Tue May 15 13:52:24 2018) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "Zjets and leading photon",0,45,900,600);
   gStyle->SetOptStat(0);
   c1->Range(-0.00225,-350.4437,0.02025,3153.993);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *h11__1 = new TH1D("h11__1","Barrel Region",10,0,0.018);
   h11__1->SetBinContent(0,568114.9);
   h11__1->SetBinContent(1,10.67681);
   h11__1->SetBinContent(2,5.733336);
   h11__1->SetBinContent(3,16.81889);
   h11__1->SetBinContent(4,84.49353);
   h11__1->SetBinContent(5,1194.06);
   h11__1->SetBinContent(6,2670.047);
   h11__1->SetBinContent(7,1387.231);
   h11__1->SetBinContent(8,1097.627);
   h11__1->SetBinContent(9,819.4053);
   h11__1->SetBinContent(10,554.5781);
   h11__1->SetBinContent(11,13149.45);
   h11__1->SetBinError(0,272.7556);
   h11__1->SetBinError(1,0.9911035);
   h11__1->SetBinError(2,0.8248791);
   h11__1->SetBinError(3,1.39412);
   h11__1->SetBinError(4,3.191656);
   h11__1->SetBinError(5,11.49459);
   h11__1->SetBinError(6,17.59867);
   h11__1->SetBinError(7,13.97076);
   h11__1->SetBinError(8,12.56272);
   h11__1->SetBinError(9,10.93645);
   h11__1->SetBinError(10,8.88003);
   h11__1->SetBinError(11,44.7821);
   h11__1->SetEntries(9159867);
   h11__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   h11__1->SetLineColor(ci);
   h11__1->SetLineWidth(3);
   h11__1->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
   h11__1->GetXaxis()->SetLabelFont(42);
   h11__1->GetXaxis()->SetLabelSize(0.035);
   h11__1->GetXaxis()->SetTitleSize(0.035);
   h11__1->GetXaxis()->SetTitleFont(42);
   h11__1->GetYaxis()->SetTitle("count");
   h11__1->GetYaxis()->SetLabelFont(42);
   h11__1->GetYaxis()->SetLabelSize(0.035);
   h11__1->GetYaxis()->SetTitleSize(0.035);
   h11__1->GetYaxis()->SetTitleOffset(0);
   h11__1->GetYaxis()->SetTitleFont(42);
   h11__1->GetZaxis()->SetLabelFont(42);
   h11__1->GetZaxis()->SetLabelSize(0.035);
   h11__1->GetZaxis()->SetTitleSize(0.035);
   h11__1->GetZaxis()->SetTitleFont(42);
   h11__1->Draw("HIST");
   
   TPaveText *pt = new TPaveText(0.3842094,0.9365652,0.6157906,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Barrel Region");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
