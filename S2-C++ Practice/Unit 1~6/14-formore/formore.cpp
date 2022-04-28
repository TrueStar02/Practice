#include<iostream>
#include<array>
using namespace std;
int main(void)
{	array<long double,100>num;
	int x;
	num[0]=1;
	for(x=1;x<100;x++)
		num[x]=num[x-1]*(x+1);	
	for(x=0;x<100;x++)
		cout<<x+1<<"!="<<num[x]<<endl;
	return 0;
}
