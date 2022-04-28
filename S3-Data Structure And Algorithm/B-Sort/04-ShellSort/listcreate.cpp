#include<iostream>
using namespace std;
int mypow(int a,int b);
int main()
{	int x,m;
	for(x=1;(m=(mypow(3,x)-1)/2)<=200000000;x++)
		cout<<m<<",";
	cout<<endl<<1<<",";
	for(x=1;(m=mypow(4,x)+3*mypow(2,x-1)+1)<=200000000;x++)
		cout<<m<<",";
	cout<<endl;
	return 0;
}
int mypow(int a,int b)
{	int x,i=1;
	for(x=1;x<=b;x++)
		i*=a;
	return i;
}
