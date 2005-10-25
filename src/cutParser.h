#if !defined(PACKAGE_CUTPARSER_H)
#define PACKAGE_CUTPARSER_H
// -*- C++ -*-
//
// Package:     <package>
// Module:      cutParser
// 
/**\class cutParser cutParser.h package/cutParser.h

 Description: <one line class summary>

 Usage:
    <usage>

*/
//
// Author:      Chris D Jones
// Created:     Sun Aug  7 20:45:51 EDT 2005
// $Id: cutParser.h,v 1.1 2005/10/24 12:59:52 llista Exp $
//
// Revision history
//
// $Log: cutParser.h,v $
// Revision 1.1  2005/10/24 12:59:52  llista
// moved from CandUtils
//
// Revision 1.1  2005/10/21 13:56:43  llista
// added Chris Jones cut parser
//
#include "PhysicsTools/Candidate/interface/Candidate.h"
#include <string>
#include <boost/shared_ptr.hpp>
#include <map>

namespace aod {
  typedef double ( aod::Candidate::* PCandMethod )() const;
  typedef std::map<std::string, PCandMethod> CandidateMethods;
  
  bool cutParser( const std::string & iString,
		  const CandidateMethods & iMethods,
		  boost::shared_ptr<aod::Candidate::selector> & oCut );
}

#endif /* PACKAGE_CUTPARSER_H */
