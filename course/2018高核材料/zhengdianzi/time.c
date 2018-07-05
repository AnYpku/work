void time(){
TString b="7200s";
ifstream f1,f2;
TGraph *g1;
TGraph *g2;
TGraph *g3;
TF1* fun2= new TF1("fun2","[0]+[1]*x",460,500);
TF1* fun1= new TF1("fun1","pol1",305,335);
f1.open(b+".txt");
f2.open("bkg.txt");
Double_t x1[1024],y1[1024],y[1024],yl[199],xl[199],xs[99],ys[99];
Double_t x2[1024],y2[1024],xo[925],yo[925];
Int_t nlines=0;
TCanvas* c1 = new TCanvas("c1","time spectrum",900,600);
c1->SetGrid();
TH1D* h1 = new TH1D("h1","energy spectrum",1024,0,1024);
Int_t p=0,n=0,m=0;
while(nlines<1024){
   f1>>y1[nlines];
   f2>>y2[nlines];
   if(y1[nlines]>0)
         {y[nlines]=log(y1[nlines]);}
   else  {y[nlines]=0;}
   if(nlines<600&&nlines>400&&y[nlines]>0)
       {
        yl[p]=y[nlines];   
        xl[p]=nlines;
        p++;}
    if(nlines<400&&nlines>300&&y[nlines]>0)
       {
        ys[m]=y[nlines];   
        xs[m]=nlines;
        m++;}
     if(nlines<=300&&y[nlines]>0) 
      {   
       yo[n]=y[nlines];
       xo[n]=nlines;
       n++;
      }
   x1[nlines]=nlines;
   x2[nlines]=nlines;
   h1->SetBinContent(nlines,y1[nlines]);
//   cout<<"y["<<nlines<<"]"<<y[nlines]<<endl;
   nlines++;
   }
cout<<"p = "<<p<<endl;
cout<<"m = "<<m<<endl;
cout<<"n = "<<n<<endl;
f1.close();
f2.close();
TMultiGraph *mg=new TMultiGraph();
Double_t T[5]={16,20,24,28,32};
Double_t channel[5]={299,469,640,806,953};
double sk[5],e[5];
g1 = new TGraph(m,xs,ys);
g2 = new TGraph(p,xl,yl);
g3 = new TGraph(n,xo,yo);

g1->Fit("fun1","ROB");
g2->Fit("fun2","ROB");
g1->SetMarkerStyle(22);
g1->SetMarkerSize(1.0);
g1->SetMarkerColor(kBlue);

g2->SetMarkerStyle(22);
g2->SetMarkerColor(kGreen);
g2->SetMarkerSize(1.0);

g3->SetMarkerStyle(22);
g3->SetMarkerColor(kOrange);
g3->SetMarkerSize(1.0);

mg->Add(g1);
mg->Add(g2);
mg->Add(g3);
mg->SetTitle("Time spectrum;channel;ln(count)");
mg->Draw("AP");
gStyle->SetOptStat(0);
//h1->Draw();
//h1->SetTitle("energy spectrum;channel;count");
h1->SetLineColor(kBlue);
h1->SetLineWidth(2);

mg->GetXaxis()->SetLabelFont(10);
mg->GetXaxis()->SetLabelSize(0.05);
mg->GetXaxis()->SetTitleSize(0.07);
mg->GetXaxis()->SetTitleFont(20);
mg->GetXaxis()->CenterTitle();
mg->GetXaxis()->SetTitleOffset(0.6);
mg->GetYaxis()->SetLabelFont(10);
mg->GetYaxis()->SetLabelSize(0.05);
mg->GetYaxis()->CenterTitle();
mg->GetYaxis()->SetTitleSize(0.07);
mg->GetYaxis()->SetTitleFont(20);
mg->GetYaxis()->SetTitleOffset(0.7);

TLegend *l1 = new TLegend(0.7,0.7,0.9,0.9);
l1->AddEntry(g1,"short lifetime");
l1->AddEntry(g2,"longe lifetime");
//l1->AddEntry(g3,"subtract bkg");
l1->Draw();

TCanvas* c2 = new TCanvas("c2","time spectrum",900,600);
c2->SetGrid();
g2->Draw("AP");
g2->Fit("fun2","ROB");
g2->SetTitle("Short lifetime spectrum;channel;ln(count)");
g2->GetXaxis()->SetLabelFont(10);
g2->GetXaxis()->SetLabelSize(0.05);
g2->GetXaxis()->SetTitleSize(0.07);
g2->GetXaxis()->SetTitleFont(20);
g2->GetXaxis()->CenterTitle();
g2->GetXaxis()->SetTitleOffset(0.6);
g2->GetYaxis()->SetLabelFont(10);
g2->GetYaxis()->SetLabelSize(0.05);
g2->GetYaxis()->CenterTitle();
g2->GetYaxis()->SetTitleSize(0.07);
g2->GetYaxis()->SetTitleFont(20);
g2->GetYaxis()->SetTitleOffset(0.7);

Double_t a1,b1,a2,b2;
a1=fun1->GetParameter(0);
b1=fun1->GetParameter(1);
a2=fun2->GetParameter(0);
b2=fun2->GetParameter(1);
cout<<"a1 = "<<a1<<endl;
cout<<"b1 = "<<b1<<endl;
cout<<"a2 = "<<a2<<endl;
cout<<"b2 = "<<b2<<endl;
Double_t Yl,Ys,YS[32],XS[32];
Int_t num=0;
for(Int_t i=305;i<336;i++)
   {
    Yl=a2+b2*i;
    Ys=a1+b1*i;
    YS[num]=Ys-Yl;
    XS[num]=i;
    cout<<"YS = Ys - Yl = "<<Ys<<" - "<<Yl<<" = "<<YS[num]<<endl;
    num++;
   }
cout<<"num = "<<num<<endl;
TCanvas* cc1 = new TCanvas("cc1","short spetrum",900,600);
cc1->SetGrid();
TGraph* gr = new TGraph(num,XS,YS);
TF1* fgr = new TF1("f","pol1",305,335);
gr->SetTitle("Short lifetime spectrum;channel;ln(count)");
gr->SetMarkerStyle(22);
gr->SetMarkerColor(kRed);
gr->SetMarkerSize(1.0);
gr->Fit("f","ROB");
gr->Draw("AP");
gr->GetXaxis()->SetLabelFont(10);
gr->GetXaxis()->SetLabelSize(0.05);
gr->GetXaxis()->SetTitleSize(0.07);
gr->GetXaxis()->SetTitleFont(20);
gr->GetXaxis()->CenterTitle();
gr->GetXaxis()->SetTitleOffset(0.6);
gr->GetYaxis()->SetLabelFont(10);
gr->GetYaxis()->SetLabelSize(0.05);
gr->GetYaxis()->CenterTitle();
gr->GetYaxis()->SetTitleSize(0.07);
gr->GetYaxis()->SetTitleFont(20);
gr->GetYaxis()->SetTitleOffset(0.7);
//c1->Print(b+"1.eps");
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
