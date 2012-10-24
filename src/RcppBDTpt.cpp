// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTpt.cpp: Rcpp and Boost Date_Time glue for posix time
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

// define template specialisations for as and wrap
namespace Rcpp {
    template <> boost::posix_time::ptime as( SEXP dtsexp ) {
        Rcpp::Datetime dt(dtsexp);
        boost::posix_time::ptime pt(boost::gregorian::date(dt.getYear(), dt.getMonth(), dt.getDay()), 
                                    boost::posix_time::time_duration(dt.getHours(), dt.getMinutes(), dt.getSeconds(), dt.getMicroSeconds()/1000.0));
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
    if( ! op.compare("+") ){
        return new bdtPt( e1.m_pt + e2.m_td ) ;   
    } else if( ! op.compare("-") ){
        return new bdtPt( e1.m_pt - e2.m_td ) ;
    }
    Rf_error( "operator not implemented" )  ;
    // not reached
    return new bdtPt();
}

bool compare_bdtPt_bdtPt(const bdtPt& e1, const bdtPt& e2, std::string op) {
    if( !op.compare( "==" ) ){
        return e1.m_pt == e2.m_pt ;   
    } else if( !op.compare( "!=" ) ){
        return e1.m_pt != e2.m_pt ;
    } else if( !op.compare( ">" ) ){
        return e1.m_pt > e2.m_pt ;
    } else if( !op.compare( "<" ) ){
        return e1.m_pt < e2.m_pt ;
    } else if( !op.compare( ">=" ) ){
        return e1.m_pt >= e2.m_pt ;
    } else if( !op.compare( "<=" ) ){
        return e1.m_pt <= e2.m_pt ;
    }
    Rf_error("unknown operator in bdtPt comparison");
    return R_NilValue ;
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
    Rcpp::function("compare_bdtPt_bdtPt",	&compare_bdtPt_bdtPt);
}
