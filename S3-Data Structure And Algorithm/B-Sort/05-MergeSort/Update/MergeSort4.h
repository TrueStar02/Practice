#ifndef MERGESORT4_H_
#define MERGESORT4_H_
namespace UPDATE
{	void InsSrt(int * arr,int size)
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
	void Merge(int * arr,int beg,int mid,int end,int *temp)
	{	int x,i=beg,j=mid+1;
		if(arr[mid]<arr[mid+1])
			return;
		for(x=beg;x<=end;x++)
			temp[x]=arr[x];
		for(x=beg;x<=end;x++)
			if(i>mid)
			{	arr[x]=temp[j];
				j++;
			}
			else if(j>end)
			{	arr[x]=temp[i];
				i++;
			}
			else if(temp[i]<temp[j])
			{	arr[x]=temp[i];
				i++;
			}
			else
			{	arr[x]=temp[j];
				j++;
			}
	}
	void TopDown(int * arr,int beg,int end,int * temp)
	{	if(beg<end-14) 
		{	int mid=(beg+end)/2;
			TopDown(arr,beg,mid,temp);
			TopDown(arr,mid+1,end,temp);
			Merge(arr,beg,mid,end,temp);
		}
		else if(beg<end)
			InsSrt(arr+beg,end-beg+1);
	}
	void TopDownMergeSort(int * arr,int size)
	{	int temp[size];
		TopDown(arr,0,size-1,temp);
	}
	void BottomUpMergeSort(int * arr,int size)
	{	int x,y;
		int temp[size];
		for(y=0;y<size;y+=15)
			InsSrt(arr+y,((size-y)>15?15:(size-y)));
		for(x=15;x<size;x*=2)
		for(y=0;y<size-x;y+=2*x)
			Merge(arr,y,y+x-1,((size-1>y+2*x-1)?(y+2*x-1):(size-1)),temp);
	}
};
#endif
