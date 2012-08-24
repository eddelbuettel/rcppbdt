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

class bdtTz {

public:

    bdtTz(std::string region) {
	// nice little trick: evaluate a Language() object corresponding to the R call
	//    system.file("data", "date_time_zonespec.csv", package="RcppBDT")
	// but from C++
	Rcpp::Language ll = Rcpp::Language("system.file", "data", 
					   "date_time_zonespec.csv", 
					   Rcpp::Named("package","RcppBDT"));
	std::string zonefile = Rcpp::as<std::string>(ll.eval(R_GlobalEnv));

    	m_tz.load_from_file(zonefile); 			// load db from csv zonefile
    	m_tzp = m_tz.time_zone_from_region(region);	// init with given region
    }

    std::vector<std::string> getRegions() { return( m_tz.region_list() ); }

    long getUtcTotalSec() {
	boost::posix_time::time_duration tdt = m_tzp->base_utc_offset();
	return(tdt.total_seconds());
    }

    long getDstTotalSec() {
	boost::posix_time::time_duration tdt = m_tzp->dst_offset();
	return(tdt.total_seconds());
    }

    std::string getDstZoneAbbrev() { return(m_tzp->dst_zone_abbrev()); }
    std::string getStdZoneAbbrev() { return(m_tzp->std_zone_abbrev()); }
    std::string getDstZoneName()   { return(m_tzp->dst_zone_name());   }
    std::string getStdZoneName()   { return(m_tzp->std_zone_name());   }
    bool        hasDst()           { return(m_tzp->has_dst());         }
    std::string getPosixString()   { return(m_tzp->to_posix_string()); }

private:

    bdtTz() {};			// hide default constructor

    boost::local_time::tz_database m_tz;
    boost::local_time::time_zone_ptr m_tzp;
};


RCPP_MODULE(bdtTzMod) {

    Rcpp::class_<bdtTz>("bdtTz")   
	
    .constructor<std::string>("constructor with region string (eg \"Europe/London\")")  

    .method("getRegions",       &bdtTz::getRegions,       "get vector of TZ region names")

    .method("getUtcOffset",     &bdtTz::getUtcTotalSec,   "get UTC offset in seconds")
    .method("getDstOffset",     &bdtTz::getDstTotalSec  , "get DST offset in seconds")

    .method("getDstZoneAbbrev", &bdtTz::getDstZoneAbbrev, "get DST zone abbreviation")
    .method("getStdZoneAbbrev", &bdtTz::getStdZoneAbbrev, "get standard zone abbreviation")
    .method("getDstZoneName",   &bdtTz::getDstZoneName,   "get DST zone name")
    .method("getStdZoneName",   &bdtTz::getStdZoneName,   "get standard zone name")
    .method("hasDst",           &bdtTz::hasDst,           "true if timezone has daylight savings")
    .method("getPosixString",   &bdtTz::getPosixString,   "get posix time zone representation")

    ;

}








