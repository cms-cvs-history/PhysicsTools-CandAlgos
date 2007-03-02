/* \class PdgIdCandSelector
 * 
 * Candidate Selector based on a minimum pt cut.
 * Usage:
 * 
 * module selectedCands = PdgIdCandSelector {
 *   InputTag src = myCollection
 *   vint32 pdgId = { 15.0
 * };
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "PhysicsTools/UtilAlgos/interface/PdgIdSelector.h"
#include "DataFormats/Candidate/interface/Candidate.h"

typedef SingleObjectSelector<
          reco::CandidateCollection,
          PdgIdSelector<reco::Candidate>
        > PdgIdCandSelector;

DEFINE_FWK_MODULE( PdgIdCandSelector );
