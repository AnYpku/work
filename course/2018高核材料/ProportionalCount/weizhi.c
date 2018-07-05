void weizhi(){
ifstream infile;
TGraph*g[3];
TF1*f[3];
Double_t u[3];
TMultiGraph *mg = new TMultiGraph();
Int_t p=0;
for(Int_t i=1;i<4;i++){
   infile.open(Form("/Users/andy/work/course/2018高核材料/data/正比计数器/txt/weizhi%d.txt",i),ios::in);
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
cout<<"read the file"<< " "<<i<<endl;
g[p] = new TGraph(nlines,x,y);
f[p] = new TF1(Form("f%d",p),"gaus",0,1000);
f[p]->SetParameters(1,1,1);
p++;
}
cout<<"p = "<<p<<endl;
TCanvas *c = new TCanvas("c","count of unknown elements",0,0,900,600);
c->SetGrid();
g[0]->SetMarkerColor(kOrange);
g[0]->SetMarkerStyle(22);
g[0]->SetLineColor(kOrange);
g[0]->Fit("f0","R");
u[0]=f[0]->GetParameter(1);
TLegend *l1=new TLegend(0.6,0.6,0.9,0.9);
l1->AddEntry(g[0],"the unknown elements1");
mg->Add(g[0]);
Int_t m=2;  
for(Int_t j=1;j<p;j++){
  g[j]->Draw("Same");
  g[j]->SetLineColor(j+2);
  g[j]->SetFillColor(j+1);
  g[j]->SetMarkerStyle(j+2);
  g[j]->SetMarkerColor(j+2);
  g[j]->Fit(Form("f%d",j),"R");
  mg->Add(g[j]);
  u[j]=f[j]->GetParameter(1);
  l1->AddEntry(g[j],Form("the unknown  elements%d",j+1));
  m++;
 }
mg->Draw("AP");
mg->SetTitle("the absorption curve of unknown elements");
mg->GetXaxis()->SetTitle("channel");
mg->GetXaxis()->CenterTitle();
mg->GetYaxis()->SetTitle("count");
mg->GetYaxis()->CenterTitle();
l1->Draw();
TString t1="";
TString t;
TString t3="  ";
TString t2;
for(Int_t n=0;n<3;n++){
char mu[100];
sprintf(mu,"%f",u[n]);
t = t3 + mu + t3;
t1 += t;
t2 = "#mu = " + t1;
 }
TPaveText *pt = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
pt->SetTextSize(0.035);
TText *text = pt->AddText(t2);
pt->Draw();
}
