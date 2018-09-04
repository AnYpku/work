from WMCore.Configuration import Configuration

config = Configuration()

config.section_("General")
config.General.requestName   = 'cscgem-0504'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'QL_cfg.py'
config.JobType.maxMemoryMB=2500


config.section_("Data")
config.Data.inputDataset = '/MinBias/yian-CRAB3_step3-0501c_MINIAODSIMoutput-27d184f439975153b0faf64e9b3245e2/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = 10
config.Data.publication = True
config.Data.outputDatasetTag = '0504-cscgem'

config.section_("Site")
# Where the output files will be transmitted to
config.Site.storageSite = 'T2_CN_Beijing'
