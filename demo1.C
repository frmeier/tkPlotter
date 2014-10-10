#include <iostream>

#include "TCanvas.h"
#include "TH1D.h"

#include "det.h"
#include "tracker.h"

using std::cout;
using std::endl;

void demo1(int strawman)
{
    Tracker trk;

    if (strawman <= 3)
    {
    // FPix
    { Det d; d.setDisk( 29.1, 4.5, 16.1, 56, false); trk.add(d); }
    { Det d; d.setDisk( 39.6, 4.5, 16.1, 56, false); trk.add(d); }
    { Det d; d.setDisk( 51.6, 4.5, 16.1, 56, false); trk.add(d); }

    // BPix
    { Det d; d.setLayer(  3.0,  0.0, 27.4, 0, false); trk.add(d); }
    { Det d; d.setLayer(  6.8,  0.0, 27.4, 0, false); trk.add(d); }
    { Det d; d.setLayer( 10.9,  0.0, 27.4, 0, false); trk.add(d); }
    { Det d; d.setLayer( 16.0,  0.0, 27.4, 0, false); trk.add(d); }

    // Variant used for the initial proposal: 4 full disks, 3 half disks
    if (strawman == 0)
    {
	{ Det d; d.setDisk(  76.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk(  85.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 108.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 140.0, 4.5, 16.1, 56, true); trk.add(d); }

	{ Det d; d.setDisk( 200.0, 10.0, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 230.0, 10.0, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 264.0, 10.0, 16.1, 56, true); trk.add(d); }
    }

    // Variant using 6 disks a la FPix
    if (strawman == 1)
    {
	{ Det d; d.setDisk(  83.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk(  99.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 138.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 175.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 218.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 264.0, 4.5, 16.1, 56, true); trk.add(d); }
    }

    // Variant optimising lever arm using small and large r rings
    if (strawman == 2)
    {
	{ Det d; d.setDisk( 100.0, 14.5, 16.0, 56, true); trk.add(d); } // 1
	{ Det d; d.setDisk( 109.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 118.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 128.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 140.0, 14.5, 16.0, 56, true); trk.add(d); } // 5
	{ Det d; d.setDisk( 153.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 168.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 184.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 202.0, 14.5, 16.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 222.0, 14.5, 16.0, 56, true); trk.add(d); } // 10
	{ Det d; d.setDisk( 240.0, 14.5, 16.0, 56, true); trk.add(d); }

	{ Det d; d.setDisk( 66.0, 5.5, 12.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 88.0, 5.5, 12.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 130.0, 5.5, 12.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 180.0, 5.5, 12.0, 56, true); trk.add(d); }

	{ Det d; d.setDisk( 34.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 48.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 65.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 84.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 112.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 138.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 164.0, 3.2, 4.8, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 190.0, 3.2, 4.8, 56, true); trk.add(d); }

	{ Det d; d.setDisk( 264.0, 4.5, 16.1, 56, true); trk.add(d); }
    }

    // Variant using 6 disks a la FPix but the rings are separated in z for disks 1-5
    if (strawman == 3)
    {
	{ Det d; d.setDisk(  68.0, 4.5, 11.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk(  92.0, 4.5, 11.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 125.0, 4.5, 11.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 170.0, 4.5, 11.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 210.0, 4.5, 11.0, 56, true); trk.add(d); }

	{ Det d; d.setDisk(  90.0, 10.0, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 115.0, 10.0, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 140.0, 10.0, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 180.0, 10.0, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 220.0, 10.0, 16.1, 56, true); trk.add(d); }

	{ Det d; d.setDisk( 264.0, 4.5, 16.1, 56, true); trk.add(d); }
    }

    // Variant with conical supply tube, first attempt
    if (strawman == 104)
    {
	// another FPix disk
	{ Det d; d.setDisk(  68.0, 4.5, 16.1, 56, true); trk.add(d); }

	// Now the start of VFpix
	{ Det d; d.setDisk(  85.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 109.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 140.0, 4.5, 16.1, 56, true); trk.add(d); }

	// In conical part, increasing radii
	{ Det d; d.setDisk( 183.0, 7.5, 20.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 230.0, 7.5, 35.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 265.0,12.0, 39.0, 56, true); trk.add(d); }
    }

    // Variant with conical supply tube, first attempt
    if (strawman == 105)
    {
	// another FPix disk
	{ Det d; d.setDisk(  51.6, 3.0,  4.5, 56, true); trk.add(d); }
	{ Det d; d.setDisk(  68.0, 4.5, 16.1, 56, true); trk.add(d); }

	// Now the start of VFpix
	{ Det d; d.setDisk(  85.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 109.0, 4.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 140.0, 4.5, 16.1, 56, true); trk.add(d); }

	// In conical part, increasing radii
	{ Det d; d.setDisk( 183.0, 7.5, 20.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 230.0, 7.5, 35.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 265.0,12.0, 39.0, 56, true); trk.add(d); }
    }
    }

    if (strawman == 4)
    {
        // BPix
        { Det d; d.setLayer(  2.0,  0.0, 20.0, 0, false); trk.add(d); }
        { Det d; d.setLayer(  4.0,  0.0, 33.0, 0, false); trk.add(d); }
        { Det d; d.setLayer(  7.0,  0.0, 33.0, 0, false); trk.add(d); }
        { Det d; d.setLayer( 11.5,  0.0, 33.0, 0, false); trk.add(d); }
        { Det d; d.setLayer( 17.6,  0.0, 33.0, 0, false); trk.add(d); }

        // FPix
        { Det d; d.setDisk( 35.5, 4.0, 16.0, 56, false); trk.add(d); }
        { Det d; d.setDisk( 47.5, 4.0, 16.0, 56, false); trk.add(d); }
        { Det d; d.setDisk( 75.0, 10.0, 16.0, 56, false); trk.add(d); }

        // VFPix
        { Det d; d.setLayer(  2.0, 20.0, 55.0, 0, true); trk.add(d); }
	{ Det d; d.setDisk( 75.0, 4.0, 10.0, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 95.0, 4.0, 14.6, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 120.0, 4.5, 14.6, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 160.0, 6.0, 12, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 165.0, 10.5, 16.1, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 215.0, 8.0, 20, 56, true); trk.add(d); }
	{ Det d; d.setDisk( 285.0, 10.5, 28, 56, true); trk.add(d); }

    // Define tracker volumes
    trk.volBP.addPoint(0, 0);
    trk.volBP.addPoint(300, 0);
    trk.volBP.addPoint(300, 4.6);
    trk.volBP.addPoint(96, 1.5);
    trk.volBP.addPoint(0, 1.5);
    trk.volBP.addPoint(0, 0);

    trk.volBPix.addPoint(0, 2.0);
    trk.volBPix.addPoint(30, 2.0);
    trk.volBPix.addPoint(30, 17.4);
    trk.volBPix.addPoint(152, 17.4);
    trk.volBPix.addPoint(290, 33.4);
    trk.volBPix.addPoint(290, 50);
    trk.volBPix.addPoint(280, 50);
    trk.volBPix.addPoint(280, 34);
    trk.volBPix.addPoint(156, 19);
    trk.volBPix.addPoint(0, 19);
    trk.volBPix.addPoint(0, 2.0);

    trk.volFPix.addPoint(30, 2.0);
    trk.volFPix.addPoint(70, 2.0);
    trk.volFPix.addPoint(70, 15.6);
    trk.volFPix.addPoint(141, 15.6);
    trk.volFPix.addPoint(300, 33);
    trk.volFPix.addPoint(300, 50);
    trk.volFPix.addPoint(290, 50);
    trk.volFPix.addPoint(290, 33.2);
    trk.volFPix.addPoint(150, 17.2);
    trk.volFPix.addPoint(30, 17.2);
    trk.volFPix.addPoint(30, 2.0);

    trk.volVFPix.addPoint(70, 2.0);
    trk.volVFPix.addPoint(90, 2.0);
    trk.volVFPix.addPoint(310, 10);
    trk.volVFPix.addPoint(310, 50);
    trk.volVFPix.addPoint(300, 50);
    trk.volVFPix.addPoint(300, 32.2);
    trk.volVFPix.addPoint(143.5, 15.4);
    trk.volVFPix.addPoint(70, 15.4);
    trk.volVFPix.addPoint(70, 2.0);
    }

    if (strawman == 5)
    {
        // BPix
        { Det d; d.setLayer(  3.0,  0.0, 32.0, 0, false); trk.add(d); } // vtx_b1
        { Det d; d.setLayer(  6.8,  0.0, 32.0, 0, false); trk.add(d); } // vtx_b2
        { Det d; d.setLayer( 11.8,  0.0, 32.0, 0, false); trk.add(d); } // vtx_b3
        { Det d; d.setLayer( 18.8,  0.0, 32.0, 0, false); trk.add(d); } // vtx_b4

        // FPix
        { Det d; d.setDisk( 34.0, 12.0, 20.0, 56, false); trk.add(d); } // vtx_f1_d1
        { Det d; d.setDisk( 37.0,  6.8, 12.8, 56, false); trk.add(d); } // vtx_f1_d2
        { Det d; d.setDisk( 54.0, 12.0, 20.0, 56, false); trk.add(d); } // vtx_f2_d1
        { Det d; d.setDisk( 69.0,  7.6, 15.6, 56, false); trk.add(d); } // vtx_f2_d2
        { Det d; d.setDisk( 92.0, 12.0, 20.0, 56, false); trk.add(d); } // vtx_f3_d1
        { Det d; d.setDisk(109.0, 12.0, 20.0, 56, false); trk.add(d); } // vtx_f4_d1
        { Det d; d.setDisk(145.0, 16.0, 20.0, 56, true); trk.add(d); } // vtx_f5_d1

        // VFPix
        { Det d; d.setLayer(  3.0, 32.0, 72.0, 0, true); trk.add(d); } // pt_b1
	{ Det d; d.setDisk( 88.0, 3.2, 11.2, 56, true); trk.add(d); } // pt_f1_d1
	{ Det d; d.setDisk(126.0, 9.2, 15.2, 56, true); trk.add(d); } // pt_f2_d1
	{ Det d; d.setDisk(144.0, 5.4, 11.4, 56, true); trk.add(d); } // pt_f2_d2
	{ Det d; d.setDisk(183.0,12.2, 20.2, 56, true); trk.add(d); } // pt_f3_d1
	{ Det d; d.setDisk(189.0, 7.0, 13.0, 56, true); trk.add(d); } // pt_f3_d2
	{ Det d; d.setDisk(233.0,17.6, 25.6, 56, true); trk.add(d); } // pt_f4_d1
	{ Det d; d.setDisk(230.0,11.8, 17.8, 56, true); trk.add(d); } // pt_f4_d2
	{ Det d; d.setDisk(238.0, 8.8, 12.8, 56, true); trk.add(d); } // pt_f4_d3
	{ Det d; d.setDisk(287.0,24.0, 32.0, 56, true); trk.add(d); } // pt_f5_d1
	{ Det d; d.setDisk(284.0,16.0, 24.0, 56, true); trk.add(d); } // pt_f5_d2
	{ Det d; d.setDisk(288.0,10.6, 16.6, 56, true); trk.add(d); } // pt_f5_d3
    }


    cout << "Tracker consists of " << trk.getSize() << " units" << endl;

    const double eta_min(0);
    const double eta_max(5);
    const double eta_delta = eta_max-eta_min;
    const int N(5000);
    const double eta_step = eta_delta / N;

    TH1D *h1 = new TH1D("h1", "all pixels;#eta;# of hits", N, eta_min, eta_max);
    TH1D *h2 = new TH1D("h2", "VFPix only;#eta;# of hits", N, eta_min, eta_max);
    TH1D *h3 = new TH1D("h3", "all pixels;#eta;r_{min} [cm]", N, eta_min, eta_max);
    TH1D *h4 = new TH1D("h4", "all pixels;#eta;r_{max} [cm]", N, eta_min, eta_max);
    TH1D *h5 = new TH1D("h5", "all pixels;#eta;r_{max}-r_{min} [cm]", N, eta_min, eta_max);
    TH1D *h6 = new TH1D("h6", "all pixels;#eta;z_{min} [cm]", N, eta_min, eta_max);

    for (int i = 0; i!=N; i++)
    {
	const double eta = eta_min + i*eta_step;
	Trackresult res = trk.track(eta);
	//cout << "eta: " << eta << " nHits: " << res.nHits << endl;
	h1->SetBinContent(i+1,res.nHits);
	h2->SetBinContent(i+1,res.nHits_vfpix);
	h3->SetBinContent(i+1,res.r_min);
	h4->SetBinContent(i+1,res.r_max);
	h5->SetBinContent(i+1,res.r_max-res.r_min);
	h6->SetBinContent(i+1,res.z_min);
    }
    TCanvas *c = new TCanvas("c","c", 500, 500);
    trk.draw(0, 0, 300, 50); c->SaveAs("tracker.pdf"); c->SaveAs("tracker.png");
    h1->Draw(); c->SaveAs("h1.pdf"); c->SaveAs("h1.png");
    h2->Draw(); c->SaveAs("h2.pdf"); c->SaveAs("h2.png");
    h3->Draw(); c->SaveAs("h3.pdf"); c->SaveAs("h3.png");
    h4->Draw(); c->SaveAs("h4.pdf"); c->SaveAs("h4.png");
    h5->Draw(); c->SaveAs("h5.pdf"); c->SaveAs("h5.png");
    h6->Draw(); c->SaveAs("h6.pdf"); c->SaveAs("h6.png");
    trk.dump();
}

