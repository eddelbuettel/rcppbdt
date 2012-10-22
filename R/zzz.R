##
## zzz.R: Loading Rcpp and Boost Date_Time glue
##
## Copyright (C) 2010 - 2012  Dirk Eddelbuettel and Romain Francois
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


loadModule("bdtDtMod", TRUE)
loadModule("bdtTzMod", TRUE)
loadModule("bdtDuMod", TRUE)
loadModule("bdtPtMod", TRUE)

## create a variable 'bdt' from the bdtDt Module (formerly: bdtMod)
## this variable is used as a package-global instance in some R access function
delayedAssign( "bdt", local( {
    x <- new( bdtDt )
    x$setFromUTC()
    x
}) )

.format_dt <- function(x, ...) format(x$getDate(), ...)
.show_dt   <- function(object) print(object$getDate())

.format_tz <- function(x, ...) format(x$getRegion(), ...)
.show_tz   <- function(object) print(object$getRegion())

.format_pt <- function(x, ...) format(x$getDatetime(), ...)
.show_pt   <- function(object) print(object$getDatetime())

.format_du <- function(x, ...) format(as.difftime( x$getTotalSeconds( ) + x$getFractionalSeconds( ) / 1.0e9 , units="secs"))
.show_du   <- function(object) print(as.difftime( object$getTotalSeconds( ) + object$getFractionalSeconds( ) / 1.0e9 , units="secs"))


## define an onLoad expression to set some methods
evalqOnLoad({
    setMethod("show", "Rcpp_bdtDt", .show_dt)
    setMethod("show", "Rcpp_bdtTz", .show_tz)
    setMethod("show", "Rcpp_bdtPt", .show_pt)
    setMethod("show", "Rcpp_bdtDu", .show_du)
    setGeneric("format", function(x,...) standardGeneric("format"))
    setMethod("format", "Rcpp_bdtDt", .format_dt)
    setMethod("format", "Rcpp_bdtTz", .format_tz)
    setMethod("format", "Rcpp_bdtPt", .format_pt)
    setMethod("format", "Rcpp_bdtDu", .format_du)
    
    setMethod("Arith", signature(e1 = "Rcpp_bdtDu", e2 = "Rcpp_bdtDu" ), function(e1, e2){
        arith_bdtDu_bdtDu( e1, e2, .Generic )
    } )
    setMethod("Arith", signature(e1 = "Rcpp_bdtDu", e2 = "integer" ), function(e1, e2){
        arith_bdtDu_int( e1, e2, .Generic )
    } )
    setMethod("Arith", signature(e1 = "Rcpp_bdtDu", e2 = "numeric" ), function(e1, e2){
        arith_bdtDu_int( e1, as.integer(e2), .Generic )
    } )
    setMethod("Compare", signature(e1 = "Rcpp_bdtDu", e2 = "Rcpp_bdtDu" ), function(e1, e2){
        compare_bdtDu_bdtDu( e1, e2, .Generic )
    } )
})
