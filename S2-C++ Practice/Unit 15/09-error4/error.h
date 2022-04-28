#include<iostream>
using namespace std;
class bad_hmean
{	private:
		double v1;
		double v2;
	public:
		bad_hmean(int m,int n):v1(m),v2(n){}
		void mesg(){cout<<"Input:"<<v1<<" "<<v2<<" is invalid for harmonic mean!\n";}
};
class bad_gmean
{	private:
		double v1;
		double v2;
	public:
		bad_gmean(int m,int n):v1(m),v2(n){}
		const char * mesg(){return "Input can't be negative!\n";}
};

