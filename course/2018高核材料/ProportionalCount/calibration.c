void calibration(){

Double_t count[7]={16029,12332,9780,7958,6274,4713,3889};
Double_t t[7];
for(int i=0;i<7;i++){
    t[i]=2*i*2.15/2700;
    }
TGraph*g=new TGraph(7,t,count);
TF1*f=new TF1("f","[0]*exp([1]*x)",0,30);
TCanvas*can=new TCanvas("can","Mass absorption coefficient",900,600);
can->SetGrid();
f->SetParameters(1,1);
g->SetMarkerStyle(22);
g->SetMarkerSize(2);
g->Draw("AP");
g->SetTitle("#mu_{m}");
g->GetXaxis()->SetTitle("thickness");
g->GetXaxis()->SetRangeUser(-10,20);
g->GetXaxis()->CenterTitle();
g->GetYaxis()->SetTitle("count");
g->GetYaxis()->CenterTitle();
g->Fit("f","R");
Double_t a=f->GetParameter(0);
Double_t b=f->GetParameter(1);
Double_t c=(0-b)/2.7;
TPaveText *pt =new TPaveText(0.6,0.3,0.9,0.4,"BRNDC");
TString s1="#mu_{m} = ";
TString s2=" ";
char c1[20],c2[20];
sprintf(c1,"%f",c);
sprintf(c2,"%f",b);
TString s=s1+s2 +c1;
TText*text=pt->AddText(s);
pt->Draw();







}
