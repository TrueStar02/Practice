#include "vector.h"
void Vector::set_cart()
{	x=r*cos(theta);
	y=r*sin(theta);
}
void Vector::set_polar()
{	r=sqrt(x*x+y*y);
	if(x==0&&y==0)
		theta=0;
	else
		theta=atan2(y,x);
}
Vector::Vector()
{	x=y=theta=r=polar=0;
}
Vector::Vector(double n1,double n2,bool mo)
{	if(mo)
	{	r=n1;
		theta=n2/RTD;
		polar=1;
		set_cart();
	}
	else
	{	x=n1;
		y=n2;
		polar=0;
		set_polar();
	}
}
Vector::~Vector()
{	//cout<<"Bye~\n";
}
void Vector::reset(double n1,double n2,bool mo)
{	if(mo)
	{	r=n1;
		theta=n2/RTD;
		polar=1;
		set_cart();
	}
	else
	{	x=n1;
		y=n2;
		polar=0;
		set_polar();
	}
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
double Vector::operator*(const Vector & b)const
{	return x*b.x+y*b.y;
}
ostream & operator<<(ostream & os,const Vector & b)
{	if(b.polar)
		os<<"Polar Mode:("<<b.r<<","<<b.theta*RTD<<") ";
	else
		os<<"Rectangle Mode:("<<b.x<<","<<b.y<<") ";
	return os;
}
