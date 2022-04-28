#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;
void BubSrt1(int * arr,int size);
void BubSrt2(int * arr,int size);
void BubSrt3(int * arr,int size);
void Test(int * arr,int size,void(*pf)(int * arr,int size)){pf(arr,size);}
int main()
{	srand((unsigned int)time(0));
	int x,ele,max;
	cout<<"Number of elements:";
	cin>>ele;
	cout<<"Max Value:";
	cin>>max;
	int test1[ele],test2[ele],test3[ele];
	for(x=0;x<ele;x++)
		test1[x]=test2[x]=test3[x]=rand()%max+1;
	clock_t beg=clock();
	Test(test1,ele,BubSrt1);
	clock_t end=clock();
	cout<<"Time Used(Algo1):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test2,ele,BubSrt2);
	end=clock();
	cout<<"Time Used(Algo2):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	beg=clock();
	Test(test3,ele,BubSrt3);
	end=clock();
	cout<<"Time Used(Algo3):"<<double(end-beg)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
