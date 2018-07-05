//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 28 06:29:17 2016 by ROOT version 5.34/18
// from TTree ZPKUCandidates/ZPKU Candidates
// found on file: STt.root
//////////////////////////////////////////////////////////

#ifndef xx_h
#define xx_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
using namespace std;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxpassFilter_HBHE = 1;
const Int_t kMaxpassFilter_HBHEIso = 1;
const Int_t kMaxpassFilter_globalTightHalo = 1;
const Int_t kMaxpassFilter_ECALDeadCell = 1;
const Int_t kMaxpassFilter_GoodVtx = 1;
const Int_t kMaxpassFilter_EEBadSc = 1;
const Int_t kMaxpassFilter_badMuon = 1;
const Int_t kMaxpassFilter_badChargedHadron = 1;

class xx {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           event;
   Int_t           nVtx;
   Double_t        theWeight;
   Double_t        nump;
   Double_t        numm;
   Double_t        npT;
   Int_t           lep;
   Double_t        ptVlep;
   Double_t        yVlep;
   Double_t        phiVlep;
   Double_t        massVlep;
   Double_t        Mla;
   Double_t        Mla2;
   Double_t        Mva;
   Int_t           nlooseeles;
   Int_t           nloosemus;
   Bool_t          passEleVeto;
   Bool_t          passEleVetonew;
   Bool_t          passPixelSeedVeto;
   Double_t        photonet;
   Double_t        photoneta;
   Double_t        photonphi;
   Double_t        photone;
   Double_t        photonsieie;
   Double_t        photonphoiso;
   Double_t        photonchiso;
   Double_t        photonnhiso;
   Int_t           iphoton;
   Double_t        drla;
   Double_t        drla2;
   Int_t           isTrue;
   Int_t           isprompt;
   Double_t        jet1pt;
   Double_t        jet1eta;
   Double_t        jet1phi;
   Double_t        jet1e;
   Double_t        jet1csv;
   Double_t        jet1icsv;
   Double_t        jet2pt;
   Double_t        jet2eta;
   Double_t        jet2phi;
   Double_t        jet2e;
   Double_t        jet2csv;
   Double_t        jet2icsv;
   Double_t        drj1a;
   Double_t        drj2a;
   Double_t        drj1l;
   Double_t        drj2l;
   Double_t        drj1l2;
   Double_t        drj2l2;
   Double_t        Mjj;
   Double_t        deltaetajj;
   Double_t        zepp;
   Double_t        ptlep1;
   Double_t        etalep1;
   Double_t        philep1;
   Double_t        ptlep2;
   Double_t        etalep2;
   Double_t        philep2;
   // for muon rochester correction
   Int_t	   muon1_trackerLayers;
   Double_t	   matchedgenMu1_pt;
   Int_t	   muon2_trackerLayers;
   Double_t	   matchedgenMu2_pt;
//   Double_t 	   mu1_rochester_scale;
//   Double_t 	   mu2_rochester_scale;
   // for muon rochester correction
   Double_t        j1metPhi;
   Double_t        j2metPhi;
   Double_t        MET_et;
   Double_t        MET_phi;
   Int_t           HLT_Ele1;
//Meng
   Int_t	   HLT_Ele2;
//Lu
   Int_t           HLT_Mu1;
//Meng reMiniaod
   Int_t 	   HLT_Mu2;
   Int_t           HLT_Mu3;
   Int_t           HLT_Mu4;
   Int_t           HLT_Mu5;
   Int_t           HLT_Mu6;
   Int_t           HLT_Mu7;
   Int_t           HLT_Mu8;
//Lu
   Bool_t          passFilter_HBHE;
   Bool_t          passFilter_HBHEIso;
   Bool_t          passFilter_globalTightHalo;
   Bool_t          passFilter_ECALDeadCell;
   Bool_t          passFilter_GoodVtx;
   Bool_t          passFilter_EEBadSc;
   Bool_t          passFilter_badMuon;
   Bool_t          passFilter_badChargedHadron;
//Meng reMiniaod
   Bool_t	   passFilter_MetbadMuon;
   Bool_t   	   passFilter_duplicateMuon;
//Lu
   Double_t        lumiWeight;
   Double_t	   pileupWeight;
   Int_t	   run_period;
//Meng reMiniaod
   Double_t 	   lep1_eta_station2;
   Double_t 	   lep1_phi_station2;
   Int_t	   lep1_sign;
   Double_t	   lep2_eta_station2;
   Double_t	   lep2_phi_station2;
   Int_t	   lep2_sign;
   Double_t 	   l1_weight;
//Lu

// lep and photon scales
   Double_t	   ele1_id_scale;
   Double_t	   ele2_id_scale;
   Double_t	   ele1_reco_scale;
   Double_t	   ele2_reco_scale;
   Double_t	   photon_id_scale;
   
   Double_t	   muon1_id_scale;
   Double_t	   muon2_id_scale;
   Double_t	   muon1_iso_scale;
   Double_t	   muon2_iso_scale;
   Double_t	   muon1_track_scale;
   Double_t	   muon2_track_scale;
   Double_t	   muon_hlt_scale;
// lep and photn scales
   Double_t        photon_pt[6];
   Double_t        photon_eta[6];
   Double_t        photon_phi[6];
   Double_t        photon_e[6];
   Bool_t          photon_pev[6];
   Bool_t          photon_pevnew[6];
   Bool_t          photon_ppsv[6];
   Bool_t          photon_iseb[6];
   Bool_t          photon_isee[6];
   Double_t        photon_hoe[6];
   Double_t        photon_sieie[6];
   Double_t        photon_sieie2[6];
   Double_t        photon_chiso[6];
   Double_t        photon_nhiso[6];
   Double_t        photon_phoiso[6];
   Int_t           photon_istrue[6];
   Int_t           photon_isprompt[6];
   Double_t        photon_drla[6];
   Double_t        photon_drla2[6];
   Double_t        photon_mla[6];
   Double_t        photon_mla2[6];
   Double_t        photon_mva[6];
   Double_t        pweight[703];
   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_theWeight;   //!
   TBranch        *b_nump;   //!
   TBranch        *b_numm;   //!
   TBranch        *b_npT;   //!
   TBranch        *b_lep;   //!
   TBranch        *b_ptVlep;   //!
   TBranch        *b_yVlep;   //!
   TBranch        *b_phiVlep;   //!
   TBranch        *b_massVlep;   //!
   TBranch        *b_Mla;   //!
   TBranch        *b_Mla2;   //!
   TBranch        *b_Mva;   //!
   TBranch        *b_nlooseeles;   //!
   TBranch        *b_nloosemus;   //!
   TBranch        *b_passEleVeto;   //!
   TBranch        *b_passEleVetonew;   //!
   TBranch        *b_passPixelSeedVeto;   //!
   TBranch        *b_photonet;   //!
   TBranch        *b_photoneta;   //!
   TBranch        *b_photonphi;   //!
   TBranch        *b_photone;   //!
   TBranch        *b_photonsieie;   //!
   TBranch        *b_photonphoiso;   //!
   TBranch        *b_photonchiso;   //!
   TBranch        *b_photonnhiso;   //!
   TBranch        *b_iphoton;   //!
   TBranch        *b_drla;   //!
   TBranch        *b_drla2;   //!
   TBranch        *b_isTrue;   //!
   TBranch        *b_isprompt;   //!
   TBranch        *b_jet1pt;   //!
   TBranch        *b_jet1eta;   //!
   TBranch        *b_jet1phi;   //!
   TBranch        *b_jet1e;   //!
   TBranch        *b_jet1csv;   //!
   TBranch        *b_jet1icsv;   //!
   TBranch        *b_jet2pt;   //!
   TBranch        *b_jet2eta;   //!
   TBranch        *b_jet2phi;   //!
   TBranch        *b_jet2e;   //!
   TBranch        *b_jet2csv;   //!
   TBranch        *b_jet2icsv;   //!
   TBranch        *b_drj1a;   //!
   TBranch        *b_drj2a;   //!
   TBranch        *b_drj1l;   //!
   TBranch        *b_drj2l;   //!
   TBranch        *b_drj1l2;   //!
   TBranch        *b_drj2l2;   //!
   TBranch        *b_Mjj;   //!
   TBranch        *b_deltaetajj;   //!
   TBranch        *b_zepp;   //!
   TBranch        *b_ptlep1;   //!
   TBranch        *b_etalep1;   //!
   TBranch        *b_philep1;   //!
   TBranch        *b_ptlep2;   //!
   TBranch        *b_etalep2;   //!
   TBranch        *b_philep2;   //!
   //for muon rochester correction
   TBranch        *b_muon1_trackerLayers;   //!
   TBranch        *b_matchedgenMu1_pt;   //!
   TBranch        *b_muon2_trackerLayers;   //!
   TBranch        *b_matchedgenMu2_pt;   //!
   //for muon rochester correction
   TBranch        *b_j1metPhi;   //!
   TBranch        *b_j2metPhi;   //!
   TBranch        *b_MET_et;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_HLT_Ele1;   //!
   TBranch	  *b_HLT_Ele2;
   TBranch        *b_HLT_Mu1;   //!
   TBranch        *b_HLT_Mu2;   //!
   TBranch        *b_HLT_Mu3;   //!
   TBranch        *b_HLT_Mu4;   //!
   TBranch        *b_HLT_Mu5;   //!
   TBranch        *b_HLT_Mu6;   //!
   TBranch        *b_HLT_Mu7;   //!
   TBranch        *b_HLT_Mu8;   //!
   TBranch        *b_passFilter_HBHE_;   //!
   TBranch        *b_passFilter_HBHEIso_;   //!
   TBranch        *b_passFilter_globalTightHalo_;   //!
   TBranch        *b_passFilter_ECALDeadCell_;   //!
   TBranch        *b_passFilter_GoodVtx_;   //!
   TBranch        *b_passFilter_EEBadSc_;   //!
   TBranch        *b_passFilter_badMuon_;   //!
   TBranch        *b_passFilter_badChargedHadron_;   //!
   TBranch	  *b_passFilter_MetbadMuon_;
   TBranch	  *b_passFilter_duplicateMuon_;
   TBranch        *b_lumiWeight;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch	  *b_run_period;
   TBranch        *b_lep1_eta_station2;   //!
   TBranch        *b_lep1_phi_station2;   //!
   TBranch        *b_lep1_sign;   //!
   TBranch        *b_lep2_eta_station2;   //!
   TBranch        *b_lep2_phi_station2;   //!
   TBranch        *b_lep2_sign;
   TBranch	  *b_l1_weight;
   TBranch        *b_photon_pt;   //!
   TBranch        *b_photon_eta;   //!
   TBranch        *b_photon_phi;   //!
   TBranch        *b_photon_e;   //!
   TBranch        *b_photon_pev;   //!
   TBranch        *b_photon_pevnew;   //!
   TBranch        *b_photon_ppsv;   //!
   TBranch        *b_photon_iseb;   //!
   TBranch        *b_photon_isee;   //!
   TBranch        *b_photon_hoe;   //!
   TBranch        *b_photon_sieie;   //!
   TBranch        *b_photon_sieie2;   //!
   TBranch        *b_photon_chiso;   //!
   TBranch        *b_photon_nhiso;   //!
   TBranch        *b_photon_phoiso;   //!
   TBranch        *b_photon_istrue;   //!
   TBranch        *b_photon_isprompt;   //!
   TBranch        *b_photon_drla;   //!
   TBranch        *b_photon_drla2;   //!
   TBranch        *b_photon_mla;   //!
   TBranch        *b_photon_mla2;   //!
   TBranch        *b_photon_mva;   //!
   TBranch        *b_pweight;   //!

/// Meng
   TString m_dataset;
   xx(TTree *tree=0, TString dataset="");
///  Lu

   virtual ~xx();
   virtual Int_t    Cut(Long64_t entry);
   virtual void     endJob();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

///Meng
private:
    TTree *ExTree;
    TFile *fout;
    double scalef;
///Lu
};

#endif

#ifdef xx_cxx
xx::xx(TTree *tree,TString dataset) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("STt.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("STt.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("STt.root:/treeDumper");
      dir->GetObject("ZPKUCandidates",tree);

   }
///Meng
	m_dataset=dataset;
///Lu
   Init(tree);
}

xx::~xx()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t xx::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t xx::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void xx::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fout = new TFile(m_dataset, "RECREATE");
   ExTree = new TTree("demo","demo");
   ExTree->Branch("scalef",&scalef,"scalef/D");
   ExTree->Branch("nVtx", &nVtx, "nVtx/I");
   ExTree->Branch("theWeight", &theWeight, "theWeight/D");
   ExTree->Branch("lumiWeight", &lumiWeight, "lumiWeight/D");
   ExTree->Branch("pileupWeight", &pileupWeight, "pileupWeight/D");
   ExTree->Branch("run_period", &run_period, "run_period/I");
   ExTree->Branch("lep1_eta_station2", &lep1_eta_station2, "lep1_eta_station2/D");
   ExTree->Branch("lep1_phi_station2", &lep1_phi_station2, "lep1_phi_station2/D");
   ExTree->Branch("lep1_sign", &lep1_sign, "lep1_sign/I");
   ExTree->Branch("lep2_eta_station2", &lep2_eta_station2, "lep2_eta_station2/D");
   ExTree->Branch("lep2_phi_station2", &lep2_phi_station2, "lep2_phi_station2/D");
   ExTree->Branch("lep2_sign", &lep2_sign, "lep2_sign/I");
   ExTree->Branch("l1_weight", &l1_weight, "l1_weight/D");
   ExTree->Branch("HLT_Ele1", &HLT_Ele1, "HLT_Ele1/I");
   ExTree->Branch("HLT_Ele2", &HLT_Ele2, "HLT_Ele2/I");
   ExTree->Branch("HLT_Mu1", &HLT_Mu1, "HLT_Mu1/I");
   ExTree->Branch("HLT_Mu2", &HLT_Mu2, "HLT_Mu2/I");
   ExTree->Branch("HLT_Mu3", &HLT_Mu3, "HLT_Mu3/I");
   ExTree->Branch("HLT_Mu4", &HLT_Mu4, "HLT_Mu4/I");
   ExTree->Branch("HLT_Mu5", &HLT_Mu5, "HLT_Mu5/I");
   ExTree->Branch("HLT_Mu6", &HLT_Mu6, "HLT_Mu6/I");
   ExTree->Branch("HLT_Mu7", &HLT_Mu7, "HLT_Mu7/I");
   ExTree->Branch("HLT_Mu8", &HLT_Mu8, "HLT_Mu8/I");
   ExTree->Branch("nump", &nump, "nump/D");
   ExTree->Branch("numm", &numm, "numm/D");
   ExTree->Branch("npT", &npT, "npT/D");
   ExTree->Branch("lep", &lep, "lep/I");
   ExTree->Branch("ptVlep", &ptVlep, "ptVlep/D");
   ExTree->Branch("yVlep", &yVlep, "yVlep/D");
   ExTree->Branch("phiVlep", &phiVlep, "phiVlep/D");
   ExTree->Branch("massVlep", &massVlep, "massVlep/D");
   ExTree->Branch("ptlep1", &ptlep1, "ptlep1/D");
   ExTree->Branch("etalep1", &etalep1, "etalep1/D");
   ExTree->Branch("philep1", &philep1, "philep1/D");
   ExTree->Branch("ptlep2", &ptlep2, "ptlep2/D");
   ExTree->Branch("etalep2", &etalep2, "etalep2/D");
   ExTree->Branch("philep2", &philep2, "philep2/D");
   // for muon rochester correction
   ExTree->Branch("muon1_trackerLayers", &muon1_trackerLayers, "muon1_trackerLayers/I");
   ExTree->Branch("matchedgenMu1_pt", &matchedgenMu1_pt, "matchedgenMu1_pt/D");
   ExTree->Branch("muon2_trackerLayers", &muon2_trackerLayers, "muon2_trackerLayers/I");
   ExTree->Branch("matchedgenMu2_pt", &matchedgenMu2_pt, "matchedgenMu2_pt/D");
//   ExTree->Branch("mu1_rochester_scale", &mu1_rochester_scale, "mu1_rochester_scale/D");
//   ExTree->Branch("mu2_rochester_scale", &mu2_rochester_scale, "mu2_rochester_scale/D");
   // for muon rochester correction
   ExTree->Branch("drla", &drla, "drla/D");
   ExTree->Branch("drla2", &drla2, "drla2/D");
   ExTree->Branch("nlooseeles", &nlooseeles, "nlooseeles/I");
   ExTree->Branch("drj1a", &drj1a, "drj1a/D");
   ExTree->Branch("drj2a", &drj2a, "drj2a/D");
   ExTree->Branch("drj1l", &drj1l, "drj1l/D");
   ExTree->Branch("drj2l", &drj2l, "drj2l/D");
   ExTree->Branch("drj1l2", &drj1l2, "drj1l2/D");
   ExTree->Branch("drj2l2", &drj2l2, "drj2l2/D");
   ExTree->Branch("nloosemus", &nloosemus, "nloosemus/I");
   ExTree->Branch("MET_et", &MET_et, "MET_et/D");
   ExTree->Branch("photonet", &photonet, "photonet/D");
   ExTree->Branch("photoneta", &photoneta, "photoneta/D");
   ExTree->Branch("photonphi", &photonphi, "photonphi/D");
   ExTree->Branch("photone", &photone, "photone/D");
   ExTree->Branch("photonsieie", &photonsieie, "photonsieie/D");
   ExTree->Branch("photonphoiso", &photonphoiso, "photonphoiso/D");
   ExTree->Branch("photonchiso", &photonchiso, "photonchiso/D");
   ExTree->Branch("photonnhiso", &photonnhiso, "photonnhiso/D");
   ExTree->Branch("isprompt", &isprompt, "isprompt/I");
   ExTree->Branch("jet1pt", &jet1pt, "jet1pt/D");
   ExTree->Branch("jet1eta", &jet1eta, "jet1eta/D");
   ExTree->Branch("jet1phi", &jet1phi, "jet1phi/D");
   ExTree->Branch("jet1e", &jet1e, "jet1e/D");
   ExTree->Branch("jet2pt", &jet2pt, "jet2pt/D");
   ExTree->Branch("jet2eta", &jet2eta, "jet2eta/D");
   ExTree->Branch("jet2phi", &jet2phi, "jet2phi/D");
   ExTree->Branch("jet2e", &jet2e, "jet2e/D");
   ExTree->Branch("Mjj", &Mjj, "Mjj/D");
   ExTree->Branch("zepp", &zepp, "zepp/D");
   ExTree->Branch("deltaetajj", &deltaetajj, "deltaetajj/D");   
   ExTree->Branch("photon_pt", &photon_pt, "photon_pt[6]/D");
   ExTree->Branch("photon_eta", &photon_eta, "photon_eta[6]/D");
   ExTree->Branch("photon_phi", &photon_phi, "photon_phi[6]/D");
   ExTree->Branch("photon_e", &photon_e, "photon_e[6]/D");
   ExTree->Branch("photon_pev", &photon_pev, "photon_pev[6]/O");
   ExTree->Branch("photon_pevnew", &photon_pevnew, "photon_pevnew[6]/O");
   ExTree->Branch("photon_ppsv", &photon_ppsv, "photon_ppsv[6]/O");
   ExTree->Branch("photon_iseb", &photon_iseb, "photon_iseb[6]/O");
   ExTree->Branch("photon_isee", &photon_isee, "photon_isee[6]/O");
   ExTree->Branch("photon_hoe", &photon_hoe, "photon_hoe[6]/D");
   ExTree->Branch("photon_sieie", &photon_sieie, "photon_sieie[6]/D");
   ExTree->Branch("photon_sieie2", &photon_sieie2, "photon_sieie2[6]/D");
   ExTree->Branch("photon_chiso", &photon_chiso, "photon_chiso[6]/D");
   ExTree->Branch("photon_nhiso", &photon_nhiso, "photon_nhiso[6]/D");
   ExTree->Branch("photon_phoiso", &photon_phoiso, "photon_phoiso[6]/D");
   ExTree->Branch("photon_istrue", &photon_istrue, "photon_istrue[6]/I");
   ExTree->Branch("photon_isprompt", &photon_isprompt, "photon_isprompt[6]/I");
   ExTree->Branch("photon_drla", &photon_drla, "photon_drla[6]/D");
   ExTree->Branch("photon_drla2", &photon_drla2, "photon_drla2[6]/D");
   ExTree->Branch("photon_mla", &photon_mla, "photon_mla[6]/D");
   ExTree->Branch("photon_mla2", &photon_mla2, "photon_mla2[6]/D");
   ExTree->Branch("photon_mva", &photon_mva, "photon_mva[6]/D");
   ExTree->Branch("pweight", &pweight, "pweight[703]/D");
// lep and photon scales
   ExTree->Branch("ele1_id_scale", &ele1_id_scale, "ele1_id_scale/D");
   ExTree->Branch("ele2_id_scale", &ele2_id_scale, "ele2_id_scale/D");
   ExTree->Branch("ele1_reco_scale", &ele1_reco_scale, "ele1_reco_scale/D");
   ExTree->Branch("ele2_reco_scale", &ele2_reco_scale, "ele2_reco_scale/D");
   ExTree->Branch("photon_id_scale", &photon_id_scale, "photon_id_scale/D");

   ExTree->Branch("muon1_id_scale", &muon1_id_scale, "muon1_id_scale/D");
   ExTree->Branch("muon2_id_scale", &muon2_id_scale, "muon2_id_scale/D");
   ExTree->Branch("muon1_iso_scale", &muon1_iso_scale, "muon1_iso_scale/D");
   ExTree->Branch("muon2_iso_scale", &muon2_iso_scale, "muon2_iso_scale/D");
   ExTree->Branch("muon1_track_scale", &muon1_track_scale, "muon1_track_scale/D");
   ExTree->Branch("muon2_track_scale", &muon2_track_scale, "muon2_track_scale/D");
   ExTree->Branch("muon_hlt_scale", &muon_hlt_scale, "muon_hlt_scale/D");
// lep and photon scales

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("theWeight", &theWeight, &b_theWeight);
   fChain->SetBranchAddress("nump", &nump, &b_nump);
   fChain->SetBranchAddress("numm", &numm, &b_numm);
   fChain->SetBranchAddress("npT", &npT, &b_npT);
   fChain->SetBranchAddress("lep", &lep, &b_lep);
   fChain->SetBranchAddress("ptVlep", &ptVlep, &b_ptVlep);
   fChain->SetBranchAddress("yVlep", &yVlep, &b_yVlep);
   fChain->SetBranchAddress("phiVlep", &phiVlep, &b_phiVlep);
   fChain->SetBranchAddress("massVlep", &massVlep, &b_massVlep);
   fChain->SetBranchAddress("Mla", &Mla, &b_Mla);
   fChain->SetBranchAddress("Mla2", &Mla2, &b_Mla2);
   fChain->SetBranchAddress("Mva", &Mva, &b_Mva);
   fChain->SetBranchAddress("nlooseeles", &nlooseeles, &b_nlooseeles);
   fChain->SetBranchAddress("nloosemus", &nloosemus, &b_nloosemus);
   fChain->SetBranchAddress("passEleVeto", &passEleVeto, &b_passEleVeto);
   fChain->SetBranchAddress("passEleVetonew", &passEleVetonew, &b_passEleVetonew);
   fChain->SetBranchAddress("passPixelSeedVeto", &passPixelSeedVeto, &b_passPixelSeedVeto);
   fChain->SetBranchAddress("photonet", &photonet, &b_photonet);
   fChain->SetBranchAddress("photoneta", &photoneta, &b_photoneta);
   fChain->SetBranchAddress("photonphi", &photonphi, &b_photonphi);
   fChain->SetBranchAddress("photone", &photone, &b_photone);
   fChain->SetBranchAddress("photonsieie", &photonsieie, &b_photonsieie);
   fChain->SetBranchAddress("photonphoiso", &photonphoiso, &b_photonphoiso);
   fChain->SetBranchAddress("photonchiso", &photonchiso, &b_photonchiso);
   fChain->SetBranchAddress("photonnhiso", &photonnhiso, &b_photonnhiso);
   fChain->SetBranchAddress("iphoton", &iphoton, &b_iphoton);
   fChain->SetBranchAddress("drla", &drla, &b_drla);
   fChain->SetBranchAddress("drla2", &drla2, &b_drla2);
   fChain->SetBranchAddress("isTrue", &isTrue, &b_isTrue);
   fChain->SetBranchAddress("isprompt", &isprompt, &b_isprompt);
   fChain->SetBranchAddress("jet1pt", &jet1pt, &b_jet1pt);
   fChain->SetBranchAddress("jet1eta", &jet1eta, &b_jet1eta);
   fChain->SetBranchAddress("jet1phi", &jet1phi, &b_jet1phi);
   fChain->SetBranchAddress("jet1e", &jet1e, &b_jet1e);
   fChain->SetBranchAddress("jet1csv", &jet1csv, &b_jet1csv);
   fChain->SetBranchAddress("jet1icsv", &jet1icsv, &b_jet1icsv);
   fChain->SetBranchAddress("jet2pt", &jet2pt, &b_jet2pt);
   fChain->SetBranchAddress("jet2eta", &jet2eta, &b_jet2eta);
   fChain->SetBranchAddress("jet2phi", &jet2phi, &b_jet2phi);
   fChain->SetBranchAddress("jet2e", &jet2e, &b_jet2e);
   fChain->SetBranchAddress("jet2csv", &jet2csv, &b_jet2csv);
   fChain->SetBranchAddress("jet2icsv", &jet2icsv, &b_jet2icsv);
   fChain->SetBranchAddress("drj1a", &drj1a, &b_drj1a);
   fChain->SetBranchAddress("drj2a", &drj2a, &b_drj2a);
   fChain->SetBranchAddress("drj1l", &drj1l, &b_drj1l);
   fChain->SetBranchAddress("drj2l", &drj2l, &b_drj2l);
   fChain->SetBranchAddress("drj1l2", &drj1l2, &b_drj1l2);
   fChain->SetBranchAddress("drj2l2", &drj2l2, &b_drj2l2);
   fChain->SetBranchAddress("Mjj", &Mjj, &b_Mjj);
   fChain->SetBranchAddress("deltaetajj", &deltaetajj, &b_deltaetajj);
   fChain->SetBranchAddress("zepp", &zepp, &b_zepp);
   fChain->SetBranchAddress("ptlep1", &ptlep1, &b_ptlep1);
   fChain->SetBranchAddress("etalep1", &etalep1, &b_etalep1);
   fChain->SetBranchAddress("philep1", &philep1, &b_philep1);
   fChain->SetBranchAddress("ptlep2", &ptlep2, &b_ptlep2);
   fChain->SetBranchAddress("etalep2", &etalep2, &b_etalep2);
   fChain->SetBranchAddress("philep2", &philep2, &b_philep2);
   // for muon rochester correction
   fChain->SetBranchAddress("muon1_trackerLayers", &muon1_trackerLayers, &b_muon1_trackerLayers);
   fChain->SetBranchAddress("matchedgenMu1_pt", &matchedgenMu1_pt, &b_matchedgenMu1_pt);
   fChain->SetBranchAddress("muon2_trackerLayers", &muon2_trackerLayers, &b_muon2_trackerLayers);
   fChain->SetBranchAddress("matchedgenMu2_pt", &matchedgenMu2_pt, &b_matchedgenMu2_pt);
   // for muon rochester correction
   fChain->SetBranchAddress("j1metPhi", &j1metPhi, &b_j1metPhi);
   fChain->SetBranchAddress("j2metPhi", &j2metPhi, &b_j2metPhi);
   fChain->SetBranchAddress("MET_et", &MET_et, &b_MET_et);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("HLT_Ele1", &HLT_Ele1, &b_HLT_Ele1);
   fChain->SetBranchAddress("HLT_Ele2", &HLT_Ele2, &b_HLT_Ele2);
   fChain->SetBranchAddress("HLT_Mu1", &HLT_Mu1, &b_HLT_Mu1);
   fChain->SetBranchAddress("HLT_Mu2", &HLT_Mu2, &b_HLT_Mu2);
   fChain->SetBranchAddress("HLT_Mu3", &HLT_Mu3, &b_HLT_Mu3);
   fChain->SetBranchAddress("HLT_Mu4", &HLT_Mu4, &b_HLT_Mu4);
   fChain->SetBranchAddress("HLT_Mu5", &HLT_Mu5, &b_HLT_Mu5);
   fChain->SetBranchAddress("HLT_Mu6", &HLT_Mu6, &b_HLT_Mu6);
   fChain->SetBranchAddress("HLT_Mu7", &HLT_Mu7, &b_HLT_Mu7);
   fChain->SetBranchAddress("HLT_Mu8", &HLT_Mu8, &b_HLT_Mu8);
   fChain->SetBranchAddress("passFilter_HBHE", &passFilter_HBHE, &b_passFilter_HBHE_);
   fChain->SetBranchAddress("passFilter_HBHEIso", &passFilter_HBHEIso, &b_passFilter_HBHEIso_);
   fChain->SetBranchAddress("passFilter_globalTightHalo", &passFilter_globalTightHalo, &b_passFilter_globalTightHalo_);
   fChain->SetBranchAddress("passFilter_ECALDeadCell", &passFilter_ECALDeadCell, &b_passFilter_ECALDeadCell_);
   fChain->SetBranchAddress("passFilter_GoodVtx", &passFilter_GoodVtx, &b_passFilter_GoodVtx_);
   fChain->SetBranchAddress("passFilter_EEBadSc", &passFilter_EEBadSc, &b_passFilter_EEBadSc_);
   fChain->SetBranchAddress("passFilter_badMuon", &passFilter_badMuon, &b_passFilter_badMuon_);
   fChain->SetBranchAddress("passFilter_badChargedHadron", &passFilter_badChargedHadron, &b_passFilter_badChargedHadron_);
   fChain->SetBranchAddress("passFilter_MetbadMuon",	&passFilter_MetbadMuon, &b_passFilter_MetbadMuon_);
   fChain->SetBranchAddress("passFilter_duplicateMuon", &passFilter_duplicateMuon, &b_passFilter_duplicateMuon_);
   fChain->SetBranchAddress("lumiWeight", &lumiWeight, &b_lumiWeight);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("lep1_eta_station2", &lep1_eta_station2, &b_lep1_eta_station2);
   fChain->SetBranchAddress("lep1_phi_station2", &lep1_phi_station2, &b_lep1_phi_station2);
   fChain->SetBranchAddress("lep1_sign", &lep1_sign, &b_lep1_sign);
   fChain->SetBranchAddress("lep2_eta_station2", &lep2_eta_station2, &b_lep2_eta_station2);
   fChain->SetBranchAddress("lep2_phi_station2", &lep2_phi_station2, &b_lep2_phi_station2);
   fChain->SetBranchAddress("lep2_sign", &lep2_sign, &b_lep2_sign);
   fChain->SetBranchAddress("photon_pt", photon_pt, &b_photon_pt);
   fChain->SetBranchAddress("photon_eta", photon_eta, &b_photon_eta);
   fChain->SetBranchAddress("photon_phi", photon_phi, &b_photon_phi);
   fChain->SetBranchAddress("photon_e", photon_e, &b_photon_e);
   fChain->SetBranchAddress("photon_pev", photon_pev, &b_photon_pev);
   fChain->SetBranchAddress("photon_pevnew", photon_pevnew, &b_photon_pevnew);
   fChain->SetBranchAddress("photon_ppsv", photon_ppsv, &b_photon_ppsv);
   fChain->SetBranchAddress("photon_iseb", photon_iseb, &b_photon_iseb);
   fChain->SetBranchAddress("photon_isee", photon_isee, &b_photon_isee);
   fChain->SetBranchAddress("photon_hoe", photon_hoe, &b_photon_hoe);
   fChain->SetBranchAddress("photon_sieie", photon_sieie, &b_photon_sieie);
   fChain->SetBranchAddress("photon_sieie2", photon_sieie2, &b_photon_sieie2);
   fChain->SetBranchAddress("photon_chiso", photon_chiso, &b_photon_chiso);
   fChain->SetBranchAddress("photon_nhiso", photon_nhiso, &b_photon_nhiso);
   fChain->SetBranchAddress("photon_phoiso", photon_phoiso, &b_photon_phoiso);
   fChain->SetBranchAddress("photon_istrue", photon_istrue, &b_photon_istrue);
   fChain->SetBranchAddress("photon_isprompt", photon_isprompt, &b_photon_isprompt);
   fChain->SetBranchAddress("photon_drla", photon_drla, &b_photon_drla);
   fChain->SetBranchAddress("photon_drla2", photon_drla2, &b_photon_drla2);
   fChain->SetBranchAddress("photon_mla", photon_mla, &b_photon_mla);
   fChain->SetBranchAddress("photon_mla2", photon_mla2, &b_photon_mla2);
   fChain->SetBranchAddress("photon_mva", photon_mva, &b_photon_mva);
   fChain->SetBranchAddress("pweight", pweight, &b_pweight);
   Notify();
}

Bool_t xx::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void xx::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
///Meng
void xx::endJob() {
    fout->cd();
    ExTree->Write();
    fout->Write();
    fout->Close();
    delete fout;
 }
///Lu


Int_t xx::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef xx_cxx
