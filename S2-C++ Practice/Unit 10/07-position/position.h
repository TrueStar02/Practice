#ifndef POSITION_H_
#define POSITION_H_
#include<iostream>
using namespace std;
class Point
{	private:
		double x;
		double y;
	public:
		Point(double x0=0,double y0=0);
		~Point();
		void move(double dx,double dy);
		void show()const;
		Point copy(double dx,double dy) const;
		void reset(double x0=0,double y0=0);
};
#endif
