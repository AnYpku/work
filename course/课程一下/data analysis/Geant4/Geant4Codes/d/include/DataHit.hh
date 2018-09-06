
#ifndef DataHit_h
#define DataHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DataHit : public G4VHit
{
public:

    DataHit();
    ~DataHit();
    const DataHit& operator=(const DataHit&);
    G4int operator==(const DataHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);
	inline  G4double GetEnergy() {return fDeltaE;}
	inline void SetEnergy(G4double dE) {fDeltaE=dE;}
	inline  G4double GetTime() {return fTime;}
	inline void SetTime(G4double t) {fTime=t;}

private:
	G4double fDeltaE;
	G4double fTime;

};

//////////////////////////////////////////////////

typedef G4THitsCollection<DataHit> DataHitsCollection;
extern G4Allocator<DataHit> DataHitAllocator;

inline void* DataHit::operator new(size_t)
{
  void *pHit;
  pHit = (void *) DataHitAllocator.MallocSingle();
  return pHit;
}

inline void DataHit::operator delete(void *pHit)
{
  DataHitAllocator.FreeSingle((DataHit*) pHit);
}

#endif
