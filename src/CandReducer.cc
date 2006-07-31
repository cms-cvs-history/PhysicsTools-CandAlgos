// $Id: CandReducer.cc,v 1.5 2006/04/04 11:12:48 llista Exp $
#include <memory>
#include "PhysicsTools/CandAlgos/src/CandReducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Candidate/interface/LeafCandidate.h"
#include "FWCore/Utilities/interface/EDMException.h"

using namespace reco;
using namespace edm;
using namespace cand::modules;

CandReducer::CandReducer( const edm::ParameterSet& cfg ) :
  src_( cfg.getParameter<std::string>("src") ) {
  produces<CandidateCollection>();
}

CandReducer::~CandReducer() {
}

void CandReducer::produce( Event& evt, const EventSetup& ) {
  Handle<CandidateCollection> cands;
  evt.getByLabel( src_, cands );
  std::auto_ptr<CandidateCollection> comp( new CandidateCollection );
  for( CandidateCollection::const_iterator c = cands->begin(); c != cands->end(); ++c ) {
    std::auto_ptr<Candidate> cand( new LeafCandidate( * c ) );
    comp->push_back( cand.release() );
  }
  evt.put( comp );
}

