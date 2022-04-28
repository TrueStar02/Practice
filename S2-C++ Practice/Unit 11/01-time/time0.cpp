#include "time0.h"
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
Time Time::operator*(int n) const
{	Time temp(hh*n,mm*n,ss*n);
	temp.mm+=(temp.ss/60);
	temp.ss%=60;
	temp.hh+=(temp.mm/60);
	temp.mm%=60;
	return temp;
}
void Time::show(void) const
{	cout<<"Time:"<<hh<<":"<<mm<<":"<<ss<<endl;
}
