#ifndef LbMclassTrack_HH
#define LbMclassTrack_HH 1

#include <TObjString.h>
#include <TObject.h>
#include <TPointsArray3D.h>

class LbMclassTrack: public TObject {
public:
  Double_t mass;
  Double_t E;
  Double_t px;
  Double_t py;
  Double_t pz;
  Double_t chi2; // Track Chi2
  Double_t q;
  TObjString *particleId;
  TPointsArray3D *track;
  Double_t pvx;
  Double_t pvy;
  Double_t pvz;
  Double_t ipchi2;
  Double_t ip;
  Double_t zFirstMeasurement;
	
  LbMclassTrack();
  void printTrack();
  static bool compare (LbMclassTrack i, LbMclassTrack j){return (i.particleId < j.particleId);}
  ClassDef(LbMclassTrack, 1)
};

#endif // LbMclassTrack_HH
