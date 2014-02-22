// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdu.h: Rcpp and Boost Date_Time duration class
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

#ifndef RCPPBDT__RCPPBDTDU_H
#define RCPPBDT__RCPPBDTDU_H

class bdtDu {

public:

    bdtDu(int hours, int minutes, int seconds, int fractionalseconds) : m_td(hours, minutes, seconds, fractionalseconds) { }
    bdtDu(boost::posix_time::time_duration td) : m_td(td) {} 
    bdtDu(const bdtDu& other) : m_td(other.m_td ){}
    
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
    Rcpp::Datetime getAddedPosixtime(SEXP ptsexp)  { 
        boost::posix_time::ptime pt(Rcpp::as<boost::posix_time::ptime>(ptsexp)); 
        pt += m_td;
        return Rcpp::wrap(pt); 
    }

private:
    boost::posix_time::time_duration m_td;

    friend bdtDu* arith_bdtDu_bdtDu(  const bdtDu&, const bdtDu&, std::string);
    friend bdtDu* arith_bdtDu_int(    const bdtDu&, const int,    std::string);
    friend bdtDu* arith_int_bdtDu(    const int,    const bdtDu&, std::string);
    friend bool   compare_bdtDu_bdtDu(const bdtDu&, const bdtDu&, std::string);
    friend bdtPt* arith_bdtPt_bdtDu(  const bdtPt&, const bdtDu&, std::string);
    friend bdtPt* arith_bdtDu_bdtPt(  const bdtDu&, const bdtPt&, std::string);
    friend bdtDt* arith_bdtDt_int(    const bdtDt&, const int&,   std::string);
};

#endif

