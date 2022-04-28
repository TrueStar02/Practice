#include "complex0.h"
Complex::Complex()
{	a=b=0;
}
Complex::Complex(double m,double n)
{	a=m;
	b=n;
}
Complex::~Complex()
{	a=b=0;
}
double Complex::length() const
{	return sqrt(a*a+b*b);
}
Complex Complex::operator+(const Complex &c)const
{	return Complex(a+c.a,b+c.b);
}
Complex Complex::operator-(const Complex &c)const
{	return Complex(a-c.a,b-c.b);
}
Complex Complex::operator*(const Complex &c)const
{	return Complex(a*c.a-b*c.b,a*c.b+b*c.a);
}
Complex Complex::operator/(const Complex &c)const
{	return Complex((a*c.a+b*c.b)/(c.a*c.a+c.b*c.b),(b*c.a-a*c.b)/(c.a*c.a+c.b*c.b));
}
Complex Complex::operator-()const
{	return Complex(-a,-b);
}
Complex Complex::operator~()const
{	return Complex(a,-b);
}
ostream & operator<<(ostream & os,const Complex &c)
{	if(c.b==0)
		os<<c.a;
	else if(c.a!=0)
	{	os<<c.a;
		if(c.b==1)
			os<<"+i";
		else if(c.b==-1)
			os<<"-i";
		else if(c.b>0)
			os<<"+"<<c.b<<"i";
		else
			os<<"-"<<-c.b<<"i";
	}
	else 
	{	if(c.b==1)
			os<<"i";
		else if(c.b==-1)
			os<<"-i";
		else if(c.b>0)
			os<<c.b<<"i";
		else
			os<<"-"<<-c.b<<"i";
	}
	return os;
}
istream & operator>>(istream & is,Complex &c)
{	cout<<"Enter the real and imaginary part of this number:\n";
	double x,y;
	is>>x>>y;
	c.a=x;
	c.b=y;
	return is;
}
