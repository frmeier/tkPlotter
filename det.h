#ifndef GUARD_det_h
#define GUARD_det_h

#include <string>
#include "TVector3.h"

class Det
{
    public:
	Det();
	void setDisk(double z, double r_min, double r_max, int nModules, bool isVfpix);
	void setLayer(double r, double z_min, double z_max, int nModules, bool isVfpix);
	bool hit(double eta, double &r, double &z) const;
	double getEtaMin() const { return _eta_min; };
	double getEtaMax() const { return _eta_max; };
	bool getIsVfpix() const { return _isVfpix; };
	int getNModules() const { return _nModules; };
	ClassDef(Det, 1);

    private:
	void calcEtaBoundaries(); // calculates the eta coverage of the given detector unit

	std::string _type;
	TVector3 _vec_min, _vec_max; // min/max ordered by eta
	double _eta_min, _eta_max;
	bool _isVfpix;
	bool _isDisk;
	int _nModules;
};

#endif
