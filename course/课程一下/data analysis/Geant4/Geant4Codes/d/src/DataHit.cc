#include "DataHit.hh"

G4Allocator<DataHit> DataHitAllocator;

DataHit::DataHit() 
{
}

DataHit::~DataHit()
 {
 }

const DataHit& DataHit::operator=(const DataHit& )
{
	return *this;
}

G4int DataHit::operator==(const DataHit& right) const
{
	return (this==&right) ? 1 : 0;
}
