// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTtz.cpp: Rcpp and Boost Date_Time glue for timezones
//
// Copyright (C) 2012        Dirk Eddelbuettel and Romain Francois
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

#include <RcppBDT.h>

void tzSetDB(boost::local_time::tz_database *tz, std::string file) {
    tz->load_from_file(file);
}

Rcpp::CharacterVector tzGetRegions(boost::local_time::tz_database *tz) {
    std::vector<std::string> regions = tz->region_list();
    Rcpp::StringVector vec(regions.begin(), regions.end());
    return(vec);		// Rcpp::wrap() called implicitly
}

SEXP tzGetTotalSecondsFromUTC(boost::local_time::tz_database *tz, std::string region) {
    boost::local_time::time_zone_ptr tzp = tz->time_zone_from_region(region);
    boost::posix_time::time_duration tdt = tzp->base_utc_offset();
    long offset = tdt.total_seconds();
    //std::cout << tdt << " -- " << offset << std::endl;
    return(Rcpp::wrap(offset));
}

SEXP tzGetDstTotalSeconds(boost::local_time::tz_database *tz, std::string region) {
    boost::local_time::time_zone_ptr tzp = tz->time_zone_from_region(region);
    boost::posix_time::time_duration tdt = tzp->dst_offset();
    long offset = tdt.total_seconds();
    //std::cout << tdt << " -- " << offset << std::endl;
    return(Rcpp::wrap(offset));
}

RCPP_MODULE(bdtTzMod) {

    using namespace boost::local_time;
    using namespace Rcpp;

    // exposing a class (boost::gregorian::)date as "bdtTz" on the R side
    class_<tz_database>("bdtTz")
	
    // constructors
    .constructor("default constructor")  // needs to invalidate as we need a tz file

    .method("setDB", &tzSetDB, "load time zone database from file")

    .method("getRegions", &tzGetRegions, "get vector of TZ region names")

    .method("getUtcOffsetInSeconds", &tzGetTotalSecondsFromUTC)
    .method("getDstOffsetInSeconds", &tzGetDstTotalSeconds)

    ;

}








