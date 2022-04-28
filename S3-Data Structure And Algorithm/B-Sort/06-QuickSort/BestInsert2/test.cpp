#include<cstdlib>
#include<functional>
#include<iostream>
#include<ctime>
#include<cassert>
#include "QuickSort4.h"
using namespace std;
void Test(int * arr,int size,int m,function<void(int * ,int,int)> pf){pf(arr,size,m);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,y,ele,max,z,temp;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test[50][ele];
	double tot_t[50]={0};
	clock_t beg,end;
	for(y=0;y<100;y++)
	{	for(x=0;x<ele;x++)
		{	temp=rand()%max+1;
			for(z=0;z<50;z++)
				test[z][x]=temp;
		}
		for(z=0;z<50;z++)
		{	beg=clock();
			Test(test[z],ele,z+1,QuickSort());
			end=clock();
			assert(IsSorted(test[z],ele));
			tot_t[z]+=double(end-beg)/CLOCKS_PER_SEC;
		}
	}
	for(z=0;z<50;z++)
		cout<<"Group"<<z+1<<":"<<tot_t[z]/100<<"s\n";
	return 0;
}
bool IsSorted(int * arr,int size)
{	int x;
	for(x=0;x<size-1;x++)
		if(arr[x]>arr[x+1])
			break;
	return (x==size-1);
}
