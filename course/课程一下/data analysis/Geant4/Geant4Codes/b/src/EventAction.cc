#include "EventAction.hh"

EventAction::EventAction()
{
}
 
EventAction::~EventAction()
{
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
}

void EventAction::EndOfEventAction(const G4Event *pEvent)
{
}

