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

    { Det d; d.setDisk( 29.1, 4.5, 16.1, 56, false); trk.add(d); }
    { Det d; d.setDisk( 39.6, 4.5, 16.1, 56, false); trk.add(d); }
    { Det d; d.setDisk( 51.6, 4.5, 16.1, 56, false); trk.add(d); }

    { Det d; d.setLayer( 27.4, 0, 3.0, 0, false); trk.add(d); }
    { Det d; d.setLayer( 27.4, 0, 6.8, 0, false); trk.add(d); }
    { Det d; d.setLayer( 27.4, 0, 10.9, 0, false); trk.add(d); }
    { Det d; d.setLayer( 27.4, 0, 18.0, 0, false); trk.add(d); }

    { Det d; d.setDisk(  83.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk(  99.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 138.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 175.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 218.0, 4.5, 16.1, 56, true); trk.add(d); }
    { Det d; d.setDisk( 264.0, 4.5, 16.1, 56, true); trk.add(d); }

    cout << "Tracker consists of " << trk.getSize() << " units" << endl;

    const double eta_min(0);
    const double eta_max(5);
    const double eta_delta = eta_max-eta_min;
    const int N(5000);
    const double eta_step = eta_delta / N;

    TH1D *h1 = new TH1D("h1", "Number of hits", N, eta_min, eta_max);

    for (int i = 0; i!=N; i++)
    {
	const double eta = eta_min + i*eta_step;
	Trackresult res = trk.track(eta);
	//cout << "eta: " << eta << " nHits: " << res.nHits << endl;
	h1->SetBinContent(i+1,res.nHits);
    }
    h1->Draw();
}

