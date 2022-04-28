#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cassert>
#include<functional>
#include "KMergeSort.h"
#include "MergeSort4.h"
using namespace std;
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
void Test(int * arr,int size,int k,function<void(int *,int,int)> pf){pf(arr,size,k);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,y,ele,max,z;
	clock_t beg,end;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test[10][ele];
	for(y=1;y<=10;y++)
	{	for(x=0;x<ele;x++)
		for(z=0;z<10;x++)
			test[z][x]=rand()%max+1;
		cout<<"Case "<<y<<endl;
		beg=clock();
		Test(test[0],ele,UPDATE::TopDownMergeSort);
		end=clock();
		assert(IsSorted(test[0],ele));
		cout<<"Time Used(Origin):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		for(z=1;z<10;z++)
		beg=clock();
		Test(test[z],ele,z+1,TopDownMergeSort());
		end=clock();
		assert(IsSorted(test[z],ele));
		cout<<"Time Used(Merge"<<z+1<<"):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
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
