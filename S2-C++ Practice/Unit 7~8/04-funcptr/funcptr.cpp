#include<iostream>
using namespace std;
const int * func0(const int *ptr,int n);
const int * func1(const int *ptr,int n);
const int * func2(const int *ptr,int n);
int main(void)
{	const int * (* pf[3])(const int *ptr,int n)={func0,func1,func2};
	const int * (* (*ppf)[3])(const int *ptr,int n)=&pf;
	int x;
	int arr[3]={0,1,2};
	for(x=0;x<3;x++)
		cout<<*(pf[x](arr,3))<<endl;
	for(x=0;x<3;x++)
		cout<<*((*ppf)[x](arr,3))<<endl;
	return 0;
}
const int * func0(const int *ptr,int n)
{	return ptr;''	`
}
const int * func1(const int *ptr,int n)
{	return ptr+1;
}
const int * func2(const int *ptr,int n)
{	return ptr+2;
}
