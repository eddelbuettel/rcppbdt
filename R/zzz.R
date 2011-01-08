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

## a simple alternative to enum type in C++ -- we could also have
## these as parts of a data.frame
Sun <- 0
Mon <- 1
Tue <- 2
Wed <- 3
Thu <- 4
Fri <- 5
Sat <- 6

## likewise, identifiers for the months
Jan <- 1
Feb <- 2
Mar <- 3
Apr <- 4
May <- 5
Jun <- 6
Jul <- 7
Aug <- 8
Sep <- 9
Oct <- 10
Nov <- 11
Dec <- 12

## and for sequences
first <- 1
second <- 2
third <- 3
fourth <- 4
fifth <- 5

.onLoad <- function (lib, pack) {

    ## we need the methods package
    require(methods, quiet=TRUE, warn=FALSE)

    ## store an instance of the date class as BDTDate
    bdtEnv$BDTDate <- Module("bdt")$date
    ## and create a new object of the class as bdt
    bdtEnv$bdt <- new(bdtEnv$BDTDate)
    bdtEnv$bdt$setFromUTC()

    #attach(daysOfWeek)

}
