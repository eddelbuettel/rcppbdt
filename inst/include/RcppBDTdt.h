// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdt.h: Rcpp and Boost Date_Time date class 
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

#ifndef RCPPBDT__RCPPBDTDT_H
#define RCPPBDT__RCPPBDTDT_H

class bdtDt {

public:
    bdtDt()  				 { setFromLocalClock(); } 	// default empty constructor, using epoch
    bdtDt(SEXP dt) 			 { setDate(dt); } 		// constructor from SEXP using R Date
    bdtDt(int year, int month, int day) : m_dt(year, month, day) { } 	// constructor using year, month, day
    bdtDt(boost::gregorian::date dt) : m_dt(dt) {} 
    bdtDt(const bdtDt& other) : m_dt(other.m_dt) {}

    // these set the date from the clock, in local or universal time
    void setFromLocalClock()		 { m_dt = boost::gregorian::date(boost::gregorian::day_clock::local_day()); }
    void setFromUTCClock()        	 { m_dt = boost::gregorian::date(boost::gregorian::day_clock::universal_day()); }
    boost::gregorian::date getLocalDay() { return boost::gregorian::date(boost::gregorian::day_clock::local_day()); }
    boost::gregorian::date getUTCDay() 	 { return boost::gregorian::date(boost::gregorian::day_clock::universal_day()); }

    // these extract the requested date portion or representation as an integer
    int getYear() 			 { return static_cast<int>( m_dt.year() ); }
    int getMonth() 			 { return static_cast<int>( m_dt.month() ); }
    int getDay() 			 { return static_cast<int>( m_dt.day() ); }
    int getDayOfWeek() 			 { return static_cast<int>( m_dt.day_of_week() ); }
    int getDayOfYear() 			 { return static_cast<int>( m_dt.day_of_year() ); }

    void setDate(SEXP dt)		 { m_dt = Rcpp::as<boost::gregorian::date>(dt); }
    void fromDate(SEXP dt)		 { m_dt = Rcpp::as<boost::gregorian::date>(dt); Rf_warning("'fromDate' is deprecated, use 'setDate'"); }
    boost::gregorian::date getDate()	 { return m_dt; }

    int getWeekNumber()			 { return m_dt.week_number(); }
    long getModJulian()			 { return m_dt.week_number(); }
    long getJulian()			 { return m_dt.week_number(); }

    // construct end-of-month and first-of-next-monthm returning a boost::gregorian::date object
    void setEndOfMonth()		 { m_dt = m_dt.end_of_month(); } 
    boost::gregorian::date getEndOfMonth() { return m_dt.end_of_month(); } 
    void setFirstOfNextMonth()		 { m_dt = m_dt.end_of_month() + boost::gregorian::days(1); } 
    boost::gregorian::date getFirstOfNextMonth() { return m_dt.end_of_month() + boost::gregorian::days(1); }

    void setEndOfBizWeek() 		 { 
        m_dt += boost::gregorian::days_until_weekday(m_dt, boost::gregorian::greg_weekday(boost::gregorian::Friday)); 
    }
    boost::gregorian::date getEndOfBizWeek() 	 { 
        return m_dt += boost::gregorian::days_until_weekday(m_dt, boost::gregorian::greg_weekday(boost::gregorian::Friday) ); 
    }

    void addDays(unsigned int len) 	 { m_dt += boost::gregorian::date_duration(len); }
    void subtractDays(unsigned int len)  { m_dt -= boost::gregorian::date_duration(len); }
    void addMonths(int m)                { m_dt += boost::gregorian::months(m); }
    void addYears(int y) 	         { m_dt += boost::gregorian::years(y); }

    // with thanks to Whit Armstong for doing this in his rboostdatetime
    void setIMMDate(int mon, int year)   { 
        m_dt = boost::gregorian::nth_day_of_the_week_in_month(boost::gregorian::nth_day_of_the_week_in_month::third, 
                                                              boost::gregorian::Wednesday, mon).get_date(year); 
    }

private:
    boost::gregorian::date m_dt; 			// private Boost date instance

    friend bdtDt* arith_bdtDt_int(const bdtDt&, const int&, std::string);
    friend bdtDt* arith_int_bdtDt(const int&, const bdtDt&, std::string);
    friend bool compare_bdtDt_bdtDt(const bdtDt&, const bdtDt&, std::string);
    friend bdtDt* arith_bdtDd_bdtDt(const bdtDd&, const bdtDt&, std::string);
    friend bdtDt* arith_bdtDt_bdtDd(const bdtDt&, const bdtDd&, std::string);
};

#endif
