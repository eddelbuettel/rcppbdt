// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDT.h: Rcpp and Boost Date_Time glue
//
// Copyright (C) 2010 - 2012  Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPPBDT__RCPPBDT_H
#define RCPPBDT__RCPPBDT_H

#include <RcppCommon.h>

// Setting this variable enables use of nanoseconds (as opposed to microseconds)
// for the maximum resolution; this comes at a cost of 96 bits as opposed to 64 bits
// We enable it to experiement with it knowing that R already has a 64 bit resolution
#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG 1

// Setting this variable governs whether we need to link against the
// Boost Date.Time library (eg -lboost_date_time on Debian/Ubuntu) or
// not The functions not involving string parsing or conversion are
// all available via the templated Boost header files and are thus
// compile-time only which make things a little easier.
// On Windows, set the BOOSTLIB variable to point to a suitable directory.
// On other systems, just have Boost in the include path 
#define RcppBDT_UseWithStrings 0

#if RcppBDT_UseWithString
  #include <boost/date_time/gregorian/gregorian.hpp> 		// Gregorian calendar types, with I/O
#else
  #include <boost/date_time/gregorian/gregorian_types.hpp> 	// Gregorian calendar types, no I/O
#endif

#include <boost/date_time/local_time/local_time.hpp> 	 


namespace Rcpp {

    // First the 'date' class boost::gregorian::date
    //
    // non-intrusive extension via template specialisation
    template <> boost::gregorian::date as(SEXP dt);
    //
    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const boost::gregorian::date &d);


    // Second the 'datetime' class boost::posix_time::ptime
    //
    // non-intrusive extension via template specialisation
    template <> boost::posix_time::ptime as(SEXP dt);
    //
    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const boost::posix_time::ptime &dt);
}

#include <Rcpp.h>


class bdtDu;

class bdtPt {

public:
    bdtPt() 				  { setFromLocalTimeInMicroSeconds(); }  	// default empty constructor 
    bdtPt(SEXP dt) 			  { setFromDatetime(dt); }     			// constructor from R's / Rcpp's Datetime
    bdtPt(double dt) 			  { setFromDouble(dt); }     			// constructor from double using Rcpp's Datetime
    bdtPt(int year, int month, int day, 			// constructor from date and duration
          int hours, int minutes, int seconds, 
          int fractionalseconds) : m_pt(boost::gregorian::date(year, month, day), 
                                        boost::posix_time::time_duration(hours, minutes, seconds, fractionalseconds)) { }
    bdtPt(boost::posix_time::ptime pt) : m_pt(pt) {} 
    bdtPt(const bdtPt& other) : m_pt(other.m_pt ) {}
    
    void setFromLocalTimeInSeconds()      { m_pt = boost::posix_time::second_clock::local_time(); }
    void setFromUTCInSeconds()            { m_pt = boost::posix_time::second_clock::universal_time(); }
    void setFromLocalTimeInMicroSeconds() { m_pt = boost::posix_time::microsec_clock::local_time(); }
    void setFromUTCInMicroSeconds()       { m_pt = boost::posix_time::microsec_clock::universal_time(); }
                                    
    void setFromTimeT(const time_t t)     { m_pt = boost::posix_time::from_time_t(t); }

    void setFromDatetime(const SEXP dt)   { m_pt = Rcpp::as<boost::posix_time::ptime>(dt); }
    void setFromDouble(const double d)   { 
        Rcpp::Datetime dt(d);
        m_pt = boost::posix_time::ptime(boost::gregorian::date(dt.getYear(), dt.getMonth(), dt.getDay()), 
                                        boost::posix_time::time_duration(dt.getHours(), dt.getMinutes(), dt.getSeconds(), dt.getMicroSeconds()/1000.0));
    }

    Rcpp::Datetime getDatetime() 	  { return Rcpp::wrap(m_pt); }

    Rcpp::Date getDate() { 
        boost::gregorian::date::ymd_type ymd = m_pt.date().year_month_day();     // convert to date and then to y/m/d struct
        return Rcpp::Date( ymd.year, ymd.month, ymd.day );
    }

    void addHours(int h)        	  { m_pt += boost::posix_time::time_duration(h, 0, 0, 0); }
    void addMinutes(int m)        	  { m_pt += boost::posix_time::time_duration(0, m, 0, 0); }
    void addSeconds(int s)        	  { m_pt += boost::posix_time::time_duration(0, 0, s, 0); }
    void addFractionalSeconds(int fs)     { m_pt += boost::posix_time::time_duration(0, 0, 0, fs); }

private:
    boost::posix_time::ptime m_pt; 		// private ptime instace

    friend Rcpp::object<bdtPt> arith_bdtPt_bdtDu(Rcpp::object<bdtPt>, Rcpp::object<bdtDu>, std::string);
    friend bool compare_bdtPt_bdtPt(Rcpp::object<bdtPt>, Rcpp::object<bdtPt>, std::string);
};

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

    friend Rcpp::object<bdtDu> arith_bdtDu_bdtDu(Rcpp::object<bdtDu>, Rcpp::object<bdtDu>, std::string);
    friend Rcpp::object<bdtDu> arith_bdtDu_int(Rcpp::object<bdtDu>, int, std::string);
    friend bool compare_bdtDu_bdtDu(Rcpp::object<bdtDu>, Rcpp::object<bdtDu>, std::string);

    friend Rcpp::object<bdtPt> arith_bdtPt_bdtDu(Rcpp::object<bdtPt>, Rcpp::object<bdtDu>, std::string);
};


#endif
