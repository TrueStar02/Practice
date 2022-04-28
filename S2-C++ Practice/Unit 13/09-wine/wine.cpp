#include "wine.h"
Port::Port(const char *br, const char *st, int b)
{	brand=new char[strlen(br)+1];
	strcpy(brand,br);
	style=new char[strlen(st)+1];
	strcpy(style,st);
	bottles=b;
}
Port::Port(const Port &p)
{	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);
	style=new char[strlen(p.style)+1];
	strcpy(style,p.style);
	bottles=p.bottles;
}
Port::~Port()
{	delete [] brand;
	delete [] style;
}
Port & Port::operator=(const Port &p)
{	if(this==&p)
		return *this;
	else
	{	delete [] brand;
		delete [] style;
		brand=new char[strlen(p.brand)+1];
		strcpy(brand,p.brand);
		style=new char[strlen(p.style)+1];
		strcpy(style,p.style);
		bottles=p.bottles;
		return *this;
	}
}
Port & Port::operator+=(int b)
{	if(bottles+b>=0)
		bottles+=b;
	else
		cout<<"Bottles can't be negative!\n";
	return *this;
}
Port & Port::operator-=(int b)
{	if(bottles-b>=0)
		bottles-=b;
	else
		cout<<"Bottles can't be negative!\n";
	return *this;
}
void Port::Show() const
{	cout<<"Brand:"<<brand<<endl;
	cout<<"Kind:"<<style<<endl;
	cout<<"Bottles:"<<bottles<<endl;
}
ostream & operator<<(ostream &os, const Port &p)
{	os<<p.brand<<", "<<p.style<<", "<<p.bottles;
	return os;
}
VintagePort::VintagePort():Port()
{	nickname=new char[5];
	strcpy(nickname,"null");
	year=0; 
}
VintagePort::VintagePort(const char *br, int b, const char *nn, int y):Port(br,"null",b)
{	nickname=new char[strlen(nn)+1];
	strcpy(nickname,nn);
	year=y; 
}
VintagePort::VintagePort(const VintagePort &vp):Port(vp)
{	nickname=new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year; 
}
VintagePort::~VintagePort()
{	delete [] nickname;
}
VintagePort & VintagePort::operator=(const VintagePort &vp)
{	if(this==&vp)
		return *this;
	else
	{	Port::operator=(vp);
		delete [] nickname;
		nickname=new char[strlen(vp.nickname)+1];
		strcpy(nickname,vp.nickname);
		year=vp.year; 
		return *this;
	}
}
void VintagePort::Show() const
{	Port::Show();
	cout<<"Nickname:"<<nickname<<endl;
	cout<<"Year:"<<year<<endl;	
}
ostream & operator<<(ostream &os, const VintagePort &vp)
{	os<<(const Port &)vp;
	os<<", "<<vp.nickname<<", "<<vp.year;
	return os;
}
