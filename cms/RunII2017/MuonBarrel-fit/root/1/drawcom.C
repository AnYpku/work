void drawcom(){
    gStyle->SetOptStat(0);
//    TFile* fileZA=new TFile("/Users/andy/tmp/True_template-cutLEP-outZA-EWK.root");
//    TFile* fileZA_EWK=new TFile("/Users/andy/tmp/True_template-cutLEP-outZA.root");
    TFile* fileZA=new TFile("/Users/andy/work/cms/RunII/ZAfit/root/True_template-cutlep-outTTA.root");
    TFile* fileZA_EWK=new TFile("/Users/andy/work/cms/RunII/ZAfit/root/True_template-outZA-EWK.root");
//    Double_t lowpt[9]= {25,30,35,40,45,50,60,80,120};
//    Double_t highpt[9]={30,35,40,45,50,60,80,120,400};
    Double_t lowpt[8]= {25,30,35,45,55,65,85,130};
    Double_t highpt[8]={30,35,45,55,65,85,130,400};
    TH1D* h1[8];
    TH1D* h2[8];
    for(Int_t i=0;i<8;i++){
        TLegend*l1=new TLegend(0.8,0.8,0.9,0.9);
        h1[i] =(TH1D*)fileZA->Get(Form("h1_pt%0.f_%0.f",lowpt[i],highpt[i]));
        h2[i] =(TH1D*)fileZA_EWK->Get(Form("h1_pt%0.f_%0.f",lowpt[i],highpt[i]));
        TCanvas*c1=new TCanvas("c1","2017 EWK-ZA vs 2017 TTA",900,600);
        h1[i]->SetLineColor(2);
        h2[i]->SetLineColor(3);
        h2[i]->SetTitle(Form("pt%0.f_%0.f",lowpt[i],highpt[i]));
        l1->AddEntry(h2[i]," TTA","LP");
        l1->AddEntry(h1[i]," EWK-ZA","LP");
        h2[i]->DrawNormalized("HIST");
        h1[i]->DrawNormalized("HIST SAME");
        l1->Draw();
        c1->Print(Form("./2017template-pt%0.f_%0.f.eps",lowpt[i],highpt[i]));
    }

}
