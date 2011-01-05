##
## bdt.R: Some accessor functions for Boost Date_Time functionality
##
## Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
##
## This file is part of RcppBDT.
##
## RcppBDT is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## RcppBDT is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with RcppBDT.  If not, see <http://www.gnu.org/licenses/>.

getEndOfBizWeek <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$getEndOfBizWeek(d)
}

getEndOfMonth <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$getEndOfMonth(d)
}

getYear <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$fromDate(d)
    .bdt$getYear()
}

getMonth <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$fromDate(d)
    .bdt$getMonth()
}

getDay <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$fromDate(d)
    .bdt$getDay()
}

getDayOfWeek <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$fromDate(d)
    .bdt$getDayOfWeek()
}

getDayOfYear <- function(d = Sys.Date()) {
    stopifnot(inherits(d, "Date"))
    .bdt$fromDate(d)
    .bdt$getDayOfYear()
}

getIMMDate <- function(mon, year) {     # defined as third Wednesday
    .bdt$getIMMDate(mon, year)
}

getNthDayOfMthWeek <- function(nthday, mthweek, mon, year) {
    .bdt$getNthDayMthWeek(nthday, mthweek, mon, year)
}
