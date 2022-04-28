#include "vector2.h"
Vector::Vector()
{	x=y=polar=0;
}
Vector::Vector(double n1,double n2,bool mo)
{	if(mo)
	{	x=n1*cos(n2/RTD);
		y=n1*sin(n2/RTD);
		polar=1;
	}
	else
	{	x=n1;
		y=n2;
		polar=0;
	}
}
Vector::~Vector()
{	cout<<"Bye~\n";
}
void Vector::switch_mode()
{	polar^=1;
}
Vector Vector::operator+(const Vector & b)const
{	return Vector(x+b.x,y+b.y);
}
Vector Vector::operator-(const Vector & b)const
{	return Vector(x-b.x,y-b.y);
}
Vector Vector::operator-()const
{	return Vector(-x,-y);
}
Vector Vector::operator*(double n)const
{	return Vector(x*n,y*n);
}
double Vector::operator^(const Vector & b)const
{	return x*b.x+y*b.y;
}
double Vector::operator*(const Vector & b)const
{	return x*b.y-y*b.x;
}
ostream & operator<<(ostream & os,const Vector & b)
{	if(b.polar)
		os<<"Polar Mode:("<<b.r_val()<<","<<b.theta_val()*RTD<<")\n";
	else
		os<<"Rectangle Mode:("<<b.x<<","<<b.y<<")\n";
	return os;
}
