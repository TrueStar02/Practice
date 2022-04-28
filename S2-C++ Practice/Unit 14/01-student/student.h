#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<valarray>
using namespace std;
class Student
{	private:
		string name;
		valarray<double> scores;
		ostream & arr_out(ostream & os) const;
	public:
		Student();
		explicit Student(const string & s):name(s),scores() {}
		explicit Student(int n):name("Anonymous"),scores(n) {}
		Student(const string & s,const valarray<double> & a):name(s),scores(a) {}
		Student(const string & s,double * pd,int n):name(s),scores(pd,n) {}
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
