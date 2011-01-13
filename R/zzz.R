##
## zzz.R: Loading Rcpp and Boost Date_Time glue
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

## This and the code below in onLoad() owe some gratitude to
## the wls package inside the Rcpp repository on R-forge
##
## grab the namespace of this package for use below
.NAMESPACE <- environment()

# dummy module, will be replaced later
bdt <- new( "Module" )

.onLoad <- function (lib, pack) {

    ## we need the methods package
    require(methods, quiet=TRUE, warn=FALSE)

    unlockBinding("bdt", .NAMESPACE)    	# unlock
    bdtMod <- Module( "bdt" )			# get the module code
    bdt <- new( bdtMod$date )                  	# date class default constructor for reference instance
    bdt$setFromUTC()                    	# but set a default value
    assign("bdt", bdt, .NAMESPACE)      	# assign the reference instance
    assign("bdtMod", bdtMod, .NAMESPACE)  	# and the module

    setMethod("print", "Rcpp_date", function(x, ...) print(x$getDate(), ...))
    setMethod("format", "Rcpp_date", function(x, ...) format(x$getDate(), ...))

    lockBinding( "bdt", .NAMESPACE)		# and lock
}


