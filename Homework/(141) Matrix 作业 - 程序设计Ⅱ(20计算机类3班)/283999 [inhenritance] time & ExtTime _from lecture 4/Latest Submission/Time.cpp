
#include "Time.h"

void Time::Write() const {
  	if (hrs < 10)
    	cout << '0';
  	cout << hrs << ':';
  	if (mins < 10)
    	cout << '0';
  	cout << mins << ':';
  	if (secs < 10)
    	cout << '0';
  	cout << secs;
  }
void Time::Set(int hours, int minutes, int seconds)
{   hrs=hours;
    mins=minutes;
    secs=seconds;
}
void Time::Increment()
{   secs++;
    if(secs==60)
    {   secs=0;
        mins++;
    }
    if(mins==60)
    {   mins=0;
        hrs++;
    }
    if(hrs==24)
    {   hrs=0;
    }
}
Time::Time(int hours, int minutes, int seconds)
{   hrs=hours;
    mins=minutes;
    secs=seconds;
}
Time::Time ()
{   hrs=0;
    mins=0;
    secs=0;

}