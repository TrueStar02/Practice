#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cassert>
#include "MergeSort.h"
#include "MergeSort4.h"
using namespace std;
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,y,ele,max;
	clock_t beg,end;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test1[ele],test2[ele],test3[ele],test4[ele],test5[ele],test6[ele];
	for(y=1;y<=10;y++)
	{	for(x=0;x<ele;x++)
			test1[x]=test2[x]=test3[x]=test5[x]=test4[x]=test6[x]=rand()%max+1;
		cout<<"Case "<<y<<endl;
		beg=clock();
		Test(test4,ele,ORIGIN::TopDownMergeSort);
		end=clock();
		assert(IsSorted(test4,ele));
		cout<<"Time Used(Merge1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test5,ele,ORIGIN::BottomUpMergeSort);
		end=clock();
		assert(IsSorted(test5,ele));
		cout<<"Time Used(Merge2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test1,ele,UPDATE::TopDownMergeSort);
		end=clock();
		assert(IsSorted(test1,ele));
		cout<<"Time Used(Merge1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test3,ele,UPDATE::BottomUpMergeSort);
		end=clock();
		assert(IsSorted(test3,ele));
		cout<<"Time Used(Merge2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
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
