#ifndef RecoMuon_StandAloneMuonProducer_STAMuonAnalyzer_H
#define RecoMuon_StandAloneMuonProducer_STAMuonAnalyzer_H

/** \class STAMuonAnalyzer
 *  Analyzer of the StandAlone muon tracks
 *
 *  \author R. Bellan - INFN Torino <riccardo.bellan@cern.ch>
 */

// Base Class Headers
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/Track/interface/SimTrack.h"

namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

class TFile;
class TH1F;
class TH2F;

class STAMuonAnalyzer: public edm::EDAnalyzer {
public:
  /// Constructor
  STAMuonAnalyzer(const edm::ParameterSet& pset);

  /// Destructor
  virtual ~STAMuonAnalyzer();

  // Operations

  void analyze(const edm::Event & event, const edm::EventSetup& eventSetup);

  virtual void beginJob() ;
  virtual void endJob() ;
protected:

private:
  //std::string theRootFileName;
  //TFile* theFile;

  edm::EDGetTokenT<edm::View<reco::Track>> staSrc_;
  edm::EDGetTokenT<edm::View<SimTrack>> simSrc_;
  //std::string theSTAMuonLabel;
  //std::string theSeedCollectionLabel;

  // Histograms
  TH1F *hPtRec;
  TH1F *hPtRec_new;
  TH1F *hPtRec_newB;

  TH1F *hChi2Rec;
  TH1F *hChi2Rec_new;
  TH1F *hChi2Rec_newB;

  TH1F *hPtSim; 
  TH1F *hPtSim_new;
  TH1F *hPtSim_newB;

  TH1F *hEtaSim;
  TH1F *hEtaSim_new;
  TH1F *hEtaSim_newB;

  TH1F *hphiSim;
  TH1F *hphiSim_new;
  TH1F *hphiSim_newB;
  TH1F *hphiSimA;
  TH1F *hphiSimA_new;
  TH1F *hphiSimA_newB;
  TH1F *hphiSimB;
  TH1F *hphiSimB_new;
  TH1F *hphiSimB_newB;
  TH1F *hphiSimC;
  TH1F *hphiSimC_new;
  TH1F *hphiSimC_newB;
  TH1F *hphiSimB2;
  TH1F *hphiSimB2_new;
  TH1F *hphiSimB2_newB;
  TH1F *hphiSimC2;
  TH1F *hphiSimC2_new;
  TH1F *hphiSimC2_newB;


  TH1F *hPres;
  TH1F *hPres_new;
  TH1F *hPres_newB;

  TH1F *h1_Pres;
  TH1F *hPTDiff;
  TH1F *hEtaDiff;
  TH1F *hPhiDiff;
  TH1F *hDrDiff;
  TH1F *hPTDiff2;
  TH2F *hPTDiffvsEta;
  TH2F *hPTDiffvsPhi;

  // Counters
  int numberOfSimTracks;
  int numberOfRecTracks;

  std::string theDataType;
  
};
#endif

