#ifndef MERGESORT_H_
#define MERGESORT_H_

void Merge(int * arr,int beg,int mid,int end,int *temp)
{	int x,i=beg,j=mid+1;
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
{	if(beg<end) 
	{	int mid=(beg+end)/2;
		TopDown(arr,beg,mid,temp);
		TopDown(arr,mid+1,end,temp);
		Merge(arr,beg,mid,end,temp);
	}
}
void TopDownMergeSort(int * arr,int size)
{	int temp[size];
	TopDown(arr,0,size-1,temp);
}
void BottomUpMergeSort(int * arr,int size)
{	int x,y;
	int temp[size];
	for(x=1;x<size;x*=2)
	for(y=0;y<size-x;y+=2*x)
		Merge(arr,y,y+x-1,((size-1>y+2*x-1)?(y+2*x-1):(size-1)),temp);
}
#endif
