##
## zzz.R: Loading Rcpp and Boost Date_Time glue
##
## Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
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


## .onLoad <- function (lib, pkg) {
##     req <- get(paste("req", "uire", sep=""))	# we already Imports: methods, but there may
##     req("methods")  	        		# be a race condition lurking
##     loadRcppModules(direct=FALSE)

##     setMethod("show", "Rcpp_date", .show_date)
##     setGeneric("format", function(x,...) standardGeneric("format") )
##     setMethod("format", "Rcpp_date", .format_date )
## }


loadModule("bdtMod", TRUE)
loadModule("bdtTzMod", TRUE)
loadModule("bdtDuMod", TRUE)
loadModule("bdtPtMod", TRUE)

## create a variable 'bdt' from out bdtMod Module
## this variable is used as a package-global instance
delayedAssign( "bdt", local( {
    x <- new( bdtDate )
    x$setFromUTC()
    x
}) )

.format_date <- function(x, ...) format(x$getDate(), ...)
.show_date <- function(object) print(object$getDate())

.format_tz <- function(x, ...) format(x$getRegion(), ...)
.show_tz <- function(object) print(object$getRegion())

## define an onLoad expression to set some methods
evalqOnLoad({
    setMethod("show", "Rcpp_bdtDate", .show_date)
    setMethod("show", "Rcpp_bdtTz", .show_tz)
    setGeneric("format", function(x,...) standardGeneric("format") )
    setMethod("format", "Rcpp_bdtDate", .format_date )
    setMethod("format", "Rcpp_bdtTz", .format_tz )
})
