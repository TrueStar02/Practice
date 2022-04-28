#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_
#include<iostream>
void BubSrt1(int * arr,int size)
{	int x,y,temp;
	for(x=0;x<size-1;x++)
	for(y=x+1;y<size;y++)
		if(arr[x]>arr[y])
		{	temp=arr[x];
			arr[x]=arr[y];
			arr[y]=temp;
		}
}
void BubSrt2(int * arr,int size)
{	int x,y,temp;
	for(x=1;x<size;x++)
	for(y=size-1;y>=x;y--)
		if(arr[y]<arr[y-1])
		{	temp=arr[y];
			arr[y]=arr[y-1];
			arr[y-1]=temp;
		}
}
void BubSrt3(int * arr,int size)
{	int x,y,temp;
	bool flag=0;
	for(x=1;x<size;x++)
	{	flag=1;
		for(y=size-1;y>=x;y--)
			if(arr[y]<arr[y-1])
			{	temp=arr[y];
				arr[y]=arr[y-1];
				arr[y-1]=temp;
				flag=0;
			}
		if(flag) 
			break;
	}
}
#endif
