void drawhist(){
gStyle->SetOptStat(0);
TFile*f1=new TFile("./histo.root");
TH1D*h1=(TH1D*)f1->Get("h1_313"); 
TH1D*h2=(TH1D*)f1->Get("h1_372");
h1->SetLineColor(kBlue);
h2->SetLineColor(kGreen+1);
TCanvas* c1 = new TCanvas("c1","c1",900,600);
TLegend*l1 = new TLegend(0.7,0.7,0.85,0.85);
h1->GetXaxis()->SetTitle("P_{T}^{#gamma}");
h1->SetTitle("P_{T}^{#gamma}");
h1->SetMarkerColor(kBlue);
h2->SetMarkerColor(kGreen+1);
h1->SetMarkerStyle(29);
h1->SetMarkerSize(1.2);
h2->SetMarkerStyle(22);
h2->SetMarkerSize(1.2);
l1->AddEntry(h1,"the biggest weight","LP");
l1->AddEntry(h2,"the SM weight","LP");
h1->Draw();
h2->Draw("same");
l1->Draw();

}
