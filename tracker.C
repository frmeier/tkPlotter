#include <iostream>
#include <string>

#include "TH1F.h"
#include "TLine.h"
#include "TPolyLine.h"
#include "TLatex.h"

#include "tracker.h"
#include "det.h"

void Tracker::add(Det det)
{
    _detv.push_back(det);
}

Trackresult Tracker::track(double eta)
{
    Trackresult res;
    for (std::vector<Det>::const_iterator it = _detv.begin(); it != _detv.end(); it++)
    {
	double r,z;
	if (it->hit(eta, r,z))
	{
	    res.nHits++;
	    if (it->getIsVfpix()) res.nHits_vfpix++;
	    if (res.nHits == 1)
	    {
		res.r_min = res.r_max = r;
		res.z_min = z;
	    }
	    else
	    {
		res.r_min = ( r<res.r_min ? r : res.r_min);
		res.r_max = ( r>res.r_max ? r : res.r_max);
		res.z_min = ( z<res.z_min ? z : res.z_min);
	    }
	}
    }
    return res;
}

void Tracker::draw(double z0, double r0, double z1, double r1) const // draws the tracker
{
    TH1F *h = new TH1F("tracker","Layout of tracker;z [cm];r [cm]", 1, z0, z1);
    h->SetMinimum(r0);
    h->SetMaximum(r1);
    h->SetStats(false);
    h->Draw();

/*
    drawVolume(volBP, 1);
    drawVolume(volBPix, 2);
    drawVolume(volFPix, 3);
    drawVolume(volVFPix, 4);
*/

    TLatex *tl = new TLatex;
    tl->SetTextSize(0.017);
    for (std::vector<Det>::const_iterator it = _detv.begin(); it != _detv.end(); it++)
    {
        TLine *l = new TLine(it->getZ0(), it->getR0(), it->getZ1(), it->getR1());
        l->SetLineColor(it->getColor());
        tl->SetTextColor(it->getColor());
        l->Draw();
        if (it->getIsDisk())
        {
            tl->SetTextAngle(90);
            tl->SetTextAlign(23);
            tl->DrawLatex(it->getZ0()+3, .5*(it->getR0()+it->getR1()), it->getName().c_str());
        }
        else
        {
            tl->SetTextAngle(0);
            tl->SetTextAlign(21);
            tl->DrawLatex(.5*(it->getZ0()+it->getZ1()), it->getR0()+.2, it->getName().c_str());
        }
    }
}

void Tracker::drawVolume(TkVolume vol, int col) const
{
    TPolyLine *pline = new TPolyLine(vol.size(), &vol.x_[0], &vol.y_[0]);
    pline->SetFillColorAlpha(col,0.3);
    pline->SetLineColor(col);
    pline->SetLineWidth(1);
    pline->Draw("f");
}

void Tracker::dump() const
{
    bool setTWiki(true);
    bool setLaTeX(false);
    std::cout << "#Dump of tracker" << endl;
    std::cout << "#No R0 Z0 R1 Z1" << endl;
    int i=0;
    for (std::vector<Det>::const_iterator it = _detv.begin(); it != _detv.end(); it++)
    {
	if (setTWiki) std::cout << "|  ";
	std::cout << i << " ";
	if (it->getIsDisk())
	{
	    if (setTWiki) std::cout << " |";
	    cout << " Disk ";
	    if (setTWiki) std::cout << " |  ";
	}
	else
	{
	    if (setTWiki) std::cout << " |";
	    cout << " Layer ";
	    if (setTWiki) std::cout << " |  ";
	}
	std::cout << it->getName() << " ";
	if (setTWiki) std::cout << " |  ";
	std::cout << it->getR0() << " ";
	if (setTWiki) std::cout << " |  ";
	std::cout << it->getZ0() << " ";
	if (setTWiki) std::cout << " |  ";
	std::cout << it->getR1() << " ";
	if (setTWiki) std::cout << " |  ";
	std::cout << it->getZ1() << " ";
	if (setTWiki) std::cout << " |  ";
	std::cout << std::endl;
	i++;
    }
}

