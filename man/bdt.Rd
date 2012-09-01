\name{bdt}
\alias{bdt}
\alias{bdtMod}
\alias{show,Rcpp_bdtDate-method}
\alias{format,Rcpp_bdtDate-method}
\alias{bdtDate}
\alias{Rcpp_bdtDate-class}
\docType{package}
\title{Default object for RcppBDT Boost Date_Time binding}
\description{
  The \verb{bdt} variable is a default instance of the 'date' class
  created by means of Rcpp modules. It facilities accessing the member
  functions via utility function, see for example \code{\link{getEndOfBizWeek}}.

  The \verb{bdtDate} variable is an instance of the class created by Rcpp
  modules. It contain just the \code{date} class from Boost Date_time; see
  \code{print(bdtDate)} for the available methods. 
  
  New instances can be created using either the default constructor
  (without arguments) or the constructor using year, month, date arguments.
}
\section{Method}{
  \describe{
    \item{show}{\code{signature(x = "Rcpp_date")}: prints a (BDT) date class object}
    \item{format}{\code{signature(x = "Rcpp_date")}: formats a (BDT) date class object}
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
