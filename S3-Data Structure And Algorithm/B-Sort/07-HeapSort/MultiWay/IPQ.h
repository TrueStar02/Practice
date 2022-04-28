#ifndef IPQ_H_
#define IPQ_H_
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class IPQ
{	private:
		vector<int>	index;
		vector<int> heap;
		vector<string> ele;
		void Sink(int beg,int end);
		void Swim(int beg,int end);
	public:
		IPQ(){heap.push_back(0);index.resize(100,0);ele.resize(100,"");}
		string operator[](int i) const;
		string & operator[](int i);
		bool empty(void){return heap.size()==1;} 
		int size(void) const{return heap.size()-1;}
		bool push(const string & s,int i);
		string pop(int & i);	
		bool del(int i);
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
	{	if(x<end&&ele[heap[x]]<ele[heap[x+1]])
			x++;
		if(ele[heap[0]]>=ele[heap[x]])
			break;
		heap[beg]=heap[x];
		index[heap[beg]]=beg;
		beg=x;
	}
	heap[beg]=heap[0];
	index[heap[beg]]=beg;
}
void IPQ::Swim(int beg,int end)
{	int x;
	heap[0]=heap[end];
	for(x=end/2;x>=1;x/=2)
	{	if(ele[heap[0]]<=ele[heap[x]])
			break;
		heap[end]=heap[x];
		index[heap[end]]=end;       
		end=x;
	}
	heap[end]=heap[0];
	index[heap[end]]=end;
}
string IPQ::operator[](int i) const
{	if(index[i])
		return ele[i];
	else
		return string("Cannot find the element!");
}
string & IPQ::operator[](int i)
{	//if(index[i])
		return ele[i];
	//else
		//return string("Cannot find the element!");
}
bool IPQ::push(const string & s,int i)
{	if(index[i])
		return 0;
	heap.push_back(i);
	if(i>index.size()-1)
	{	index.resize(i+1,0);
		ele.resize(i+1,"");
	}
	index[i]=heap.size()-1;
	ele[i]=s;
	Swim(1,heap.size()-1);
	return 1;
}
string IPQ::pop(int & i)
{	if(heap.size()==1)
		return string("Empty Queue!");
	i=heap[1];
	string s=ele[heap[1]];
	index[heap[1]]=0;
	ele[heap[1]]="";
	heap[1]=heap[heap.size()-1];
	if(heap.size()!=2)
		index[heap[1]]=1;
	heap.erase(heap.end()-1);
	if(heap.size()!=1)
		Sink(1,heap.size()-1);
	return s;
}
bool IPQ::del(int i)
{	if(index[i]==0)
		return 0;
	int temp=index[i];
	index[i]=0;
	ele[i]="";
	if(heap.size()!=temp+1)
	{	heap[temp]=heap[heap.size()-1];
		index[heap[temp]]=temp;
	}
	heap.erase(heap.end()-1);
	if(heap.size()!=temp)
	{	if(temp!=1&&ele[heap[temp]]>ele[heap[temp/2]])
			Swim(1,temp);
		else 
			Sink(temp,heap.size()-1);
	}
	return 1;
}
#endif
