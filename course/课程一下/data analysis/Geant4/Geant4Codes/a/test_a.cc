#include <ctime>// initialize random seed
#include <string>

#include "Randomize.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
using namespace std;
int main(int argc,char** argv)
{
	//================================Main Codes==================================//
	G4RunManager* runManager = new G4RunManager();
	//Detector
	DetectorConstruction* detector = new DetectorConstruction();
	runManager->SetUserInitialization(detector);
	//PhysicsList
	PhysicsList* physics= new PhysicsList(); 
	runManager->SetUserInitialization(physics);

	//Action
	PrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction;
	runManager->SetUserAction(gen_action);
	//============================Initialize G4 kernel============================// 	
	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();
	runManager->Initialize();
	
	//==========================Control the Verbose Level=========================//
	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	UImanager->ApplyCommand("/run/verbose 0");
	UImanager->ApplyCommand("/event/verbose 0");
	UImanager->ApplyCommand("/tracking/verbose 0");
	
	//===================================BeamOn==================================//
	if(argc==1)
	{
		runManager->BeamOn(1);
	}else if(argc!=1 && string(argv[1])=="vis")
	{
		G4UIExecutive *ui=new G4UIExecutive(argc,argv);
		UImanager->ApplyCommand("/control/execute vis.mac"); 	
		ui->SessionStart();
		delete ui;
		ui=NULL;
	}
	

	delete visManager;
	visManager=NULL;	
	delete runManager;
	runManager=NULL;
	
	return 0;
}
