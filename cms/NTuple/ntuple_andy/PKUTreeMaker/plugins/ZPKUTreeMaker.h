#ifndef _ZPKUTreeMaker_h
#define _ZPKUTreeMaker_h
#include <memory>
#include "TMath.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/View.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Candidate/interface/ShallowCloneCandidate.h"
#include "DataFormats/Candidate/interface/CompositeCandidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/CompositeCandidateFwd.h"
#include "CommonTools/CandUtils/interface/AddFourMomenta.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "TTree.h"
#include "TFile.h"
#include "TLorentzVector.h"
#include<algorithm>
#define Pi 3.141593
#include "Math/VectorUtil.h"
#include "TMath.h"
#include <TFormula.h>
#include "CommonTools/Utils/interface/StringCutObjectSelector.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "RecoEgamma/EgammaTools/interface/EffectiveAreas.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"
#include "MuonAnalysis/MuonAssociators/interface/PropagateToMuon.h"
#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
class ZPKUTreeMaker : public edm::EDAnalyzer {
  public:
      explicit ZPKUTreeMaker(const edm::ParameterSet&);
      ~ZPKUTreeMaker();
      enum PhotonMatchType {UNMATCHED = 0,
			MATCHED_FROM_GUDSCB,
			MATCHED_FROM_PI0,
			MATCHED_FROM_OTHER_SOURCES};
  private:
        virtual void beginJob() override;
		virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
		virtual void endJob() override;
		virtual void beginRun(const edm::Run&, const edm::EventSetup&) override;
		virtual void endRun(const edm::Run&, const edm::EventSetup&) override;
		virtual void addTypeICorr( edm::Event const & event );
//		virtual void addTypeICorr_user( edm::Event const & event );//---for MET, Meng
		virtual double getJEC( reco::Candidate::LorentzVector& rawJetP4, const pat::Jet& jet, double& jetCorrEtaMax, std::vector<std::string> jecPayloadNames_ );
		virtual double getJECOffset( reco::Candidate::LorentzVector& rawJetP4, const pat::Jet& jet, double& jetCorrEtaMax, std::vector<std::string> jecPayloadNames_ );
		math::XYZTLorentzVector getNeutrinoP4(double& MetPt, double& MetPhi, TLorentzVector& lep, int lepType);
		bool hasMatchedPromptElectron(const reco::SuperClusterRef &sc, const edm::Handle<edm::View<pat::Electron> > &eleCol,const edm::Handle<reco::ConversionCollection> &convCol, const math::XYZPoint &beamspot,float lxyMin=2.0, float probMin=1e-6, unsigned int nHitsBeforeVtxMax=0);
		int matchToTruth(const reco::Photon &pho,const edm::Handle<edm::View<reco::GenParticle>>  &genParticles, bool &ISRPho, double &dR, int &isprompt);

		void findFirstNonPhotonMother(const reco::Candidate *particle,int &ancestorPID, int &ancestorStatus);
        void setDummyValues();

        float EAch(float x);
		float EAnh(float x);
		float EApho(float x);
        std::pair<double,double> EtaPhiAtME2X(const pat::Muon *iM, const PropagateToMuon *propagatetomuon);

/* member data */

    edm::EDGetTokenT<edm::View<pat::Muon> > goodmuonToken_;
    edm::EDGetTokenT<edm::View<pat::Electron> > goodeleToken_;
    edm::EDGetTokenT<double> rhoToken_;
    edm::EDGetTokenT<pat::METCollection> metInputToken_;
    std::vector<edm::EDGetTokenT<pat::METCollection>> mettokens;
    edm::EDGetTokenT<pat::METCollection> metToken_;
    edm::EDGetTokenT<edm::View<pat::Electron> > electronToken_ ;
    edm::EDGetTokenT<edm::View<pat::Photon> > photonToken_;
    edm::EDGetTokenT<reco::BeamSpot> beamSpotToken_;
    edm::EDGetTokenT<std::vector<reco::Conversion> > conversionsToken_;
    edm::EDGetTokenT<edm::View<pat::Electron> > looseelectronToken_ ;
    edm::EDGetTokenT<edm::View<pat::Muon> > loosemuonToken_;
    
    edm::EDGetTokenT<edm::TriggerResults>            noiseFilterToken_;
    edm::EDGetTokenT<bool>  badMuon_Selector_;
    edm::EDGetTokenT<bool>  badChargedHadron_Selector_;

    edm::EDGetTokenT<edm::ValueMap<float> > full5x5SigmaIEtaIEtaMapToken_;
    edm::EDGetTokenT<edm::ValueMap<float> > phoChargedIsolationToken_;
    edm::EDGetTokenT<edm::ValueMap<float> > phoNeutralHadronIsolationToken_;
    edm::EDGetTokenT<edm::ValueMap<float> > phoPhotonIsolationToken_;


    edm::EDGetTokenT<edm::TriggerResults> hltToken_;

    edm::EDGetTokenT<GenEventInfoProduct> GenToken_;
    edm::EDGetTokenT<LHEEventProduct> LheToken_;
    edm::EDGetTokenT<reco::GenJetCollection> genJet_;
    edm::EDGetTokenT<std::vector<PileupSummaryInfo>> PUToken_;
    edm::EDGetTokenT<edm::View<reco::Candidate>> leptonicVSrc_;
    edm::EDGetTokenT<edm::View<pat::Jet>> ak4jetsSrc_;
    edm::EDGetTokenT<edm::View<pat::Photon>> photonSrc_;
    edm::EDGetTokenT<edm::View<reco::GenParticle>> genSrc_;
    edm::EDGetTokenT<edm::View<reco::Candidate>> metSrc_;
    edm::EDGetTokenT<reco::VertexCollection> VertexToken_;
    edm::EDGetTokenT<pat::JetCollection> t1jetSrc_;
    edm::EDGetTokenT<edm::View<pat::Muon>> t1muSrc_;

/* member data */

    // ----------member data in the tree ---------------------------
		TTree* outTree_;

        double ele1_sigmaieie, ele2_sigmaieie;
		double lep1_eta_station2;
		double lep1_phi_station2;
		int lep1_sign;
		double lep2_eta_station2;
		double lep2_phi_station2;
		int lep2_sign;

		int nevent, run, ls;
		int nVtx;
		double triggerWeight, lumiWeight, pileupWeight;
		double theWeight;
		double  nump=0.;
		double  numm=0.;
		double  npT, npIT;
		int     nBX;
		double ptVlep, yVlep, phiVlep, massVlep;
		double Mla, Mla2, Mva;
		double Mla_f, Mla2_f, Mva_f;
		double ptlep1, etalep1, philep1;
		double ptlep2, etalep2, philep2;
		// for muon rochester correction
		int muon1_trackerLayers;
		double matchedgenMu1_pt;
		int muon2_trackerLayers;
		double matchedgenMu2_pt;
		double getDR(double eta1, double phi1, double eta2, double phi2);
		// for muon rochester correction
		int  lep, nlooseeles,nloosemus, ngoodmus;
		double met, metPhi, j1metPhi, j2metPhi;
		double j1metPhi_f, j2metPhi_f;
		//Met JEC
		double METraw_et, METraw_phi, METraw_sumEt;
		double genMET, MET_et, MET_phi, MET_sumEt, MET_corrPx, MET_corrPy;
		double useless;
		// AK4 Jets
		double ak4jet_pt[6],ak4jet_eta[6],ak4jet_phi[6],ak4jet_e[6];
		double ak4jet_pt_jer[6];
		double ak4jet_csv[6],ak4jet_icsv[6];
		double drjetlep[6], drjetphoton[6];
		double genphoton_pt[6],genphoton_eta[6],genphoton_phi[6];
		double genjet_pt[6],genjet_eta[6],genjet_phi[6],genjet_e[6];
		double genmuon_pt[6],genmuon_eta[6],genmuon_phi[6];
		int genmuon_pid[6];
		double genelectron_pt[6],genelectron_eta[6],genelectron_phi[6];
		//Photon
		double photon_pt[6],photon_eta[6],photon_phi[6],photon_e[6];
		bool   photon_pev[6],photon_pevnew[6],photon_ppsv[6],photon_iseb[6],photon_isee[6];
		double photon_hoe[6],photon_sieie[6],photon_sieie2[6],photon_chiso[6],photon_nhiso[6],photon_phoiso[6],photon_drla[6],photon_drla2[6],photon_mla[6],photon_mla2[6],photon_mva[6];
		int      photon_istrue[6], photon_isprompt[6];
		double photonet, photoneta, photonphi, photone;
		double photonet_f, photoneta_f, photonphi_f, photone_f;
		double photonsieie, photonphoiso, photonchiso, photonnhiso;
		double photonsieie_f, photonphoiso_f, photonchiso_f, photonnhiso_f;
		int iphoton;
		int iphoton_f;
		double drla,drla2;
		double drla_f,drla2_f;
		bool passEleVeto, passEleVetonew, passPixelSeedVeto;
		//Photon gen match
		int   isTrue_;
		bool ISRPho;
		int isprompt_;
		double dR_;
		//Jets
		double jet1pt, jet1eta, jet1phi, jet1e, jet1csv, jet1icsv;
		double jet1pt_f, jet1eta_f, jet1phi_f, jet1e_f, jet1csv_f, jet1icsv_f;
		double jet2pt, jet2eta, jet2phi, jet2e, jet2csv, jet2icsv;
		double jet2pt_f, jet2eta_f, jet2phi_f, jet2e_f, jet2csv_f, jet2icsv_f;
		double drj1a, drj2a, drj1l, drj2l, drj1l2,drj2l2;
		double drj1a_f, drj2a_f, drj1l_f, drj2l_f, drj1l2_f, drj2l2_f;
		double Mjj, deltaetajj, zepp;
		double Mjj_f, deltaetajj_f, zepp_f;

		// lhe for fiducial, 2018_7_23
		double lhe_ele1_px, lhe_ele1_py,lhe_ele1_pz,lhe_ele1_e;
		double lhe_ele2_px, lhe_ele2_py,lhe_ele2_pz,lhe_ele2_e;
		double lhe_mu1_px, lhe_mu1_py,lhe_mu1_pz,lhe_mu1_e;
		double lhe_mu2_px, lhe_mu2_py,lhe_mu2_pz,lhe_mu2_e;
		double lhe_photon_px, lhe_photon_py,lhe_photon_pz,lhe_photon_e;
		double lhe_jet1_px, lhe_jet1_py,lhe_jet1_pz,lhe_jet1_e;
		double lhe_jet2_px, lhe_jet2_py,lhe_jet2_pz,lhe_jet2_e;
		// lhe for fiducial, 2018_7_23
        int  HLT_Ele1;
		int  HLT_Ele2;
		int  HLT_Ele3;
		int  HLT_Ele4;
		int  HLT_Ele5;
		int  HLT_Ele6;
		int  HLT_Ele7;
		int  HLT_Mu1;
		int  HLT_Mu2;
		int  HLT_Mu3;
		int  HLT_Mu4;
		int  HLT_Mu5;
		int  HLT_Mu6;
		int  HLT_Mu7;
		int  HLT_Mu8;
		int  HLT_Mu9;
        int  HLT_Mu10;
        int  HLT_Mu11;
		// filter
		bool passFilter_HBHE_                   ;
		bool passFilter_HBHEIso_                ;
		bool passFilter_globalTightHalo_ ;
		bool passFilter_ECALDeadCell_           ;
		bool passFilter_GoodVtx_                ;
		bool passFilter_EEBadSc_                ;
		bool passFilter_badMuon_                ;
		bool passFilter_badChargedHadron_       ;
		// Meng
		bool passFilter_MetbadMuon_		  ;
		bool passFilter_duplicateMuon_	  ;
// ----------member data in the tree ---------------------------

//Parameters to steer the treeDumper
      std::pair<double,double> lep1_etaphi_;
      std::pair<double,double> lep2_etaphi_;

      PropagateToMuon *muPropagator2nd_;

      std::vector<std::string> offsetCorrLabel_;
      FactorizedJetCorrector* jecOffset_;
      std::vector<std::string> jetCorrLabel_;

      edm::Handle< double >  rho_;
      edm::Handle< edm::TriggerResults>  noiseFilterBits_;

      std::string HBHENoiseFilter_Selector_;
      std::string HBHENoiseIsoFilter_Selector_;
      std::string ECALDeadCellNoiseFilter_Selector_;
      std::string GoodVtxNoiseFilter_Selector_;
      std::string EEBadScNoiseFilter_Selector_;
      std::string globalTightHaloFilter_Selector_;

      // Filter, Meng, bad muon, duplicate muon
      std::string badMuonFilter_Selector_;
      std::string duplicateMuonFilter_Selector_;

      EffectiveAreas effAreaChHadrons_;
      EffectiveAreas effAreaNeuHadrons_;
      EffectiveAreas effAreaPhotons_;

//Parameters to steer the treeDumper
      int originalNEvents_;
      double crossSectionPb_;
      double targetLumiInvPb_;
      std::string PKUChannel_;
      bool isGen_ , RunOnMC_;
      std::vector<std::string> jecAK4Labels_;
      std::vector<std::string> jecAK4chsLabels_;
      //correction jet
      FactorizedJetCorrector* jecAK4_;
      std::string gravitonSrc_;
      std::map<std::string,double>  TypeICorrMap_;
      edm::InputTag mets_;
      //High Level Trigger
      HLTConfigProvider hltConfig;
      std::vector<std::string> elPaths1_, elPaths2_, elPaths3_, elPaths4_, elPaths5_, elPaths6_, elPaths7_;
      std::vector<std::string> muPaths1_, muPaths2_, muPaths3_, muPaths4_, muPaths5_, muPaths6_, muPaths7_, muPaths8_, muPaths9_, muPaths10_, muPaths11_;
      std::vector<std::string> elPaths1, elPaths2, elPaths3, elPaths4, elPaths5, elPaths6, elPaths7;
      std::vector<std::string> muPaths1, muPaths2, muPaths3, muPaths4,muPaths5, muPaths6, muPaths7, muPaths8, muPaths9, muPaths10, muPaths11;
  }
#endif
