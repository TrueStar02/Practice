#include "time2.h"
Time::Time()
{	hh=mm=ss=0;
}
Time::Time(int h,int m,int s)
{	hh=h;
	mm=m;
	ss=s;
}
Time::~Time()
{	cout<<"Bye~\n";
}
void Time::Reset(int h,int m,int s)
{	hh=h;
	mm=m;
	ss=s;
}
Time Time::operator+(const Time & t) const
{	Time temp(hh+t.hh,mm+t.mm,ss+t.ss);
	if(temp.ss>=60)
	{	temp.ss-=60;
		temp.mm++;
	}
	if(temp.mm>=60)
	{	temp.mm-=60;
		temp.hh++;
	}
	return temp;
}
Time Time::operator-(const Time & t) const
{	Time temp(hh-t.hh,mm-t.mm,ss-t.ss);
	if(temp.ss<0)
	{	temp.ss+=60;
		temp.mm--;
	}
	if(temp.mm<0)
	{	temp.mm+=60;
		temp.hh--;
	}
	return temp;
}
Time Time::operator*(double n) const
{	int sec=(hh*3600+mm*60+ss)*n;
	Time temp;
	temp.mm+=(sec/60);
	temp.ss=sec%60;
	temp.hh+=(temp.mm/60);
	temp.mm%=60;
	return temp;
}
Time Time::operator/(double n) const
{	int sec=(hh*3600+mm*60+ss)/n;
	Time temp;
	temp.mm+=(sec/60);
	temp.ss=sec%60;
	temp.hh+=(temp.mm/60);
	temp.mm%=60;
	return temp;
}
ostream & operator<<(ostream & os,const Time & t)
{	os<<"Time:"<<t.hh<<":"<<t.mm<<":"<<t.ss<<"\n";
	return os;
}
