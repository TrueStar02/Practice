#include<cstdlib>
#include<iostream>
#include<ctime>
#include "BubbleSort.h"
#include "SelectionSort.h"
using namespace std;
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
int main()
{	srand((unsigned int)time(0));
	int x,ele,max;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test1[ele],test2[ele];
	for(x=0;x<ele;x++)
		test1[x]=test2[x]=rand()%max+1;
	clock_t beg=clock();
	Test(test1,ele,BubSrt2);
	clock_t end=clock();
	cout<<"Time Used(Bubble):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test2,ele,SeleSrt);
	end=clock();
	cout<<"Time Used(Select):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
