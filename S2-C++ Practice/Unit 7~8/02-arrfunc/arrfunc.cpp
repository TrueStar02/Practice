#include<iostream>
#include<array>
using namespace std;
void twice(array<int,5> *arr);
int Sum(array<int,5>arr);
int main()
{	array<int,5>arr={0,1,2,3,4};
	twice(&arr);
	int sum=Sum(arr);
	cout<<"Total:"<<sum<<endl;
}
void twice(array<int,5> *arr)
{	int x;
	for(x=0;x<=4;x++)
		(*arr)[x]*=2;
}
int Sum(array<int,5>arr)
{	int sum=0,x;
	for(x=0;x<5;x++)
		sum+=arr[x];
	return sum;
}
