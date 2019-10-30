void th2draw(){

TFile* file = new TFile("th2-histo.root");
TH2D* h2[103];
TCanvas* c[103];
for(Int_t i=0;i<103;i++){
    c[i] = new TCanvas(Form("c%d",i+1),Form("Mjj vs deltaeatjj %d histo",i+1),900,600);
    h2[i] = (TH2D*)file->Get(Form("th2_%d",i));
    h2[i]->Draw("COLZTEXTE");
    h2[i]->SetMarkerSize(1.8);

    } 










}
