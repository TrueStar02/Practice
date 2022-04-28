#include<iostream>
using namespace std;
int main(void)
{	double tc=21.5;
	double && rr1=11.1;
	double && rr2=1.1*tc;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.precision(2);
	cout<<"tc :"<<tc<<" address:"<<&tc<<endl;
	cout<<"rr1:"<<rr1<<" address:"<<&rr1<<endl;
	cout<<"rr2:"<<rr2<<" address:"<<&rr2<<endl;
	return 0;
}
