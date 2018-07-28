
#include "LbMclassTrack.h"
#include <iostream>

ClassImp(LbMclassTrack);

LbMclassTrack::LbMclassTrack(): TObject(),
	mass(0), E(0), px(0), py(0), pz(0), chi2(0), q(0), particleId(0), track(0),
  pvx(-9999), pvy(-9999), pvz(-9999), ipchi2(-9999), ip(-9999), zFirstMeasurement(-9999) {
  }

void LbMclassTrack::printTrack() {
    if (particleId != 0) {
    	std::cout << "Particle: " << particleId->GetString() << std::endl;
    }
    std::cout << " Mass   : " << mass << std::endl;
    std::cout << " px     : " << px << std::endl;
    std::cout << " py     : " << py << std::endl;
    std::cout << " pz     : " << pz << std::endl;
    std::cout << " q      : " << q << std::endl;
    std::cout << " chi2   : " << chi2 << std::endl;
    std::cout << " pvx    : " << pvx << std::endl;
    std::cout << " pvy    : " << pvy << std::endl;
    std::cout << " pvz    : " << pvz << std::endl;
    std::cout << " ipchi2 : " << ipchi2 << std::endl;
    std::cout << " ip     : " << ip << std::endl;
    std::cout << " z meas : " << zFirstMeasurement << std::endl;

}
