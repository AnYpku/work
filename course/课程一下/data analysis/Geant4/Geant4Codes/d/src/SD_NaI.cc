#include "SD_NaI.hh"

SD_NaI::SD_NaI(G4String thisname):G4VSensitiveDetector(thisname)
{	
	G4cout<<"creating SD_NaI: "<<fName<<"..."<<G4endl;
	fName=thisname;

	collectionName.insert(fName);
}

SD_NaI::~SD_NaI()
{ 
	G4cout<<"deleting SD_NaI: "<<fName<<"..."<<G4endl;
}

void SD_NaI::Initialize(G4HCofThisEvent* pHCE)
{
	fDeltaE=0.;
	fHCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); 
	pHitsCollection= new DataHitsCollection(SensitiveDetectorName,collectionName[0]); 
	pHCE->AddHitsCollection(fHCID ,pHitsCollection);
	
}

G4bool SD_NaI::ProcessHits(G4Step* pStep,G4TouchableHistory* )
{
	//energy
	fDeltaE+=pStep->GetTotalEnergyDeposit();
	//globaltime	
//	fGlobaltime=pPostStepPoint->GetGlobalTime();
	
	return true;
}

void SD_NaI::EndOfEvent(G4HCofThisEvent* )
{
	DataHit *pHit=new DataHit();
	if(fDeltaE>0.1)
	{
		fDeltaE=CLHEP::RandGauss::shoot(fDeltaE,fDeltaE*0.01);
	}
	pHit->SetEnergy(fDeltaE);
	pHitsCollection->insert(pHit);
}
