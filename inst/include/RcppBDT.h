// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppBDT.h: Rcpp and Boost Date_Time glue
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
//
// This file is part of RcppBDT.
//
// RcppBDT is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//                           
// RcppBDT is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RcppBDT.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RCPPBDT__RCPPBDT_H
#define RCPPBDT__RCPPBDT_H

#include <RcppCommon.h>

// this variable governs whether we need to link against 
#define UseWithStrings 0

//#include <boost/date_time.hpp>

#if UseWithString
  #include <boost/date_time/gregorian/gregorian.hpp> 	// Gregorian calendar types, including I/O
#else
  #include <boost/date_time/gregorian/gregorian_types.hpp> 	// Gregorian calendar types, no I/O
#endif

namespace Rcpp {
    // non-intrusive extension via template specialisation
    template <> boost::gregorian::date as( SEXP dt ) throw(not_compatible);

    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const boost::gregorian::date &d) throw(not_compatible);
}

#include <Rcpp.h>

#endif
