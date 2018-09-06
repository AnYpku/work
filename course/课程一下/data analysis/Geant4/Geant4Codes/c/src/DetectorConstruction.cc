
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
	//NaI
	G4Tubs* solidNaI = new G4Tubs("sNaI",0.*cm, 5.*cm, 10.*cm, 0.*deg, 360.*deg);
	G4LogicalVolume* logicNaI = new G4LogicalVolume(solidNaI,NaI,"lNaI",0,0,0);
	G4VPhysicalVolume* physiNaI = new G4PVPlacement(0,G4ThreeVector(0,0,15*cm),logicNaI,"pNaI",pLogicWorld,false,0); 
	
	//Sensitive Detector 	
	SD_NaI *NaISD= new SD_NaI("NaISD");	
	logicNaI->SetSensitiveDetector( NaISD );
	G4SDManager* SDman = G4SDManager::GetSDMpointer();
	SDman->AddNewDetector( NaISD );
	
	return pPhysiWorld;
}




















