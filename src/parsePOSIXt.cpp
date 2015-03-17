// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// parsePOSIXt: Use Boost Date_Time to convert date(time) string to POSIXt
//
// Copyright (C) 2015  Dirk Eddelbuettel
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

#include <boost/date_time.hpp>
#include <Rcpp.h>

namespace bt = boost::posix_time;

const std::locale formats[] = {
    std::locale(std::locale::classic(), new bt::time_input_facet("%Y-%m-%d %H:%M:%S%f")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%Y%m%d %H%M%S%f")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%Y/%m/%d %H:%M:%S%f")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%m/%d/%Y %H:%M:%S%f")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%m-%d-%Y %H:%M:%S%f")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%d.%m.%Y %H:%M:%S%f")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%Y-%m-%d")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%Y%m%d")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%m/%d/%Y")),
    std::locale(std::locale::classic(), new bt::time_input_facet("%m-%d-%Y"))
};
const size_t nformats = sizeof(formats)/sizeof(formats[0]);

std::time_t pt_to_time_t(const bt::ptime& pt) {
    bt::ptime timet_start(boost::gregorian::date(1970,1,1));
    bt::time_duration diff = pt - timet_start;
    return diff.ticks()/bt::time_duration::rep_type::ticks_per_second;
}

double pt_to_double(const bt::ptime& pt) {
    bt::ptime timet_start(boost::gregorian::date(1970,1,1));
    bt::time_duration diff = pt - timet_start;
#if defined(BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG)
    return diff.total_nanoseconds()/1.0e9;
#else
    return diff.total_microseconds()/1.0e6;
#endif
}

//' This function uses the Boost Date_Time library to parse 
//' datetimes (and dates) from strings. It returns a 
//' \code{DatetimeVector} ie a vector of \sQuote{POSIXct} 
//' objects. 
//'
//' A numer of fixed formats are tried in succession. These include
//' the standard ISO format \sQuote{YYYY-MM-DD HH:MM:SS} as well as
//' different local variants including several forms popular in the 
//' United States.  Two-digits years and clearly ambigous formats such
//' as \sQuote{03/04/05} are ignored.  In the case of parsing failure
//' a \code{NA} value is returned.
//'
//' Fractional seconds are supported as well.  As R itself only supports 
//' microseconds, the Boost compile-time option for nano-second resolution 
//' has not been enabled.
//'
//' @title Parse POSIXct objects from character variables
//' @param sv A character vector with date(time) expressions
//' @param tz An optional character variable with a timezone expression, 
//' default is \sQuote{UTC}
//' @return A vector of \code{Datetime} objects with \sQuote{POSIXct} elements.
//' @author Dirk Eddelbuettel
//' @examples
//' times <- c("2004-03-21 12:45:33.123456",
//'           "2004/03/21 12:45:33.123456",
//'           "20040321 124533.123456",
//'           "21.03.2004 12:45:33.123456", 
//'           "03/21/2004 12:45:33.123456",
//'           "03-21-2004 12:45:33.123456", 
//'           "2004-03-21",
//'           "20040321",
//'           "03/21/2004",
//'           "03-21-2004")
//' parsePOSIXt(times)
//' format(parsePOSIXt(times), tz="UTC")
// [[Rcpp::export]]
Rcpp::DatetimeVector parsePOSIXt(Rcpp::CharacterVector sv, const std::string tz="UTC") {

    int n = sv.size();
    Rcpp::DatetimeVector pv(n);
    
    for (int j=0; j<n; j++) {
        bt::ptime pt, ptbase;
        std::string s(sv[j]);

        // loop over formats and try them til one fits
        for (size_t i=0; pt == ptbase && i < nformats; ++i) {
            std::istringstream is(s);
            is.imbue(formats[i]);
            is >> pt;
        }

        if (pt == ptbase) {
            pv[j] = NAN;
        } else { 
            pv[j] = pt_to_double(pt);
        }
    }
    //pv.attr("class") = Rcpp::CharacterVector::create("POSIXct", "POSIXt");
    //pv.attr("tzone") = tz;
    return pv;
}
