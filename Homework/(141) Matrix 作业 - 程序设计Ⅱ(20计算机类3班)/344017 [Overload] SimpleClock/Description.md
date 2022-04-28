# [Overload] SimpleClock

# Description
This is just a simple clock, please realize its operator overloading on '+', '+=', '++', istream '>>', ostream '<<'.

## Implementation details
**Private members**
```
int hour: between 0 and 23.
int minute: between 0 and 59.
int second: between 0 and 59.
```
**Public members**
```
Clock():  Default constuctor (has been implemented).
Clock(const int, const int, const int):  Arg constructor (has been implemented).

Clock operator +(const Clock &right) const:  Overload of '+'. Note that if an overflow occurs in the result, please modify it into a correct value (e.g., 15:25:35+23:34:45->15:00:20).
Clock& Operator +=(const Clock &right):  Overload of '+=', similar to the case in overloading '+'.
Clock & Operator ++():  Overload of '++', which realizes the operation of '++Clock'. Return by reference so that an unnecessary copy is avoided.
Clock Operator++(int):  Overload of '++', which realized the operation of 'Clock++'.
istream& operator>>(istream &is, Clock &obj):  Overload of input streams with extraction '>>'. "cin >> Clock" is equivalent to "cin >> Clock.hour >> Clock.minute >> Clock.second".
ostream& operator<<(ostream &os, const Clock &obj):  Overload of output streams with extraction '<<'. It should be displayed as "hour:minute:minute" (e.g. 6:9:35, 11:45:14).
```

### Hint
*In order to reduce the complexity, all of the input times are considered to be **legal**, so it is not necessary to deal with illegal times when overloading input streams '>>'.