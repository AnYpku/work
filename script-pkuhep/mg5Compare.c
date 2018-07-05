void mg5Compare(){

// Load shared library
 gSystem->Load("/store/home/andy/MC/MG5/MG5_aMC_v2_3_3/ExRootAnalysis/libExRootAnalysis.so");
// gSystem->Load("/home/qliphy/Desktop/common/root/lib/root/libPhysics.so");
// Create chain of root trees


 float inix= 0.0;
 float finx= 2000.0;
 float nbin= 50.0;

 
TString IFile1 =   "pp-zajj.root";
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
    h1->Fill(JJ.M(), 529.9/float(numberOfEntries)); 
////*****************************************************************
}
      h1->SetTitle("VBF Z(#rightarrow e^{+}e^{-})+2Jets at 13TeV LHC");
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
}
