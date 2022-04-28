#ifndef QUICKSORT5_H_
#define QUICKSORT5_H_
namespace VER1
{	class QuickSort
	{	private:
			void InsSrt(int * arr,int size);
			void QSort(int * arr,int beg,int end);
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
		{	int low=beg,mid=beg+1,high=end,temp;
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
			int key=arr[beg];
			while(high>=mid)
			{	if(arr[mid]<key)
				{	temp=arr[low];
					arr[low]=arr[mid];
					arr[mid]=temp;
					mid++;
					low++;
				}
				else if(arr[mid]==key)
					mid++;
				else
				{	temp=arr[high];
					arr[high]=arr[mid];
					arr[mid]=temp;
					high--;
				}
			}
			QSort(arr,beg,low-1);
			beg=high+1;
		}
		if(beg<end)
			InsSrt(arr+beg,end-beg+1);	
	}
};
namespace VER2
{	class QuickSort
	{	private:
			void InsSrt(int * arr,int size);
			void QSort(int * arr,int beg,int end);
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
		{	int low=beg+1,lmid=beg+1,hmid=end,high=end,temp;
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
			
			int key=arr[beg];
			while(lmid<=hmid)
			{	while(lmid<=hmid)
					if(key==arr[lmid])
					{	temp=arr[lmid];
						arr[lmid]=arr[low];
						arr[low]=temp;
						low++;
						lmid++;
					}
					else if(key>arr[lmid])
						lmid++;
					else
						break;
				while(lmid<hmid)
					if(key==arr[hmid])
					{	temp=arr[hmid];
						arr[hmid]=arr[high];
						arr[high]=temp;
						high--;
						hmid--;
					}
					else if(key<arr[hmid])
						hmid--;
					else
						break;
				if(lmid>=hmid)
					break;
				temp=arr[hmid];
				arr[hmid]=arr[lmid];
				arr[lmid]=temp;
				hmid--;
				lmid++;
			}
			if(lmid==hmid&&arr[lmid]<key)
				lmid++;
			else if(lmid==hmid&&arr[lmid]>key)
				hmid--;
			for(int tb=beg;tb<low;tb++,hmid--)
			{	temp=arr[hmid];
				arr[hmid]=arr[tb];
				arr[tb]=temp;
			}	
			for(int te=end;te>high;te--,lmid++)
			{	temp=arr[lmid];
				arr[lmid]=arr[te];
				arr[te]=temp;
			}
			QSort(arr,beg,hmid);
			beg=lmid;
		}
		if(beg<end)
			InsSrt(arr+beg,end-beg+1);	
	}
};	
#endif
