#ifndef QUICKSORT9_H_
#define QUICKSORT9_H_
#include<stack>
namespace VER1
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
		Pair tp;
		st.push(Pair(beg,end));
		while(!st.empty())
		{	tp=st.top();
			st.pop();
			if(tp.beg<tp.end-14)
			{	int low=tp.beg,mid=tp.beg+1,high=tp.end,temp;
				if(arr[tp.beg]>arr[tp.end])
				{	temp=arr[tp.beg];
					arr[tp.beg]=arr[tp.end];
					arr[tp.end]=temp;
				}
				if(arr[tp.beg+1]>arr[tp.end])
				{	temp=arr[tp.beg+1];
					arr[tp.beg+1]=arr[tp.end];
					arr[tp.end]=temp;
				}
				if(arr[tp.beg+1]>arr[tp.beg])
				{	temp=arr[tp.beg+1];
					arr[tp.beg+1]=arr[tp.beg];
					arr[tp.beg]=temp;
				}
				int key=arr[tp.beg];
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
				st.push(Pair(high+1,tp.end));
				st.push(Pair(tp.beg,low-1));
				
			}
			else if(tp.beg<tp.end)
				InsSrt(arr+tp.beg,tp.end-tp.beg+1);	
		}
	}
};
namespace VER2
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
		Pair tp;
		st.push(Pair(beg,end));
		while(!st.empty())
		{	tp=st.top();
			st.pop();
			if(tp.beg<tp.end-14)
			{	int low=tp.beg+1,lmid=tp.beg+1,hmid=tp.end,high=tp.end,temp;
				if(arr[tp.beg]>arr[tp.end])
				{	temp=arr[tp.beg];
					arr[tp.beg]=arr[tp.end];
					arr[tp.end]=temp;
				}
				if(arr[tp.beg+1]>arr[tp.end])
				{	temp=arr[tp.beg+1];
					arr[tp.beg+1]=arr[tp.end];
					arr[tp.end]=temp;
				}
				if(arr[tp.beg+1]>arr[tp.beg])
				{	temp=arr[tp.beg+1];
					arr[tp.beg+1]=arr[tp.beg];
					arr[tp.beg]=temp;
				}
				int key=arr[tp.beg];
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
				for(int tb=tp.beg;tb<low;tb++,hmid--)
				{	temp=arr[hmid];
					arr[hmid]=arr[tb];
					arr[tb]=temp;
				}	
				for(int te=tp.end;te>high;te--,lmid++)
				{	temp=arr[lmid];
					arr[lmid]=arr[te];
					arr[te]=temp;
				}
				st.push(Pair(lmid,tp.end));
				st.push(Pair(tp.beg,hmid));
				
			}
			else if(tp.beg<tp.end)
				InsSrt(arr+tp.beg,tp.end-tp.beg+1);	
		}
	}
};	
#endif
