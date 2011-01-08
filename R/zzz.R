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


## new environment for our package, local to the package
bdtEnv <- new.env(parent=emptyenv())

.onLoad <- function (lib, pack) {

    ## we need the methods package
    require(methods, quiet=TRUE, warn=FALSE)

    ## new environment for our package, stored in global env
    #.RcppBDTenv <<- new.env(parent=emptyenv())

    ## Create internal variables
    #.RcppBDTenv$BDTDate <- Module("bdt")$date
    #.RcppBDTenv$bdt <- new(.RcppBDTenv$BDTDate)
    #.RcppBDTenv$bdt$setFromUTC()

    bdtEnv$BDTDate <- Module("bdt")$date
    bdtEnv$bdt <- new(bdtEnv$BDTDate)
    bdtEnv$bdt$setFromUTC()

}
