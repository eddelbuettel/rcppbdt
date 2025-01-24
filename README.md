
## RcppBDT: R bindings for Boost Date.Time

[![CI](https://github.com/eddelbuettel/rcppbdt/workflows/ci/badge.svg)](https://github.com/eddelbuettel/rcppbdt/actions?query=workflow%3Aci)
[![License](https://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](https://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](https://www.r-pkg.org/badges/version/RcppBDT)](https://cran.r-project.org/package=RcppBDT)
[![r-universe](https://eddelbuettel.r-universe.dev/badges/rcppbdt)](https://eddelbuettel.r-universe.dev/rcppbdt)
[![Downloads](https://cranlogs.r-pkg.org/badges/RcppBDT?color=brightgreen)](https://www.r-pkg.org/pkg/RcppBDT)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcppbdt)](https://github.com/eddelbuettel/rcppbdt)

### About

This package provides R with access to [Boost
Date_Time](https://www.boost.org/doc/libs/release/doc/html/date_time.html)
functionality by using Rcpp modules.

It is effectively a precursor to the newer and more polished packages [anytime](https://github.com/eddelbuettel/anytime).

### Core Features available via [Boost Date_Time](https://www.boost.org/doc/libs/release/doc/html/date_time.html) 

* [Posix time ("Ptime")](https://www.boost.org/doc/libs/release/doc/html/date_time/posix_time.html): Nano-second precision calculations and datetime calculations
* [Date](https://www.boost.org/doc/libs/release/doc/html/date_time/gregorian.html): basic date calculation support 
* [Date duration](https://www.boost.org/doc/libs/release/doc/html/date_time/gregorian.html#date_time.gregorian.date_duration): Calculations on intervals ("days") 
* [Local time](https://www.boost.org/doc/libs/release/doc/html/date_time/local_time.html): Portable time zone support

Each of these has an individual demo file.

### Status

The package now takes advantage of R 3.1.0 and uses the C++11 standard to get
`long long` support which is needed for high-resolution timing support on all
platforms.

### TODO

All calculations work as implemented, but the package still has a "proof of
concept" flavour as they are not vectorised at the R level. All the relevant operators
operators would have to be defined. That is mostly tedious which is one of
the reasons I have not gotten around to it yet.  Get in touch if you are
interested.


### License

GPL (>= 2)
