#ifndef MERGESORT0_H_
#define MERGESORT0_H_

void Merge(int * arr,int beg,int mid,int end)
{	int x,i=beg,j=mid+1,temp[end+1];
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
void TopDown(int * arr,int beg,int end)
{	if(beg<end) 
	{	int mid=(beg+end)/2;
		TopDown(arr,beg,mid);
		TopDown(arr,mid+1,end);
		Merge(arr,beg,mid,end);
	}
}
void TopDownMergeSort0(int * arr,int size)
{	
	TopDown(arr,0,size-1);
}
void BottomUpMergeSort0(int * arr,int size)
{	int x,y;
	
	for(x=1;x<size;x*=2)
	for(y=0;y<size;y+=2*x)
		Merge(arr,y,y+x-1,((size-1>y+2*x-1)?(y+2*x-1):(size-1)));
}
#endif
