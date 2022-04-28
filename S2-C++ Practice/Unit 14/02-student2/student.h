#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<valarray>
using namespace std;
class Student:private string,private valarray<double>
{	private:
		ostream & arr_out(ostream & os) const;
	public:
		Student();
		explicit Student(const string & s):string(s),valarray<double>() {}
		explicit Student(int n):string("Anonymous"),valarray<double>(n) {}
		Student(const string & s,const valarray<double> & a):string(s),valarray<double>(a) {}
		Student(const string & s,double * pd,int n):string(s),valarray<double>	(pd,n) {}
		~Student() {}
		double Average() const;
		const string & Name() const;
		double & operator[](int i);
		double operator[](int i) const;
		friend istream & operator>>(istream & is,Student & stu);
		friend istream & getline(istream & is,Student & stu);
		friend ostream & operator<<(ostream & os,Student & stu);		
};
#endif
