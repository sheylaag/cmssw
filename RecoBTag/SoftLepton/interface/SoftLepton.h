#ifndef RecoBTag_SoftLepton_SoftLepton
#define RecoBTag_SoftLepton_SoftLepton

// -*- C++ -*-
//
// Package:    SoftLepton
// Class:      SoftLepton
// 
/**\class SoftLepton SoftLepton.h RecoBTag/SoftLepton/interface/SoftLepton.h

 Description: CMSSW EDProducer wrapper for sot lepton b tagging.

 Implementation:
     The actual tagging is performed by SoftLeptonAlgorithm.
*/
//
// Original Author:  fwyzard
//         Created:  Wed Oct 18 18:02:07 CEST 2006
// $Id: SoftLepton.h,v 1.2 2006/10/31 02:53:10 fwyzard Exp $
//

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "RecoBTag/SoftLepton/interface/SoftLeptonAlgorithm.h"

class edm::ParameterSet;
class edm::EventSetup;
class edm::Event;

class SoftLepton : public edm::EDProducer {
public:
  explicit SoftLepton(const edm::ParameterSet& iConfig);
  ~SoftLepton();

private:
  virtual void beginJob(const edm::EventSetup& iSetup);
  virtual void produce(edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void endJob(void);

  // configuration   
  const edm::ParameterSet& m_config;
  const std::string m_jetTracksAssociator;
  const std::string m_primaryVertexProducer;
  const std::string m_leptonProducer;
  const std::string m_outputInstanceName;

  // concrete algorithm
  SoftLeptonAlgorithm m_algo;
  const double        m_deltaRCut;

  // nominal beam spot position
  const reco::Vertex * m_nominalBeamSpot;
};

#endif // RecoBTag_SoftLepton_SoftLepton
