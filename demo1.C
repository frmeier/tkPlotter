#include <iostream>

#include "TCanvas.h"
#include "TH1D.h"

#include "det.h"
#include "tracker.h"

using std::cout;
using std::endl;

void demo1()
{
    Tracker trk;

    // FPix
    { Det d; d.setDisk( 29.1, 4.5, 16.1, 56, false); trk.add(d); }
    { Det d; d.setDisk( 39.6, 4.5, 16.1, 56, false); trk.add(d); }
    { Det d; d.setDisk( 51.6, 4.5, 16.1, 56, false); trk.add(d); }

    // BPix
    { Det d; d.setLayer(  3.0,  0.0, 27.4, 0, false); trk.add(d); }
    { Det d; d.setLayer(  6.8,  0.0, 27.4, 0, false); trk.add(d); }
    { Det d; d.setLayer( 10.9,  0.0, 27.4, 0, false); trk.add(d); }
    { Det d; d.setLayer( 16.0,  0.0, 27.4, 0, false); trk.add(d); }

    /*
    // Variante mit 6 Disks gleicher Grösse
    { Det d; d.setDisk(  83.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk(  99.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 138.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 175.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 218.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 264.0, 4.5, 16.1, 56, true); trk.add(d); }
    */

    // Variante mit 3 verschiedenen Diskgeometrien
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
    trk.draw(0, 0, 300, 20); c->SaveAs("tracker.pdf");
    h1->Draw(); c->SaveAs("h1.pdf");
    h2->Draw(); c->SaveAs("h2.pdf");
    h3->Draw(); c->SaveAs("h3.pdf");
    h4->Draw(); c->SaveAs("h4.pdf");
    h5->Draw(); c->SaveAs("h5.pdf");
    h6->Draw(); c->SaveAs("h6.pdf");
    trk.dump();
}

