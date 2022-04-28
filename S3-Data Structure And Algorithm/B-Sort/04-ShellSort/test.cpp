#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cassert>
#include "ShellSort.h"
#include "InsertionSort.h"
using namespace std;
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,ele,max;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test1[ele],test2[ele],test3[ele],test4[ele];
	for(x=0;x<ele;x++)
		test1[x]=test2[x]=test3[x]=test4[x]=rand()%max+1;
	clock_t beg=clock();
	Test(test1,ele,InsSrt1);
	clock_t end=clock();
	assert(IsSorted(test1,ele));
	cout<<"Time Used(Insert1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test3,ele,InsSrt2);
	end=clock();
	assert(IsSorted(test3,ele));
	cout<<"Time Used(Insert2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test2,ele,ShellSrt1);
	end=clock();
	assert(IsSorted(test2,ele));
	cout<<"Time Used( Shell1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test4,ele,ShellSrt2);
	end=clock();
	assert(IsSorted(test4,ele));
	cout<<"Time Used( Shell2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
bool IsSorted(int * arr,int size)
{	int x;
	for(x=0;x<size-1;x++)
		if(arr[x]>arr[x+1])
			break;
	return (x==size-1);
}
