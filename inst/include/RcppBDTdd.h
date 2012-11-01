// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTdd.h: Rcpp and Boost Date_Time date duration ("days") class 
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

#ifndef RCPPBDT__RCPPBDTDD_H
#define RCPPBDT__RCPPBDTDD_H

class bdtDd {

public:
    bdtDd() : m_dd(0)			 {} 			// default empty constructor, zero length 
    bdtDd(long dd) : m_dd(dd)		 {} 			// constructor from day count
    bdtDd(boost::gregorian::date_duration dd) : m_dd(dd) {} 
    bdtDd(const bdtDd& other) : m_dd(other.m_dd) {}

    long getDays()                    { return m_dd.days(); }

private:
    boost::gregorian::date_duration m_dd; 				// private Boost date duration instance

    friend bdtDd* arith_bdtDd_bdtDd(  const bdtDd&, const bdtDd&, std::string);
    friend bdtDd* arith_bdtDd_int(    const bdtDd&, const int&,   std::string);
    friend bdtDd* arith_int_bdtDd(    const int&,   const bdtDd&, std::string);
    friend bool   compare_bdtDd_bdtDd(const bdtDd&, const bdtDd&, std::string);
    friend bdtDt* arith_bdtDd_bdtDt(  const bdtDd&, const bdtDt&, std::string);
    friend bdtDt* arith_bdtDt_bdtDd(  const bdtDt&, const bdtDd&, std::string);
};

#endif
