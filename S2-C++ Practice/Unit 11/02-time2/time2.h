#ifndef TIME2_H_
#define TIME2_H_
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
		Time operator*(double n) const;
		Time operator/(double n) const;
		friend Time operator*(double n,const Time & t){return t*n;}
		friend ostream & operator<<(ostream & os,const Time & t);
		void show(void) const;
};
#endif
