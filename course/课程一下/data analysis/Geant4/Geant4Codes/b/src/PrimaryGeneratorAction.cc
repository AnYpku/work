#include "PrimaryGeneratorAction.hh"


PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	//particle number
	G4int n_particle = 1;
	particleGun = new G4ParticleGun(n_particle);

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	//方法一
	G4ParticleTable* particleTable=G4ParticleTable::GetParticleTable();
	G4ParticleDefinition* particle=particleTable->FindParticle("alpha");  //"e-","e+","gamma","neutron","proton"
	//方法二
	//G4IonTable *particleTable=G4IonTable::GetIonTable();
	//particle=particleTable->GetIon(2,4,0.0); //alpha
	//方法三
	//particleGun->SetParticleDefinition(G4Alpha::AlphaDefinition())
	particleGun->SetParticleDefinition(particle);
	particleGun->SetParticleCharge(0.);		//EM 物理过程自动修正
	particleGun->SetParticleEnergy(5.42*MeV);
	particleGun->SetParticleTime(0.);
	particleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));
	particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));  
	//particleGun->SetParticleMomentum(G4ParticleMomentum);
	//particleGun->SetParticlePolarization(G4ThreeVector);
	particleGun->GeneratePrimaryVertex(anEvent);
}





