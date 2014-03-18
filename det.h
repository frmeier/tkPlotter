#ifndef GUARD_det_h
#define GUARD_det_h

#include <string>
#include "TVector3.h"

class Det
{
    public:
	Det() {};
	bool hit(double eta, double &r, double &z) { }; // Check if a track at a certain eta creates a hit. If yes, r and z contain the coordinates where this happens

    private:
	void calcEtaBoundaries(); // calculates the eta coverage of the given detector unit

	std::string _type;
	TVector3 _vec_min, _vec_max; // min/max ordered by eta
	double _eta_min, _eta_max;
};

#endif
