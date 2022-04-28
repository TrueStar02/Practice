#ifndef MERGESORT2_H_
#define MERGESORT2_H_
class TopDownMergeSort
{	private:
		int * temp;
		void TopDown(int * arr,int beg,int end);
		void Merge(int * arr,int beg,int mid,int end);
	public:
		~TopDownMergeSort(){}
		void operator()(int * arr,int size);
};
void TopDownMergeSort::Merge(int * arr,int beg,int mid,int end)
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
void TopDownMergeSort::TopDown(int * arr,int beg,int end)
{	if(beg<end) 
	{	int mid=(beg+end)/2;
		TopDown(arr,beg,mid);
		TopDown(arr,mid+1,end);
		Merge(arr,beg,mid,end);
	}
}
void TopDownMergeSort::operator()(int * arr,int size)
{	temp=new int[size];
	TopDown(arr,0,size-1);
	delete [] temp;
}
#endif
