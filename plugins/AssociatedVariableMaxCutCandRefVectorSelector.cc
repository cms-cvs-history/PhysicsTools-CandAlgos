/* \class AssociatedVariableMaxCutCandRefVectorSelector
 * 
 * Candidate Selector based on a maximun cut on an
 * associated variable (e.g.: isolation), and saver a 
 * collection of references.
 *
 * Usage:
 * 
 * module selectedCands = AssociatedVariableMaxCutCandRefVectorSelector {
 *   InputTag src = myCollection
 *   double max = 0.2
 * }
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "PhysicsTools/UtilAlgos/interface/PairSelector.h"
#include "PhysicsTools/UtilAlgos/interface/RefSelector.h"
#include "PhysicsTools/UtilAlgos/interface/AnySelector.h"
#include "PhysicsTools/UtilAlgos/interface/MaxSelector.h"
#include "DataFormats/Candidate/interface/Candidate.h"

typedef double isolation;

typedef SingleObjectSelector<
          edm::AssociationVector<reco::CandidateRefProd, std::vector<isolation> >,
          PairSelector<
            RefSelector<AnySelector<reco::Candidate> >,
            MaxSelector<isolation>
          >,
          reco::CandidateRefVector
        > AssociatedVariableMaxCutCandRefVectorSelector;

DEFINE_FWK_MODULE( AssociatedVariableMaxCutCandRefVectorSelector );