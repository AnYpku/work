void test(){

  TFile *f1=new TFile("/home/data/data/MUST2@BigRIPS/runmust20082.root");
  TTree *t =(TTree*)f1->Get("t1");
  Double_t number;
  number = t->GetEntries();

  cout<<"number of entries = "<<number<<endl;

  TFile *f2=new TFile("tree.root","RECREATE");
  TTree *t2=new TTree("mytree","mytree");

  TBranch        *b_PPACF8;   //!
  Float_t         PPACF8[5][5];
  Float_t ppac[5][4];

  t->SetBranchAddress("PPACF8", PPACF8, &b_PPACF8);

  t2->Branch("PPAC",&ppac,"PPAC[5][4]/F");
//  t2->Branch("PPAC1b",&ppac1b_,"PPAC1b[4]/F");
//  t2->Branch("PPAC2a",&ppac2a_,"PPAC2a[4]/F");
//  t2->Branch("PPAC2b",&ppac2b_,"PPAC2b[4]/F");
//  t2->Branch("PPAC3",&ppac3_,"PPAC3[4]/F");

  for(Int_t i=0;i<number;i++)
    {
      t->GetEntry(i);
      for(Int_t m=0;m<5;m++)
        { 
	    if(PPACF8[m][4]>0)
	    {   
	       for(Int_t j=0;j<4;j++)
	         {   
                  ppac[m][j]=PPACF8[m][j];
	         }
	    }
         }  
//     ppac3_[2] =(PPACF8[4][2]+PPACF8[4][3])*0.5;       
     t2->Fill();
    }
  t2->Write();
  f2->Close();
}



