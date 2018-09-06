#include "RunAction.hh"

RunAction::RunAction()
{
	pTimer = new G4Timer;
}

RunAction::~RunAction()
{
	delete pTimer;
	pTimer=NULL;
}

void RunAction::BeginOfRunAction(const G4Run* pRun)
{
	int fRunID=pRun->GetRunID();
	pTimer->Start();
	G4cout<<"======================	  RunID = "<<fRunID<<"  ======================"<<G4endl;
}

void RunAction::EndOfRunAction(const G4Run* pRun)
{
	pTimer->Stop();
	G4cout<<"number of event = "<<pRun->GetNumberOfEvent()<<G4endl;
	G4cout<<" time:  "<<*pTimer<<G4endl;
}

