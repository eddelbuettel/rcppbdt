
## demo for duration objects

require(utils, quiet=TRUE, warn=FALSE)
require(Rcpp, quiet=TRUE, warn=FALSE)
require(RcppBDT, quiet=TRUE, warn=FALSE)

## ctor with hour, minute, second, fractional seconds (all as ints)
du <- new(bdtDu, 0, 1, 2, 123456789)
print(du)  ## converts to difftime

dn <- new(bdtDu, 0, 1, -2, 123456789)       # negative int permitted too, make it negative sign for object
print(dn)  ## converts to difftime


today <- Sys.Date()    # base R, provides Date
## TODO  fails:   today + du

now <- Sys.time()      # base R
## TODO  fails as well now + du, but this works
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

print(du + hours(2) + minutes(3) + seconds(4) + nanoseconds(42))

## use one of several bdtPt ctors
pt <- new(bdtPt, ISOdatetime(2012,1,1,00,30,0,tz="UTC"))

print(pt + du)
print(du + pt)

print(pt + hours(3) + minutes(4))

