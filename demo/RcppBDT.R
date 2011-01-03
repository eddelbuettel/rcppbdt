
demo.RcppBDT  <- function() {

    require(RcppBDT)

    ## this uses the pretty-printing the Rcpp module logic to show
    ## all available functions and their docstring
    #print(BDTDate)

    cat("Demo of setters\n");
    ## first init a base objects for uses for the functions below
    bd <- new(BDTDate, 2010, 10, 1);    cat("From 2010, 10, 1 : ", format(bd$getString()), "\n")
    ## then assign new values to the base object
    bd$fromString("2010-10-02"); 	cat("From 2010-10-02  : ", format(bd$getString()), "\n")
    bd$fromUndelString("20101003");     cat("From 20101003    : ", format(bd$getString()), "\n")
    bd$setFromUTC(); 			cat("From curr. UTC   : ", format(bd$getString()), "\n")
    bd$setFromLocalClock();		cat("From curr. local : ", format(bd$getString()), "\n")
    bd$setEndOfMonth(); 		cat("end of month     : ", format(bd$getString()), "\n")
    bd$setFirstOfNextMonth(); 		cat("1st of next Month: ", format(bd$getString()), "\n")
    bd$addDays(4);                      cat("plus four days   : ", format(bd$getString()), "\n")
    bd$subtractDays(3);                 cat("minus three  s   : ", format(bd$getString()), "\n")

    bd$setIMMDate(12, 2010); 		cat("IMM Date Dec 2010: ", format(bd$getString()), "\n")
    bd$setEndOfBizWeek();  		cat("end of biz week  : ", format(bd$getString()), "\n")

    cat("\nDemo of getters\n")
    ## now just functions that return values to R
    cat("From curr. local : ", format(bd$getLocalClock()), "\n")
    bd$setFromLocalClock();
    cat("end of biz week  : ", format(bd$getEndOfBizWeek()), "\n")
    cat("end of of month  : ", format(bd$getEndOfMonth()), "\n")
    cat("1st of next month: ", format(bd$getFirstOfNextMonth()), "\n")
}

demo.RcppBDT()
