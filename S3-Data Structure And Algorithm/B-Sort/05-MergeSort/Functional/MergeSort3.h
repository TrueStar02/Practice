#ifndef MERGESORT3_H_
#define MERGESORT3_H_
class BottomUpMergeSort
{	private:
		int * temp;
		void Merge(int * arr,int beg,int mid,int end);
	public:
		~BottomUpMergeSort(){delete [] temp;}
		void operator()(int * arr,int size);
};
void BottomUpMergeSort::Merge(int * arr,int beg,int mid,int end)
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

void BottomUpMergeSort::operator()(int * arr,int size)
{	int x,y;
	temp=new int[size];
	for(x=1;x<size;x*=2)
	for(y=0;y<size-x;y+=2*x)
		Merge(arr,y,y+x-1,((size-1>y+2*x-1)?(y+2*x-1):(size-1)));
}
#endif
