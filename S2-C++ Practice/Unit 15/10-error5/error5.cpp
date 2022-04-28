#include "error.h"
#include<cmath>
double hmean(double a,double b);
double gmean(double a,double b);
double means(double a,double b);
int main()
{	double x,y,z;
	cout<<"Enter two numbers:";
	while(cin>>x>>y)
	{	demo d1("Found in block in main()");
		try
		{	z=means(x,y);
			cout<<"Result of mean mean:"<<z<<endl;
		}
		catch(bad_hmean & bh)
		{	bh.mesg();
			cout<<"Try again:";
			continue;
		}
		catch(bad_gmean & bg)
		{	cout<<bg.mesg();
			cout<<"SB!\n";
			break;
		}
		d1.show();
		cout<<"Enter two numbers:";
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
double means(double a,double b)
{	double am,gm,hm;
	demo d2("Found in means()");
	am=(a+b)/2.0;
	try
	{	hm=hmean(a,b);
		gm=gmean(a,b);
	}
	catch(bad_hmean & bh)
	{	bh.mesg();
		cout<<"Cought in means()\n";
		throw;
	}
	return (am+gm+hm)/3.0;
}
