\name{bdtDu}
\alias{bdtDu}
\alias{Rcpp_bdtDu-class}
\alias{show,Rcpp_bdtDu-method}
\alias{format,Rcpp_bdtDu-method}
\docType{package}
\title{Rcpp module bdtDu for binding of Boost Date_Time duration functionality}
\description{
  The \verb{bdtDu} module is created using Rcpp modules and wraps a
  helper class \verb{bdtDu} around Boost Date_time duration
  functionality provided by the Boost class \code{boost::posix_time::duration}.

  New instances can be created using four integer values for hour,
  minute, seconds and fractional seconds.  Fractional seconds ought to
  be at a nano-second granularity; there may be platforms not permitting
  this.
}
\section{Method}{
  \describe{
    \item{show}{\code{signature(x = "Rcpp_bdtDu")}: prints a (BDTdu) duration class object}
    \item{format}{\code{signature(x = "Rcpp_bdtDu")}: formats a (BDTdu) duration class object}
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
