#ifndef EventAction_H
#define EventAction_H 1
//===================C++==================//
#include <fstream>
#include <sstream>
#include <map>
//=================GEANT4=================//
#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4DCofThisEvent.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"

#include "TFile.h"
#include "TTree.h"
#include "DataHit.hh"
using namespace std;
class EventAction : public G4UserEventAction
{
public:
	EventAction();
	~EventAction();
	void BeginOfEventAction(const G4Event *pEvent);
	void EndOfEventAction(const G4Event *pEvent);

private:
	G4double e0,e1;
	TFile *pFile;
	TTree *pTree;
};
#endif

    
