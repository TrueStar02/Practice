#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cassert>
#include "BubbleSort.h"
#include "SelectionSort.h"
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
	int test1[ele],test2[ele],test3[ele],test4[ele],test5[ele],test6[ele];
	for(x=0;x<ele;x++)
		test1[x]=test2[x]=test3[x]=test4[x]=test5[x]=test6[x]=rand()%max+1;
	clock_t beg=clock();
	Test(test1,ele,BubSrt2);
	clock_t end=clock();
	cout<<"Time Used(Bubble1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test2,ele,SeleSrt);
	end=clock();
	cout<<"Time Used(Select1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test5,ele,InsSrt0);
	end=clock();
	cout<<"Time Used(Insert0):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test4,ele,InsSrt1);
	end=clock();
	assert(IsSorted(test4,ele));
	cout<<"Time Used(Insert1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test3,ele,InsSrt2);
	end=clock();
	assert(IsSorted(test3,ele));
	cout<<"Time Used(Insert2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test6,ele,InsSrt3);
	end=clock();
	assert(IsSorted(test6,ele));
	cout<<"Time Used(Insert3):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";;
	return 0;
}
bool IsSorted(int * arr,int size)
{	int x;
	for(x=0;x<size-1;x++)
		if(arr[x]>arr[x+1])
			break;
	return (x==size-1);
}
