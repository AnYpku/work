#include "SD_NaI.hh"

SD_NaI::SD_NaI(G4String thisname):G4VSensitiveDetector(thisname)
{	
	G4cout<<"creating SD_NaI: "<<fName<<"..."<<G4endl;
	fName=thisname;

//	collectionName.insert(fName);
	fDeltaE=0.;
	pFile=new TFile("result.root","recreate");
	pTree=new TTree("tree","tree");
	pTree->Branch("de",&fDeltaE,"de/D");
}

SD_NaI::~SD_NaI()
{
	pTree->Write();
	pFile->Close();
	G4cout<<"deleting SD_NaI: "<<fName<<"..."<<G4endl;
}

void SD_NaI::Initialize(G4HCofThisEvent* pHCE)
{
	fDeltaE=0.;
}

G4bool SD_NaI::ProcessHits(G4Step* pStep,G4TouchableHistory* )
{
	//energy
	fDeltaE += pStep->GetTotalEnergyDeposit();
	//globaltime	
//	fGlobaltime=pPostStepPoint->GetGlobalTime();
	return true;
}

void SD_NaI::EndOfEvent(G4HCofThisEvent* )
{
	fDeltaE=CLHEP::RandGauss::shoot(fDeltaE,fDeltaE*0.01);
	pTree->Fill();	
}
