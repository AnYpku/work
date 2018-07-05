void Cs(){
ifstream f1,f2;
TGraph *g1;
TGraph *g2;

f1.open("./txt/no.txt");
f2.open("./txt/have.txt");
Double_t x1[1024],y1[1024];
Double_t x2[1024],y2[1024];
Int_t nlines=0;
while(nlines<1024){
   f1>>y1[nlines];
   f2>>y2[nlines];
   x1[nlines]=nlines;
   x2[nlines]=nlines;
   nlines++;
   }
f1.close();
f2.close();

g1 = new TGraph(nlines,x1,y1);
g2 = new TGraph(nlines,x2,y2);
g1->Draw("AP");
g2->Draw("Same");
g1->SetTitle("energy spectrum;channel;count");
TLegend *l1 = new TLegend(0.7,0.7,0.9,0.9);
l1->AddEntry(g1,"no Anti-coincidence method");
l1->AddEntry(g2,"use Anti-coincidence method");
l1->Draw();
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
