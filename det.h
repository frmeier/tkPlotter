#ifndef GUARD_det_h
#define GUARD_det_h

#include <string>
#include "TVector3.h"

class Det
{
    public:
	Det() {};
	virtual ~Det() {};
	virtual bool hit(double eta, double &r, double &z) = 0; // Check if a track at a certain eta creates a hit. If yes, r and z contain the coordinates where this happens

    private:
	virtual void calcEtaBoundaries() = 0; // calculates the eta coverage of the given detector unit

	std::string _type;
	TVector3 _vec_min, _vec_max; // min/max ordered by eta
	double _eta_min, _eta_max;
};

#endif
