/* \class reco::modules::plugins::CandViewCombiner
 * 
 * Configurable Candidate Selector reading
 * a View<Candidate> as input
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/UtilAlgos/interface/StringCutObjectSelector.h"
#include "PhysicsTools/CandAlgos/interface/NamedCandCombiner.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/NamedCompositeCandidate.h"
#include "DataFormats/Candidate/interface/NamedCompositeCandidateFwd.h"

typedef reco::modules::NamedCandCombiner<
                         reco::CandidateView,
                         StringCutObjectSelector<reco::Candidate>,
                         reco::NamedCompositeCandidateCollection
                       > NamedCandViewCombiner;
      
DEFINE_FWK_MODULE( NamedCandViewCombiner );