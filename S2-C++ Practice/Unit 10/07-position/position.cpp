#include "position.h"
Point::Point(double x0,double y0)
{	x=x0;
	y=y0;
}
Point::~Point()
{	cout<<"Bye~\n";
}
void Point::move(double dx,double dy)
{	x+=dx;
	y+=dy;
}
void Point::show()const
{	cout<<"The point is at ("<<x<<","<<y<<")\n";
}
Point Point::copy(double dx,double dy)const
{	Point temp(x,y);
	(temp.x)+=dx;
	(temp.y)+=dy;
	return temp;
}
void Point::reset(double x0,double y0)
{	x=x0;
	y=y0;
}
