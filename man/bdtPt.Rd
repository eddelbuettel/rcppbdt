\name{bdtPt}
\alias{bdtPt}
\alias{Rcpp_bdtPt-class}
\alias{show,Rcpp_bdtPt-method}
\alias{format,Rcpp_bdtPt-method}
\alias{arith_bdtPt_bdtDu}
\alias{compare_bdtPt_bdtPt}
\alias{arith_bdtPt_double}
\alias{arith_double_bdtPt}
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
\section{Method}{
  \describe{
    \item{show}{\code{signature(x = "Rcpp_bdtPt")}: prints a (bdtPt) ptime class object}
    \item{format}{\code{signature(x = "Rcpp_bdtPt")}: formats a (bdtPt) ptime class object}
  }
}
\details{
  Please consult the Boost documentation for (copious) details on the
  Date_Time library. See the Rcpp-modules vignette for details on Rcpp
  modules. 
}
\author{Dirk Eddelbuettel \email{edd@debian.org}}
\references{Boost Date_Time: \url{http://www.boost.org/doc/html/date_time.html}}
\keyword{package}
