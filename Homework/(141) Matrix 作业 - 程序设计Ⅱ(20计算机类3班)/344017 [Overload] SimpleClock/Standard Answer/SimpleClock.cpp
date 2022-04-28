#include "SimpleClock.h"



Clock Clock::operator + (const Clock &right) const {
	
	Clock c;
	
	// Deal with hour.
	c.hour = (this->hour + right.hour) % 24;
	
	// Deal with minute.
	c.hour = (c.hour + (this->minute + right.minute) / 60) % 24;
	c.minute = (this->minute + right.minute) % 60;
	
	// Deal with second.
	c.hour = (c.hour + (c.minute + (this->second + right.second) / 60) / 60) % 24;
	c.minute = (c.minute + (this->second + right.second) / 60) % 60;
	c.second = (this->second + right.second) % 60;
	
	return c;
}


Clock& Clock::operator += (const Clock &right) {
	
	// Deal with hour.
	this->hour = (this->hour + right.hour) % 24;
	
	// Deal with minute.
	this->hour = (this->hour + (this->minute + right.minute) / 60) % 24;
	this->minute = (this->minute + right.minute) % 60;
	
	// Deal with second.
	this->hour = (this->hour + (this->minute + (this->second + right.second) / 60) / 60) % 24;
	this->minute = (this->minute + (this->second + right.second) / 60) % 60;
	this->second = (this->second + right.second) % 60;
	
	return *this;
}


Clock & Clock::operator ++ () {
	Clock adder(0, 0, 1);
	*this += adder;
	return *this;
}


Clock Clock::operator ++ (int) {
	Clock c(*this);
	++ *this;
	return c;
}


istream & operator >> (istream &is, Clock &object) {
	int hour, minute, second;
	is >> hour >> minute >> second;
	
	hour %= 24;
	
	hour = (hour + minute / 60) % 24;
	minute %= 60;
	
	hour = (hour + (minute + second / 60) / 60) % 24;
	minute = (minute + second / 60) % 60;
	second %= 60;
	
	object.hour = hour;
	object.minute = minute;
	object.second = second;
	return is;
}


ostream & operator << (ostream &os, const Clock &object) {
	os << object.hour << ":" << object.minute << ":" << object.second;
	return os;
}
