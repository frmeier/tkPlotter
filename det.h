#ifndef GUARD_det_h
#define GUARD_det_h

#include <string>

class det
{
    public:
	void det() {};

    private:
	std::string _type;
	double _eta_lo, _eta_hi;
	bool _eta_cached;
};

#endif
