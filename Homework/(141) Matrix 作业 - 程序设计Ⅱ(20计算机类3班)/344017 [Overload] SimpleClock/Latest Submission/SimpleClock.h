#ifndef SIMPLECLOCK_H
#define SIMPLECLOCK_H
#include <iostream>
using namespace std;

class Clock {

private:
	int hour;
	int minute;
	int second;
	
public:
	
	// Implemented.
	Clock(): hour(0), minute(0), second(0) {}
	Clock( int hour_,  int minute_,  int second_): hour(hour_), minute(minute_), second(second_) {} 
	
	
	// Not implemented.
	
	Clock& operator += (const Clock &right);
	Clock operator + (const Clock &right) const;
	Clock& operator ++ ();
	Clock operator ++ (int) ;
	
	friend istream & operator >> (istream &is, Clock &object);
	friend ostream & operator << (ostream &os, const Clock &object);

};

#endif 
