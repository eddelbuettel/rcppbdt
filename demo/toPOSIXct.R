#!/usr/bin/r

library(RcppBDT)

## parsing character
s <- c("2004-03-21 12:45:33.123456789", # ISO
       "2004-Mar-21 12:45:33.123456789",# also support month abbreviation or full
       "2004-March-21 12:45:33.123456789",
       "2004/03/21 12:45:33.123456789",
       "20040321 124533.123456789",
       "03/21/2004 12:45:33.123456789", # US placing month first (ewwwww....)
       "03-21-2004 12:45:33.123456789",
       "21.03.2004 12:45:33.123456789", # Germany having day.month.year
       "2004-03-21",                    # just dates work fine as well
       "20040321",
       "rapunzel")                      # will produce a NA

p <- toPOSIXct(s)

options("digits.secs"=6)                # make sure we see microseconds in output
print(p)
print(format(p, tz="UTC"))              # format UTC times as UTC (helps for Date types too)

## parsing integer types
s <- c(20150315L, 20010101L, 20141231L)
p <- toPOSIXct(s)
print(format(p, tz="UTC"))

## parsing numeric types
s <- c(20150315, 20010101, 20141231)
print(format(p, tz="UTC"))
print(p)

## and also 'parsing' (ie converting) POSIXct second since epoch (also numeric)
s <- as.numeric(as.POSIXct(Sys.time())) + c(-120,0,120)
p <- toPOSIXct(s)
print(p)
