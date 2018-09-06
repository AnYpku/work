
#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction()
{

	//World
	fSizeWorld[0]=300*cm;
	fSizeWorld[1]=300*cm;
	fSizeWorld[2]=300*cm;
}

DetectorConstruction::~DetectorConstruction()
{

}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	G4NistManager* man = G4NistManager::Instance();
	//Vacuum
	G4Element *N = man->FindOrBuildElement("N");
	G4Element *O = man->FindOrBuildElement("O");
	G4Material *pVacuum = new G4Material("Vacuum",1.29e-10*mg/cm3,2,kStateGas);
	pVacuum->AddElement(N, 70.*perCent);
	pVacuum->AddElement(O, 30.*perCent);
	//NaI
	G4Element *Na = man->FindOrBuildElement("Na");
	G4Element *I = man->FindOrBuildElement("I");
	G4Element *Tl = man->FindOrBuildElement("Tl");
	G4Material *NaI = new G4Material("NaI", 3.67*g/cm3, 3, kStateSolid);
	NaI->AddElement(Na, 15.29*perCent);
	NaI->AddElement(I, 84.41*perCent);
	NaI->AddElement(Tl, 0.3*perCent);
	
	//world 
  	G4Box* pSolidWorld= new G4Box("solidWorld",0.5*fSizeWorld[0],0.5*fSizeWorld[1],0.5*fSizeWorld[2]);
  	G4LogicalVolume* pLogicWorld= new G4LogicalVolume(pSolidWorld,pVacuum, "logicWorld",0,0,0);
  	G4VPhysicalVolume* pPhysiWorld= new G4PVPlacement(0,G4ThreeVector(0,0,0),pLogicWorld,"physiWorld",0,false,0);
	//Detector
	G4SDManager* SDman = G4SDManager::GetSDMpointer();
	//NaI_0
	G4Box* solidNaI_0 = new G4Box("sNaI_0",5.*cm, 5.*cm, 5.*cm);
	G4LogicalVolume* logicNaI_0 = new G4LogicalVolume(solidNaI_0,NaI,"lNaI_0",0,0,0);
	G4VPhysicalVolume* physiNaI_0 = new G4PVPlacement(0,G4ThreeVector(-10*cm,0,20*cm),logicNaI_0,"pNaI_0",pLogicWorld,false,0);
	SD_NaI *SDNaI_0= new SD_NaI("SDNaI_0");	
	logicNaI_0->SetSensitiveDetector( SDNaI_0 );
	SDman->AddNewDetector( SDNaI_0 );
	//NaI_1
	G4Box* solidNaI_1 = new G4Box("sNaI_1",5.*cm, 5.*cm, 5.*cm);
	G4LogicalVolume* logicNaI_1 = new G4LogicalVolume(solidNaI_1,NaI,"lNaI_1",0,0,0);
	G4VPhysicalVolume* physiNaI_1 = new G4PVPlacement(0,G4ThreeVector(10*cm,0,20*cm),logicNaI_1,"pNaI_1",pLogicWorld,false,0);
	SD_NaI *SDNaI_1= new SD_NaI("SDNaI_1");	
	logicNaI_1->SetSensitiveDetector( SDNaI_1 );
	SDman->AddNewDetector( SDNaI_1 );
	
	return pPhysiWorld;
}




















