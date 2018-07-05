void bkg(){
ifstream f1,f2;
TGraph *g1;
TGraph *g2;
TGraph *g3;

f1.open("Eu152_kedu1.txt");
f2.open("bkg.txt");
Double_t x1[1024],y1[1024],y[1024];
Double_t x2[1024],y2[1024];
Int_t nlines=0;
TCanvas* c1 = new TCanvas("c1","Eu152 kedu1",900,600);
c1->SetGrid();
TH1D* h1 = new TH1D("h1","energy spectrum",1024,0,1024);
while(nlines<1024){
   f1>>y1[nlines];
   f2>>y2[nlines];
   y[nlines]=y1[nlines]-y2[nlines];
   x1[nlines]=nlines;
   x2[nlines]=nlines;
   h1->SetBinContent(nlines,y2[nlines]);
   nlines++;
   }
f1.close();
f2.close();

TMultiGraph *mg=new TMultiGraph();
g1 = new TGraph(nlines,x1,y1);
g2 = new TGraph(nlines,x2,y2);
g3 = new TGraph(nlines,x2,y);
//g1->Draw("AP");
//g2->Draw("Same");
//g3->Draw("Same");
g1->SetMarkerStyle(22);
//g2->SetMarkerStyle(22);
g3->SetMarkerStyle(3);
g1->SetMarkerSize(1.0);
g1->SetMarkerColor(kBlue);
g2->SetMarkerColor(kGreen);
g3->SetMarkerColor(kRed);
mg->Add(g1);
mg->Add(g2);
mg->Add(g3);
//mg->Draw("AP");
gStyle->SetOptStat(0);
h1->Draw();
mg->SetTitle("energy spectrum;channel;count");
h1->SetTitle("bkg energy spectrum;channel;count");
h1->SetLineColor(kBlue);
h1->SetLineWidth(2);
h1->GetXaxis()->SetLabelFont(10);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetTitleSize(0.07);
h1->GetXaxis()->SetTitleFont(20);
h1->GetXaxis()->CenterTitle();
h1->GetXaxis()->SetTitleOffset(0.6);

h1->SetTitleFont(20);

h1->GetYaxis()->SetLabelFont(10);
h1->GetYaxis()->SetLabelSize(0.05);
h1->GetYaxis()->CenterTitle();
h1->GetYaxis()->SetTitleSize(0.07);
h1->GetYaxis()->SetTitleFont(20);
h1->GetYaxis()->SetTitleOffset(0.7);
TLegend *l1 = new TLegend(0.7,0.7,0.9,0.9);
l1->AddEntry(g1,"^{60}Co");
l1->AddEntry(g2,"bkg");
l1->AddEntry(g3,"subtract bkg");
//l1->Draw();
//Double_t mu1=f1->GetParameter(1);
//Double_t s1 =f1->GetParameter(2);
//Double_t mu2=f2->GetParameter(1);
//Double_t s2 =f2->GetParameter(2);
//char u1[100],u2[100],sigma1[100],sigma2[100];
//sprintf(u1,"%f",mu1);
//sprintf(u2,"%f",mu2);
//sprintf(sigma1,"%f",s1);
//sprintf(sigma2,"%f",s2);
//TString t1 = "#mu =  ";
//TString t2 = "#sigma =  ";
//TString tt ="  ";
//TString string1 = t1 + u1 +tt+ t2 + sigma1;
//TString string2 = t1 + u2 +tt+ t2 + sigma2;
//
//TPaveText *pt = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
//pt->SetTextSize(0.035);
//TText *text = pt->AddText(string1);
//pt->Draw();
//TPaveText *pt1 = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
//pt1->SetTextSize(0.035);
//TText *text1 = pt1->AddText(string2);
//pt1->Draw();
}
