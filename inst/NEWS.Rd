\name{NEWS}
\title{News for Package \pkg{RcppBDT}}
\newcommand{\cpkg}{\href{http://CRAN.R-project.org/package=#1}{\pkg{#1}}}

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

