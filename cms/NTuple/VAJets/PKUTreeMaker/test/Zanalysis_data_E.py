import FWCore.ParameterSet.Config as cms

process = cms.Process( "TEST" )
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True),
				     SkipEvent = cms.untracked.vstring('ProductNotFound'))
corrJetsOnTheFly = True
runOnMC = False
chsorpuppi = True  # AK4Chs or AK4Puppi
#****************************************************************************************************#
process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_condDBv2_cff')
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("RecoTracker.CkfPattern.CkfTrackCandidates_cff")
process.load("TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorAlong_cfi")
from Configuration.AlCa.GlobalTag import GlobalTag
if runOnMC:
   process.GlobalTag.globaltag = '94X_mc2017_realistic_v17'
elif not(runOnMC):
   process.GlobalTag.globaltag = '94X_dataRun2_v11'

##########					                                                             
hltFiltersProcessName = 'RECO'
if runOnMC:
   hltFiltersProcessName = 'PAT' #'RECO'
reducedConversionsName = 'PAT'#'PAT'ele#'RECO'muon
if runOnMC:
   reducedConversionsName= 'PAT' #'RECO'

process.load("VAJets.PKUCommon.goodMuons_cff")
process.load("VAJets.PKUCommon.goodElectrons_cff")
process.load("VAJets.PKUCommon.goodJets_cff")
process.load("VAJets.PKUCommon.goodPhotons_cff")
process.load("VAJets.PKUCommon.leptonicZ_cff")

#for egamma smearing

process.load("RecoEgamma/ElectronIdentification/ElectronIDValueMapProducer_cfi")
process.load("RecoEgamma/ElectronIdentification/egmGsfElectronIDs_cff")
process.load('RecoEgamma/EgammaTools/calibratedEgammas_cff')
process.load('Configuration.StandardSequences.Services_cff')
process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
   calibratedPatElectrons  = cms.PSet( initialSeed = cms.untracked.uint32(81),
      engineName = cms.untracked.string('TRandom3'),
   ),
   calibratedPatPhotons  = cms.PSet( initialSeed = cms.untracked.uint32(81),
      engineName = cms.untracked.string('TRandom3'),
   ),
)
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process,
                       applyEnergyCorrections= True,#True: calibratedPat*; False: slimmed*
                       applyVIDOnCorrectedEgamma=True,#EnergyCorrections and VIDOnCorrectedEgamma should be same
                       isMiniAOD=True,
                       era="2017-Nov17ReReco",
                       eleIDModules=['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Fall17_94X_V2_cff'],
                       phoIDModules=['RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Fall17_94X_V2_cff'],
                       runVID=False,
                       runEnergyCorrections=True,#True: do egamma_modification
                       applyEPCombBug=False,
                       autoAdjustParams=True)
#process.calibratedPatElectrons.src = cms.InputTag("calibratedPatElectrons")
#process.calibratedPatElectrons.useSmearCorrEcalEnergyErrInComb = cms.bool(runOnMC)
#process.calibratedPatPhotons.src = cms.InputTag('calibratedPatPhotons')

#for egamma smearing

# If Update
process.goodMuons.src = "slimmedMuons"
#process.goodElectrons.src = "slimmedElectrons"
#process.goodPhotons.src = "slimmedPhotons"
process.goodElectrons.src = "calibratedPatElectrons"
process.goodPhotons.src = "calibratedPatPhotons"

process.load("VAJets.PKUCommon.goodJets_cff") 
if chsorpuppi:
      process.goodAK4Jets.src = "slimmedJets"
else:
      process.goodAK4Jets.src = "slimmedJetsPuppi"

#process.goodOfflinePrimaryVertex = cms.EDFilter("VertexSelector",
#                                       src = cms.InputTag("offlineSlimmedPrimaryVertices"),
#                                       cut = cms.string("chi2!=0 && ndof >= 4.0 && abs(z) <= 24.0 && abs(position.Rho) <= 2.0"),
#                                       filter = cms.bool(False)
#                                       )

ZBOSONCUT = "pt > 0.0"

process.leptonicVSelector = cms.EDFilter("CandViewSelector",
                                       src = cms.InputTag("leptonicV"),
                                       cut = cms.string( ZBOSONCUT ), 
                                       filter = cms.bool(False)
                                       )

process.leptonicVFilter = cms.EDFilter("CandViewCountFilter",
                                       src = cms.InputTag("leptonicV"),
                                       minNumber = cms.uint32(0),
                                       filter = cms.bool(False)
                                       )


process.leptonSequence = cms.Sequence(process.muSequence +
				      #process.regressionApplication* process.calibratedPatElectrons* process.calibratedPatPhotons +
                                      process.egammaPostRecoSeq*process.calibratedPatElectrons* process.calibratedPatPhotons+
                                      process.eleSequence +
                                      process.leptonicVSequence +
                                      process.leptonicVSelector +
                                      process.leptonicVFilter )

process.jetSequence = cms.Sequence(process.NJetsSequence)

process.load('RecoMET.METFilters.BadPFMuonFilter_cfi')
process.load("RecoMET.METFilters.BadChargedCandidateFilter_cfi")
process.BadPFMuonFilter.muons = cms.InputTag("slimmedMuons")
process.BadPFMuonFilter.PFCandidates = cms.InputTag("packedPFCandidates")
process.BadChargedCandidateFilter.muons = cms.InputTag("slimmedMuons")
process.BadChargedCandidateFilter.PFCandidates = cms.InputTag("packedPFCandidates")
process.metfilterSequence = cms.Sequence(process.BadPFMuonFilter+process.BadChargedCandidateFilter)

#begin------------JEC on the fly--------
if runOnMC:
   jecLevelsAK4chs = [
          'Fall17_17Nov2017_V32_MC_L1FastJet_AK4PFchs.txt',
          'Fall17_17Nov2017_V32_MC_L2Relative_AK4PFchs.txt',
          'Fall17_17Nov2017_V32_MC_L3Absolute_AK4PFchs.txt'
    ]
   jecLevelsAK4puppi = [
          'Fall17_17Nov2017_V32_MC_L1FastJet_AK4PFPuppi.txt',
          'Fall17_17Nov2017_V32_MC_L2Relative_AK4PFPuppi.txt',
          'Fall17_17Nov2017_V32_MC_L3Absolute_AK4PFPuppi.txt'
    ]
else:
   jecLevelsAK4chs = [
          'Fall17_17Nov2017DE_V32_DATA_L1FastJet_AK4PFchs.txt',
          'Fall17_17Nov2017DE_V32_DATA_L2Relative_AK4PFchs.txt',
          'Fall17_17Nov2017DE_V32_DATA_L3Absolute_AK4PFchs.txt',
	  'Fall17_17Nov2017DE_V32_DATA_L2L3Residual_AK4PFchs.txt'
    ]
   jecLevelsAK4puppi = [
          'Fall17_17Nov2017DE_V32_DATA_L1FastJet_AK4PFPuppi.txt',
          'Fall17_17Nov2017DE_V32_DATA_L2Relative_AK4PFPuppi.txt',
          'Fall17_17Nov2017DE_V32_DATA_L3Absolute_AK4PFPuppi.txt',
	  'Fall17_17Nov2017DE_V32_DATA_L2L3Residual_AK4PFPuppi.txt'
    ]
#end------------JEC on the fly--------

if chsorpuppi:
      ak4jecsrc = jecLevelsAK4chs
else:
      ak4jecsrc = jecLevelsAK4puppi

process.load("RecoEgamma/PhotonIdentification/photonIDValueMapProducer_cff")
   
process.treeDumper = cms.EDAnalyzer("ZPKUTreeMaker",
                                    originalNEvents = cms.int32(1),
                                    crossSectionPb = cms.double(1),
                                    targetLumiInvPb = cms.double(1.0),
                                    PKUChannel = cms.string("VW_CHANNEL"),
                                    isGen = cms.bool(False),
				    RunOnMC = cms.bool(runOnMC), 
                                    generator =  cms.InputTag("generator"),
				    lhe =  cms.InputTag("externalLHEProducer"),
				    genJet =  cms.InputTag("slimmedGenJets"),
                                    pileup  =   cms.InputTag("slimmedAddPileupInfo"),
                                    leptonicVSrc = cms.InputTag("leptonicV"),
                                    rho = cms.InputTag("fixedGridRhoFastjetAll"),   
                                    ak4jetsSrc = cms.InputTag("cleanAK4Jets"),      
#                                    photonSrc = cms.InputTag("goodPhotons"),
#                                    photonSrc = cms.InputTag("slimmedPhotons"),
				    photonSrc = cms.InputTag("calibratedPatPhotons"),
                                    genSrc =  cms.InputTag("prunedGenParticles"),       
                                    jecAK4chsPayloadNames = cms.vstring( jecLevelsAK4chs ),
                                    jecAK4PayloadNames = cms.vstring( ak4jecsrc ),
                                    metSrc = cms.InputTag("slimmedMETs"),
                                    vertex = cms.InputTag("offlineSlimmedPrimaryVertices"),  
                                    t1jetSrc = cms.InputTag("slimmedJets"),      
                                    t1muSrc = cms.InputTag("slimmedMuons"),       
                                    looseelectronSrc = cms.InputTag("vetoElectrons"),
#                                    electrons = cms.InputTag("slimmedElectrons"),
				    electrons = cms.InputTag("calibratedPatElectrons"),
                                    conversions = cms.InputTag("reducedEgamma","reducedConversions",reducedConversionsName),
                                    beamSpot = cms.InputTag("offlineBeamSpot","","RECO"),
                                    loosemuonSrc = cms.InputTag("looseMuons"),
				    goodmuonSrc = cms.InputTag("goodMuons"),# station2 retrieve, 2017/3/26
				    goodeleSrc = cms.InputTag("goodElectrons"),# retreive electron sigma_ieie for shape correction
                                    hltToken    = cms.InputTag("TriggerResults","","HLT"),
				    #elPaths1     = cms.vstring("HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf_v*"),
                                    #elPaths2     = cms.vstring("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v*"),
				    #elPaths3     = cms.vstring("HLT_Ele25_eta2p1_WPTight_Gsf_v*"),
                                    #elPaths4     = cms.vstring("HLT_Ele27_eta2p1_WPLoose_Gsf_v*"),
                                    #elPaths5     = cms.vstring("HLT_Ele27_WPTight_Gsf_v*"),
                                    #elPaths6     = cms.vstring("HLT_Ele30_WPTight_Gsf_v*"),
                                    #elPaths7     = cms.vstring("HLT_Ele35_WPLoose_Gsf_v*"),
                                    #muPaths1    = cms.vstring("HLT_Mu17_TrkIsoVVL_v*"),
                                    #muPaths2     = cms.vstring("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v*", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v*"),
                                    #muPaths3    = cms.vstring("HLT_IsoMu24_v*"),
                                    #muPaths4    = cms.vstring("HLT_Mu17_v*"),
				    #muPaths5     = cms.vstring("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v*", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v*"),
				    #muPaths6     = cms.vstring("HLT_IsoMu22_v*", "HLT_IsoTkMu22_v*"),
				    #muPaths7     = cms.vstring("HLT_IsoMu24_v*", "HLT_IsoTkMu24_v*"),
				    #muPaths8     = cms.vstring("HLT_IsoMu27_v*", "HLT_IsoTkMu27_v*"),
				    #muPaths9     = cms.vstring("HLT_IsoMu20_v*", "HLT_IsoTkMu20_v*"),
                                    #muPaths10     = cms.vstring("HLT_Mu45_eta2p1_v*"),
                                    #muPaths11     = cms.vstring("HLT_Mu50_v*"),
                                    elPaths1     = cms.vstring("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v*"),#B-F
                                    elPaths2     = cms.vstring("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v*"),#B-F
                                    elPaths3     = cms.vstring("HLT_Ele35_WPTight_Gsf_v*"),#B-F
                                    elPaths4     = cms.vstring("HLT_Ele38_WPTight_Gsf_v*"),#add by Ying
                                    elPaths5     = cms.vstring("HLT_Ele40_WPTight_Gsf_v*"),#add by Ying

                                    muPaths1     = cms.vstring("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v*"),#B
				    muPaths2    = cms.vstring("HLT_IsoMu24_eta2p1_v*"),#B-D
                                    muPaths3     = cms.vstring("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_3p8_v*"),#C-F
                                    muPaths4     = cms.vstring("HLT_IsoMu27_v*"),#B-F
                                    muPaths5     = cms.vstring("HLT_IsoMu20_v*"),# add by Ying
                                    muPaths6     = cms.vstring("HLT_IsoMu24_v*"),# add by Ying

				    noiseFilter = cms.InputTag('TriggerResults','', hltFiltersProcessName),
				    noiseFilterSelection_HBHENoiseFilter = cms.string('Flag_HBHENoiseFilter'),
                                    noiseFilterSelection_HBHENoiseIsoFilter = cms.string("Flag_HBHENoiseIsoFilter"),
                                    noiseFilterSelection_globalTightHaloFilter = cms.string('Flag_globalTightHalo2016Filter'),
                                    noiseFilterSelection_EcalDeadCellTriggerPrimitiveFilter = cms.string('Flag_EcalDeadCellTriggerPrimitiveFilter'),
				    noiseFilterSelection_goodVertices = cms.string('Flag_goodVertices'),
				    noiseFilterSelection_eeBadScFilter = cms.string('Flag_eeBadScFilter'),
                                    noiseFilterSelection_badMuon = cms.InputTag('BadPFMuonFilter'),
                                    noiseFilterSelection_badChargedHadron = cms.InputTag('BadChargedCandidateFilter'),
			 #Meng
                                    badMuonFilterSelection = cms.string('Flag_badMuons'),
                                    duplicateMuonFilterSelection = cms.string('Flag_duplicateMuons'),
                	 #Lu
                                    full5x5SigmaIEtaIEtaMap   = cms.InputTag("photonIDValueMapProducer:phoFull5x5SigmaIEtaIEta"),
                                    phoChargedIsolation = cms.InputTag("photonIDValueMapProducer:phoChargedIsolation"),
                                    phoNeutralHadronIsolation = cms.InputTag("photonIDValueMapProducer:phoNeutralHadronIsolation"),
                                    phoPhotonIsolation = cms.InputTag("photonIDValueMapProducer:phoPhotonIsolation"),
                                    effAreaChHadFile = cms.FileInPath("RecoEgamma/PhotonIdentification/data/Fall17/effAreaPhotons_cone03_pfChargedHadrons_90percentBased_V2.txt"),
                                    effAreaNeuHadFile= cms.FileInPath("RecoEgamma/PhotonIdentification/data/Fall17/effAreaPhotons_cone03_pfNeutralHadrons_90percentBased.txt"),
                                    effAreaPhoFile   = cms.FileInPath("RecoEgamma/PhotonIdentification/data/Fall17/effAreaPhotons_cone03_pfPhotons_90percentBased.txt")
                                    )


process.analysis = cms.Path(
#                            process.goodOfflinePrimaryVertex +
                            process.leptonSequence +
                            process.jetSequence +
                            process.metfilterSequence +
#                           process.photonSequence +
                            process.photonIDValueMapProducer*process.treeDumper)

### Source
process.load("VAJets.PKUCommon.data.RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8")
process.source.fileNames = [
"/store/data/Run2016E/DoubleEG/MINIAOD/03Feb2017-v1/110000/1EB618DF-92EA-E611-989E-0CC47A13D3B2.root"
]
                       
process.maxEvents.input = 500

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 200
process.MessageLogger.cerr.FwkReport.limit = 99999999

process.TFileService = cms.Service("TFileService",
                                    fileName = cms.string("ZtreePKU.root")
                                   )