#ifndef CandAlgos_CandDecaySelector_h
#define CandAlgos_CandDecaySelector_h
/* \class helper::CandDecayStoreManager
 *
 * \author: Luca Lista, INFN
 *
 */
#include "DataFormats/Candidate/interface/CompositeRefCandidate.h"
#include "PhysicsTools/UtilAlgos/interface/ObjectSelector.h"

namespace helper {
  class CandDecayStoreManager {
  public:
    typedef reco::CandidateCollection collection;
    CandDecayStoreManager() :
      selCands_( new reco::CandidateCollection ) {
    }
    template<typename I>
    void cloneAndStore( const I & begin, const I & end, edm::Event & evt ) {
      using namespace reco;
      CandidateRefProd cands = evt.getRefBeforePut<CandidateCollection>();
      for( I i = begin; i != end; ++ i )
	add( cands, * * i );
    }
    edm::OrphanHandle<reco::CandidateCollection> put( edm::Event & evt ) {
      return evt.put( selCands_ );
    }
    size_t size() const { return selCands_->size(); }
    
  private:
    reco::CandidateRef add( reco::CandidateRefProd cands, const reco::Candidate & c ) {
      using namespace reco;
      std::auto_ptr<CompositeRefCandidate> cmp( new CompositeRefCandidate( c ) );
      CompositeRefCandidate * p = cmp.get();
      CandidateRef ref( cands, selCands_->size() );
      selCands_->push_back( cmp );
      size_t n = c.numberOfDaughters(); 
      for( size_t i = 0; i < n; ++ i )
	p->addDaughter( add( cands, * c.daughter( i ) ) );
      return ref;
    }
    std::auto_ptr<reco::CandidateCollection> selCands_;
  };
  
  template<>
  struct StoreManagerTrait<reco::CandidateCollection> {
    typedef CandDecayStoreManager type;
    typedef ObjectSelectorBase<reco::CandidateCollection> base;
  };

}

#endif