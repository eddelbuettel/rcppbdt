// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdu.cpp: Rcpp and Boost Date_Time glue for durations
//
// Copyright (C) 2012 - 2013  Dirk Eddelbuettel and Romain Francois
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

bdtDu* hours(int h)		{ return new bdtDu(boost::posix_time::hours(h)); }
bdtDu* minutes(int m)		{ return new bdtDu(boost::posix_time::minutes(m)); }
bdtDu* seconds(int s)		{ return new bdtDu(boost::posix_time::seconds(s)); }
bdtDu* milliseconds(int ms)	{ return new bdtDu(boost::posix_time::milliseconds(ms)); }
bdtDu* microseconds(int ms)	{ return new bdtDu(boost::posix_time::microseconds(ms)); }
bdtDu* nanoseconds(int ms) 	{ return new bdtDu(boost::posix_time::nanoseconds(ms)); }
  
bdtDu* arith_bdtDu_bdtDu(const bdtDu& e1, const bdtDu& e2, std::string op) {
    if (!op.compare("+")) {
        return new bdtDu(e1.m_td + e2.m_td);   
    } else if (!op.compare("-")) {
        return new bdtDu(e1.m_td - e2.m_td);
    }
    Rcpp::stop("Only operators '+' and '-' supported between durations");
    return new bdtDu(0,0,0,0);		// not reached
}

bdtDu* arith_bdtDu_int(const bdtDu& e1, const int e2, std::string op) {
    if (!op.compare("*")) {
        return new bdtDu(e1.m_td * e2);   
    } else if(!op.compare("/")) {
        return new bdtDu(e1.m_td / e2);
    } else if(!op.compare("+")) {
        return new bdtDu(e1.m_td + boost::posix_time::time_duration(0,0,e2,0));
    } else if(!op.compare("-")) {
        return new bdtDu(e1.m_td - boost::posix_time::time_duration(0, 0, e2, 0));
    }
    Rcpp::stop("operator not implemented between duration and int");
    return new bdtDu(0,0,0,0);		// not reached

}

bdtDu* arith_int_bdtDu(const int e1, const bdtDu& e2, std::string op) {
    if (!op.compare("*")) {
        return new bdtDu( e2.m_td * e1 ) ;   
    // } else if( ! op.compare("/") ){
    //     return new bdtDu( e1.m_td / e2 ) ;
    } else if (!op.compare("+")) {
        return new bdtDu(e2.m_td + boost::posix_time::time_duration(0,0,e1,0));
    // } else if( ! op.compare("-") ){
    //     return new bdtDu(e1.m_td - boost::posix_time::time_duration(0, 0, e2, 0));
    }
    Rcpp::stop("operator not implemented between int and duration");
    return new bdtDu(0,0,0,0);		// not reached
}

bool compare_bdtDu_bdtDu( const bdtDu& e1, const bdtDu& e2, std::string op ){
    if (!op.compare("==")) {
        return e1.m_td == e2.m_td;   
    } else if(!op.compare("!=")) {
        return e1.m_td != e2.m_td;
    } else if(!op.compare(">")) {
        return e1.m_td > e2.m_td;
    } else if(!op.compare("<")) {
        return e1.m_td < e2.m_td ;
    } else if(!op.compare(">=")) {
        return e1.m_td >= e2.m_td ;
    } else if(!op.compare("<=")) {
        return e1.m_td <= e2.m_td ;
    }
    Rcpp::stop("unknown operator betweeb two durations");
    return R_NilValue ;
}


RCPP_MODULE(bdtDuMod) {
    Rcpp::class_<bdtDu>("bdtDu")   
	
        .constructor<int,int,int,int>("constructor with hours, minutes, seconds and fractional_seconds")  

        .method("getHours",               &bdtDu::getHours,               "get hours of the time duration")
        .method("getMinutes",             &bdtDu::getMinutes,             "get minutes of the time duration")
        .method("getSeconds",             &bdtDu::getSeconds,             "get seconds of the time duration")
        .method("getTotalSeconds",        &bdtDu::getTotalSeconds,        "get total seconds of the time duration")
        .method("getTotalMilliSeconds",   &bdtDu::getTotalMilliSeconds,   "get total milli seconds of the time duration")
        .method("getTotalMicroSeconds",   &bdtDu::getTotalMicroSeconds,   "get total micro seconds of the time duration")
        .method("getTotalNanoSeconds",    &bdtDu::getTotalNanoSeconds,    "get total nano seconds of the time duration")
        .method("getFractionalSeconds",   &bdtDu::getFractionalSeconds,   "get fractional seconds of time duration")

        .method("getNumFractionalDigits", &bdtDu::getNumFractionalDigits, "get number of fractional seconds (6 or 9)")
        .method("getTicksPerSecond",      &bdtDu::getTicksPerSecond,      "get number of fractional seconds (10^6 or 10^9)")

        .method("addHours",               &bdtDu::addHours,               "add given hours to duration object")
        .method("addMinutes",             &bdtDu::addMinutes,             "add given minutes to duration object")
        .method("addSeconds",             &bdtDu::addSeconds,             "add given seconds to duration object")
        .method("addMilliSeconds",        &bdtDu::addMilliSeconds,        "add given milliseconds to duration object")
        .method("addMicroSeconds",        &bdtDu::addMicroSeconds,        "add given microseconds to duration object")
        .method("addNanoSeconds",         &bdtDu::addNanoSeconds,         "add given nanoseconds to duration object")
        .method("getAddedPosixtime",      &bdtDu::getAddedPosixtime,	  "adds duration to given posix time and returns posix time")
    ;
    
    Rcpp::function( "hours",            &hours ) ; 
    Rcpp::function( "minutes",          &minutes ) ; 
    Rcpp::function( "seconds",          &seconds ) ; 
    Rcpp::function( "milliseconds",     &milliseconds ) ; 
    Rcpp::function( "microseconds",     &microseconds ) ;
    Rcpp::function( "nanoseconds",      &nanoseconds ) ; 
    
    Rcpp::function( "arith_bdtDu_bdtDu",        &arith_bdtDu_bdtDu ) ; 
    Rcpp::function( "arith_bdtDu_int",          &arith_bdtDu_int ) ; 
    Rcpp::function( "arith_int_bdtDu",          &arith_int_bdtDu ) ; 
    Rcpp::function( "compare_bdtDu_bdtDu",      &compare_bdtDu_bdtDu );

}


