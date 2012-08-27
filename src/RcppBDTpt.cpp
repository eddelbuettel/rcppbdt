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

// this enables use of nanoseconds 
#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG 1

#include <RcppBDT.h>

class bdtPt {

public:
    bdtPt() { }                    			// default empty constructor 
    bdtPt(int year, int month, int day, 		// constructor from date and duration
          int hours, int minutes, int seconds, 
          int fractionalseconds) : m_pt(boost::gregorian::date(year, month, day), 
                                        boost::posix_time::time_duration(hours, minutes, seconds, fractionalseconds)) { }
    
    void setFromLocalTimeInSeconds()      { m_pt = boost::posix_time::second_clock::local_time(); }
    void setFromUTCInSeconds()            { m_pt = boost::posix_time::second_clock::universal_time(); }
    void setFromLocalTimeInMicroSeconds() { m_pt = boost::posix_time::microsec_clock::local_time(); }
    void setFromUTCInMicroSeconds()       { m_pt = boost::posix_time::microsec_clock::universal_time(); }
                                    
    void setFromTimeT(const time_t t)     { m_pt = boost::posix_time::from_time_t(t); }

    Rcpp::Date getDate() { 
        boost::gregorian::date::ymd_type ymd = m_pt.date().year_month_day();     // convert to date and then to y/m/d struct
        return Rcpp::Date( ymd.year, ymd.month, ymd.day );
    }
    Rcpp::Datetime getDatetime() {
        boost::posix_time::ptime epoch(boost::gregorian::date(1970,1,1));
        boost::posix_time::time_duration x = m_pt - epoch;
        return Rcpp::Datetime( x.total_seconds() + 1.0 * x.fractional_seconds() / x.ticks_per_second() );
    }

private:
    boost::posix_time::ptime m_pt; 		// private ptime instace

};

RCPP_MODULE(bdtPtMod) {
    Rcpp::class_<bdtPt>("bdtPt")   
	
        .constructor("default constructor not setting a value")  
        .constructor<int,int,int,int,int,int,int>("constructor with year, month, day, hours, minutes, seconds and fractional_seconds")  

        .method("setFromLocalTimeInSeconds",      &bdtPt::setFromLocalTimeInSeconds,      "set from local time with seconds")
        .method("setFromUTCInSeconds",            &bdtPt::setFromUTCInSeconds,            "set from UTC with seconds")
        .method("setFromLocalTimeInMicroSeconds", &bdtPt::setFromLocalTimeInMicroSeconds, "set from local time with microseconds")
        .method("setFromUTCInMicroSeconds",       &bdtPt::setFromUTCInMicroSeconds,       "set from UTC with microseconds")

        .method("setFromTimeT",                   &bdtPt::setFromTimeT,                   "set from POSIXTct")  

        .method("getDate",                        &bdtPt::getDate,                        "get date representation")
        .method("getDatetime",                    &bdtPt::getDatetime,                    "get datetime representation")
    ;
}
