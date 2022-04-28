#include<iostream>
using namespace std;
int Partition(int * arr,int beg,int end);
int Finding(int * arr,int k,int size);
int main()
{	int x,arr[12]={8,6,11,3,5,12,1,9,10,2,4,7};
	for(x=1;x<=12;x++)
		cout<<Finding(arr,x,12)<<" ";
	cout<<endl;
	return 0;
}
int Finding(int * arr,int k,int size)
{	int low=0,high=size-1,pivot;
	while(low<high)
	{	pivot=Partition(arr,low,high);
		if(pivot==k-1)
			return arr[pivot];
		else if(pivot>k-1)
			high=pivot-1;
		else
			low=pivot+1;
	}
	return arr[high];
}
int Partition(int * arr,int beg,int end)
{	int key,temp;
	if(arr[beg]>arr[end])
	{	temp=arr[beg];
		arr[beg]=arr[end];
		arr[end]=temp;
	}
	if(arr[beg+1]>arr[end])
	{	temp=arr[beg+1];
		arr[beg+1]=arr[end];
		arr[end]=temp;
	}
	if(arr[beg+1]>arr[beg])
	{	temp=arr[beg+1];
		arr[beg+1]=arr[beg];
		arr[beg]=temp;
	}
	key=arr[beg];
	while(beg<end)
	{	while(beg<end&&arr[end]>=key)
			end--;
		arr[beg]=arr[end];
		while(beg<end&&arr[beg]<=key)
			beg++;
		arr[end]=arr[beg];
	}
	arr[beg]=key;
	return beg;
}

