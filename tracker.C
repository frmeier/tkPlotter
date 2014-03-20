#include <iostream>

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

void Tracker::dump() const
{
    std::cout << "#Dump of tracker" << endl;
    std::cout << "#No R0 Z0 R1 Z1" << endl;
    int i=0;
    for (std::vector<Det>::const_iterator it = _detv.begin(); it != _detv.end(); it++)
    {
	std::cout << i << " ";
	std::cout << it->getR0() << " ";
	std::cout << it->getZ0() << " ";
	std::cout << it->getR1() << " ";
	std::cout << it->getZ1() << " ";
	std::cout << std::endl;
	i++;
    }
}

