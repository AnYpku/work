from WMCore.Configuration import Configuration

config = Configuration()

config.section_("General")
config.General.requestName   = 'csc-0503a'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'QLB_cfg.py'
config.JobType.maxMemoryMB=2500


config.section_("Data")
config.Data.inputDataset = '/MinBias/yian-CRAB3_step3-0501c_MINIAODSIMoutput-27d184f439975153b0faf64e9b3245e2/USER'
#config.Data.inputDataset = '/RelValZMM_14/CMSSW_9_0_0_pre2-PU25ns_90X_upgrade2023_realistic_v1_2023D4TimingPU200-v1/GEN-SIM-RECO'
config.Data.inputDBS = 'phys03'
#config.Data.inputDBS = 'global'
#config.Data.splitting = 'FileBased'
config.Data.splitting = 'Automatic'
config.Data.unitsPerJob = 1
config.Data.totalUnits = -1
config.Data.publication = True
config.Data.outputDatasetTag = 'seed-csc-0503a'

config.section_("Site")
# Where the output files will be transmitted to
config.Site.storageSite = 'T2_CN_Beijing'
