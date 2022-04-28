#include<iostream>
using namespace std;
int main(void)
{	cout.setf(ios_base::fixed,ios_base::floatfield);
	float fx=10.0/3.0;
	double dx=10.0/3.0;
	cout<<"Float:"<<fx<<endl;
	fx=1000000*fx;
	cout<<"1M Float:"<<fx<<endl;
	cout<<"Double:"<<dx<<endl;
	dx=1000000*dx;
	cout<<"1M Double:"<<dx<<endl;
	return 0;
}

