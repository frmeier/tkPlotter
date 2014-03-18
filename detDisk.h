#ifndef GUARD_detDisk_h
#define GUARD_detDisk_h

#include <string>

#include "det.h"

class DetDisk : public det
{
    public:
	DetDisk();
	DetDisk(double z, double r_min, double r_max);
};

#endif
