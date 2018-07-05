void com(){

  TString b="photonet";
  Int_t bin=100;
  Double_t low = 0;
  Double_t high= 100 ;
  Double_t scalef;
  Double_t lumiWeight;
  Double_t pileupWeight;
  Double_t photonet;
  Double_t tmp1,tmp2;
  TFile *f1=new TFile("outofficial_ZA.root");
  TTree *t1=(TTree *)f1->Get("demo");
  TH1D *h1=new TH1D("h1",b,bin,low,high);
  Long64_t en1=t1->GetEntries();
  t1->SetBranchAddress("scalef",&scalef);
  t1->SetBranchAddress("lumiWeight",&lumiWeight);
  t1->SetBranchAddress("pileupWeight",&pileupWeight);
  t1->SetBranchAddress(b,&photonet);
  for (Long64_t i = 0; i < en1; i++) {
    /* code */
    t1->GetEntry(i);
    tmp1=scalef*lumiWeight*pileupWeight;
    h1->Fill(photonet,tmp1);
  }

  Double_t scalef2;
  Double_t lumiWeight2;
  Double_t pileupWeight2;
  Double_t photonet2;
//  Int_t nVtx2; 
  TFile *f2=new TFile("outprivate_ZA.root");
  TTree *t2=(TTree *)f2->Get("demo");
  TH1D *h2=new TH1D("h2",b,bin,low,high);
  Long64_t en2=t2->GetEntries();
  t2->SetBranchAddress("scalef",&scalef2);
  t2->SetBranchAddress("lumiWeight",&lumiWeight2);
  t2->SetBranchAddress("pileupWeight",&pileupWeight2);
  t2->SetBranchAddress(b,&photonet2);
//  t2->SetBranchAddress(b,&photonet2);
//  t2->SetBranchAddress(b,&Mjj2);
//  t2->SetBranchAddress(b,&nVtx2);
  for (Long64_t j = 0; j <en2; j++) {
    /* code */
    t2->GetEntry(j);
    tmp2=scalef2*lumiWeight2*pileupWeight2;
    h2->Fill(photonet2,tmp2);
  }

  TH1D *h3 = (TH1D *)h2->Clone();
  h3->Divide(h1);
//  TF1*fun=new TF1("fun","[0]*x+[1]",low,high);
//h3->Divide(h1);


      TCanvas *c1= new TCanvas("c1","test graph",750,500);
      gStyle->SetPadBorderMode(0);
      gStyle->SetOptStat(0);
      gStyle->SetPadGridX(1);
      gStyle->SetPadGridY(1);
      gStyle->SetPadTickX(1);
      gStyle->SetPadTickY(1);
      gStyle->SetPadTopMargin(0.07);
      gStyle->SetPadBottomMargin(0.3);
      gStyle->SetPadRightMargin(0.05);
      gStyle->SetPadLeftMargin(0.14);
      gStyle->SetPadTickX(1);
      gStyle->SetPadTickY(1);
      gStyle->SetAxisColor(1, "XYZ");
      gStyle->SetStripDecimals(kTRUE);
      gStyle->SetTickLength(0.03, "XYZ");
      gStyle->SetNdivisions(510, "XYZ");


      TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
      top_pad->Draw();
      top_pad->cd();
      top_pad->SetBottomMargin(0.1);

      //top_pad->SetLogy();


      h1->SetLineColor(kRed);
      h1->SetLineWidth(3);
      h1->SetMarkerStyle(20);
      h1->Draw("HIST");

      h2->SetLineColor(kBlue);
      h2->SetLineWidth(4);
      h2->SetLineStyle(5);
      h2->SetMarkerStyle(20);
      h2->Draw("HIST same");


      TLegend *l1 = new TLegend(0.65,0.65,0.78,0.82);
      l1->SetBorderSize(1);
      l1->SetFillColor(0);
      l1->AddEntry(h1,"Offical");
      l1->AddEntry(h2,"private");
      l1->AddEntry(h3,"private/Offical");
      l1->Draw();

      c1->cd();
      TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
      bottom_pad->Draw();
      bottom_pad->cd();
      bottom_pad->SetTopMargin(0);
//      fun->SetParameters(0,1);
//      fun->SetLineColor(2);
      h3->Draw("HIST");
//      h3->Fit("fun","R");
      h3->SetTitle("");
      h3->GetXaxis()->SetTitle( b+" [GeV] ");
      h3->GetYaxis()->SetTitle("K factor ");
      h3->GetXaxis()->CenterTitle();
      h3->GetYaxis()->CenterTitle();
      h3->SetLineColor(kBlack);
      h3->GetXaxis()->SetTitleOffset(0.9);
      h3->GetYaxis()->SetTitleOffset(0.22);
      h3->GetXaxis()->SetTitleSize(0.15);
      h3->GetYaxis()->SetTitleSize(0.15);
      h3->GetXaxis()->SetLabelSize(0.12);
      h3->GetYaxis()->SetLabelSize(0.1);
      h3->SetMaximum(1.35);
      h3->SetMinimum(0.7);
//      c1->Draw();
      c1->Print(b+".eps");
      c1->Print(b+".png");
      c1->Print(b+".pdf");





}
