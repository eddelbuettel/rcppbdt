## RcppBDT: R bindings for Boost Date.Time

[![Build Status](https://travis-ci.org/eddelbuettel/rcppbdt.png)](https://travis-ci.org/eddelbuettel/rcppbdt)

This package provides R with access to 
[Boost Date_Time](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time.html)
functionality by using Rcpp modules. 

### Core Features available via [Boost Date_Time](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time.html) 

* [Posix time ("Ptime")](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time/posix_time.html): Nano-second precision calculations and datetime calculations
* [Date](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time/gregorian.html): basic date calculation support 
* [Date duration](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time/gregorian.html#date_time.gregorian.date_duration): Calculations on intervals ("days") 
* [Local time](http://www.boost.org/doc/libs/1_55_0/doc/html/date_time/local_time.html): Portable time zone support

Each of these has an individual demo file.

### Status

The package now takes advantage of R 3.1.0 and uses the C++11 standard to get
`long long` support which is needed for high-resolution timing support on all
platforms.

### TODO

All calculations work as implemented, but the package still has a "proof of
concept" flavour as they are not vectorised at the R level. All the relevant operators
would have to be defined. That is mostly tedious which I have not gotten
around to yet.  Get in touch if you are interested.

### License

GPL (>= 2)
