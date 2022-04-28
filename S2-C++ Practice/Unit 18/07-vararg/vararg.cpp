#include<iostream>
using namespace std;
void Show() {};
template<typename T>
void Show(const T & t){cout<<t<<endl;}
template<typename T,typename ... Args>
void Show(const T & t,const Args & ... args)
{	cout<<t<<", ";
	Show(args...);
}
int main()
{	double x=6;
	string t="abasjh";
	Show(5,t,7,8.6,x*x,"cyc");
	return 0;
}
