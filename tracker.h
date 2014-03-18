#ifndef GUARD_detector_h
#define GUARD_detector_h

#include <vector>

#include "det.h"

struct Trackresult
{
    int nHits;
    int nHits_vfpix;
    double r_min, r_max;
    double z_min;
};

class Detector
{
    public:
	Detector() {};
	void add(Det det);
	Trackresult track(double eta);

    private:
	std::vector<Det> _detv;
};

#endif
