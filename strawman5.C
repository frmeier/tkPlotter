#include <iostream>

#include "TCanvas.h"
#include "TH1D.h"
#include "TMath.h"

#include "det.h"
#include "tracker.h"

using std::cout;
using std::endl;

void strawman5()
{
    Tracker trk;

    // Some constants to set colors
    const int vtxCol(8);
    const int ptCol(50);
    
    // Pixel central barrel module, will act as template for others
    DetProp modBarrelVtx;
    modBarrelVtx.name = "modBarrelVtx";
    modBarrelVtx.description = "Module for barrel optimized for vertexing";
    modBarrelVtx.isSensor = true;
    modBarrelVtx.w = 3.84; modBarrelVtx.l = 8.0;
    modBarrelVtx.alpha = 0; modBarrelVtx.beta = 0;
    modBarrelVtx.pxW = 75*0.001; modBarrelVtx.pxL = 100*0.001;
    modBarrelVtx.thickness = 0.400;
    modBarrelVtx.X0 = 21.82; // Si
    modBarrelVtx.NIL = 108.4; // Si
    modBarrelVtx.density = 2.329; // Si
    modBarrelVtx.col = vtxCol;

    // Disc for vertexing (traditional FPix-like discs), come in two sizes
    DetProp modDiscVtx80 = modBarrelVtx;
    modDiscVtx80.name = "modDiscVtx80";
    modDiscVtx80.description = "Module for disc optimized for vertexing, full size";
    DetProp modDiscVtx60 = modDiscVtx80;
    modDiscVtx60.l = 6.0;
    modDiscVtx60.description = "Module for disc optimized for vertexing, 3/4 size";

    // Now modules for pt, having different pixel shapes
    // Barrel modules for the pt-extension ("long barrel")
    DetProp modBarrelPt = modBarrelVtx;
    modBarrelPt.name = "modBarrelPt";
    modBarrelPt.description = "Module for barrel optimized for momentum";
    modBarrelPt.pxW = 15*0.001; modBarrelPt.pxL = 500*0.001;
    modBarrelPt.col = ptCol;
    modBarrelPt.alpha = 3.0/180*TMath::Pi();

    // Endcap discs, VFPix-style. Come in 3 sizes.
    DetProp modDiscPt80 = modBarrelPt;
    modDiscPt80.alpha = 0;
    modDiscPt80.name = "modDiscPt80";
    modDiscPt80.description = "Module for disc optimized for momentum, full size";
    DetProp modDiscPt60 = modDiscPt80;
    modDiscPt60.description = "Module for disc optimized for momentum, 3/4 size";
    modDiscPt60.l = 6.0;
    DetProp modDiscPt40 = modDiscPt80;
    modDiscPt40.description = "Module for disc optimized for momentum, 1/2 size";
    modDiscPt40.l = 4.0;

    DetProp matBeampipe;
    matBeampipe.name = "matBeampipe";
    matBeampipe.description = "Beampipe";
    matBeampipe.isSensor = false;
    matBeampipe.w = 1000; matBeampipe.l = 1000;
    matBeampipe.alpha = 0; matBeampipe.beta = 0;
    matBeampipe.thickness = 1;
    matBeampipe.X0 = 65.19; // Be
    matBeampipe.NIL = 77.8; // Be
    matBeampipe.density = 1.848; // Be
    matBeampipe.col = 16;

    {
        // BPix
        { Det d; d.setLayer(  3.0,  0.0, 32.0, false, modBarrelVtx, "vtx_b1"); trk.add(d); } // vtx_b1
        { Det d; d.setLayer(  6.8,  0.0, 32.0, false, modBarrelVtx, "vtx_b2"); trk.add(d); } // vtx_b2
        { Det d; d.setLayer( 11.8,  0.0, 32.0, false, modBarrelVtx, "vtx_b3"); trk.add(d); } // vtx_b3
        { Det d; d.setLayer( 18.8,  0.0, 32.0, false, modBarrelVtx, "vtx_b4"); trk.add(d); } // vtx_b4

        // FPix
        { Det d; d.setDisk( 34.0, 12.0, 20.0, false, modDiscVtx80, "vtx_f1_d1"); trk.add(d); } // vtx_f1_d1
        { Det d; d.setDisk( 37.0,  6.8, 12.8, false, modDiscVtx60, "vtx_f1_d2"); trk.add(d); } // vtx_f1_d2
        { Det d; d.setDisk( 54.0, 12.0, 20.0, false, modDiscVtx80, "vtx_f2_d1"); trk.add(d); } // vtx_f2_d1
        { Det d; d.setDisk( 69.0,  7.6, 15.6, false, modDiscVtx80, "vtx_f2_d2"); trk.add(d); } // vtx_f2_d2
        { Det d; d.setDisk( 92.0, 12.0, 20.0, false, modDiscVtx80, "vtx_f3_d1"); trk.add(d); } // vtx_f3_d1
        { Det d; d.setDisk(109.0, 12.0, 20.0, false, modDiscVtx80, "vtx_f4_d1"); trk.add(d); } // vtx_f4_d1
        { Det d; d.setDisk(145.0, 16.0, 20.0, true, modDiscPt40, "pt_f2_d3"); trk.add(d); } // pt_f2_d3 (old drawing: vtx_f5_d1)

        // VFPix
        { Det d; d.setLayer(  3.0, 32.0, 72.0, true, modBarrelPt, "pt_b1"); trk.add(d); } // pt_b1
        { Det d; d.setDisk( 88.0, 3.2, 11.2, true, modDiscPt80, "pt_f1_d1"); trk.add(d); } // pt_f1_d1
        { Det d; d.setDisk(126.0, 9.2, 15.2, true, modDiscPt60, "pt_f2_d1"); trk.add(d); } // pt_f2_d1
        { Det d; d.setDisk(144.0, 5.4, 11.4, true, modDiscPt60, "pt_f2_d2"); trk.add(d); } // pt_f2_d2
        { Det d; d.setDisk(183.0,12.2, 20.2, true, modDiscPt80, "pt_f3_d1"); trk.add(d); } // pt_f3_d1
        { Det d; d.setDisk(189.0, 7.0, 13.0, true, modDiscPt60, "pt_f3_d2"); trk.add(d); } // pt_f3_d2
        { Det d; d.setDisk(233.0,17.6, 25.6, true, modDiscPt80, "pt_f4_d1"); trk.add(d); } // pt_f4_d1
        { Det d; d.setDisk(230.0,11.8, 17.8, true, modDiscPt60, "pt_f4_d2"); trk.add(d); } // pt_f4_d2
        { Det d; d.setDisk(238.0, 8.8, 12.8, true, modDiscPt40, "pt_f4_d3"); trk.add(d); } // pt_f4_d3
        { Det d; d.setDisk(287.0,24.0, 32.0, true, modDiscPt80, "pt_f5_d1"); trk.add(d); } // pt_f5_d1
        { Det d; d.setDisk(284.0,16.0, 24.0, true, modDiscPt80, "pt_f5_d2"); trk.add(d); } // pt_f5_d2
        { Det d; d.setDisk(288.0,10.6, 16.6, true, modDiscPt60, "pt_f5_d3"); trk.add(d); } // pt_f5_d3

        // Dead material
        // Beampipe
        { Det d; d.setLayer(  2.2, 0.0, 154.0, true, matBeampipe, "bp_1"); trk.add(d); } 
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
    TH1D *hX0 = new TH1D("hX0", "Radiation length, all pixels;#eta;x/X_{0} [1]", N, eta_min, eta_max);
    TH1D *hNIL = new TH1D("hNIL", "Nuclear interaction length, all pixels;#eta;x/X_{0} [1]", N, eta_min, eta_max);

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
        hX0->SetBinContent(i+1,res.X0cum);
        hNIL->SetBinContent(i+1,res.NILcum);
    }
    TCanvas *c = new TCanvas("c","c", 500, 500);
    trk.draw(0, 0, 300, 50); c->SaveAs("tracker.pdf"); c->SaveAs("tracker.png");
    h1->Draw(); c->SaveAs("h1.pdf"); c->SaveAs("h1.png");
    h2->Draw(); c->SaveAs("h2.pdf"); c->SaveAs("h2.png");
    h3->Draw(); c->SaveAs("h3.pdf"); c->SaveAs("h3.png");
    h4->Draw(); c->SaveAs("h4.pdf"); c->SaveAs("h4.png");
    h5->Draw(); c->SaveAs("h5.pdf"); c->SaveAs("h5.png");
    h6->Draw(); c->SaveAs("h6.pdf"); c->SaveAs("h6.png");
    hX0->Draw(); c->SaveAs("hX0.pdf"); c->SaveAs("hX0.png");
    hNIL->Draw(); c->SaveAs("hNIL.pdf"); c->SaveAs("hNIL.png");
    trk.dump();
}

