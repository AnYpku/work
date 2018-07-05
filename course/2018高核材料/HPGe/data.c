void data(){
//TString b ="";
ifstream infile;
ifstream infile1;
TGraph*g[4];
TMultiGraph *mg = new TMultiGraph();
TF1 *f1=new TF1("f1","gaus",380,480);
//TF1 *f2=new TF1("f2","gaus",800,900);
f1->SetParameters(1,430,2);
//f2->SetParameters();
Int_t p=0;
Int_t n=4;
  infile1.open("bkg.txt");
  Double_t b[1024];
  Int_t nline=0;
   while(nline<1024){
    infile1>>b[nline];
    nline++;
 }
infile1.close();

for(Int_t i=0;i<1;i++){
   infile.open("Co60_kedu2.txt");
if(!infile.is_open())
   continue;
   
Double_t x[1024],y[1024],yy[1024];
Int_t nlines=0;
while(nlines<1024){
 infile>>y[nlines];
 x[nlines]=nlines;
 //yy[nlines]=y[nlines]-b[nlines];
 yy[nlines]=y[nlines];
 nlines++;
 }
infile.close();
cout<<"read the file"<<endl;
g[p] = new TGraph(nlines,x,yy);
p++;
}
cout<<"p = "<<p<<endl;
TCanvas *can = new TCanvas("can","",0,0,900,600);
can->SetGrid();
g[0]->SetMarkerColor(kOrange);
g[0]->SetMarkerStyle(7);
g[0]->SetLineColor(kOrange);
//g[0]->Fit("f1","R");
//g[0]->Fit("f2","R");
mg->Add(g[0]);
TLegend *l1=new TLegend(0.6,0.6,0.9,0.9);
//l1->AddEntry(g[0],"Mn");
l1->AddEntry(g[0],"Co");
//l1->AddEntry(g[2],"Cs");
//l1->AddEntry(g[3],"mix");
//l1->AddEntry(g[4],"bkg");
for(Int_t j=1;j<p;j++){
//  g[j]->Draw("Same");
  g[j]->SetLineColor(j);
  g[j]->SetFillColor(j+1);
  g[j]->SetMarkerStyle(7);
  g[j]->SetMarkerColor(j);
  mg->Add(g[j]);
//  g[j]->Fit("Gaus")
//  g[j]->Draw("Same");
 }
mg->Draw("AP");
mg->SetTitle("");
mg->GetXaxis()->SetTitle("channel");
mg->GetXaxis()->CenterTitle();
mg->GetYaxis()->SetTitle("count");
mg->GetYaxis()->CenterTitle();
l1->Draw();

}
