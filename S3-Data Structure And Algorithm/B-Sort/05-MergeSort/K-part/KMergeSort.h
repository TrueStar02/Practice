#ifndef KMERGESORT_H_
#define KMERGESORT_H_
class TopDownMergeSort
{	private:
		int * temp;
		void TopDown(int * arr,int beg,int end,int k);
		void Merge(int * arr,int * list,int * label,int k);
	public:
		~TopDownMergeSort(){}
		void operator()(int * arr,int size,int k);
};
void TopDownMergeSort::Merge(int * arr,int *list,int *label,int k)
{	int x,y,index;
	for(x=list[0];x<=list[k];x++)
		temp[x]=arr[x];
	for(x=list[0];x<=list[k];x++)
	{	index=0;
		for(y=1;y<k;y++)
		{	if(label[y]<list[y+1]&&temp[label[y]]<temp[label[index]])
				index=y;
		}
		arr[x]=temp[label[index]];
		label[index]++;
	}
			
}
void TopDownMergeSort::TopDown(int * arr,int beg,int end,int k)
{	if(beg<end) 
	{	int x,list[k+1],label[k+1];
		list[0]=beg;
		for(x=1;x<=k;x++)
		{	list[x]=label[x]=beg+x*(end-beg)/k;
			TopDown(arr,list[x-1],list[x],k);
		}
		Merge(arr,list,label,k);
	}
}
void TopDownMergeSort::operator()(int * arr,int size,int k)
{	temp=new int[size];
	TopDown(arr,0,size-1,k);
	delete [] temp;
	
}
#endif
