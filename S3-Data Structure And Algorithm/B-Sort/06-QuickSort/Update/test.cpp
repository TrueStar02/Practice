#include<cstdlib>
#include<functional>
#include<iostream>
#include<ctime>
#include<cassert>
#include "QuickSort.h"
#include "QuickSort2.h"
using namespace std;
void Test(int * arr,int size,function<void(int * ,int )> pf){pf(arr,size);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,y,ele,max;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test1[ele],test2[ele],test3[ele],test4[ele],test5[ele],test6[ele];
	clock_t beg,end;
	for(y=0;y<10;y++)
	{	cout<<"Case "<<y+1<<endl;
		for(x=0;x<ele;x++)
			test1[x]=test2[x]=test3[x]=test4[x]=test5[x]=test6[x]=rand()%max+1;
		beg=clock();
		Test(test2,ele,ORIGIN::VER1::QuickSort());
		end=clock();
		assert(IsSorted(test2,ele));
		cout<<"Time Used(Quick1 ORIGIN):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test1,ele,ORIGIN::VER2::QuickSort());
		end=clock();
		assert(IsSorted(test1,ele));
		cout<<"Time Used(Quick2 ORIGIN):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test3,ele,ORIGIN::VER2::QuickSort());
		end=clock();
		assert(IsSorted(test3,ele));
		cout<<"Time Used(Quick3 ORIGIN):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test4,ele,UPDATE::VER1::QuickSort());
		end=clock();
		assert(IsSorted(test4,ele));
		cout<<"Time Used(Quick1 UPDATE):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test5,ele,UPDATE::VER2::QuickSort());
		end=clock();
		assert(IsSorted(test5,ele));
		cout<<"Time Used(Quick2 UPDATE):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test6,ele,UPDATE::VER2::QuickSort());
		end=clock();
		assert(IsSorted(test6,ele));
		cout<<"Time Used(Quick3 UPDATE):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
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
