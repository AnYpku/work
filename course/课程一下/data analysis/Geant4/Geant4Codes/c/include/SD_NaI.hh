
#ifndef SD_NaI_hh
#define SD_NaI_hh 1

#include <stdio.h>
#include <cmath>
#include "globals.hh"

#include "G4EventManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4SystemOfUnits.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4Track.hh"
#include "G4TransportationManager.hh"
#include "G4Navigator.hh"
#include "Randomize.hh"

#include "TFile.h" 
#include "TTree.h" 
class SD_NaI : public G4VSensitiveDetector
{
public:
	SD_NaI(G4String thisname);
	~SD_NaI();
	
	void Initialize(G4HCofThisEvent*);
	G4bool ProcessHits(G4Step*, G4TouchableHistory*);
	void EndOfEvent(G4HCofThisEvent*);
	
private:
	G4String fName;

	G4double fDeltaE;
	G4double fGlobaltime;

	TFile *pFile;
	TTree *pTree;
};

#endif

