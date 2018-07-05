from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'step3-0502c'
config.General.workArea = 'crab_projects3'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step3_RAW2DIGI_L1Reco_RECO_RECOSIM_PAT_VALIDATION_DQM.py'

config.Data.inputDataset ='/MinBias/yian-CRAB3_step2-0501c-efa80e825f2b68de4169b4b26eb06fbd/USER' 
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1 
config.Data.totalUnits = -1
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'CRAB3_step3-0501c'

config.Site.storageSite = 'T2_CN_Beijing'
