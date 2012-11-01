\name{bdtDd}
\alias{bdtDd}
\alias{Rcpp_bdtDd-class}
\alias{show,Rcpp_bdtDd-method}
\alias{format,Rcpp_bdtDd-method}
\alias{arith_bdtDd_bdtDd}
\alias{arith_bdtDd_bdtDt}
\alias{arith_bdtDd_int}
\alias{arith_int_bdtDd}
\alias{compare_bdtDd_bdtDd}
\alias{days}
\alias{weeks}
\docType{package}
\title{Rcpp module bdtDd for binding of Boost Date_Time date duration functionality}
\description{
  The \verb{bdtDd} module is created using Rcpp modules and wraps a
  helper class \verb{bdtDd} around Boost Date_time date duration
  functionality provided by the Boost class \code{boost::gregorian::date_duration}.

  New instances can be created using an integer for days of duration.
}
\usage{
days(...)
weeks(...)
}
\arguments{
  \item{...}{suitable argument, often an integer, denoting one unit of the reference duration component}
}
\section{Method}{
  \describe{
    \item{show}{\code{signature(x = "Rcpp_bdtDd")}: prints a (BDTdd)
      date duration class object}
    \item{format}{\code{signature(x = "Rcpp_bdtDd")}: formats a (BDTdd)
      date duration class object}
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
