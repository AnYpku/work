//code for running
//step 1: .L sscc1.C
//step 2:sscc1("rec") or sscc1("gen")

//void sscc1(TString process="rec"){
void sscc1(TString process="gen"){

if(process=="rec"){
//for rec root file
TFile *f=new TFile("sscc_rec.root");
TFile *f1=new TFile("newsscc_rec.root","RECREATE");}
else if(process=="gen"){
//for gen root file
TFile *f=new TFile("sscc_gen.root");
TFile *f1=new TFile("newsscc_gen.root","RECREATE");}

TTree *t=new TTree("t","t");
f->GetObject("qqqq",t);
Double_t g1[4],g2[4],g3[4],g4[4];
t->SetBranchAddress("g1",g1);
t->SetBranchAddress("g2",g2);
t->SetBranchAddress("g3",g3);
t->SetBranchAddress("g4",g4);

TLorentzVector Zlv1,Hlv1,Zlv2,Hlv2,Zlv3,Hlv3,Zlv4,Hlv4,Zlv5,Hlv5,Zlv6,Hlv6;
Double_t Z[4],H[4],Z1[4],H1[4],Z2[4],H2[4];
TTree *t1=new TTree("t1","TLorentzVector of Z and H");
t1->Branch("Z[4]",Z,"Z[4]/D");
t1->Branch("H[4]",H,"H[4]/D");
//t1->Branch("Z1[4]",Z1,"Z1[4]/D");
//t1->Branch("H1[4]",H1,"H1[4]/D");
//t1->Branch("Z2[4]",Z2,"Z1[4]/D");
//t1->Branch("H2[4]",H2,"H1[4]/D");

TH1D *h11=new TH1D("h11","Z12_H34",130,0,130);
TH1D *h21=new TH1D("h21","Z13_H24",130,0,130);
TH1D *h31=new TH1D("h31","Z14_H23",130,0,130);
TH1D *h41=new TH1D("h41","Z23_H14",130,0,130);
TH1D *h51=new TH1D("h51","Z24_H13",130,0,130);
TH1D *h61=new TH1D("h61","Z34_H12",130,0,130);

for(int i=0;i<t->GetEntries();i++){
t->GetEntry(i);
TLorentzVector glv1; glv1.SetPxPyPzE(g1[0],g1[1],g1[2],g1[3]);
TLorentzVector glv2; glv2.SetPxPyPzE(g2[0],g2[1],g2[2],g2[3]);
TLorentzVector glv3; glv3.SetPxPyPzE(g3[0],g3[1],g3[2],g3[3]);
TLorentzVector glv4; glv4.SetPxPyPzE(g4[0],g4[1],g4[2],g4[3]);

//Z->g1g2;H->g3g4
Zlv1=glv1+glv2;
Hlv1=glv3+glv4;
h11->Fill(Hlv1.M()); 
//cout<<Hlv1.M()<<"  "<<a<<endl;
if(process=="gen"){
Z[0]=Zlv1.Px();Z[1]=Zlv1.Py();Z[2]=Zlv1.Pz();Z[3]=Zlv1.M();
H[0]=Hlv1.Px();H[1]=Hlv1.Py();H[2]=Hlv1.Pz();H[3]=Hlv1.M();}
 
//H->g1g3;Z->g2g4
Hlv2=glv1+glv3;
Zlv2=glv2+glv4;
h21->Fill(Hlv2.M());
if(process=="rec"){
Z[0]=Zlv2.Px();Z[1]=Zlv2.Py();Z[2]=Zlv2.Pz();Z[3]=Zlv2.M();
H[0]=Hlv2.Px();H[1]=Hlv2.Py();H[2]=Hlv2.Pz();H[3]=Hlv2.M();}

/*
//Z->g1g4;H->g2g3
Zlv3=glv1+glv4;
Hlv3=glv2+glv3;
h31->Fill(Hlv3.M());
Z2[0]=Zlv2.Px();Z2[1]=Zlv2.Py();Z2[2]=Zlv2.Pz();Z2[3]=Zlv2.M();
H2[0]=Hlv2.Px();H2[1]=Hlv2.Py();H2[2]=Hlv2.Pz();H2[3]=Hlv2.M();

//H->g2g3;Z->g1g4
Hlv4=glv2+glv3;
h41->Fill(Hlv4.M());

//Z->g2g4;H->g1g3
Hlv5=glv1+glv3;
h51->Fill(Hlv5.M());

//Z->g3g4;H->g1g2
Hlv6=glv1+glv2;
h61->Fill(Hlv6.M());*/
t1->Fill();
}

/*TCanvas *c1 = new TCanvas("c1","gen");
c1->Divide(2,3);
c1->cd(1); h11->Draw();   c1->cd(2); h21->Draw();
c1->cd(3); h31->Draw();   c1->cd(4); h41->Draw();
c1->cd(5); h51->Draw();   c1->cd(6); h61->Draw();*/

t1->Write();
f->Close();
f1->Close();

}
