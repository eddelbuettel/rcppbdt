// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdu.h: Rcpp and Boost Date_Time posix time class 
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

#ifndef RCPPBDT__RCPPBDTPT_H
#define RCPPBDT__RCPPBDTPT_H

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

    friend bdtPt* arith_bdtPt_bdtDu(const bdtPt&,   const bdtDu&,  std::string);
    friend bdtPt* arith_bdtDu_bdtPt(const bdtDu&,   const bdtPt&,  std::string);
    friend bool   compare_bdtPt_bdtPt(const bdtPt&, const bdtPt&,  std::string);
    //friend bdtPt* arith_bdtPt_double(const bdtPt&,  const double&, std::string);
    friend bdtPt* arith_bdtPt_double(const bdtPt&,  const std::vector<double>& d, std::string);
    friend bdtPt* arith_double_bdtPt(const double&, const bdtPt&,  std::string);
};

#endif
