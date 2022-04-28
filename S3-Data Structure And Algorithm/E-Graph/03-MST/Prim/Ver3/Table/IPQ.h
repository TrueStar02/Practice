#ifndef IPQ_H_
#define IPQ_H_
#include<vector>
#include<string>
#include<iostream>
using namespace std;
const int inf=1024*1024*1024;
class IPQ
{	private:
		vector<int>	index;
		vector<int> heap;
		vector<int> ele;
		void Sink(int beg,int end);
		void Swim(int beg,int end);
	public:
		IPQ(){heap.push_back(0);index.resize(100,0);ele.resize(100,inf);}
		void change(int s,int i);
		bool empty(void){return heap.size()==1;} 
		int size(void) const{return heap.size()-1;}
		bool push(const int & s,int i);
		int pop(int & index);
		bool contains(int i){return ele[i]!=inf;}
		void Debug()
		{	int x;
			for(x=1;x<heap.size();x++)
				cout<<heap[x]<<" "<<index[heap[x]]<<" "<<ele[heap[x]]<<endl;
		}	
};
void IPQ::Sink(int beg,int end)
{	int x;
	heap[0]=heap[beg];
	for(x=beg*2;x<=end;x*=2)
	{	if(x<end&&ele[heap[x]]>ele[heap[x+1]])
			x++;
		if(ele[heap[0]]<=ele[heap[x]])
			break;
		heap[beg]=heap[x];
		index[heap[x]]=beg;
		beg=x;
	}
	heap[beg]=heap[0];
	index[heap[beg]]=beg;
}
void IPQ::Swim(int beg,int end)
{	int x;
	heap[0]=heap[end];
	for(x=end/2;x>=1;x/=2)
	{	if(ele[heap[0]]>=ele[heap[x]])
			break;
		heap[end]=heap[x];
		index[heap[x]]=end;
		end=x;
	}
	heap[end]=heap[0];
	index[heap[end]]=end;
}
void IPQ::change(int s,int i)
{	ele[i]=s;
	if(index[i]>1&&ele[i]<ele[heap[index[i]/2]])
		Swim(1,index[i]);
	else
		Sink(index[i],heap.size()-1);
}
bool IPQ::push(const int & s,int i)
{	if(index[i])
		return 0;
	heap.push_back(i);
	if(i>index.size()-1)
	{	index.resize(i+1,0);
		ele.resize(i+1,inf);
	}
	index[i]=heap.size()-1;
	ele[i]=s;
	Swim(1,heap.size()-1);
	return 1;
}
int IPQ::pop(int & i)
{	if(heap.size()==1)
		return inf;
	i=heap[1];
	int s=ele[heap[1]];
	index[heap[1]]=0;
	ele[heap[1]]=inf;
	heap[1]=heap[heap.size()-1];
	if(heap.size()!=2)
		index[heap[1]]=1;
	heap.erase(heap.end()-1);
	if(heap.size()!=1)
		Sink(1,heap.size()-1);
	return s;
}
#endif
