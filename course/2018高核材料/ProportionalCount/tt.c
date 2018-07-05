void tt(){
ifstream f;
TGraph *g;
TF1 *f1=new TF1("f1","gaus",300,450);
TF1 *f2=new TF1("f2","gaus",450,600);

f.open("/Users/andy/work/course/2018高核材料/data/正比计数器/txt/Fe55.txt");
Double_t x[1024],y[1024];
Int_t nlines=0;
while(nlines<1024){
   f>>y[nlines];
   x[nlines]=nlines;
   nlines++;
   }
f.close();

g = new TGraph(nlines,x,y);
g->Draw("AP");
f1->SetParameters(1,1,1);
f2->SetParameters(1,1,1);
g->Fit("f1","R+");
g->Fit("f2","R+");
g->SetTitle("^{55}Fe absorption curve;channel;count");
Double_t mu1=f1->GetParameter(1);
Double_t s1 =f1->GetParameter(2);
Double_t mu2=f2->GetParameter(1);
Double_t s2 =f2->GetParameter(2);
char u1[100],u2[100],sigma1[100],sigma2[100];
sprintf(u1,"%f",mu1);
sprintf(u2,"%f",mu2);
sprintf(sigma1,"%f",s1);
sprintf(sigma2,"%f",s2);
TString t1 = "#mu =  ";
TString t2 = "#sigma =  ";
TString tt ="  ";
TString string1 = t1 + u1 +tt+ t2 + sigma1;
TString string2 = t1 + u2 +tt+ t2 + sigma2;

TPaveText *pt = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
pt->SetTextSize(0.035);
TText *text = pt->AddText(string1);
pt->Draw();
TPaveText *pt1 = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
pt1->SetTextSize(0.035);
TText *text1 = pt1->AddText(string2);
pt1->Draw();
}
