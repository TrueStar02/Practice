#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_
void InsSrt0(int * arr,int size)
{	int x,y,temp;
	for(x=1;x<size;x++)
	for(y=0;y<x;y++)
		if(arr[y]>arr[x])
		{	temp=arr[y];
			arr[y]=arr[x];
			arr[x]=temp;
		}
}
void InsSrt1(int * arr,int size)
{	int x,y,temp;
	for(x=1;x<size;x++)
	for(y=x;y>0&&arr[y]<arr[y-1];y--)
		{	temp=arr[y];
			arr[y]=arr[y-1];
			arr[y-1]=temp;
		}
}
void InsSrt2(int * arr,int size)
{	int x,y,temp,index;
	for(x=1;x<size;x++)
	{	temp=arr[x];
		for(y=x-1;y>=0;y--)
			if(arr[y]>temp)
			 	arr[y+1]=arr[y];
			 else
			 {	arr[y+1]=temp;
			 	break;
			 }
		if(y==-1)
		 	arr[0]=temp;
	}
}

#endif
