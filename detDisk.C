#include "TVector3.h"
#include "TMath.h"

#include "detDisk.h"

DetDisk::DetDisk()
{
    _vec_min.SetXYZ(0, 0, 0);
    _vec_max.SetXYZ(0, 0, 0);
}

DetDisk::DetDisk(double z, double r_min, double r_max, bool isVfpix)
{
    _vec_min.SetXYZ(r_max, 0, z); // the larger r gives the lower eta value
    _vec_max.SetXYZ(r_min, 0, z);
    calcEtaBoundaries();
    _isVfpix = isVfpix;
}

void DetDisk::calcEtaBoundaries()
{
    _eta_min = _vec_min.Eta();
    _eta_max = _vec_max.Eta();
}

bool DetDisk::hit(double eta, double &r, double &z)
{
    r = 0;
    z = 0;
    if (eta >= _eta_min && eta <= _eta_max)
    {
	z = _vec_min.z();
	const double tantheta = TMath::Tan(2*TMath::ATan(TMath::Exp(-eta)));
	r = z * tantheta;
	return true;
    }
    else
	return false;
}

