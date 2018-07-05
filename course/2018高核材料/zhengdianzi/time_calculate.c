void time_calculate(){
TString tt ="  ";
TString b="7200s";
ifstream f1,f2;
TGraph *g1;
TGraph *g2;
TGraph *g3;
Double_t timeS_low=8.611+0.0243*305;
Double_t timeS_high=8.611+0.0243*325;
Double_t timeL_low=8.611+0.0243*460;
Double_t timeL_high=8.611+0.0243*500;
TF1* fun1= new TF1("fun1","pol1",timeS_low,timeS_high);
TF1* fun2= new TF1("fun2","pol1",timeL_high,timeL_high);
f1.open(b+".txt");
f2.open("bkg.txt");
Double_t x1[1024],y1[1024],y[1024],yl[199],xl[199],xs[99],ys[99];
Double_t x2[1024],y2[1024],xo[925],yo[925];
Double_t timel[199],times[99],timeo[925];
Int_t nlines=0;
TCanvas* c1 = new TCanvas("c1","time spectrum",900,600);
c1->SetGrid();
TH1D* h1 = new TH1D("h1","Long Lifetime",112,timeL_low,timeL_high);
TH1D* h2 = new TH1D("h2","Short Lifetime",20,timeS_low,timeS_high);
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
        timel[p]=8.611+0.0243*nlines;
        h1->SetBinContent(p,yl[p]);
        p++;
        }
    if(nlines<400&&nlines>300&&y[nlines]>0)
       {
        ys[m]=y[nlines];   
        xs[m]=nlines;
        times[m]=8.611+0.0243*nlines;
        cout<<"ys"<<ys[m]<<endl;
        m++;}
     if(nlines<=300&&y[nlines]>0) 
      {   
       yo[n]=y[nlines];
       xo[n]=nlines;
       timeo[n]=8.611+0.0243*nlines;
       n++;
      }
   x1[nlines]=nlines;
   x2[nlines]=nlines;
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
//g1 = new TGraph(m,xs,ys);
//g2 = new TGraph(p,xl,yl);
//g3 = new TGraph(n,xo,yo);
g1 = new TGraph(m,times,ys);
g2 = new TGraph(p,timel,yl);
g3 = new TGraph(n,timeo,yo);

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
//mg->SetTitle("Time spectrum;channel;ln(count)");
mg->SetTitle("Time spectrum;time/ns;ln(count)");
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
Double_t a1,b1,ea1,eb1,a2,b2,ea2,eb2;

TCanvas* c2 = new TCanvas("c2","time spectrum",900,600);
c2->SetGrid();
h1->Draw();
h1->Fit("fun2","ROB");
a2=fun2->GetParameter(0);
b2=fun2->GetParameter(1);
ea2=fun2->GetParError(0);
eb2=fun2->GetParError(1);

h1->SetTitle("Long lifetime spectrum;time/ns;ln(count)");
h1->GetXaxis()->SetLabelFont(10);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetTitleSize(0.07);
h1->GetXaxis()->SetTitleFont(20);
h1->GetXaxis()->CenterTitle();
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetYaxis()->SetLabelFont(10);
h1->GetYaxis()->SetLabelSize(0.05);
h1->GetYaxis()->CenterTitle();
h1->GetYaxis()->SetTitleSize(0.07);
h1->GetYaxis()->SetTitleFont(20);
h1->GetYaxis()->SetTitleOffset(0.7);
cout<<"a2 = "<<a2<<endl;
cout<<"b2 = "<<b2<<endl;
Double_t tl=fabs(1/b2);
Double_t sigmal=0.301;
char A2[100],B2[100],Tl[100],Sl[100];
sprintf(A2,"%f",a2);
sprintf(B2,"%f",b2);
sprintf(Tl,"%f",tl);
sprintf(Sl,"%f",sigmal);
TString tL1 = "lnN_{01} =  ";
TString tL2 = "#lambda_{1} =  ";
TString tL = "#tau_{1} = ";
TString stringL = tL1 + A2 +tt+ tL2 + B2+"\n"+tL+Tl+" +- "+Sl;
TPaveText *pt1 = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
pt1->SetTextSize(0.035);
TText *text1 = pt1->AddText(stringL);
pt1->Draw();

Double_t Yl,Ys,YS[32],XS[32],timeS[32];
Int_t num=0;
TRandom3 r;
Double_t xx,error;
error=sqrt(ea2*ea2+eb2*eb2);
cout<<"error = "<<error<<endl;
for(Int_t i=305;i<326;i++)
   {
    timeS[num]=8.611+0.0243*i;
    xx=r.Uniform(0,error);
    Yl=a2+b2*timeS[num]-0.5*error;
    Ys=exp(ys[num]);
    YS[num]=log(Ys-exp(Yl));
//    cout<<"YS = Ys - Yl = "<<Ys<<" - "<<Yl<<" = "<<YS[num]<<endl;
    cout<<"YS = "<<YS[num]<<endl;
    h2->SetBinContent(num,YS[num]);
    num++;
   }
cout<<"num = "<<num<<endl;
TCanvas* cc1 = new TCanvas("cc1","short spetrum",900,600);
cc1->SetGrid();
//TGraph* gr = new TGraph(num,XS,YS);
TGraph* gr = new TGraph(num,timeS,YS);
TF1* fgr = new TF1("f","pol1",timeS_low,timeS_high);
h2->SetTitle("Short lifetime spectrum;time/ns;ln(count)");
gr->SetMarkerStyle(22);
gr->SetMarkerColor(kGreen);
gr->SetMarkerSize(1.0);
h2->Fit("f");
h2->Draw();
//gr->Draw("AP SAME");
h2->SetLineColor(kBlue);
h2->SetLineWidth(2);
h2->GetXaxis()->SetLabelFont(10);
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetTitleSize(0.07);
h2->GetXaxis()->SetTitleFont(20);
h2->GetXaxis()->CenterTitle();
h2->GetXaxis()->SetTitleOffset(0.6);
h2->GetYaxis()->SetLabelFont(10);
h2->GetYaxis()->SetLabelSize(0.05);
h2->GetYaxis()->CenterTitle();
h2->GetYaxis()->SetTitleSize(0.07);
h2->GetYaxis()->SetTitleFont(20);
h2->GetYaxis()->SetTitleOffset(0.7);

a1=fgr->GetParameter(0);
b1=fgr->GetParameter(1);
cout<<"a1 = "<<a1<<endl;
cout<<"b1 = "<<b1<<endl;
Double_t ts=fabs(1/b1);
//c1->Print(b+"1.eps");
//Double_t mu1=f1->GetParameter(1);
//Double_t s1 =f1->GetParameter(2);
//Double_t mu2=f2->GetParameter(1);
//Double_t s2 =f2->GetParameter(2);
Double_t sigmas=2.184820;
char A1[100],B1[100],TS[100],Ss[100];
sprintf(A1,"%f",a1);
sprintf(B1,"%f",b1);
sprintf(TS,"%f",ts);
sprintf(Ss,"%f",sigmas);
TString tS1 = "lnN_{02} =  ";
TString tS2 = "#lambda_{2} =  ";
TString tS = "#tau_{2} =  ";
TString stringS = tS1 + A1 +tt+ tS2 + B1+"\n"+tS+TS+" +- "+Ss;
TPaveText *pt = new TPaveText(0.55,0.4,1.0,0.5,"BRNDC");
pt->SetTextSize(0.035);
TText *text = pt->AddText(stringS);
pt->Draw();
TFile* file=new TFile("LongLifetime.root","RECREATE");
h1->Write();
h2->Write();
file->Close();
}
