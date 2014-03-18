#include "detDisk.h"

DetDisk::DetDisk(double z, double r_min, double r_max)
{
    _vec_min.SetXYZ(r_max, 0, z); // the larger r gives the lower eta value
    _vec_max.SetXYZ(r_min, 0, z);
    _eta_min = _vec_min.Eta();
    _eta_max = _vec_max.Eta();
}

DetDisk::calcEtaBoundaries()
{

}

