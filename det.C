#include "TMath.h"
#include "det.h"

Det::Det()
{
    _vec_min.SetXYZ(0, 0, 0);
    _vec_max.SetXYZ(0, 0, 0);
}

void Det::setDisk(double z, double r_min, double r_max, int nModules, bool isVfpix, std::string name)
{
    _vec_min.SetXYZ(r_max, 0, z); // the larger r gives the lower eta value
    _vec_max.SetXYZ(r_min, 0, z);
    calcEtaBoundaries();
    _isVfpix = isVfpix;
    _nModules = nModules;
    _isDisk = true;
    _name = name;
}

void Det::setLayer(double r, double z_min, double z_max, int nModules, bool isVfpix, std::string name)
{
    _vec_min.SetXYZ(r, 0, z_min);
    _vec_max.SetXYZ(r, 0, z_max);
    calcEtaBoundaries();
    _isVfpix = isVfpix;
    _nModules = nModules;
    _isDisk = false;
    _name = name;
}

void Det::calcEtaBoundaries()
{
    _eta_min = _vec_min.Eta();
    _eta_max = _vec_max.Eta();
}

bool Det::hit(double eta, double &r, double &z) const
{
    r = 0;
    z = 0;

    if (eta >= _eta_min && eta <= _eta_max)
    {
	if (_isDisk)
	{
	    z = _vec_min.z();
	    const double tantheta = TMath::Tan(2*TMath::ATan(TMath::Exp(-eta)));
	    r = z * tantheta;
	    return true;
	}
	else
	{
	    r = _vec_min.x();
	    if (r <= 0) return false;
	    const double tantheta = TMath::Tan(2*TMath::ATan(TMath::Exp(-eta)));
	    if (tantheta == 0) return false;
	    z = r / tantheta;
	    return true;
	}
    }
    else
	return false;
}

