#ifndef QUICKSORT8_H_
#define QUICKSORT8_H_
#include<stack>
	namespace VER0
	{	using namespace std;
		class QuickSort
		{	private:
				class Pair
				{	public:
						int beg;
						int end;
						Pair(){}
						Pair(int b,int e):beg(b),end(e){}
				};
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
		{	stack<Pair> st;
			st.push(Pair(beg,end));
			Pair temp;
			int pivot;
			while(!st.empty())
			{	temp=st.top();
				st.pop();
				if(temp.end-temp.beg<14)
					InsSrt(arr+temp.beg,temp.end-temp.beg+1);
				else
				{	pivot=Partition(arr,temp.beg,temp.end);
					st.push(Pair(pivot+1,temp.end));
					st.push(Pair(temp.beg,pivot-1));
				}
			}
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
