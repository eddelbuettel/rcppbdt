// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDT.h: Rcpp and Boost Date_Time glue
//
// Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois
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

// forward declarations and helping module classes 
RCPP_EXPOSED_CLASS(bdtDd)
RCPP_EXPOSED_CLASS(bdtDu)
RCPP_EXPOSED_CLASS(bdtDt)
RCPP_EXPOSED_CLASS(bdtPt)

// cf http://stackoverflow.com/a/15234757/143305
#define BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS 1

// Setting this variable enables use of nanoseconds (as opposed to microseconds)
// for the maximum resolution; this comes at a cost of 96 bits as opposed to 64 bits
// We enable it to experiement with it knowing that R already has a 64 bit resolution
// 
// Note that this fails on Windows (per R's win-builder.r-project.org) for lack of a
// long long int type, so we make this conditional on not being on Windows
#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG 1

// Setting this variable governs whether we need to link against the
// Boost Date.Time library (eg -lboost_date_time on Debian/Ubuntu) or
// not The functions not involving string parsing or conversion are
// all available via the templated Boost header files and are thus
// compile-time only which make things a little easier.
// On Windows, set the BOOSTLIB variable to point to a suitable directory.
// On other systems, just have Boost in the include path 
#define RcppBDT_UseWithStrings 0

#if RcppBDT_UseWithString
  #include <boost/date_time/gregorian/gregorian.hpp> 		// Gregorian calendar types, with I/O
#else
  #include <boost/date_time/gregorian/gregorian_types.hpp> 	// Gregorian calendar types, no I/O
#endif

#include <boost/date_time/local_time/local_time.hpp> 	 


namespace Rcpp {

    // First the 'date' class boost::gregorian::date
    //
    // non-intrusive extension via template specialisation
    template <> boost::gregorian::date as(SEXP dt);
    //
    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const boost::gregorian::date &d);


    // Second the 'datetime' class boost::posix_time::ptime
    //
    // non-intrusive extension via template specialisation
    template <> boost::posix_time::ptime as(SEXP dt);
    //
    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const boost::posix_time::ptime &dt);

}

#include <Rcpp.h>

#include <RcppBDTdd.h>
#include <RcppBDTdt.h>
#include <RcppBDTpt.h>
#include <RcppBDTdu.h>
#include <RcppBDTtz.h>

#endif
