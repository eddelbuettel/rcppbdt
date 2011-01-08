
demo.RcppBDT  <- function() {

    require(RcppBDT, quiet=TRUE, warn=FALSE)

    ## this uses the pretty-printing the Rcpp module logic to show all
    ## available functions and their docstring (symbol now in per-package env)
    #print(RcppBDT::bdtEnv$BDTDate)

    ## first init a base objects for uses for the functions below
    ## using the instance stored in an internal environment
    ## alternative form: RcppBDT$bdt)
    bd <- getBDT()

    ## alternative constructors: see R/zzz.R

    cat("Demo of setters\n");
    ## conversions from string commented out, see inst/include/RcppBDT.h for details
    ##bd$fromString("2010-10-02"); 	cat("From 2010-10-02   : ", format(bd$getDate()), "\n")
    ##bd$fromUndelString("20101003");    cat("From 20101003     : ", format(bd$getDate()), "\n")
    bd$setFromUTC(); 			cat("From curr. UTC    : ", format(bd$getDate()), "\n")
    bd$setFromLocalClock();		cat("From curr. local  : ", format(bd$getDate()), "\n")
    bd$setEndOfMonth(); 		cat("end of month      : ", format(bd$getDate()), "\n")
    bd$setFirstOfNextMonth(); 		cat("1st of next Month : ", format(bd$getDate()), "\n")
    bd$addDays(4);                      cat("plus four days    : ", format(bd$getDate()), "\n")
    bd$subtractDays(3);                 cat("minus three days  : ", format(bd$getDate()), "\n")

    bd$setIMMDate(12, 2010); 		cat("IMM Date Dec 2010 : ", format(bd$getDate()), "\n")
    bd$setEndOfBizWeek();  		cat("end of biz week   : ", format(bd$getDate()), "\n")

    cat("\nDemo of getters\n")
    ## now just functions that return values to R
    cat("From curr. local  : ", format(bd$getLocalClock()), "\n")
    bd$setFromLocalClock();
    cat("end of biz week   : ", format(bd$getEndOfBizWeek()), "\n")
    cat("end of of month   : ", format(bd$getEndOfMonth()), "\n")
    cat("1st of next month : ", format(bd$getFirstOfNextMonth()), "\n")

    cat("\nDemo of functions\n")
    cat("IMM Date Dec 2010 : ", format(getIMMDate(Dec, 2010)), "\n")
    cat("3rd Wed Dec 2010  : ", format(getNthDayOfWeek(third, Wed, Dec, 2010)), "\n")
    cat("Last Sat Dec 2010 : ", format(getLastDayOfWeekInMonth(Sat, Dec, 2010)), "\n")
    cat("First Sat Dec 2010: ", format(getFirstDayOfWeekInMonth(Sat, Dec, 2010)), "\n")
    cat("First Wed in 2011 : ", format(getFirstDayOfWeekAfter(Wed, as.Date("2010-12-31"))), "\n")
    cat("Last Wed in 2010  : ", format(getLastDayOfWeekBefore(Wed, as.Date("2010-12-31"))), "\n")
}

demo.RcppBDT()
