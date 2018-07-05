void cal(){
ifstream infile;
TGraph*g[3];
TF1*f[4];
TF1 *ff = new TF1("ff","[0]*x+[1]",0,800);
Double_t u[5];
Double_t E[4]={0.835,1.17,1.33,0.662};
Double_t channel[4]={523,732,833,415};
Double_t EE[5];
TGraph *gg ;
TMultiGraph *mg = new TMultiGraph();
Int_t p=0;
for(Int_t i=0;i<3;i++){
   infile.open(Form("/Users/andy/work/course/2018高核材料/nijuzhen/txt/%d.txt",i),ios::in);
if(!infile.is_open())
   continue;
   
Double_t x[1024],y[1024];
Int_t nlines=0;
while(nlines<1024){
 infile>>y[nlines];
 x[nlines]=nlines;
 nlines++;
 }
infile.close();
cout<<"read the file"<<endl;
g[p] = new TGraph(nlines,x,y);
f[p] = new TF1(Form("f%d",p),"gaus",0,1000);
f[p]->SetParameters(1,1,1);
p++;
}
cout<<"p = "<<p<<endl;
TCanvas *c = new TCanvas("c","count of Cu",0,0,900,600);
//      gStyle->SetPadBorderMode(0);
//      gStyle->SetOptStat(0);
//      gStyle->SetPadGridX(1);
//      gStyle->SetPadGridY(1);
//      gStyle->SetPadTickX(1);
//      gStyle->SetPadTickY(1);
//      gStyle->SetPadTopMargin(0.07);
//      gStyle->SetPadBottomMargin(0.3);
//      gStyle->SetPadRightMargin(0.05);
//      gStyle->SetPadLeftMargin(0.14);
//      gStyle->SetPadTickX(1);
//      gStyle->SetPadTickY(1);
//      gStyle->SetAxisColor(1, "XYZ");
//      gStyle->SetStripDecimals(kTRUE);
//      gStyle->SetTickLength(0.03, "XYZ");

//      TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
//      top_pad->Draw();
//      top_pad->cd();
TLegend *l1=new TLegend(0.6,0.6,0.9,0.9);
l1->AddEntry(g[0],"^{54}Mn ");
l1->AddEntry(g[1],"^{60}Co ");
l1->AddEntry(g[2],"^{137}Cs ");
//l1->AddEntry(g[3],"^{30}Zn ");
//l1->AddEntry(g[4],"^{32}Ge ");
Int_t m=2;  
for(Int_t j=0;j<p;j++){
  g[j]->SetLineColor(j+2);
  g[j]->SetFillColor(j+1);
  g[j]->SetMarkerStyle(7);
  g[j]->SetMarkerColor(j+2);
  g[j]->Fit(Form("f%d",j),"R");
//  mg->Add(g[j]);
  u[j]=f[j]->GetParameter(1);
  m++;
  EE[j]=50*E[j];
 }
gg = new TGraph(4,channel,E);
gg->SetMarkerStyle(22);
gg->SetMarkerSize(2.0);
ff->SetParameters(1,1);
gg->Fit("ff","B");
mg->Add(gg);
mg->Draw("AP");
mg->SetTitle("the energy calibration");
mg->GetXaxis()->SetTitle("channel");
mg->GetXaxis()->CenterTitle();
mg->GetYaxis()->SetTitle("count");
mg->GetYaxis()->CenterTitle();
//l1->Draw();
TString t1="";
TString t;
TString t3="  ";
TString t2;
for(Int_t n=0;n<5;n++){
char mu[100];
sprintf(mu,"%f",u[n]);
t = t3 + mu + t3;
t1 += t;
t2 = "#mu = " + t1;
 }
TPaveText *pt = new TPaveText(0.1,0.5,0.9,0.6,"BRNDC");
pt->SetTextSize(0.035);
TText *text = pt->AddText(t2);
//pt->Draw();

    TLine *line = new TLine(340.9051,269.4072,340.9051,3.387746e-07);
    line->SetLineColor(50);
    line->SetLineStyle(2);
//    line->Draw();
    line = new TLine(406.6389,320.5604,406.6389,-1.136739);
    line->SetLineColor(50);
    line->SetLineStyle(2);
//    line->Draw();
    line = new TLine(514.6302,402.4057,514.6302,3.387746e-07);
    line->SetLineColor(50);
    line->SetLineStyle(2);
//    line->Draw();
    line = new TLine(538.1065,426.2772,538.1065,1.136739);
    line->SetLineColor(50);
    line->SetLineStyle(2);
//    line->Draw();
    line = new TLine(628.8818,492.208,628.8818,1.136739);
    line->SetLineColor(50);
    line->SetLineStyle(2);
//    line->Draw();

//      TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
//      bottom_pad->Draw();
//      bottom_pad->cd();
//gg->SetTitle("Calibration");
//gg->GetXaxis()->SetTitle("channel");
//gg->GetXaxis()->CenterTitle();
//gg->GetYaxis()->SetTitle("Energy/MeV");
//gg->GetYaxis()->CenterTitle();
}
