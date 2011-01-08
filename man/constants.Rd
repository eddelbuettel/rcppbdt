\name{RcppBDT-constants}
\alias{RcppBDT-constants}
\alias{Sun}
\alias{Mon}
\alias{Tue}
\alias{Wed}
\alias{Thu}
\alias{Fri}
\alias{Sat}
\alias{Jan}
\alias{Feb}
\alias{Mar}
\alias{Apr}
\alias{May}
\alias{Jun}
\alias{Jul}
\alias{Aug}
\alias{Sep}
\alias{Oct}
\alias{Nov}
\alias{Dec}
\alias{first}
\alias{second}
\alias{third}
\alias{fourth}
\alias{fifth}
\docType{package}
\title{Constants for date functions with Boost Date_Time}
\description{
  This constants are provided for convenience. In the C++ sources,
  enumeration types are used for days of the week, months of the year as
  well as the ordering terms.

  Similar package-level constants are provided here as well. This should
  be considered as experimental and may be withdrawn in a later version
  of the package.  
}
\details{
  \verb{Sun}, \verb{Mon}, \verb{Tue}, ..., \verb{Sat} can be used instead of the values 0 to 6.

  \verb{Jan}, \verb{Feb}, ..., \verb{Dec} can be used instead of the values 1 to 12.

  \verb{first}, \verb{second}, ..., \verb{fifth} can be used instead of the values 1 to 5. 

  We use the same values as the Boost source code. In other words,
  Sunday is 0, Monday is 1 and so on.  Months, however, start at 1 for
  January. 
}
\author{Dirk Eddelbuettel \email{edd@debian.org}}
\references{Boost Date_Time: \url{http://www.boost.org/doc/html/date_time.html}}
\keyword{package}
