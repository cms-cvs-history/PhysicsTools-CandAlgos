#include "PluginManager/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/Parser/interface/SingleObjectSelector.h"
#include "PhysicsTools/Utilities/interface/PtMinSelector.h"
#include "PhysicsTools/UtilAlgos/interface/ObjectSelector.h"
#include "PhysicsTools/UtilAlgos/interface/SingleElementCollectionSelector.h"
#include "PhysicsTools/UtilAlgos/interface/Merger.h"
#include "PhysicsTools/CandAlgos/src/CandCombiner.h"
#include "PhysicsTools/CandAlgos/src/CandReducer.h"
#include "DataFormats/Candidate/interface/Candidate.h"

namespace cand {
  namespace modules {
    /// merge an arbitrary number of candidate collections  
    typedef Merger<reco::CandidateCollection> CandMerger;

    /// configurable single track selector
    typedef ObjectSelector<
              SingleElementCollectionSelector<
                reco::CandidateCollection, 
                SingleObjectSelector<reco::Candidate> 
              >
            > CandSelector;

    /// configurable single track selector
    typedef ObjectSelector<
              SingleElementCollectionSelector<
                reco::CandidateCollection, 
                PtMinSelector<reco::Candidate> 
              >
            > PtMinCandSelector;

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE( CandSelector );
DEFINE_ANOTHER_FWK_MODULE( PtMinCandSelector );
DEFINE_ANOTHER_FWK_MODULE( CandCombiner );
DEFINE_ANOTHER_FWK_MODULE( CandReducer );
DEFINE_ANOTHER_FWK_MODULE( CandMerger );
  }
}
