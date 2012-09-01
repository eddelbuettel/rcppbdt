\name{bdtPt}
\alias{bdtPt}
\alias{Rcpp_bdtPt-class}
\docType{package}
\title{Rcpp module bdtPt for binding of Boost Date_Time ptime functionality}
\description{
  The \verb{bdtDu} module is created using Rcpp modules and wraps a
  helper class \verb{bdtPt} around Boost Date_time duration
  functionality provided by the Boost class \code{boost::posix_time::ptime}.

  New instances can be created using either a default construction
  (creating an unset instance) or using seven integer values for year,
  month, day, hour, minute, seconds and fractional seconds.  Fractional
  seconds ought to be at a nano-second granularity; there may be
  platforms not permitting this.
}
\details{
  Please consult the Boost documentation for (copious) details on the
  Date_Time library. See the Rcpp-modules vignette for details on Rcpp
  modules. 
}
\author{Dirk Eddelbuettel \email{edd@debian.org}}
\references{Boost Date_Time: \url{http://www.boost.org/doc/html/date_time.html}}
\keyword{package}
