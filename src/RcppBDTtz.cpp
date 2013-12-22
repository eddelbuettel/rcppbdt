// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppBDTtz.cpp: Rcpp and Boost Date_Time glue for timezones
//
// Copyright (C) 2012   Dirk Eddelbuettel and Romain Francois
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

RCPP_MODULE(bdtTzMod) {

    Rcpp::class_<bdtTz>("bdtTz")   
	
        .constructor<std::string>("constructor with region string (eg \"Europe/London\")")  

        .method("getRegion",        &bdtTz::getRegion,        "get region string of this tz object")
        .method("getAllRegions",    &bdtTz::getAllRegions,    "get vector of TZ region names")
        
        .method("getUtcOffset",     &bdtTz::getUtcTotalSec,   "get UTC offset in seconds")
        .method("getDstOffset",     &bdtTz::getDstTotalSec  , "get DST offset in seconds")

        .method("getDstZoneAbbrev", &bdtTz::getDstZoneAbbrev, "get DST zone abbreviation")
        .method("getStdZoneAbbrev", &bdtTz::getStdZoneAbbrev, "get standard zone abbreviation")
        .method("getDstZoneName",   &bdtTz::getDstZoneName,   "get DST zone name")
        .method("getStdZoneName",   &bdtTz::getStdZoneName,   "get standard zone name")
        .method("hasDst",           &bdtTz::hasDst,           "true if timezone has daylight savings")
        .method("getPosixString",   &bdtTz::getPosixString,   "get posix time zone representation")
        
        .method("getDstLocalStart", &bdtTz::getDstLocalStart, "get start of DST in given year (in local tzone)")
        .method("getDstLocalEnd",   &bdtTz::getDstLocalEnd,   "get end of DST in given year (in local tzone)")
        //.method("getDstStart",      &bdtTz::getDstStart,      "get start of DST in given year (as Datetime with tzone)")
        //.method("getDstEnd",        &bdtTz::getDstEnd,        "get end of DST in given year (as Datetime with tzone)")

    ;
}
