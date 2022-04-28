#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cassert>
#include<iomanip>
#include "ShellSort.h"
using namespace std;
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,ele,max;
	clock_t beg,end;
	for(ele=128;ele<100000000;ele*=2)
	{	int arr[ele];
		for(x=0;x<ele;x++)
			arr[x]=rand()%1000000;
		beg=clock();
		Test(arr,ele,ShellSrt2);
		end=clock();
		cout<<"Size:"<<setw(8)<<ele<<"  Time Used:"<<setw(10)<<double(end-beg)/CLOCKS_PER_SEC<<endl;
		
	}
	return 0;
}
bool IsSorted(int * arr,int size)
{	int x;
	for(x=0;x<size-1;x++)
		if(arr[x]>arr[x+1])
			break;
	return (x==size-1);
}
