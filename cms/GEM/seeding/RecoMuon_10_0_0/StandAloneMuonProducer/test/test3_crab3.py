from WMCore.Configuration import Configuration

config = Configuration()

config.section_("General")
config.General.requestName   = 'csc-0504'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'QLiOLDB_cfg.py'


config.section_("Data")
config.Data.inputDataset = '/MinBias/yian-csc-v3-429bab36e3be7d426b2b9ed276f25af8/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = -1
config.Data.publication = True
config.Data.outputDatasetTag = 'csc-0504'

config.section_("Site")
# Where the output files will be transmitted to
config.Site.storageSite = 'T2_CN_Beijing'
