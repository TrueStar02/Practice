#ifndef QUICKSORT6_H_
#define QUICKSORT6_H_
namespace VER0
{	class QuickSort
	{	private:
			void InsSrt(int * arr,int size);
			void QSort(int * arr,int beg,int end);
			int Partition(int * arr,int beg,int end);
		public:
			void operator()(int * arr,int size){QSort(arr,0,size-1);}
	};
	void QuickSort::InsSrt(int * arr,int size)
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
	void QuickSort::QSort(int * arr,int beg,int end)
	{	while(beg<end-14)
		{	int pivot=Partition(arr,beg,end);
			QSort(arr,beg,pivot-1);
			beg=pivot+1;
		}
		if(beg<end)
			InsSrt(arr+beg,end-beg+1);
		
	}
	int QuickSort::Partition(int * arr,int beg,int end)
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
};
#endif
