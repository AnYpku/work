#include "Particle.h"
#include <TPointsArray3D.h>
#include <TObjArray.h>
#include <TTree.h>
#include <TObjString.h>
#include <iostream>
#include <TFile.h>

int main(int argc, char *argv[]) {

  TFile *f = TFile::Open("mydata.root", "RECREATE");

  Particle *track1 = 0;
  track1 = new Particle();
  track1->particleId = new TObjString("D0 ");
  track1->px = 1;
  track1->py = 2;
  track1->pz = 3;
  track1->mass = 42;

  TPointsArray3D *points = new TPointsArray3D();
  points->SetPoint(0, 1, 2, 3);
  points->SetPoint(1, 2, 3, 4);
  points->SetPoint(2, 0, 1, 0);
  track1->track = points;

  track1->printTrack();
  //std::cout << track1->particleId->GetString() << std::endl;

  //track1->Write("Toto");

  TObjArray *array = new TObjArray();
  array->Add(track1);

  //std::cout << track1->px << std::endl;
  TTree *tree = new TTree("MCEvent", "Masterclass Event list");

  tree->Branch("event", &array);
  tree->SetBranchAddress("event", &array);
  tree->Fill();


  tree->Write();
  f->Close();
  return 0;

}

