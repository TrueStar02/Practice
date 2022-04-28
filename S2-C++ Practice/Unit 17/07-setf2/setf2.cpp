#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{	int x;
	cout.setf(ios_base::showpoint);
	cout.setf(ios_base::showpos);
	cout.precision(3);
	ios_base::fmtflags old=cout.setf(ios_base::scientific,ios_base::floatfield);
	cout.setf(ios_base::left,ios_base::adjustfield);
	cout<<"Left Justification:\n";
	for(x=1;x<=41;x+=10)
	{	cout.width(4);
		cout<<x<<'|';
		cout.width(12);
		cout<<sqrt(x)<<"|\n";
	}
	cout.setf(old,ios_base::floatfield);
	cout.setf(ios_base::internal,ios_base::adjustfield);
	cout<<"Internal Justification:\n";
	for(x=1;x<=41;x+=10)
	{	cout.width(4);
		cout<<x<<'|';
		cout.width(12);
		cout<<sqrt(x)<<"|\n";
	}
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.setf(ios_base::right,ios_base::adjustfield);
	cout<<"Right Justification:\n";
	for(x=1;x<=41;x+=10)
	{	cout.width(4);
		cout<<x<<'|';
		cout.width(12);
		cout<<sqrt(x)<<"|\n";
	}
	return 0;
}
