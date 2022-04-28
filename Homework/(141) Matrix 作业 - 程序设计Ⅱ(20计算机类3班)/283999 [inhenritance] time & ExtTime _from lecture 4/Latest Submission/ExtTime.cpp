
#include "ExtTime.h"
//#include<iostream>
//using namespace std;

ExtTime::ExtTime (int initHrs, int initMins, int initSecs, ZoneType initZone):Time(initHrs,initMins,initSecs),zone(initZone){}
ExtTime::ExtTime ():Time(0,0,0),zone(EST){}
void ExtTime::Set (int hours, int minutes, int seconds, ZoneType timeZone)
{   Time::Set(hours,minutes,seconds);
    zone=timeZone;
}
void ExtTime::Write() const
{   const string z[8]={" EST", " CST", " MST", " PST", " EDT", " CDT", " MDT", " PDT"};
    Time::Write();
    cout<<z[zone];
}



