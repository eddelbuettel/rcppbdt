
## demo / sketch for duration objects

require(utils, quiet=TRUE, warn=FALSE)
require(Rcpp, quiet=TRUE, warn=FALSE)
require(RcppBDT, quiet=TRUE, warn=FALSE)

## ctor with hour, minute, second, fractional seconds (all as ints)
du <- new(bdtDu, 1, 2, 3, 456)
print(du)  ## not bad: converts to difftime

dn <- new(bdtDu, 0, 1, -3, 123456789)       # negative int permitted too, make it negative sign for object
print(dn)  ## not bad: converts to difftime


today <- Sys.Date()    # base R

## fails:   today + du

now <- Sys.time()      # base R

## fails as well now + du, but
print(du$getAddedPosixtime(now))

du$addSeconds(2.2)
du$addMilliSeconds(3.3)
du$addMicroSeconds(4.4)
du$addNanoSeconds(5.5)
du

print(du$getAddedPosixtime(now))

# add 'du' to something and get a time object ?
# convert posix time (from Boost) to POSIXct ?
# more conversions ?
