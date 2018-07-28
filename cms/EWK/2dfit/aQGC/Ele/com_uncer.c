void com_uncer(){
 gStyle->SetOptStat(0);
 ifstream f1("ele-uncertainty.txt");
 ifstream f2("muon-uncertainty.txt");
 ifstream f3("uncertaintymm-ele.txt");
 ifstream f4("uncertaintymm-muon.txt");
 if(!f1.is_open()){cout<<"can not open the file f1"<<endl;}
 if(!f2.is_open()){cout<<"can not open the file f2"<<endl;}
 if(!f3.is_open()){cout<<"can not open the file f3"<<endl;}
 if(!f4.is_open()){cout<<"can not open the file f4"<<endl;}
 Double_t ele[5],muon[5];
 Double_t elemm[5],muonmm[5];
 for(Int_t i=0;i<5;i++){
      f1>>ele[i];
      f2>>muon[i];
      f3>>elemm[i];
      f4>>muonmm[i];
    }
Double_t ZGmass_bins[6]={150, 250, 350, 400,600,800};
TH1D* h1 =new TH1D("h1","uncertainty",5,ZGmass_bins);
TH1D* h2 =new TH1D("h2","",5,ZGmass_bins);
TH1D* h3 =new TH1D("h3","",5,ZGmass_bins);
TH1D* h4 =new TH1D("h4","",5,ZGmass_bins);
TCanvas* can = new TCanvas("can","uncertainty",900,600);
TLegend* l1 = new TLegend(0.65,0.8,0.75,0.9);
can->SetGrid();
const char *name[6]={"Za 100~250","Za 250~350","Za 350~400","Za 400~600","Za 600~infi"};

 for(Int_t i=0;i<5;i++){
    h2->SetBinContent(i+1,ele[i]);
    h1->SetBinContent(i+1,muon[i]);
    h3->SetBinContent(i+1,elemm[i]);
    h4->SetBinContent(i+1,muonmm[i]);
    h1->GetXaxis()->SetBinLabel(i+1,name[i]);
  }
    h1->SetTitle("uncertainty;;uncertainty");
    h1->GetYaxis()->CenterTitle();
    h1->GetYaxis()->SetRangeUser(0.1,0.4);
    h1->GetYaxis()->SetTitleFont(22);
    h1->GetYaxis()->SetLabelFont(32);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetTitleSize(0.06);
    h1->GetYaxis()->SetTitleOffset(0.85);
    h1->GetXaxis()->SetTitle("Z+#gamma mass/GeV/c^{2}");
    h1->GetXaxis()->CenterTitle();
    h1->GetXaxis()->SetTitleFont(22);
    h1->GetXaxis()->SetTitleOffset(0.8);
    h1->GetXaxis()->SetTitleSize(0.05);
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetXaxis()->SetLabelFont(32);
    h1->SetMarkerStyle(29);
    h1->SetMarkerColor(kRed);
    h1->SetMarkerSize(1.5);
    h2->SetMarkerStyle(22);
    h2->SetMarkerSize(1.5);
    h3->SetMarkerStyle(22);
    h3->SetMarkerSize(1.5);
    h4->SetMarkerStyle(29);
    h4->SetMarkerColor(kRed);
    h4->SetMarkerSize(1.5);
    l1->AddEntry(h1,"muon","LP");
    l1->AddEntry(h2,"electron","LP");
    h1->Draw("P");
    h2->Draw("P same");
    h2->Draw("P same");
    h3->Draw("P same");
    h4->Draw("P same");
    l1->Draw();








}
