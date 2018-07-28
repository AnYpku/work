void ntuple()
{
double g1[4];
double g2[4];
double g3[4];
double g4[4];
TH1F *h =new TH1F("h","Mj1j2",100,50,160);
TH1F *h2 =new TH1F("h","Mj3j4",100,50,160);
TH1F *h3 =new TH1F("h","Mj1j3",100,50,160);
TH1F *h4 =new TH1F("h","Mj2j4",100,50,160);
TH1F *h5 =new TH1F("h","Mj1j4",100,50,160);
TH1F *h6 =new TH1F("h","Mj2j3",100,50,160);
TFile *f = new TFile("sscc_rec.root");
TTree *t = (TTree*)f->Get("qqqq");
t->SetBranchAddress("g1",g1);
t->SetBranchAddress("g2",g2);
t->SetBranchAddress("g3",g3);
t->SetBranchAddress("g4",g4);
TFile *fp=new TFile("sscc_rec_mjj.root", "recreate");
TTree *tree = new TTree("tree", "tree");
double mj1j3;
tree->Branch("mj1j3",&mj1j3,"mj1j3/D");
double mj2j4;
tree->Branch("mj2j4",&mj2j4,"mj2j4/D");
for(int count=0; count < t->GetEntries(); count++)
   {
   t->GetEntry(count);
   TLorentzVector J1, J2, J3,J4;
   J1.SetPxPyPzE(g1[0],g1[1],g1[2],g1[3]);
   J2.SetPxPyPzE(g2[0],g2[1],g2[2],g2[3]);
   J3.SetPxPyPzE(g3[0],g3[1],g3[2],g3[3]);
   J4.SetPxPyPzE(g4[0],g4[1],g4[2],g4[3]);
   cout<<g1[0]<<" "<<g1[1]<<" "<<g1[2]<<" "<<g1[3]<<endl;
   double mjj=(J1+J2).M();
   h->Fill(mjj);
   mjj=(J3+J4).M();
   h2->Fill(mjj);
   mjj=(J1+J3).M();
   h3->Fill(mjj);
   mj1j3=mjj;
   mjj=(J2+J4).M();
   h4->Fill(mjj);
   mj2j4=mjj;
   mjj=(J1+J4).M();
   h5->Fill(mjj);
   mjj=(J2+J3).M();
   h6->Fill(mjj);
   tree->Fill();
   } 
   TCanvas *c= new TCanvas("c","gen");
   c->Divide(2,3) ;
   c->cd(1);
   h->Draw();   
   c->cd(2);
   h2->Draw();
   c->cd(3);
   h3->Draw();
   c->cd(4);
   h4->Draw();
   c->cd(5);
   h5->Draw();
   c->cd(6);
   h6->Draw();
   c->SaveAs("gen.pdf");
   fp->cd();
   tree->Write();
   fp->Close();
}


