// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdd.cpp: Rcpp and Boost Date_Time date duration ("days") class 
//
// Copyright (C) 2013  Dirk Eddelbuettel and Romain Francois
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

bdtDd* days(int d)		{ return new bdtDd(boost::gregorian::date_duration(d)); }
bdtDd* weeks(int w)		{ return new bdtDd(boost::gregorian::weeks(w)); }

bdtDd* arith_bdtDd_bdtDd(const bdtDd& e1, const bdtDd& e2, std::string op) {
    if (!op.compare("+")) {
        return new bdtDd(e1.m_dd + e2.m_dd);   
    } else if (!op.compare("-")) {
        return new bdtDd(e1.m_dd - e2.m_dd);
    }
    Rcpp::stop("Only operators '+' and '-' supported between two date durations");
    return new bdtDd(0);	// not reached
}

bdtDd* arith_bdtDd_int(const bdtDd& e1, const int& e2, std::string op) {
    if (!op.compare("+")) {
        return new bdtDd(e1.m_dd + boost::gregorian::date_duration(e2));
    } else if (! op.compare("-")) {
        return new bdtDd(e1.m_dd - boost::gregorian::date_duration(e2));
    }
    Rcpp::stop("Only operators '+' and '-' supported between date duration and int");
    return new bdtDd(0);    	// not reached
}

bdtDd* arith_int_bdtDd(const int& e1, const bdtDd& e2, std::string op) {
    if (! op.compare("+")) {
        return new bdtDd(e2.m_dd + boost::gregorian::date_duration(e1));
    }
    Rcpp::stop("Only operator '+' supported between int and date duration");
    return new bdtDd(0);    	// not reached
}

bool compare_bdtDd_bdtDd( const bdtDd& e1, const bdtDd& e2, std::string op ){
    if (!op.compare( "==" ) ){
        return e1.m_dd == e2.m_dd;   
    } else if (!op.compare("!=")) {
        return e1.m_dd != e2.m_dd;
    } else if (!op.compare(">")) {
        return e1.m_dd > e2.m_dd;
    } else if (!op.compare("<")) {
        return e1.m_dd < e2.m_dd;
    } else if (!op.compare(">=")) {
        return e1.m_dd >= e2.m_dd;
    } else if (!op.compare("<=")) {
        return e1.m_dd <= e2.m_dd;
    }
    Rcpp::stop("unknown operator between durations");
    return R_NilValue;
}

RCPP_MODULE(bdtDdMod) {
    Rcpp::class_<bdtDd>("bdtDd")   
        .constructor<int>("constructor with days")  
        // ?  .constructor<SEXP>("constructor with days")  
        .method("getDays",                   &bdtDd::getDays,               "get hours of the time duration")
    ;
    
    Rcpp::function( "days",                  &days); 
    Rcpp::function( "weeks",                 &weeks); 
    
    Rcpp::function( "arith_bdtDd_bdtDd",     &arith_bdtDd_bdtDd); 
    Rcpp::function( "arith_bdtDd_int",       &arith_bdtDd_int); 
    Rcpp::function( "arith_int_bdtDd",       &arith_int_bdtDd); 
    Rcpp::function( "compare_bdtDd_bdtDd",   &compare_bdtDd_bdtDd);
}
