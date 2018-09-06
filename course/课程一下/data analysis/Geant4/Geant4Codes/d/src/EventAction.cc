#include "EventAction.hh"

EventAction::EventAction()
{
	pFile=new TFile("result.root","recreate");
	pTree=new TTree("tree","tree");
	pTree->Branch("e0",&e0,"e0/D");
	pTree->Branch("e1",&e1,"e1/D");
}
 
EventAction::~EventAction()
{
	pTree->Write();
	pFile->Close();
}
 
void EventAction::BeginOfEventAction(const G4Event *pEvent)
{	
	int fTotalEventNumber=G4RunManager::GetRunManager()->GetNumberOfEventsToBeProcessed();
	int fPercentEvent=fTotalEventNumber/10;
	if(fTotalEventNumber<100000)
	{
		if(pEvent->GetEventID()%10000==0)
		{
			G4cout<<"eventid:  "<<pEvent->GetEventID()<<"  "<<fTotalEventNumber<<G4endl;
		}
	}else
	{
		if((pEvent->GetEventID()+1)%fPercentEvent==0)
		{
			G4cout<<"progress:  "<<10*(pEvent->GetEventID()+1)/fPercentEvent<<"%"<<G4endl;
		}
	}
	e0=0.,e1=0.;
}

void EventAction::EndOfEventAction(const G4Event *pEvent)
{
/*
	size_t NumofHC=pEvent->GetHCofThisEvent()->GetNumberOfCollections();
	size_t NumofHits=pHC->entries();
*/
	
	DataHitsCollection *pHC_0=(DataHitsCollection*)pEvent->GetHCofThisEvent()->GetHC(0);
	DataHitsCollection *pHC_1=(DataHitsCollection*)pEvent->GetHCofThisEvent()->GetHC(1);
	e0=(*pHC_0)[0]->GetEnergy();
	e1=(*pHC_1)[0]->GetEnergy();

	if(e0>0.001 || e1>0.001)
	{
		pTree->Fill();
	}
}

