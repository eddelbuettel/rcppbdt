## RcppBDT: R bindings for Boost Date.Time

[![Build Status](https://travis-ci.org/eddelbuettel/rcppbdt.png)](https://travis-ci.org/eddelbuettel/rcppbdt)

This package provides R with access to [Boost Date_Time](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time.html)
functionality by using Rcpp modules. 

### Status

The package is under development. The (current) CRAN release is not as
featureful as the version on this repo. 

The code in the repo will not build on (64-bit) Windows without `long long int`
support, which we will get with C++11 support once R 3.1.0 is released.

### License

GPL (>= 2)
