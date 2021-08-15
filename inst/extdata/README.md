
## Possible Issue

See
[this Stackoverflow question](http://stackoverflow.com/questions/29413175/generating-date-time-zonespec-csv-for-boostdate-time-from-ianas-time-zone-dat)
for problems with this csv file, and the following quote

> Why don't you use Boost.DateTime time zone support?
>
> Boost.DateTime's time zone support is broken. Time zones can not be
> represented with a simple table of rules where daylight saving depend only on
> certain n'th day of week in month. The daylight savings time may vary by
> year, political issues and many other things.

attributed to the
[Boost locale](https://www.boost.org/doc/libs/release/libs/locale/doc/html/dates_times_timezones.html)
documentation.
