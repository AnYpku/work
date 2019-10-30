using namespace RooFit;
void Hgg(){
    gStyle->SetOptStat(0);
ifstream file("Hgg.txt");
Double_t data[30770],a,x[30770];
int k=30770,i=0;
TH1D* h1 = new TH1D("h1","Higgs mass",30,110,160);
TFile* f1 = new TFile("Hgg2.root","RECREATE");
TTree* tree = new TTree("tree","tree");
tree->Branch("hgg",&a,"hgg/D");
while(i<30770){
file>>data[i];
a=data[i];
h1->Fill(data[i]);
tree->Fill();
x[i]=i;
i++;
}
TGraph* gr =new TGraph(30770,x,data);
TCanvas* c1 = new TCanvas("c1","",900,600);
c1->SetGrid();
h1->Draw("P");
gr->Draw("AP");
h1->SetMarkerStyle(22);
h1->GetXaxis()->SetLabelFont(22);
h1->GetXaxis()->SetTitleFont(32);
h1->GetYaxis()->SetTitle("Events/1.67GeV/c^{2}");
h1->GetYaxis()->SetLabelFont(22);
h1->GetYaxis()->SetTitleFont(32);
h1->GetXaxis()->SetTitle("M_{#gamma#gamma}");
h1->GetYaxis()->CenterTitle();
h1->GetXaxis()->CenterTitle();
c1->SaveAs("Hgg.eps");
tree->Write();
h1->Write();
f1->Close();
}
