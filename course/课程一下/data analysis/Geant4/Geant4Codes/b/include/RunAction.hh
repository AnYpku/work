#ifndef RunAction_H
#define RunAction_H 1
//==================Linux=================//
#include "unistd.h"
//===================C++==================//
#include <fstream>
//=================GEANT4=================//
#include "globals.hh"
#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4ios.hh"
#include "G4Timer.hh"
using namespace std;

class RunAction : public G4UserRunAction
{
public:
	RunAction();
	virtual ~RunAction();

public:
	void BeginOfRunAction(const G4Run* aRun);
	void EndOfRunAction(const G4Run* aRun);

private:
	G4Timer* pTimer;
};

#endif
