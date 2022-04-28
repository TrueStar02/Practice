#include "error.h"
#include<cmath>
#include<typeinfo>
double hmean(double a,double b);
double gmean(double a,double b);
int main()
{	double x,y,z;
	cout<<"Enter two numbers:";
	while(cin>>x>>y)
	{	try
		{	z=hmean(x,y);
			cout<<"Result of harmonic mean:"<<z<<endl;
			cout<<"Result of geometric mean:"<<gmean(x,y)<<endl;
			cout<<"Enter two numbers:";
		}
		catch(base_error & b)
		{	b.report();
			cout<<"SB!\n";
			break;
		}
	}
	cout<<"Bye~\n";
	return 0;
}
double hmean(double a,double b)
{	double z;
	if(a+b==0)
	{	cout<<"Invalid Input!\n";
		throw bad_hmean(a,b);
	}
	else
	{	z=2.0*a*b/(a+b);
		return z;
	}
}
double gmean(double a,double b)
{	if(a<0||b<0)
	{	cout<<"Invalid Input!\n";
		throw bad_gmean(a,b);
	}
	else
		return sqrt(a*b);
}
