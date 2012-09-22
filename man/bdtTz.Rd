\name{bdtTz}
\alias{bdtTz}
\alias{Rcpp_bdtTz-class}
\alias{show,Rcpp_bdtTz-method}
\alias{format,Rcpp_bdtTz-method}
\docType{package}
\title{Rcpp module bdtTz for binding of Boost Date_Time timezone functionality}
\description{
  The \verb{bdtTz} module is created using Rcpp modules and wraps a
  helper class \verb{bdtTz} around Boost Date_time timezone
  functionality provided mainly by the Boost classes
  \code{boost::local_time::tz_database} and
  \code{boost::local_time::time_zone_ptr}.

  On startup, the database object is initialized using a local copy (in
  csv format) of the timezone data.  Instances of the timezone object,
  represented by an instance of the timezone pointer class, can be
  created and queried.
  
  New instances can be created using a valid timezone region string
  (such \dQuote{Europe/London}).
}
\section{Method}{
  \describe{
    \item{show}{\code{signature(x = "Rcpp_bdtTz")}: prints a (bdtTz) timezone class object}
    \item{format}{\code{signature(x = "Rcpp_bdtTz")}: formats a (bdtTz) timezone class object}
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
