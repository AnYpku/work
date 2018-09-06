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

	G4double phi=CLHEP::RandFlat::shoot(0.,2.*3.14159);
	G4double costheta=CLHEP::RandFlat::shoot(-1.,1.);
	G4double sintheta=sqrt(1.0-costheta*costheta);
	G4double dir_x=sintheta*cos(phi);
	G4double dir_y=sintheta*sin(phi);
	G4double dir_z=costheta;

	particleGun->SetParticleMomentumDirection(G4ThreeVector(dir_x,dir_y,dir_z));    	
	particleGun->GeneratePrimaryVertex(anEvent);
}





