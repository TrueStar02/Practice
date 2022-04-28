#include<iostream>
#include<stdexcept>
using namespace std;
class base_error:public logic_error
{	private:
		double v1;
		double v2;
	public:
		base_error(const string & s,double x,double y):logic_error(s),v1(x),v2(y){}
		virtual void report() const=0;
};
class bad_hmean:public base_error
{	public:
		explicit bad_hmean(double x,double y,const string & s="Input is invalid for harmonic mean!\n"):base_error(s,x,y){}
		virtual void report() const;
};
class bad_gmean:public base_error
{	public:
		explicit bad_gmean(double x,double y,const string & s="Input is invalid for geometric mean!\n"):base_error(s,x,y){}
		virtual void report() const;
};
void base_error::report() const
{	cout<<"Your input:"<<v1<<" "<<v2<<endl;
}
void bad_hmean::report() const
{	cout<<"In bad_hmean()\n";
	base_error::report();
	cout<<what();
}
void bad_gmean::report() const
{	cout<<"In bad_gmean()\n";
	base_error::report();
	cout<<what();
}
