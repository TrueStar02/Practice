#include "SimpleClock.h"


Clock Clock::operator+(const Clock &right) const
{   Clock c(hour+right.hour,minute+right.minute,second+right.second);
    if(c.second>=60)
    {   c.second-=60;
        c.minute++;
    }
    if(c.minute>=60)
    {   c.minute-=60;
        c.hour++;
    }
    if(c.hour>=24)
        c.hour-=24;
    return c;
}
Clock& Clock::operator+=(const Clock &right)
{   hour+=right.hour;
    minute+=right.minute;
    second+=right.second;
    if(second>=60)
    {   second-=60;
        minute++;
    }
    if(minute>=60)
    {   minute-=60;
        hour++;
    }
    if(hour>=24)
        hour-=24;
    return *this;

}
Clock & Clock::operator++()
{   second++;
    if(second>=60)
    {   second-=60;
        minute++;
    }
    if(minute>=60)
    {   minute-=60;
        hour++;
    }
    if(hour>=24)
        hour-=24;
    return *this;
}
Clock Clock::operator++(int)
{   Clock c=*this;
    second++;
    if(second>=60)
    {   second-=60;
        minute++;
    }
    if(minute>=60)
    {   minute-=60;
        hour++;
    }
    if(hour>=24)
        hour-=24;
    return c;
}
istream& operator>>(istream &is, Clock &Clock)
{  is >> Clock.hour >> Clock.minute >> Clock.second;
    return is;
}
ostream& operator<<(ostream &os, const Clock &obj)
{   os<<obj.hour<<":"<<obj.minute<<":"<<obj.second;
    return os;
}