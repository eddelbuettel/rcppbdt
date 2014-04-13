\name{NEWS}
\title{News for Package \pkg{RcppBDT}}
\newcommand{\cpkg}{\href{http://CRAN.R-project.org/package=#1}{\pkg{#1}}}

\section{Changes in version 0.2.3 (2014-04-13)}{
  \itemize{
    \item New module 'bdtDt' replacing the old 'bdtDate' module in a
    more transparent stule using a local class which is wrapped, just like
    the three other new classes do
    \item New module 'bdtTd' providing date durations which can be added
    to dates.
    \item New module 'bdtTz' providing time zone information such as offset to
    UTC, amount of DST, abbreviated and full timezone names.
    \item New module 'bdtDu' using 'posix_time::duration' for time durations types
    \item New module 'bdtPt' using 'posix_time::ptime' for posix time,
    down to nanosecond granularity (where hardware and OS permit it)
    \item Now selects C++11 compilation by setting \code{CXX_STD = CXX11} in
    \code{src/Makevars*} and hence depend on R 3.1.0 or later -- this gives
    gives us \code{long long} needed for the nano-second high-resolution time 
    calculations across all builds and platforms.
  }
}

\section{Changes in version 0.2.2 (2014-02-21)}{
  \itemize{
    \item Updates to current CRAN Policy standards for \code{Depends:}
    and \code{Imports:} in DESCRIPTION
    \item Also take advantage of new \cpkg{Rcpp} 0.11.0 build options
    \item New code remains in GitHub repo master branch until R 3.1.0 is
    released so that we can use C++11 in order to get the \code{long long
      int} support without which the package does not build on Windows
    (whereas Linux is fine)
  }
}

\section{Changes in version 0.2.1 (2012-08-08)}{
  \itemize{
    \item Bug for getEndOfBizWeek() and getEndOfMonth() who were lacking
    a call to fromDate(date) to actually pass the date for which the
    functions are computing the end of business week or month.
  }
}
\section{Changes in version 0.2.0 (2012-07-02)}{
  \itemize{
    \item The core module, which wraps what in C++ is
    boost::gregorian::date, is now exposed as an Rcpp module bdtDate.
    As all example and demos operated off a (package-global) variable
    'bdt', no user visible change was needed outside of the code
    instantiating at package load.

    \item Updated package instantiation to the new facilities offered by
    the current versions R 2.15.1 and Rcpp 0.9.13 which make Rcpp module
    initialization easier and more streamlined.
  } 
}
\section{Changes in version 0.1.0 (2011-01-17)}{
  \itemize{
    \item First CRAN upload (and see ChangeLog for more granular
    details) bug fix in svm cross validation
  }
}

