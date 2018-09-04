from WMCore.Configuration import Configuration

config = Configuration()

config.section_("General")
config.General.requestName   = '0504-cscgem'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = 'QLiOLD_cfg.py'


config.section_("Data")
config.Data.inputDataset = '/MinBias/yian-cscgem-0303-29d6111ebaf17f20d67b06eae82605f9/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.totalUnits = -1
config.Data.publication = True
config.Data.outputDatasetTag = '0504-cscgem'

config.section_("Site")
# Where the output files will be transmitted to
config.Site.storageSite = 'T2_CN_Beijing'
