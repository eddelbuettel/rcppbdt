\name{bdt}
\alias{bdt}
\alias{bdtMod}
\docType{package}
\title{Default object for RcppBDT Boost Date_Time binding}
\description{
  The \verb{bdt} variable is a default instance of the reference class
  created by means of Rcpp modules.

  The \verb{bdtMod} variable is an instance of the class created by Rcpp
  modules; see \code{print(bdtMod)} for available methods.
  
  New instances can be created using either the default constructor
  (without argument) or the constructor using year, month, date arguments.
}
\details{
  Please consult the Boost documentation for (copious) details on the
  Date_Time library. See the Rcpp-modules vignette for details on Rcpp
  modules. 
}
\author{Dirk Eddelbuettel \email{edd@debian.org}}
\references{Boost Date_Time: \url{http://www.boost.org/doc/html/date_time.html}}
\keyword{package}
