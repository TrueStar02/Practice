#ifndef SHAPE_H_
#define SHAPE_H_
#include<iostream>
using namespace std;
const double PI=3.1415926535;
class Base
{	private:
		double x;
		double y;
	public:
		Base(double x0=0,double y0=0){x=x0;y=y0;}
		virtual ~Base() {}
		void move(double dx,double dy){x+=dx,y+=dy;}
		virtual void print() const=0;
		virtual double area() const=0; 
};
class Circle:public Base
{	private:
		double r;
	public:
		Circle(double x0=0,double y0=0,double r0=1):Base(x0,y0){r=r0;}
		virtual ~Circle() {}
		virtual double area() const{return PI*r*r;}
		void reset_r(double r0){r=r0;}
		virtual void print() const;
};
class Ellipse:public Base
{	private:
		double a;
		double b;
		double theta;
	public:
		Ellipse(double x0=0,double y0=0,double a0=1,double b0=1,double t0=0):Base(x0,y0){a=a0;b=b0;theta=t0;}
		virtual ~Ellipse() {};
		virtual double area() const{return PI*a*b;}
		void reset_a(double a0){a=a0;}
		void reset_b(double b0){b=b0;}
		void twist(double dt){theta+=dt;};
		virtual void print() const;
};
#endif
