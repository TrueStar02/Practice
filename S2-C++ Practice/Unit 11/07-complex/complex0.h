#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>
#include<cmath>
using namespace std;
class Complex
{	private:
		double a;
		double b;
	public:
		Complex();
		Complex(double m,double n=0);
		~Complex();
		double length() const;
		Complex operator+(const Complex &c)const;
		Complex operator-(const Complex &c)const;
		Complex operator*(const Complex &c)const;
		Complex operator/(const Complex &c)const;
		Complex operator-()const;
		Complex operator~()const;
		friend ostream & operator<<(ostream & os,const Complex &c);
		friend istream & operator>>(istream & is,Complex &c);
};
#endif
