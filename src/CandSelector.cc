// $Id: CandSelector.cc,v 1.12 2006/06/14 11:54:30 llista Exp $
#include <memory>
#include "PhysicsTools/CandAlgos/src/CandSelector.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "PhysicsTools/CandAlgos/src/cutParser.h"
#include "PhysicsTools/CandAlgos/src/candidateMethods.h"
#include "FWCore/Utilities/interface/EDMException.h"

using namespace reco;
using namespace std;
using namespace edm;

namespace cand {
  namespace modules {
 
    CandSelector::CandSelector( const ParameterSet& cfg ) :
      CandSelectorBase( cfg ) {
      string cut = cfg.getParameter<string>( "cut" );
      if( ! cand::parser::cutParser( cut, candidateMethods(), select_ ) ) {
	throw Exception( errors::Configuration, 
			 "failed to parse \"" + cut + "\"" );
      }
    }
  }
}

