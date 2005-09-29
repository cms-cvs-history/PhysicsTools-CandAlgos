// $Id: TrackCandidateProducer.cc,v 1.4 2005/09/29 00:23:33 llista Exp $

#include "PhysicsTools/CandAlgos/src/TrackCandidateProducer.h"
#include "PhysicsTools/DSTCandidate/interface/DSTCandidate.h"
#include "DataFormats/DSTTrack/interface/Track.h"
#include "FWCore/Framework/interface/Handle.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <iostream>
#include <cmath>
using namespace phystools;
using namespace edm;
using namespace dst;
using namespace std;

// pion mass. Should be taken from a table...
const double TrackCandidateProducer::defaultMass = 0.13956995; 

TrackCandidateProducer::TrackCandidateProducer( const ParameterSet & p ) :
  source( p.getParameter<string>( "src" ) ),
  massSqr( p.getUntrackedParameter<double>( "mass", defaultMass ) ) {
  produces<Candidates>();
  massSqr *= massSqr;
}
	  
void TrackCandidateProducer::produce( Event& evt, const EventSetup& ) {
  typedef vector<Track> Tracks;
  Handle<Tracks> tracks;
  try {
    evt.getByLabel( source, tracks );
  } catch ( exception e ) {
    cerr << "Error: can't get collection " << source << endl;
  }
  
  auto_ptr<Candidates> cands( new Candidates );
  const edm::EventID cid = evt.id();
  const edm::ProductID pid = tracks.provenance()->product.productID_;
  int idx = 0;
  for( Tracks::const_iterator trk = tracks->begin(); trk != tracks->end(); ++ trk ) {
    const Track::Vector & p = trk->inner().momentum();
    double x = p.x(), y = p.y(), z = p.z();
    double t = sqrt( massSqr + p.mag2() );
    DSTCandidate * c = new DSTCandidate( Candidate::LorentzVector( x, y, z, t ), trk->charge() );
    c->setTrack( DSTCandidate::TrackRef( cid, pid, idx ++ ) );
    cands->push_back( c );
  }
  evt.put( cands );
}
