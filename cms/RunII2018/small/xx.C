#define xx_cxx
#include "L1_weight.C"
#include "xx.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;
void xx::Loop(TString name)
{
//   In a ROOT session, you can do:
//      root> .L xx.C
//      root> xx t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();


   double lep1_phi_station2_tmp = 0;
   double lep2_phi_station2_tmp = 0;
   

   cut0=0,cut1=0;
//   TFile* f1 = new TFile("/eos/uscms/store/user/qliphy/andy/2017/WJets_FX.root");
//   TTree* t1 =(TTree*)f1->Get("treeDumper/ZPKUCandidates");
//   Long64_t npp = t1->GetEntries("theWeight>0.");
//   Long64_t nmm = t1->GetEntries("theWeight<0.");
//   f1->Close();
   bool LEPele,LEPmu,JET,PHOTON,SignalRegion,DR;
//  nentries=1000;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      lep1_phi_station2_tmp = lep1_phi_station2;
      lep2_phi_station2_tmp = lep2_phi_station2;      
      //scalef =   
      cut0++;//total events, cut0=t1->GetEntries()
       
      if(name.Contains("Muon")) scalef=1;
      if(lep1_phi_station2<0) lep1_phi_station2_tmp = lep1_phi_station2+6.28319;
      if(lep2_phi_station2<0) lep2_phi_station2_tmp = lep2_phi_station2+6.28319;

      l1_weight = L1_weight(lep1_phi_station2_tmp, lep2_phi_station2_tmp, lep1_eta_station2, lep2_eta_station2);      
      if(drla==10) drla=-1;
      if(drla2==10) drla2=-1; 
      if(drj1a==10) drj1a=-1;
      if(drj2a==10) drj2a=-1;
      if(m_dataset.Contains("plj")){scalef=1.0;run_period=6;}
//      if(m_dataset.Contains("ZAJets")){scalef=1000.*6259.0/float(npp-nmm)*fabs(theWeight)/theWeight; run_period=8;}
//     if(m_dataset.Contains("TTJets")){scalef=1000.*831.76/float(npp-nmm)*fabs(theWeight)/theWeight; run_period=8;}
//      if(m_dataset.Contains("WJets_MLM")){scalef=1000.*52940.0 /float(npp-nmm)*fabs(theWeight)/theWeight; run_period=8;}
//      if(m_dataset.Contains("WJets_FX")){scalef=1000.*61526.7/float(npp-nmm)*fabs(theWeight)/theWeight; run_period=8;}

      LEPele = lep==11 && HLT_Ele1>0 && ptlep1 > 25. && ptlep2 > 25.&& fabs(etalep1) < 2.5 &&abs(etalep2) < 2.5 && nlooseeles < 3 && nloosemus == 0  && massVlep >70.;
      LEPmu = lep==13 && (HLT_Mu1>0||HLT_Mu2>0) && ptlep1 > 20. && ptlep2 > 20.&& fabs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles==0 && nloosemus <3  && massVlep >70. ;
      SignalRegion= Mjj>500 && deltaetajj>2.5;// && zepp<1.8;
      PHOTON= photonet>20 &&( (fabs(photoneta)<2.5&&fabs(photoneta)>1.566) || (fabs(photoneta)<1.4442) );
      JET=jet1pt> 30 && jet2pt > 30 && fabs(jet1eta)< 4.7 && fabs(jet2eta)<4.7;
      DR =drla>0.7 && drla2>0.7 && drj1a>0.5 && drj2a>0.5;
      if(jentry%1000000==0)   cout<<jentry<<"; "<<nentries<<"; cut1 = "<<cut1<<endl;
      if( ! ( (LEPmu || LEPele) && PHOTON  ) )
	      continue;
      if(m_dataset.Contains("contamination")){
	      if(isprompt!=1 ) continue;
      }
      cut1++;//how many events passing the selection 
      newtree->Fill(); //fill the brach when this entry pass the both selection
//                 cout<<"jentry = "<<jentry<<"; cut1 = "<<cut1<<endl;

    }
}
