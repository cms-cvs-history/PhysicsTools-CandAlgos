/* \class reco::modules::CandSelector
 * 
 * Configurable Candidate Selector
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/Parser/interface/SingleObjectSelector.h"
#include "PhysicsTools/CandAlgos/src/CandCombiner.h"
#include "DataFormats/Candidate/interface/Candidate.h"

DEFINE_SEAL_MODULE();

namespace reco {
  namespace modules {
    typedef ::CandCombiner<
              SingleObjectSelector<reco::Candidate>
            > CandCombiner;

DEFINE_ANOTHER_FWK_MODULE( CandCombiner );

  }
}
