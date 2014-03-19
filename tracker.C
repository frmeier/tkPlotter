#include "tracker.h"
#include "det.h"

void Tracker::add(Det det)
{
    _detv.push_back(det);
}

Trackresult Tracker::track(double eta)
{
    Trackresult res;
    for (std::vector<Det>::const_iterator it = _detv.begin(); it != _detv.end(); it++)
    {
	double r,z;
	if (it->hit(eta, r,z))
	{
	    res.nHits++;
	    if (it->getIsVfpix()) res.nHits_vfpix++;
	    if (res.nHits == 1)
	    {
		res.r_min = res.r_max = r;
		res.z_min = z;
	    }
	    else
	    {
		res.r_min = ( r<res.r_min ? r : res.r_min);
		res.r_max = ( r>res.r_max ? r : res.r_max);
		res.z_min = ( z<res.z_min ? z : res.z_min);
	    }
	}
    }
    return res;
}

