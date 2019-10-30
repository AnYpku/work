from WMCore.Configuration import Configuration

config = Configuration()

config.section_("General")
config.General.requestName   = 'DY_100-200_mg242_v2'
#config.General.saveLogs = True
config.General.transferLogs = True

#config.JobType.numCores = 8
config.section_("JobType")
config.JobType.numCores = 4
config.JobType.pluginName  = 'PrivateMC'
#config.JobType.generator = 'lhe'
#config.JobType.inputFiles = ['/cvmfs/cms.cern.ch/phys_generator/gridpacks/slc6_amd64_gcc481/13TeV/madgraph/V5_2.4.2/DYJets_Test_pdfwgt/DYJets_HT-incl_nopdfwgt_slc6_amd64_gcc630_CMSSW_9_3_8_tarball.tar.xz']
# Name of the CMSSW configuration file
config.JobType.psetName    = 'DY-100-200_v1_mg242.py'


config.section_("Data")
# This string determines the primary dataset of the newly-produced outputs.
# For instance, this dataset will be named /CrabTestSingleMu/something/USER
#config.Data.inputDataset = '/WH1000-LH'
config.Data.outputPrimaryDataset = 'DY-HT_Binned'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 5000
config.Data.totalUnits = 625000
config.Data.publication = False

# This string is used to construct the output dataset name
config.Data.outputDatasetTag = 'DY_100-200_mg242_v2'

config.section_("Site")
# Where the output files will be transmitted to
config.Site.storageSite = 'T2_CH_CERNBOX'
#config.Site.storageSite = 'T2_CN_Beijing'
#config.Site.whitelist = ['T2_CH_CERN']
