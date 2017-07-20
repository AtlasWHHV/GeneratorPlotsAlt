#ifndef __neutrino_plots__
#define __neutrino_plots__

#include "xAODTruth/TruthParticle.h"
#include "xAODTruth/TruthVertex.h"
#include <EventLoop/Worker.h>

#include "TH1F.h"

#include <string>

class neutrino_plots {
  public:
    neutrino_plots(const std::string &name, const std::string &title, EL::Worker *wk) 
    {
      _pt = new TH1F((name + "pt").c_str(), (title + "p_{T}; p_{T} [GeV]").c_str(), 250, 0.0, 2000.0);
      wk->addOutput (_pt);
      _eta = new TH1F((name + "eta").c_str(), (title + "\\eta; \\eta").c_str(), 200, -5.0, 5.0);
      wk->addOutput (_eta);
      _phi = new TH1F((name + "phi").c_str(), (title + "\\phi; \\phi [rad]").c_str(), 200, -3.15, 3.15);
      wk->addOutput (_phi);
    }

    void Process(const xAOD::TruthParticle *p) 
    {
      _pt->Fill(p->pt()*0.001);
      _eta->Fill(p->eta());
      _phi->Fill(p->phi());
    }

  private:
    TH1F *_mass;
    TH1F *_pt;
    TH1F *_eta;
    TH1F *_phi;
};

#endif
