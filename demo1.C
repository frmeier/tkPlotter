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
    { Det d; d.setDisk( 100.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 111.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 123.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 136.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 150.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 166.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 184.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 200.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 220.0, 13.5, 15.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 243.0, 13.5, 15.0, 56, true); trk.add(d); }

    { Det d; d.setDisk( 76.0, 5.5, 12.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 120.0, 5.5, 12.0, 56, true); trk.add(d); }
    { Det d; d.setDisk( 190.0, 5.5, 12.0, 56, true); trk.add(d); }

    { Det d; d.setDisk( 60.0, 3.2, 4.8, 56, true); trk.add(d); }
    { Det d; d.setDisk( 88.0, 3.2, 4.8, 56, true); trk.add(d); }
    { Det d; d.setDisk( 120.0, 3.2, 4.8, 56, true); trk.add(d); }
    { Det d; d.setDisk( 150.0, 3.2, 4.8, 56, true); trk.add(d); }
    { Det d; d.setDisk( 178.0, 3.2, 4.8, 56, true); trk.add(d); }
    { Det d; d.setDisk( 208.0, 3.2, 4.8, 56, true); trk.add(d); }

    { Det d; d.setDisk( 264.0, 4.5, 16.1, 56, true); trk.add(d); }

    cout << "Tracker consists of " << trk.getSize() << " units" << endl;

    const double eta_min(0);
    const double eta_max(5);
    const double eta_delta = eta_max-eta_min;
    const int N(5000);
    const double eta_step = eta_delta / N;

    TH1D *h1 = new TH1D("h1", "Full tracker;#eta;# of hits", N, eta_min, eta_max);
    TH1D *h2 = new TH1D("h2", "VFPix only;#eta;# of hits", N, eta_min, eta_max);
    TH1D *h3 = new TH1D("h3", "Full tracker;#eta;r_{min} [cm]", N, eta_min, eta_max);
    TH1D *h4 = new TH1D("h4", "Full tracker;#eta;r_{max} [cm]", N, eta_min, eta_max);
    TH1D *h5 = new TH1D("h5", "Full tracker;#eta;r_{max}-r_{min} [cm]", N, eta_min, eta_max);
    TH1D *h6 = new TH1D("h6", "Full tracker;#eta;z_{min} [cm]", N, eta_min, eta_max);

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
    h1->Draw(); c->SaveAs("h1.pdf");
    h2->Draw(); c->SaveAs("h2.pdf");
    h3->Draw(); c->SaveAs("h3.pdf");
    h4->Draw(); c->SaveAs("h4.pdf");
    h5->Draw(); c->SaveAs("h5.pdf");
    h6->Draw(); c->SaveAs("h6.pdf");
}

