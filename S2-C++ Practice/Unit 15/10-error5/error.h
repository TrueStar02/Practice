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
class demo
{	private:
		string word;
	public:
		demo(const string & str):word(str){cout<<"demo "<<word<<" created\n";}
		~demo(){cout<<"demo "<<word<<" destroyed\n";}
		void show() const{cout<<"demo "<<word<<" is living\n";}
};
