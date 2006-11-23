#ifndef DeltaRMatcher_h
#define DeltaRMatcher_h
/* \class DeltaRMatcher
 *
 * Producer fo simple match map
 * based on DeltaR
 *
 */
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"
#include "FWCore/ParameterSet/interface/InputTag.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"

class DeltaRMatcher : public edm::EDProducer {
public:
  DeltaRMatcher( const edm::ParameterSet & );
  ~DeltaRMatcher();
private:
  void produce( edm::Event&, const edm::EventSetup& );
  edm::InputTag src_;
  edm::InputTag matched_;
  double drMin_;
  double matchDistance( const reco::Candidate &, const reco::Candidate & ) const;
  bool select( const reco::Candidate & ) const;
};

#endif
