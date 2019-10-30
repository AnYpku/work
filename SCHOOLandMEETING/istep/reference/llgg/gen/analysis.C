void analysis()
{
double l1[4];
double l2[4];
double g1[4];
double g2[4];
TH1F *h1 =new TH1F("h","ml1l2",100,70,110);
TH1F *h2 =new TH1F("h","mg1g2",100,124.99999,125.000008);


TFile *f = new TFile("llgg_gen.root");
//TFile *f = new TFile("llgg_rec.root");

TTree *t = (TTree*)f->Get("llgg");
t->SetBranchAddress("l1",l1);
t->SetBranchAddress("l2",l2);
t->SetBranchAddress("g1",g1);
t->SetBranchAddress("g2",g2);

TFile *fp=new TFile("llgg_gen_new.root", "recreate");
//TFile *fp=new TFile("llgg_rec_new.root", "recreate");

TTree *tree = new TTree("tree", "tree");
double mll;
tree->Branch("mll",&mll,"mll/D");
double mgg;
tree->Branch("mgg",&mgg,"mgg/D");
for(int count=0; count < t->GetEntries(); count=count+1)
   {
   t->GetEntry(count);
   TLorentzVector J1, J2, J3,J4;
   J1.SetPxPyPzE(l1[0],l1[1],l1[2],l1[3]);
   J2.SetPxPyPzE(l2[0],l2[1],l2[2],l2[3]);
   J3.SetPxPyPzE(g1[0],g1[1],g1[2],g1[3]);
   J4.SetPxPyPzE(g2[0],g2[1],g2[2],g2[3]);
   cout<<l1[0]<<" "<<l1[1]<<" "<<l1[2]<<" "<<l1[3]<<endl;
   double tmp=(J1+J2).M();
    mll=tmp;
   h1->Fill(mll);
    tmp=(J3+J4).M();
    mgg=tmp;
      h2->Fill(mgg);
   //fitTo(h1);
   tree->Fill();
   } 
   TCanvas *c= new TCanvas("c","gen");
   c->Divide(1,2);
   c->cd(1);
   h1->Draw();
   c->cd(2);
   h2->Draw();
   //c->SaveAs("llgg_gen.pdf");
   //c->SaveAs("llgg_rec.pdf");
   fp->cd();
   tree->Write();
   fp->Close();
}



