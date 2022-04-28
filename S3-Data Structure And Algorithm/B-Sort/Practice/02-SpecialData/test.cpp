#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cassert>
#include "ShellSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
using namespace std;
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
bool IsSorted(int * arr,int size);
int main()
{	srand((unsigned int)time(0));
	int x,ele,max,y;
	clock_t beg,end;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test[4][4][ele];//dim1:0-Sorted 1-Inversed 2-95% Sorted 3-Bool Value dim2:0-BubbleSort 1-SelectionSort 2-InsertionSort 3-ShellSort
	for(y=0;y<3;y++)
	{	for(x=0;x<ele;x++)
		{	test[0][y][x]=test[2][y][x]=x;
			test[1][y][x]=ele-1-x;
			test[3][y][x]=rand()%2;
		}
 		for(x=0;x<ele/20;x++)
 		{	test[2][y][rand()%ele]=rand()%max+1;
 		}
	}
	cout<<"Sorted Array:\n";
	{	beg=clock();
		Test(test[0][0],ele,BubSrt2);
		end=clock();
		cout<<"Time Used(Bubble):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[0][1],ele,SeleSrt);
		end=clock();
		cout<<"Time Used(Select):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[0][2],ele,InsSrt3);
		end=clock();
		cout<<"Time Used(Insert):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[0][3],ele,ShellSrt2);
		end=clock();
		cout<<"Time Used( Shell):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	}
	cout<<"Inversed Array:\n";
	{	beg=clock();
		Test(test[1][0],ele,BubSrt2);
		end=clock();
		cout<<"Time Used(Bubble):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[1][1],ele,SeleSrt);
		end=clock();
		cout<<"Time Used(Select):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[1][2],ele,InsSrt3);
		end=clock();
		cout<<"Time Used(Insert):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[1][3],ele,ShellSrt2);
		end=clock();
		cout<<"Time Used( Shell):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	}
	cout<<"95% Sorted Array:\n";
	{	beg=clock();
		Test(test[2][0],ele,BubSrt2);
		end=clock();
		cout<<"Time Used(Bubble):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[2][1],ele,SeleSrt);
		end=clock();
		cout<<"Time Used(Select):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[2][2],ele,InsSrt3);
		end=clock();
		cout<<"Time Used(Insert):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[2][3],ele,ShellSrt2);
		end=clock();
		cout<<"Time Used( Shell):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	}
	cout<<"Bool Array:\n";
	{	beg=clock();
		Test(test[3][0],ele,BubSrt2);
		end=clock();
		cout<<"Time Used(Bubble):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[3][1],ele,SeleSrt);
		end=clock();
		cout<<"Time Used(Select):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[3][2],ele,InsSrt3);
		end=clock();
		cout<<"Time Used(Insert):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
		beg=clock();
		Test(test[3][3],ele,ShellSrt2);
		end=clock();
		cout<<"Time Used( Shell):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
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
