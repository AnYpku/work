void makePlots_detajj(){

TFile* f16 = new TFile("./16/histos_Muon.root");
TH1D* h16 =(TH1D*)f16->Get("detajj_mu");
TFile* f16ZA = new TFile("./16/histos_ZA.root");
TH1D* h16ZA =(TH1D*)f16ZA->Get("detajj_mu");
TFile* f16ST = new TFile("./16/histos_ST.root");
TH1D*  h16ST =(TH1D*)f16ST->Get("detajj_mu");
TFile* f16VV = new TFile("./16/histos_VV.root");
TH1D*  h16VV =(TH1D*)f16VV->Get("detajj_mu");
TFile* f16plj_mubarrel = new TFile("./16/histos_plj_mubarrel.root");
TH1D*  h16plj_mubarrel =(TH1D*)f16plj_mubarrel->Get("detajj_mu");
TFile* f16WA = new TFile("./16/histos_WA.root");
TH1D*  h16WA =(TH1D*)f16WA->Get("detajj_mu");
TFile* f16TTA = new TFile("./16/histos_TTA.root");
TH1D*  h16TTA =(TH1D*)f16TTA->Get("detajj_mu");
TFile* f16Sig = new TFile("./16/histos_ZA-EWK.root");
TH1D*  h16Sig =(TH1D*)f16Sig->Get("detajj_mu");


TFile* f17 = new TFile("./17/histos_Muon.root");
TH1D*  h17 =(TH1D*)f17->Get("detajj_mu");
TFile* f17ZA = new TFile("./17/histos_ZA.root");
TH1D*  h17ZA =(TH1D*)f17ZA->Get("detajj_mu");
TFile* f17ST = new TFile("./17/histos_ST.root");
TH1D*  h17ST =(TH1D*)f17ST->Get("detajj_mu");
TFile* f17VV = new TFile("./17/histos_VV.root");
TH1D*  h17VV =(TH1D*)f17VV->Get("detajj_mu");
TFile* f17plj_mubarrel = new TFile("./17/histos_plj_mubarrel.root");
TH1D*  h17plj_mubarrel =(TH1D*)f17plj_mubarrel->Get("detajj_mu");
TFile* f17WA = new TFile("./17/histos_WA.root");
TH1D*  h17WA =(TH1D*)f17WA->Get("detajj_mu");
TFile* f17TTA = new TFile("./17/histos_TTA.root");
TH1D*  h17TTA =(TH1D*)f17TTA->Get("detajj_mu");
TFile* f17Sig = new TFile("./17/histos_ZA-EWK.root");
TH1D*  h17Sig =(TH1D*)f17Sig->Get("detajj_mu");

TFile* f18 = new TFile("./18/histos_Muon.root");
TH1D*  h18 =(TH1D*)f18->Get("detajj_mu");
TFile* f18ZA = new TFile("./18/histos_ZA.root");
TH1D*  h18ZA =(TH1D*)f18ZA->Get("detajj_mu");
TFile* f18ST = new TFile("./18/histos_ST.root");
TH1D*  h18ST =(TH1D*)f18ST->Get("detajj_mu");
TFile* f18VV = new TFile("./18/histos_VV.root");
TH1D*  h18VV =(TH1D*)f18VV->Get("detajj_mu");
TFile* f18plj_mubarrel = new TFile("./18/histos_plj_mubarrel.root");
TH1D*  h18plj_mubarrel =(TH1D*)f18plj_mubarrel->Get("detajj_mu");
TFile* f18WA = new TFile("./18/histos_WA.root");
TH1D*  h18WA =(TH1D*)f18WA->Get("detajj_mu");
TFile* f18TTA = new TFile("./18/histos_TTA.root");
TH1D*  h18TTA =(TH1D*)f18TTA->Get("detajj_mu");
TFile* f18Sig = new TFile("./18/histos_ZA-EWK.root");
TH1D*  h18Sig =(TH1D*)f18Sig->Get("detajj_mu");


TH1D* hZA = (TH1D*)h16ZA->Clone("ZA");
hZA->Scale(36);
hZA->Add(h17ZA,41.52);
hZA->Add(h18ZA,59.97);

TH1D* hVV = (TH1D*)h16VV->Clone("VV");
hVV->Scale(36);
hVV->Add(h17VV,41.52);
hVV->Add(h18VV,59.97);

TH1D* hST = (TH1D*)h16ST->Clone("ST");
hST->Scale(36);
hST->Add(h17ST,41.52);
hST->Add(h18ST,59.97);

TH1D* hWA = (TH1D*)h16WA->Clone("WA");
hWA->Scale(36);
hWA->Add(h17WA,41.52);
hWA->Add(h18WA,59.97);

TH1D* hTTA = (TH1D*)h16TTA->Clone("TTA");
hTTA->Scale(36);
hTTA->Add(h17TTA,41.52);
hTTA->Add(h18TTA,59.97);

TH1D* hplj_mubarrel = (TH1D*)h16plj_mubarrel->Clone("plj_mubarrel");
hplj_mubarrel->Add(h17plj_mubarrel);
hplj_mubarrel->Add(h18plj_mubarrel);

TH1D* hSig = (TH1D*)h16Sig->Clone("ZA-EWK");
hSig->Scale(36);
hSig->Add(h17Sig,41.52);
hSig->Add(h18Sig,59.97);

TH1D* hmuon = (TH1D*)h16->Clone("hmuon");
hmuon->Add(h17);
hmuon->Add(h18);

hSig->SetLineColor(kRed);
hZA->SetLineColor(kOrange);
hTTA->SetLineColor(kGreen-7);
hVV->SetLineColor(kGreen-10);
hST->SetLineColor(kBlue-7);
hplj_mubarrel->SetLineColor(kBlue-9);
hWA->SetLineColor(kMagenta);

hSig->SetFillColor(kRed);
hZA ->SetFillColor(kOrange);
hTTA->SetFillColor(kGreen-7);
hVV ->SetFillColor(kGreen-10);
hST ->SetFillColor(kBlue-7);
hWA ->SetFillColor(kMagenta);
hplj_mubarrel->SetFillColor(kBlue-9);

hmuon->SetMarkerStyle(20);
hmuon->SetMarkerColor(1);
hmuon->SetMarkerSize(1.0);

THStack* hs = new THStack("hs", "");
vector<TH1D*> hist;
hist.push_back(hSig);
hist.push_back(hZA);
hist.push_back(hWA);
hist.push_back(hTTA);
hist.push_back(hST);
hist.push_back(hVV);
hist.push_back(hplj_mubarrel);
TLegend* l1 = new TLegend(0.7,0.5,0.9,0.9);
double yieldsData = hmuon->GetSumOfWeights();
char yData[100];sprintf(yData,"%0.f",yieldsData);
TString samplesData = "Data";
TString LabelData = samplesData +" ["+ yData+"]";
cout<<hist[1]->GetName()<<endl;
l1->AddEntry(hmuon,LabelData, "ep");
for(int i=0;i<7;i++){
    double yields = hist[i]->GetSumOfWeights();
    char y[100];sprintf(y,"%.2f",yields);
    TString samples =hist[i]->GetName();
    TString LabelMC = samples +" ["+ y+"]";
    l1->AddEntry(hist[i], LabelMC, "f");
    cout<<LabelMC<<endl;
    hs->Add(hist[i]);
}
TCanvas*c1 = new TCanvas("c1","",900,600);
//hs->GetYaxis()->SetRangeUser(0,1600);
hs->Draw("hist ");
hmuon->Draw("SAME E P");
l1->Draw();
//hSig->Draw("same hist");
//hZA->Draw("same hist");
//hTTA->Draw("same hist");
//hVV->Draw("same hist");
//hST->Draw("same hist");
//hplj_mubarrel->Draw("same hist");
//hWA->Draw("same hist");
TFile * file = new TFile("./fullRunII_Zmass.root","RECREATE");
hmuon->Write();
hZA->Write();
hplj_mubarrel->Write();
}
