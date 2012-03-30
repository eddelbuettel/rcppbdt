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


delayedAssign( "bdt", local( { 
    x <- new( bdtMod$date ); x$setFromUTC(); x 
}) )                                                                        


.format_date <- function(x, ...) format(x$getDate(), ...)
.show_date <- function(object) print(object$getDate())

.onLoad <- function (lib, pkg) {
    loadRcppModules(direct=FALSE)
    
    setMethod("show", "Rcpp_date", .show_date)
    setGeneric( "format", function(x,...) standardGeneric("format") )
    setMethod("format", "Rcpp_date", .format_date )

}


