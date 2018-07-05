void NcTd(){
TGraph *g1;
Double_t Nc[13]={227739,218778,202377,194246,193707,192644,192404,192442,192640,192783,192725,199267,224843};
Double_t Td[13]={0.4,0.5,0.7,0.8,0.9,1.1,1.5,1.6,1.7,2.0,2.3,2.5,2.8};
TF1* f=new TF1("f","[0]*x*x+[1]*x+[2]",0,3);
f->SetParameters(1,-1,10);
g1 = new TGraph(13,Td,Nc);
g1->Draw("AP*");
g1->Fit("f","R");
g1->SetMarkerColor(kBlue);
g1->SetMarkerSize(2.0);
g1->SetTitle("N_{c}-t_{d} curve;t_{d}/#mu s;count");
}
