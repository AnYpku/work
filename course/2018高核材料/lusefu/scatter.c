#define pi 3.14159265357589793
void scatter(){
Double_t bkg[7]={57,16,7,0,1,1,0};
Double_t tot[7]={1021,260,103,42,33,11,5};
Double_t sig[7];
Double_t theta[7]={20,25,30,35,40,45,50};
Double_t angle[7];
Double_t P[7];
for(Int_t i=0;i<7;i++){
    sig[i]=tot[i]-bkg[i];
    angle[i]=theta[i]*pi/180;
    P[i]=pow(sin(angle[i]/2),4)*sig[i];
    cout<<"P"<<" ["<<i<<"] = "<<P[i]<<endl;
    }
cout<<"xlow = "<<angle[0]<<endl;
cout<<"xhigh = "<<angle[6]<<endl;
TGraph *g =new TGraph(7,angle,P);
TGraph *gr=new TGraph(7,angle,sig);
TGraph *gt=new TGraph(7,angle,tot);
TGraph *gb=new TGraph(7,angle,bkg);
//TF1 *f1=new TF1("f1","[0]+[1]*pow(cos([2]*x),2)",0,1);
TF1 *f2=new TF1("f2","[0]*x+[1]",0.3,0.9);
f2->SetParameters(1,0);
TF1 *f1=new TF1("f1","[0]*pow(sin(0.5*x),-4)",0,1);
f1->SetParameter(1,1);
gr->Draw("AP");
gr->SetMarkerStyle(22);
gt->SetMarkerStyle(3);
gb->SetMarkerStyle(29);
gr->SetMarkerSize(2);
gt->SetMarkerSize(2);
gb->SetMarkerSize(2);
gr->SetMarkerColor(kRed);
gr->SetTitle("N vs #theta ; #theta  ; N");
gr->Fit("f1","R");
gt->Draw("SAME");
gb->Draw("SAME");
TLegend* l1 = new TLegend(0.7,0.5,0.8,0.8);
l1->AddEntry(gr,"signal");
l1->AddEntry(gt,"tot");
l1->AddEntry(gb,"bkg");
l1->Draw();
TCanvas *c = new TCanvas("c1","",900,600);
g->Draw("AP*");
g->Fit("f2","R");
}
