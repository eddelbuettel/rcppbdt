\name{bdtDt}
\alias{bdt}
\alias{bdtDt}
\alias{show,Rcpp_bdtDt-method}
\alias{format,Rcpp_bdtDt-method}
\alias{arith_bdtDt_bdtDd}
\alias{arith_bdtDt_int}
\alias{arith_int_bdtDt}
\alias{compare_bdtDt_bdtDt}
\alias{Rcpp_bdtDt-class}
\docType{package}
\title{Rcpp module bdtDt for binding of Boost Date_Time Date functionality}
\description{
  The \verb{bdtDt} module is created using Rcpp modules and wraps a
  helper class \verb{bdtDt} around Boost Date_time date
  functionality provided by the Boost class \code{boost::gregorian::date}.

  New instances can be created using either the default constructor
  (without arguments) or the constructor using year, month, date arguments.

  The \verb{bdt} variable is a default instance of this \code{bdtDt}
  reference class. It facilities accessing the member functions via
  utility function, see for example \code{\link{getEndOfBizWeek}} or
  \code{print(bdtDt)} for the available methods.
  
}
\section{Method}{
  \describe{
    \item{show}{\code{signature(x = "Rcpp_bdtDt")}: prints a (bdtDt) date class object}
    \item{format}{\code{signature(x = "Rcpp_bdtDt")}: formats a (bdtDt) date class object}
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
