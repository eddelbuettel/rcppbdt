
## demo for date duration objects

require(utils, quiet=TRUE, warn=FALSE)
require(Rcpp, quiet=TRUE, warn=FALSE)
require(RcppBDT, quiet=TRUE, warn=FALSE)

dd <- new(bdtDd, 5)
print(dd)  ## converts to difftime

print(dd + dd)                          # date_duration + date_duration
print(dd + 3)
print(dd - 2)
#print(2L + dd)				# should work
##print(2 - dd)				# not permitted

dt <- new(bdtDt, 2012, 10, 10)
print(dt)
#print(dd + dt)
print(dt + dd)
#print(dt - dd)

print(dt + dd + days(3) + weeks(2))
print(dt)
dt$addMonths(2)
dt$addYears(1)
print(dt)

## no converter from Date yet:  today <- Sys.Date()    # base R, provides Date
## print(today + dd)
