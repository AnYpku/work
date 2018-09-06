#include "SteppingAction.hh"

SteppingAction::SteppingAction(): G4UserSteppingAction()
{ 


}

SteppingAction::~SteppingAction()
{ 

}
void SteppingAction::UserSteppingAction(const G4Step* pStep) 
{
	G4Track* pTrack = pStep->GetTrack();
	G4String fParticleName=pTrack->GetDefinition()->GetParticleName();
	//for G4 time cut
	if(pTrack->GetGlobalTime()>1.e15*ns)
	{
		pTrack->SetTrackStatus(fKillTrackAndSecondaries);

	}
	//for decay time cut
	if(pTrack->GetGlobalTime()>360000*s)
	{
		pTrack->SetTrackStatus(fKillTrackAndSecondaries);

	}	


	if(fParticleName=="Be9")
	{
		pTrack->SetTrackStatus(fKillTrackAndSecondaries);
	}else if(fParticleName=="alpha")
	{
		pTrack->SetTrackStatus(fKillTrackAndSecondaries);
	}

/*
if(fParticleName=="Co51")
{
G4StepPoint *pPrePoint=pStep->GetPreStepPoint();		
G4StepPoint *pPostPoint=pStep->GetPostStepPoint();	
G4cout<<"fParticleName: "<<fParticleName<<"  precharge="<<pPrePoint->GetCharge()<<"  postcharge="<<pPostPoint->GetCharge()
<<"  Ek="<<pTrack->GetKineticEnergy()<<"  z1="<<pPrePoint->GetPosition().getZ()<<"  z2="<<pPostPoint->GetPosition().getZ()
<<"   ProName: "<<pPostPoint->GetProcessDefinedStep()->GetProcessName()<<G4endl;
}
*/

}



