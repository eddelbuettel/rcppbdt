\name{RcppBDT Date functions}
\alias{getEndOfBizWeek}
\alias{getEndOfMonth}
\alias{getYear}
\alias{getMonth}
\alias{getDay}
\alias{getDayOfWeek}
\alias{getDayOfYear}
\alias{getEndOfMonth}
\alias{getYear}
\alias{getMonth}
\alias{getDay}
\alias{getDayOfWeek}
\alias{getDayOfYear}
\alias{getIMMDate}
\alias{getNthDayOfWeek}
\alias{getLastDayOfWeekInMonth}
\alias{getFirstDayOfWeekInMonth}
\alias{getFirstDayOfWeekAfter}
\alias{getLastDayOfWeekBefore}
\docType{package}
\title{Date accessor and construction functions from Boost Date_Time}
\description{
  This constants are provided for convenience. In the C++ sources,
  enumeration types are used for days of the week, months of the year as
  well as the ordering terms.

  Similar package-level constants are provided here as well. This should
  be considered as experimental and may be withdrawn in a later version
  of the package.  
}
\usage{
getEndOfBizWeek(date)
getEndOfMonth(date)
getYear(date)
getMonth(date)
getDay(date)
getDayOfWeek(date)
getDayOfYear(date)
getIMMDate(mon, year)
getNthDayOfWeek(nthday, dow, mon, year)
getLastDayOfWeekInMonth(nthday, mon, year) 
getFirstDayOfWeekInMonth(nthday, mon, year) 
getFirstDayOfWeekAfter(dow, date) 
getLastDayOfWeekBefore(dow, date)
}
\arguments{
  \item{date}{a \code{\link{Date}} object}
  \item{mon}{a month, specified either as an integer or one of the
    constants \code{\link{Jan}}, \code{\link{Feb}}, ... defined in this
    package}
  \item{year}{a four-digit year, specified as an integer}
  \item{nthday}{either an integer between 1 and 5, or one of the
    constants \code{\link{first}}, \code{\link{second}},
    ... \code{\link{fifth}} defined in this package.}
  \item{dow}{either an integer between 0 and 6 denoting a day of the
    week, or one of the constants \code{\link{Sun}}, \code{\link{Mon}},
    ... \code{\link{Sat}} defined in this package.}
}
\value{
  All functions return a \code{\link{Date}} object.
}
\details{Details of the Boost functions are provided by the Boost documentation.}
\author{Dirk Eddelbuettel \email{edd@debian.org}}
\references{Boost Date_Time: \url{http://www.boost.org/doc/html/date_time.html}}
\keyword{package}
