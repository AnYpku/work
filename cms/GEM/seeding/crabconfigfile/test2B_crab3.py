from WMCore.Configuration import Configuration

config = Configuration()

config.section_("General")
config.General.requestName   = 'fcsc-v3'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'QLB_cfg.py'
config.JobType.maxMemoryMB=4000


config.section_("Data")
config.Data.inputDataset = '/RelValZMM_14/CMSSW_9_0_0_pre4-PU25ns_90X_upgrade2023_realistic_v3_D4TPU200c2-v1/GEN-SIM-RECO'
#config.Data.inputDataset = '/RelValZMM_14/CMSSW_9_0_0_pre2-PU25ns_90X_upgrade2023_realistic_v1_2023D4TimingPU200-v1/GEN-SIM-RECO'
#config.Data.inputDBS = 'phys03'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = 40
config.Data.publication = True
config.Data.outputDatasetTag = 'fcsc-v3'

config.section_("Site")
# Where the output files will be transmitted to
config.Site.storageSite = 'T2_CH_CERN'
