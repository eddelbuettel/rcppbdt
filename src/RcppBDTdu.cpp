// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdu.cpp: Rcpp and Boost Date_Time glue for durations
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

class bdtDu {

public:

    bdtDu(int hours, int minutes, int seconds, int fractionalseconds) : m_td(hours, minutes, seconds, fractionalseconds) { }

    long getHours()             { return(m_td.hours()); }
    long getMinutes()           { return(m_td.minutes()); }
    long getSeconds()           { return(m_td.seconds()); }
    long getTotalSeconds()      { return(m_td.total_seconds()); }
    long getTotalMilliSeconds() { return(m_td.total_milliseconds()); }
    long getTotalMicroSeconds() { return(m_td.total_microseconds()); }
    long getTotalNanoSeconds()  { return(m_td.total_nanoseconds()); }
    long getFractionalSeconds() { return(m_td.fractional_seconds()); }
    unsigned short getNumFractionalDigits() { return(m_td.num_fractional_digits()); }
    long getTicksPerSecond()    { return(m_td.ticks_per_second()); }

    void addHours(int h)        { m_td += boost::posix_time::hours(h); }
    void addMinutes(int m)      { m_td += boost::posix_time::minutes(m); }
    void addSeconds(int s)      { m_td += boost::posix_time::seconds(s); }
    void addMilliSeconds(int s) { m_td += boost::posix_time::milliseconds(s); }
    void addMicroSeconds(int s) { m_td += boost::posix_time::microseconds(s); }
    void addNanoSeconds(int s)  { m_td += boost::posix_time::nanoseconds(s); }
            
private:
    boost::posix_time::time_duration m_td;
            
};

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
    ;
}
