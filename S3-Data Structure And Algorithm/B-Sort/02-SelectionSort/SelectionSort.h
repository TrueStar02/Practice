#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_
#include<iostream>
void SeleSrt(int *arr,int size)
{	int x,y,index,temp;
	for(x=0;x<size;x++)
	{	index=x;
		for(y=x+1;y<size;y++)
			if(arr[index]>arr[y])
				index=y;
		if(index!=x)
		{	temp=arr[x];
			arr[x]=arr[index];
			arr[index]=temp;
		}
	}
}
#endif
