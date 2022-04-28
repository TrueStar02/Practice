#ifndef VECTOR2_H_
#define VECTOR2_H_
#include<iostream>
#include<cmath>
using namespace std;
const double RTD=45.0/atan(1.0);
class Vector
{	private:
		double x;
		double y;
		bool polar;
	public:
		Vector();
		Vector(double n1,double n2,bool mo=0);
		~Vector();
		double x_val() const{return x;}
		double y_val() const{return y;}
		double r_val() const{return sqrt(x*x+y*y);}
		double theta_val() const{if(x==0&&y==0)return 0;return atan2(y,x);}
		void switch_mode();
		Vector operator+(const Vector & b)const;
		Vector operator-(const Vector & b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		double operator^(const Vector & b)const;//Inner Product
		double operator*(const Vector & b)const;//Outer Product
		friend Vector operator*(double n,const Vector & b){return b*n;}
		friend ostream & operator<<(ostream & os,const Vector & b);
};
#endif
