void vvgg()
{
double g1[4];
double g2[4];
TH1F *h =new TH1F("h","mg1g2",100,90,170);


TFile *f = new TFile("vvgg_rec.root");

TTree *t = (TTree*)f->Get("vvgg");
t->SetBranchAddress("g1",g1);
t->SetBranchAddress("g2",g2);

TFile *fp=new TFile("vvgg_rec_new.root", "recreate");

TTree *tree = new TTree("tree", "tree");
double mgg;
tree->Branch("mgg",&mgg,"mgg/D");
for(int count=0; count < t->GetEntries(); count++)
   {
   t->GetEntry(count);
   TLorentzVector J1, J2, J3,J4;
   J1.SetPxPyPzE(g1[0],g1[1],g1[2],g1[3]);
   J2.SetPxPyPzE(g2[0],g2[1],g2[2],g2[3]);
   //cout<<l1[0]<<" "<<l1[1]<<" "<<l1[2]<<" "<<l1[3]<<endl;
   double mll=(J1+J2).M();
   h->Fill(mll);
   tree->Fill();
   } 
   TCanvas *c= new TCanvas("c","rec");
   h->Draw();
   c->SaveAs("vvgg_rec.pdf");
   fp->cd();
   tree->Write();
   fp->Close();
}


