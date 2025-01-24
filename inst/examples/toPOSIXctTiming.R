
library(microbenchmark)

library(fasttime)
#library(parsedate)
library(RcppBDT)


set.seed(42)

nobs <- 10000
startTime <- as.POSIXct("2015-01-01 00:00:00", tz="UTC")
pt <- startTime + (0:nobs)*1

v <- format(pt, tz="UTC")

base   <- function(x) as.POSIXct(strptime(x, format="%Y-%m-%d %H:%M:%S", tz="UTC"))
ftime  <- function(x) fastPOSIXct(x) #, tz="UTC")
#parset <- function(x) parse_date(x)

rbase  <- base(v)
rftime <- ftime(v)
#rparse <- parset(v)
rbdt   <- toPOSIXct(v)
cbdt   <- charToPOSIXct(v)
#cbdtns   <- charToPOSIXctNS(v)
ccbdt <- cToPOSIXct(v)
all.equal(rbase, rftime, rbdt, cbdt, rcppbdt)

res <- microbenchmark(base(v), ftime(v), #parset(v),
                      toPOSIXct(v), charToPOSIXct(v), #charToPOSIXctNS(v),
                      cToPOSIXct(v),
                      times=100)
print(res)
