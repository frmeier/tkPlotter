#include <iostream>
#include "TMath.h"
#include "det.h"

Det::Det()
{
    _vec_min.SetXYZ(0, 0, 0);
    _vec_max.SetXYZ(0, 0, 0);
}

void Det::setDisk(double z, double r_min, double r_max, bool isVfpix, DetProp prop, std::string name)
{
    _vec_min.SetXYZ(r_max, 0, z); // the larger r gives the lower eta value
    _vec_max.SetXYZ(r_min, 0, z);
    calcEtaBoundaries();
    _isVfpix = isVfpix;
    _isDisk = true;
    _properties = prop;
    _name = name;
    // Calculate number of modules per disc, assuming to have two half disks
    _nModules = 2 * ( (int)(r_max * TMath::Pi() / _properties.w) + 1);
    // To estimate the fill factor, take the area of the modules and divide by annulus area
    _fillfactor = _nModules * _properties.area() / (TMath::Pi() * (r_max*r_max - r_min*r_min));
}

void Det::setLayer(double r, double z_min, double z_max, bool isVfpix, DetProp prop, std::string name)
{
    _vec_min.SetXYZ(r, 0, z_min);
    _vec_max.SetXYZ(r, 0, z_max);
    calcEtaBoundaries();
    _isVfpix = isVfpix;
    _isDisk = false;
    _properties = prop;
    _name = name;
    // Calculate number of faces = minimal number of modules to make two half-circles
    const double nFaces = 2 * ( (int)(r * TMath::Pi() / _properties.w) + 1);
    // Number of modules is nFaces multiplied by the number of modules per ladder
    _nModules = nFaces * (z_max-z_min) / _properties.l;
    // Calculate angle covered by one module, needed for estimating fill factor. Assumes r is closest point of a face
    const double anglePerModule = 2 * TMath::ATan(_properties.w / (2 * r) ); 
    // Fill factor > 1 means overlap, and also more material
    _fillfactor = anglePerModule / (2 * TMath::Pi() / nFaces);
}

void Det::calcEtaBoundaries()
{
    _eta_min = _vec_min.Eta();
    _eta_max = _vec_max.Eta();
}

bool Det::hit(double eta, double &r, double &z, double &dX0, double &dNIL) const
{
    r = 0;
    z = 0;
    dX0 = 0;
    dNIL = 0;

    if (eta >= _eta_min && eta <= _eta_max)
    {
        const double tantheta = TMath::Tan(2*TMath::ATan(TMath::Exp(-eta)));
        if (_isDisk)
        {
            z = _vec_min.z();
            r = z * tantheta;
            dX0 = _properties.xOverX0() * TMath::Sqrt(1+tantheta*tantheta) * _fillfactor;
            dNIL = _properties.xOverNIL() * TMath::Sqrt(1+tantheta*tantheta) * _fillfactor;
            return true;
        }
        else
        {
            r = _vec_min.x();
            if (r <= 0) return false;
            if (tantheta == 0) return false;
            z = r / tantheta;
            const double tanPihalvMinTheta = TMath::Tan(0.5*TMath::Pi()-2*TMath::ATan(TMath::Exp(-eta) + _properties.alpha));
            const double tanPihalvMinTheta2 = TMath::Sqrt(1+tanPihalvMinTheta*tanPihalvMinTheta);
            dX0  = _properties.xOverX0()  * tanPihalvMinTheta2 * _fillfactor;
            dNIL = _properties.xOverNIL() * tanPihalvMinTheta2 * _fillfactor;
            return true;
        }
    }
    else
        return false;
}

