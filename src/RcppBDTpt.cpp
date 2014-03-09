// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTpt.cpp: Rcpp and Boost Date_Time glue for posix time
//
// Copyright (C) 2012 - 2014  Dirk Eddelbuettel and Romain Francois
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

// define template specialisations for as and wrap
namespace Rcpp {
    template <> boost::posix_time::ptime as(SEXP dtsexp) {
        Rcpp::Datetime dt(dtsexp);
        boost::posix_time::ptime pt(boost::gregorian::date(dt.getYear(), dt.getMonth(), dt.getDay()), 
                                    boost::posix_time::time_duration(dt.getHours(), 
                                                                     dt.getMinutes(), 
                                                                     dt.getSeconds(), 
                                                                     dt.getMicroSeconds()*1000.0));
        return pt;
    }

    template <> SEXP wrap(const boost::posix_time::ptime &dt) {
        boost::posix_time::ptime epoch(boost::gregorian::date(1970,1,1)); // TODO: cache this value...
        boost::posix_time::time_duration x = dt - epoch; 	// this needs a UTC to local correction, but we get the fractional seconds
        struct tm t = boost::posix_time::to_tm(dt);      	// this helps with UTC conversion
        return Rcpp::wrap(Rcpp::Datetime( mktime(&t) + 1.0 * x.fractional_seconds() / x.ticks_per_second()));
    }
}

bdtPt* arith_bdtPt_bdtDu(const bdtPt& e1, const bdtDu& e2, std::string op){
    if (!op.compare("+")) {
        return new bdtPt(e1.m_pt + e2.m_td);   
    } else if(!op.compare("-")) {
        return new bdtPt(e1.m_pt - e2.m_td);
    }
    Rcpp::stop("only operators '+' and '-' supported betweeb posix time and duration");
    return new bdtPt();    // not reached
}

bdtPt* arith_bdtDu_bdtPt(const bdtDu& e1, const bdtPt& e2, std::string op) {
    if (!op.compare("+")) {
        return new bdtPt( e2.m_pt + e1.m_td ) ;   
    }
    // e1 - e2, ie duration - ptime, makes no sense 
    Rcpp::stop("only operator '+' permitted between duration and posix time");
    return new bdtPt();    // not reached
}

bool compare_bdtPt_bdtPt(const bdtPt& e1, const bdtPt& e2, std::string op) {
    if (!op.compare("==")) {
        return e1.m_pt == e2.m_pt;   
    } else if(!op.compare("!=")) {
        return e1.m_pt != e2.m_pt ;
    } else if(!op.compare(">")) {
        return e1.m_pt > e2.m_pt ;
    } else if(!op.compare("<")) {
        return e1.m_pt < e2.m_pt ;
    } else if(!op.compare(">=")) {
        return e1.m_pt >= e2.m_pt ;
    } else if(!op.compare("<=")) {
        return e1.m_pt <= e2.m_pt ;
    }
    Rcpp::stop("unknown operator between posix time objects");
    return R_NilValue ;
}

#if 0
// scalar case
bdtPt* arith_bdtPt_double(const bdtPt& e1, const double& d, std::string op){
    int secs = static_cast<int>(d);
    int fracs = (d - secs) *  boost::posix_time::time_duration::ticks_per_second();
    //REprintf("%f -> %d %d\n", d, secs, fracs);
    boost::posix_time::time_duration td(0, 0, secs, fracs);
    if (! op.compare("+")) {
        return new bdtPt(e1.m_pt + td);   
    } else if(!op.compare("-")) {
        return new bdtPt(e1.m_pt - td);
    }
    Rcpp::stop("operator not implemented between posix time and double");
    return new bdtPt();    // not reached
}
#endif

// vector case: e1 could be vector, d could be vector, need to check
// a) both are vector: same length?
// b) either one is vector, other is scalar
// c) both are scalar
// all three could be generalized if we assumed vector on vector returning vector
bdtPt* arith_bdtPt_double(const bdtPt& e1, const std::vector<double>& d, std::string op){
    int secs = static_cast<int>(d[0]);
    int fracs = (d[0] - secs) *  boost::posix_time::time_duration::ticks_per_second();
    //REprintf("%f -> %d %d\n", d, secs, fracs);
    boost::posix_time::time_duration td(0, 0, secs, fracs);
    if (!op.compare("+")) {
        return new bdtPt(e1.m_pt + td);   
    } else if(!op.compare("-")) {
        return new bdtPt(e1.m_pt - td);
    }
    Rcpp::stop("operator not implemented between posix time and double");
    return new bdtPt();    // not reached
}

bdtPt* arith_double_bdtPt(const double& d, const bdtPt& e1, std::string op){
    int secs = static_cast<int>(d);
    int fracs = (d - secs) *  boost::posix_time::time_duration::ticks_per_second();
    boost::posix_time::time_duration td(0, 0, secs, fracs);
    if( ! op.compare("+") ){
        return new bdtPt(e1.m_pt + td);   
    } else if( ! op.compare("-") ) {
        return new bdtPt(e1.m_pt - td);
    }
    Rf_error("operator not implemented");
    return new bdtPt();    // not reached
}


RCPP_MODULE(bdtPtMod) {
    Rcpp::class_<bdtPt>("bdtPt")   
	
        .constructor("default constructor setting current local time")  
        .constructor<SEXP>("constructor using R Datetime")
        .constructor<double>("constructor from numeric via Datetime")
        .constructor<int,int,int,int,int,int,int>("constructor with year, month, day, hours, minutes, seconds and fractional_seconds")  

        .method("setFromLocalTimeInSeconds",      &bdtPt::setFromLocalTimeInSeconds,      "set from local time with seconds")
        .method("setFromUTCInSeconds",            &bdtPt::setFromUTCInSeconds,            "set from UTC with seconds")
        .method("setFromLocalTimeInMicroSeconds", &bdtPt::setFromLocalTimeInMicroSeconds, "set from local time with microseconds")
        .method("setFromUTCInMicroSeconds",       &bdtPt::setFromUTCInMicroSeconds,       "set from UTC with microseconds")

        .method("setFromTimeT",                   &bdtPt::setFromTimeT,                   "set from POSIXTct")  

        .method("setFromDatetime",                &bdtPt::setFromDatetime,                "set from Datetime representation")

        .method("getDatetime",                    &bdtPt::getDatetime,                    "get datetime representation")
        .method("getDate",                        &bdtPt::getDate,                        "get date representation")

        .method("addHours",                       &bdtPt::addHours,                       "add given hours to posix time object")
        .method("addMinutes",                     &bdtPt::addMinutes,                     "add given minutes to posix time object")
        .method("addSeconds",                     &bdtPt::addSeconds,                     "add given seconds to posix time object")
        .method("addFractionalSeconds",           &bdtPt::addFractionalSeconds,           "add given fractional seconds to posix time object")

    ;

    Rcpp::function("arith_bdtPt_bdtDu", 	&arith_bdtPt_bdtDu); 
    Rcpp::function("arith_bdtDu_bdtPt", 	&arith_bdtDu_bdtPt); 
    Rcpp::function("compare_bdtPt_bdtPt",	&compare_bdtPt_bdtPt);
    Rcpp::function("arith_bdtPt_double", 	&arith_bdtPt_double); 
    Rcpp::function("arith_double_bdtPt", 	&arith_double_bdtPt); 
}

