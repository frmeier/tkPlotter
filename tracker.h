#ifndef GUARD_tracker_h
#define GUARD_tracker_h

#include <vector>

#include "det.h"

struct TkVolume
{
    std::vector<double> x_;
    std::vector<double> y_;
    int col_;
    int size() { return x_.size(); };
    void addPoint(double x, double y) { x_.push_back(x); y_.push_back(y); };
    void setColor(int col) { col_ = col; };
};

struct Trackresult
{
    Trackresult() : nHits(0), nHits_vfpix(0), r_min(0), r_max(0), z_min(0) {};
    int nHits;
    int nHits_vfpix;
    double r_min, r_max;
    double z_min;
};

class Tracker
{
    public:
	Tracker() {};
	void add(Det det);
	Trackresult track(double eta);
	int getSize() const { return _detv.size(); };
	void draw(double z0, double r0, double z1, double r1) const; // draws the tracker
	void dump() const; // dumps the tracker as text

	TkVolume volBPix, volFPix, volVFPix, volBP;
	void drawVolume(TkVolume vol, int col) const;

    private:
	std::vector<Det> _detv;
};

#endif
