from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'step2-0501c'
config.General.workArea = 'crab_projects2'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step2_DIGI_L1_L1TrackTrigger_DIGI2RAW_HLT.py'

config.Data.inputDataset = '/MinBias/yian-CRAB3_step1-0501-b6ed8c0ae370524943b4b73c07c5bb50/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
#config.Data.splitting = 'Automatic'
config.Data.unitsPerJob = 1
config.Data.totalUnits = -1 
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'CRAB3_step2-0501c'

config.Site.storageSite = 'T2_CN_Beijing'
