#include<iostream>
using namespace std;
long double Sum(void){return 0;}
template<typename T,typename ... Args>
long double Sum(T t,Args ... args){	return t+Sum(args ...);}
int main(void)
{	int x=1;
	float y=1.06;
	double m=91.77;
	long double z=8.1931;
	cout<<Sum(7.09,x,-0.08,y,z,m)<<endl;
	return 0;
}

