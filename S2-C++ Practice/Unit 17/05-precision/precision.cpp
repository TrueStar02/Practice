#include<iostream>
using namespace std;
int main()
{	double p1=16.40;
	double p2=20.0/9.0;
	cout.setf(ios_base::showpoint);
	cout<<"Good 1:$"<<p1<<endl;
	cout<<"Good 2:$"<<p2<<endl;
	cout.precision(2);
	cout<<"Good 1:$"<<p1<<endl;
	cout<<"Good 2:$"<<p2<<endl;
	return 0;	
}
