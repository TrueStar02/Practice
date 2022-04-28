#include "exttime.h"

ExtTime::ExtTime(int initHrs, 
                 int initMins,
                 int initSecs,
                 ZoneType initZone)
  :Time(initHrs, initMins, initSecs) {
  zone = initZone;
}

ExtTime::ExtTime() {
  zone = EST;
}

void ExtTime::Set(int hours,
									int minutes,
									int seconds,
									ZoneType timeZone) {
	Time::Set(hours, minutes, seconds);
	zone = timeZone;
}

void ExtTime::Write() const {
 	static string zoneString[8] =
  {"EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT"};
  Time::Write();
  cout << ' ' << zoneString[zone];
}