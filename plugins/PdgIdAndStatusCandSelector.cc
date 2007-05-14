/* \class PdgIdAndStatusCandSelector
 * 
 * Candidate Selector based on a pdgId set
 * Usage:
 * 
 * module leptons = PdgIdAndStatusCandSelector {
 *   InputTag src = myCollection
 *   vint32 pdgId = { 11, 13 }
 *   vint32 status = { 1 }
 * };
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "PhysicsTools/UtilAlgos/interface/AndSelector.h"
#include "PhysicsTools/UtilAlgos/interface/PdgIdSelector.h"
#include "PhysicsTools/UtilAlgos/interface/StatusSelector.h"
#include "DataFormats/Candidate/interface/Candidate.h"

typedef SingleObjectSelector<
          reco::CandidateCollection,
          AndSelector<
            PdgIdSelector<reco::Candidate>,
            StatusSelector<reco::Candidate>
          >
        > PdgIdAndStatusCandSelector;

DEFINE_FWK_MODULE( PdgIdAndStatusCandSelector );
