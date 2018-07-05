void mg5Compare1(){

// Load shared library
 gSystem->Load("/store/home/andy/MC/MG5/MG5_aMC_v2_3_3/ExRootAnalysis/libExRootAnalysis.so");
// gSystem->Load("/home/qliphy/Desktop/common/root/lib/root/libPhysics.so");
// Create chain of root trees


 float inix= 0.0;
 float finx= 2000.0;
 float nbin= 50.0;

 
TString IFile1 =   "pp-ll.root";
TChain chain("LHEF");
chain.Add(IFile1); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
 Long64_t numberOfEntries = treeReader->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent = treeReader->UseBranch("Event");
 TClonesArray *branchParticle = treeReader->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h1= new TH1F("1_Mjj","test histogram",nbin,inix,finx);
 h1->Sumw2();
 TLorentzVector J1, J2, JJ;
for(int i=0; i<=numberOfEntries-1; i++)
{
////*****************************************************************
    J1.SetPtEtaPhiE(0.,0.,0.,0.);
    J2.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader->ReadEntry(i);
    TRootLHEFEvent *event=(TRootLHEFEvent*) branchEvent->At(0);
    int np=event->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle1=(TRootLHEFParticle*) branchParticle->At(j);
      if((abs(particle1->PID)<6 || (particle1->PID)==21) ) {
          if(J1.E()>0){
          J2.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
             }
          else{  
          J1.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
             }
        }
     }
    JJ=J1+J2;
    h1->Fill(JJ.M(), 634800/float(numberOfEntries)); 
////*****************************************************************
}

TString IFile2 =   "pp-z-ll.root";
TChain chain2("LHEF");
chain2.Add(IFile2); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader2 = new ExRootTreeReader(&chain2);
 Long64_t numberOfEntries2 = treeReader2->GetEntries();
      cout<<"numberOfEntries2 = "<<numberOfEntries2<<endl;
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent2 = treeReader2->UseBranch("Event");
 TClonesArray *branchParticle2 = treeReader2->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h2= new TH1F("2_Mjj","test histogram",nbin,inix,finx);
 h2->Sumw2();
 TLorentzVector J12, J22, JJ2;
for(int i=0; i<=numberOfEntries2-1; i++)
{
////*****************************************************************
    J12.SetPtEtaPhiE(0.,0.,0.,0.);
    J22.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader2->ReadEntry(i);
    TRootLHEFEvent *event2=(TRootLHEFEvent*) branchEvent2->At(0);
    int np2=event2->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle12=(TRootLHEFParticle*) branchParticle2->At(j);
      if((abs(particle12->PID)<6 || (particle12->PID)==21) ) {
          if(J12.E()>0){
          J22.SetPtEtaPhiE(particle12->PT,particle12->Eta,particle12->Phi,particle12->E);
             }
          else{  
          J12.SetPtEtaPhiE(particle12->PT,particle12->Eta,particle12->Phi,particle12->E);
             }
        }
     }
    JJ2=J12+J22;
    h2->Fill(JJ2.M(), 2863000/float(numberOfEntries2)); 
////*****************************************************************
}
      h1->SetTitle("mg5 Z(#rightarrow e^{+}e^{-})+2Jets at 13TeV");
//      h1->GetXaxis()->SetTitle("M_{jj} [GeV] ");
      h1->GetYaxis()->SetTitle("#sigma (fb) # bin");
      h1->GetXaxis()->CenterTitle();
      h1->GetYaxis()->CenterTitle();
      h1->SetStats(kFALSE);
      h1->SetLineColor(kBlack);
      h1->SetLineWidth(3);
      h1->SetMarkerStyle(20);
      h1->GetXaxis()->SetTitleOffset(0.6);
      h1->GetYaxis()->SetTitleOffset(0.8);
      h1->Draw("Hist");
      h2->SetStats(kFALSE);
      h2->SetLineColor(kBlue);
      h2->SetLineWidth(3);
      h2->Draw("same HIST");

      TLegend *l1=new TLegend(0.65,0.65,0.78,0.82);
      l1->AddEntry(h1,"p21");
      l1->AddEntry(h2,"z2l");
      l1->Draw();
}
