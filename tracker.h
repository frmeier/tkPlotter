#ifndef GUARD_tracker_h
#define GUARD_tracker_h

#include <vector>

#include "det.h"

struct Trackresult
{
    int nHits;
    int nHits_vfpix;
    double r_min, r_max;
    double z_min;
};

class Tracker
{
    public:
	Tracker() {};
	void add(Det det);
	Trackresult track(double eta);

    private:
	std::vector<Det> _detv;
};

#endif
