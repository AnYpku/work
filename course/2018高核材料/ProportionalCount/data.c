void data(){
ifstream infile;
TGraph*g[7];
TMultiGraph *mg = new TMultiGraph();
Int_t p=0;
for(Int_t i=0;i<7;i++){
   infile.open(Form("/Users/andy/work/course/2018高核材料/data/正比计数器/txt/Cu%d.txt",2*i));
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
p++;
}
cout<<"p = "<<p<<endl;
TCanvas *can = new TCanvas("can","count of Cu",0,0,900,600);
can->SetGrid();
g[0]->SetMarkerColor(kOrange);
g[0]->SetMarkerStyle(3);
g[0]->SetLineColor(kOrange);
mg->Add(g[0]);
TLegend *l1=new TLegend(0.6,0.6,0.9,0.9);
l1->AddEntry(g[0],"the numeber of Al sheets 0");
Int_t m=2;  
for(Int_t j=1;j<p;j++){
  g[j]->Draw("Same");
  g[j]->SetLineColor(j);
  g[j]->SetFillColor(j+1);
  g[j]->SetMarkerStyle(j);
  g[j]->SetMarkerColor(j);
  mg->Add(g[j]);
//  g[j]->Draw("Same");
  l1->AddEntry(g[j],Form("the numeber of Al sheets %d",2*m));
  m++;
 }
mg->Draw("AP");
mg->SetTitle("the counts of Cu with different Al sheets");
mg->GetXaxis()->SetTitle("channel");
mg->GetXaxis()->CenterTitle();
mg->GetYaxis()->SetTitle("count");
mg->GetYaxis()->CenterTitle();
l1->Draw();
}
