// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTtz.h: Rcpp and Boost Date_Time time zone class 
//
// Copyright (C) 2012  Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPPBDT__RCPPBDTTZ_H
#define RCPPBDT__RCPPBDTTZ_H

class bdtTz {

public:

    bdtTz(std::string region) : m_tzone(region) {
	// nice little trick: evaluate a Language() object corresponding to the R call
	//    system.file("data", "date_time_zonespec.csv", package="RcppBDT")
	// but from C++
	Rcpp::Language ll = Rcpp::Language("system.file", "extdata", "date_time_zonespec.csv", 
					   Rcpp::Named("package","RcppBDT"));
	std::string zonefile = Rcpp::as<std::string>(ll.eval(R_GlobalEnv));
    	m_tz.load_from_file(zonefile); 			// load db from csv zonefile
    	m_tzp = m_tz.time_zone_from_region(region);	// init with given region
        if (m_tzp == NULL) 
            ::Rf_error("Unknown region supplied, no tz object created");
    }

    std::vector<std::string> getAllRegions() { return( m_tz.region_list() ); }

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
    std::string getRegion()        { return(m_tzone);                  }
    bool        hasDst()           { return(m_tzp->has_dst());         }
    std::string getPosixString()   { return(m_tzp->to_posix_string()); }

    // we (currently ?) cannot return Rcpp::Datetime with a tzone attribute, though returning a SEXP works
    // SEXP getDstStart(const int year) {
    //     boost::posix_time::ptime t = m_tzp->dst_local_start_time(year);
    //     boost::posix_time::ptime epoch(boost::gregorian::date(1970,1,1));
    //     boost::posix_time::time_duration::sec_type x = // need to correct difference to epoch by UTC offset
    //         (t - epoch - m_tzp->base_utc_offset()).total_seconds();
    //     Rcpp::RObject dt = Rcpp::wrap(Rcpp::Datetime(x));
    //     dt.attr("tzone") = m_tzone;
    //     return dt;
    // }
    Rcpp::Datetime getDstLocalStart(const int year) { 
        return Rcpp::wrap( m_tzp->dst_local_start_time(year) ); 	// uses posix_time::ptime wrap()
    }
    // SEXP getDstEnd(const int year) {
    //     boost::posix_time::ptime t = m_tzp->dst_local_end_time(year);
    //     boost::posix_time::ptime epoch(boost::gregorian::date(1970,1,1));
    //     boost::posix_time::time_duration::sec_type x = // need to correct difference to epoch by UTC offset
    //         (t - epoch - m_tzp->base_utc_offset()).total_seconds();
    //     Rcpp::RObject dt = Rcpp::wrap(Rcpp::Datetime(x));
    //     dt.attr("tzone") = m_tzone;
    //     return dt;
    // }
    Rcpp::Datetime getDstLocalEnd(const int year) {
        return Rcpp::wrap(m_tzp->dst_local_end_time(year));		// uses posix_time::ptime wrap()
    }

private:

    bdtTz() {};			// hide default constructor
    std::string m_tzone;

    boost::local_time::tz_database m_tz;
    boost::local_time::time_zone_ptr m_tzp;
};

#endif
