from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'step1-0501c'
config.General.workArea = 'crab_projects1'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'TenMuE_0_200_pythia8_cfi_GEN_SIM.py'

config.Data.outputPrimaryDataset = 'MinBias'
config.Data.splitting = 'EventBased'
#config.Data.splitting = 'Automatic'
config.Data.unitsPerJob = 30
config.Data.totalUnits = 1000  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'CRAB3_step1-0501'

config.Site.storageSite = 'T2_CN_Beijing'
