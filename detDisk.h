#ifndef GUARD_detDisk_h
#define GUARD_detDisk_h

#include <string>

#include "TVector3.h"

#include "det.h"

class DetDisk : public Det
{
    public:
	DetDisk();
	DetDisk(double z, double r_min, double r_max, bool isVfpix);
	bool hit(double eta, double &r, double &z);
	double getEtaMin() { return _eta_min; };
	double getEtaMax() { return _eta_max; };
	bool getIsVfpix() { return _isVfpix; };
	ClassDef(DetDisk, 1);

    private:
	void calcEtaBoundaries();
};

#endif
