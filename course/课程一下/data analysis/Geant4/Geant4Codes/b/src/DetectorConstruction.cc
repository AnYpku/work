
#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction()
{

	//World
	fSizeWorld[0]=30*cm;
	fSizeWorld[1]=30*cm;
	fSizeWorld[2]=30*cm;
}

DetectorConstruction::~DetectorConstruction()
{

}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	//构造材料，方法一
	//Vacuum
	G4Material *pVacuum = new G4Material("Vacuum",1.29e-10*mg/cm3,2,kStateGas,0.1*kelvin,1e-19*pascal);//kStateSolid,kStateLiquid
		//定义元素，方法一
		//G4Element* H = new G4Element("Hydrogen","H" , 1., 1.*g/mole);
		//定义元素，方法二
		G4NistManager* man = G4NistManager::Instance();
		G4Element *N = man->FindOrBuildElement("N");
		G4Element *O = man->FindOrBuildElement("O");
	//填充材料，方法一
	pVacuum->AddElement(N, 70.*perCent);
	pVacuum->AddElement(O, 30.*perCent);
	//填充材料，方法二
	//pVacuum->AddElement(N, 7);
	//pVacuum->AddElement(O, 3);

	//构造材料，方法二
	//Air = man->FindOrBuildMaterial("G4_AIR");
	G4Material *pSi = man->FindOrBuildMaterial("G4_Si");
	
	//world 
  	pSolidWorld= new G4Box("solidWorld",0.5*fSizeWorld[0],0.5*fSizeWorld[1],0.5*fSizeWorld[2]);
  	pLogicWorld= new G4LogicalVolume(pSolidWorld,pVacuum, "logicWorld",0,0,0);
  	pPhysiWorld= new G4PVPlacement(0,G4ThreeVector(0,0,0),pLogicWorld,"physiWorld",0,false,0);


	G4RotationMatrix *ro=new G4RotationMatrix();
	ro->rotateY(45*deg);	//迎着转动轴方向，顺时针为正,与3D相反
	G4ThreeVector tr(0.,0.,0.);
	G4Box *pSolidBox= new G4Box("solidDSSD",0.5*80.*mm,0.5*80.*mm,0.5*300.*um);
	G4LogicalVolume *pLogicpBox= new G4LogicalVolume(pSolidBox,pSi, "logicDSSD",0,0,0);
	G4PVPlacement *pPhysiBox= new G4PVPlacement(ro,tr,pLogicpBox,"physiDSSD",pLogicWorld,false,0,true);
//	G4PVPlacement *pPhysiBox2= new G4PVPlacement(G4Transform3D(*ro,tr),pLogicpBox,"physiBox",pLogicWorld,false,1,true);
	
	return pPhysiWorld;
}




















