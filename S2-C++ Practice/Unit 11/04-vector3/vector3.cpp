#include "vector3.h"
Vector::Vector()
{	x=y=z=0;
}
Vector::Vector(double a,double b,double c)
{	x=a;
	y=b;
	z=c;
}
Vector::~Vector()
{	cout<<"Bye~\n";
}
Vector Vector::operator+(const Vector & v)const
{	return Vector(x+v.x,y+v.y,z+v.z);
}
Vector Vector::operator-(const Vector & v)const
{	return Vector(x-v.x,y-v.y,z-v.z);
}
Vector Vector::operator-()const
{	return Vector(-x,-y,-z);
}
Vector Vector::operator*(double n)const
{	return Vector(x*n,y*n,z*n);
}
Vector Vector::operator/(double n)const
{	return Vector(x/n,y/n,z/n);
}
double Vector::operator^(const Vector & v)const //Inner Product
{	return x*v.x+y*v.y+z*v.z;
}
Vector Vector::operator*(const Vector & v)const //Outer Product
{	return Vector(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);
}
ostream & operator<<(ostream & os,const Vector &v)
{	os<<"("<<v.x<<","<<v.y<<","<<v.z<<")\n";
	return os;
}
