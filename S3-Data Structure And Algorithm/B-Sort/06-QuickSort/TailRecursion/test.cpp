#include<cstdlib>
#include<functional>
#include<iostream>
#include<ctime>
#include<cassert>
#include "QuickSort6.h"
#include "QuickSort7.h"
using namespace std;
void Test(int * arr,int size,function<void(int * ,int )> pf){pf(arr,size);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,y,ele,max;
	cout<<"Number of elements:";
	cin>>ele;
	int test1[ele],test2[ele],test3[ele],test4[ele],test5[ele],test6[ele];
	clock_t beg,end;
	for(y=65536*4;y>=2;y/=2)
	{	cout<<"Max:"<<y<<endl;
		for(x=0;x<ele;x++)
			test1[x]=test2[x]=test3[x]=rand()%y+1;
		beg=clock();
		Test(test2,ele,VER0::QuickSort());
		end=clock();
		assert(IsSorted(test2,ele));
		cout<<"Time Used(NORMAL Quick):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test1,ele,VER1::QuickSort());
		end=clock();
		assert(IsSorted(test1,ele));
		cout<<"Time Used(TRIPLE Quick):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test3,ele,VER2::QuickSort());
		end=clock();
		assert(IsSorted(test3,ele));
		cout<<"Time Used(TRIPLE Quick):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
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
