#ifndef TIME0_H_
#define TIME0_H_
#include<iostream>
using namespace std;
class Time
{	private:
		int hh;
		int mm;
		int ss;
	public:
		Time();
		Time(int h,int m=0,int s=0);
		~Time();
		void Reset(int h,int m=0,int s=0);
		Time operator+(const Time & t) const;
		Time operator-(const Time & t) const;
		Time operator*(int n) const;
		void show(void) const;
};
#endif
