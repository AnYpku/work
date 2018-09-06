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
	G4ParticleTable* particleTable=G4ParticleTable::GetParticleTable();
	G4ParticleDefinition* particle=particleTable->FindParticle("alpha");  
	particleGun->SetParticleDefinition(particle);
	particleGun->SetParticleCharge(0.);
	particleGun->SetParticleEnergy(5.42*MeV);
	particleGun->SetParticleTime(0.);
	particleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));
	particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));    	
	particleGun->GeneratePrimaryVertex(anEvent);
}





