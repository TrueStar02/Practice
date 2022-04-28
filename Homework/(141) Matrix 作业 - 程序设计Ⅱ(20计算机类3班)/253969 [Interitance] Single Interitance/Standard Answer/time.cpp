#include "singletime.h"

Time::Time(int initHrs, int initMins, int initSecs) {
  hrs = initHrs;
  mins = initMins;
  secs = initSecs;
}

Time::Time() {
  hrs = 0;
  mins = 0;
  secs = 0;
}

void Time::Set(int hours, int minutes, int seconds) {
  hrs = hours;
  mins = minutes;
  secs = seconds;
}

void Time::Increment() { // IMPLEMENTATION FILE ( time.cpp )
  secs++;
  if (secs > 59) {
    secs = 0;
    mins++;
    if (mins > 59) {
      mins = 0;
      hrs++;
      if (hrs > 23)
        hrs = 0;
    }
  }
}
