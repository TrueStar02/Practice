#ifndef VECTOR3_H_
#define VECTOR3_H_
#include<iostream>
using namespace std;
class Vector
{	private:
		double x;
		double y;
		double z;
	public:
		Vector();
		Vector(double a,double b,double c);
		~Vector();
		Vector operator+(const Vector & v)const;
		Vector operator-(const Vector & v)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		Vector operator/(double n)const;
		double operator^(const Vector & v)const; //Inner Product
		Vector operator*(const Vector & v)const; //Outer Product
		friend Vector operator*(double n,const Vector &v){return v*n;}
		friend ostream & operator<<(ostream & os,const Vector &v);
};
#endif
