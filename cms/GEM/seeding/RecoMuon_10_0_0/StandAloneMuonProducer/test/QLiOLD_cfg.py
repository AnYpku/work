import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras
process = cms.Process("STARECO")
process.load("RecoMuon.Configuration.RecoMuon_cff")
process.load("RecoMuon.Configuration.MessageLogger_cfi")
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.Geometry.GeometryExtended2023D17Reco_cff')
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load('Configuration.StandardSequences.EndOfProcess_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
      #'file:/tmp/seed-csc.root'
      'file:/afs/cern.ch/work/y/yian/cmssw1000_station1/hits_switch/seed-cscgem.root'
    )
)
#process.UpdaterService = cms.Service( "UpdaterService",
#)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.MessageLogger = cms.Service("MessageLogger",
    cout = cms.untracked.PSet(
        threshold = cms.untracked.string('INFO'),
        noLineBreaks = cms.untracked.bool(True)
    ),
    destinations = cms.untracked.vstring('cout')
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('Rec-cscgem.root')
)

process.load("RecoMuon.StandAloneMuonProducer.standAloneMuons_cff")
process.standAloneMuons.InputObjects = cms.InputTag("MSeed") 

process.p = cms.Path(process.standAloneMuons)
process.this_is_the_end = cms.EndPath(process.out)
