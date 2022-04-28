#include<cstdlib>
#include<functional>
#include<iostream>
#include<ctime>
#include<cassert>
#include "HeapSort.h"

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
	int test1[ele+1],test2[ele+1],test3[ele+1];
	clock_t beg,end;
	for(y=0;y<10;y++)
	{	cout<<"Case "<<y+1<<endl;
		for(x=0;x<=ele;x++)
			test1[x]=test2[x]=test3[x]=rand()%max+1;
		beg=clock();
		Test(test2,ele,HeapSort());
		end=clock();
		assert(IsSorted(test2+1,ele));
		cout<<"Time Used(Quick1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		/*beg=clock();
		Test(test1,ele,VER2::QuickSort());
		end=clock();
		assert(IsSorted(test1,ele));
		cout<<"Time Used(Quick2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test3,ele,VER3::QuickSort());
		end=clock();
		assert(IsSorted(test3,ele));
		cout<<"Time Used(Quick3):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";*/
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
