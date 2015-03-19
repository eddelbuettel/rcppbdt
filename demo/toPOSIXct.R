#!/usr/bin/r

library(RcppBDT)

## parsing character
s <- c("2004-03-21 12:45:33.123456789",
       "2004/03/21 12:45:33.123456789", "20040321 124533.123456789",
       "21.03.2004 12:45:33.123456789", "03/21/2004 12:45:33.123456789",
       "03-21-2004 12:45:33.123456789", "2004-03-21", "20040321", "rapunzel")

p <- parsePOSIXt(s)

options("digits.secs"=6)
print(p)
print(format(p, tz="UTC"))

## parsing integers
s <- c(20150315L, 20010101L, 20141231L)
p <- parsePOSIXt(s)
print(format(p, tz="UTC"))

## parsing numeric
s <- c(20150315, 20010101, 20141231)
print(format(p, tz="UTC"))
print(p)

## parsing POSIXct (also numeric)
s <- as.numeric(as.POSIXct(Sys.time()))
p <- parsePOSIXt(s)
print(p)
