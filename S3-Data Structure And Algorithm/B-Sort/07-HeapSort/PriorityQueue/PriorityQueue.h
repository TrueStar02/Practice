#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include<vector>
using namespace std;
class PriorityQueue
{	private:
		vector<int> arr;
		void Swim(int beg,int end);
		void Sink(int beg,int end);
	public:
		PriorityQueue(){arr.push_back(0);}
		PriorityQueue(int * a,int size);
		int size(){return arr.size()-1;}
		void Push(int n);
		int Pop(void);
};
void PriorityQueue::Swim(int beg,int end)
{	int x;
	arr[0]=arr[end];
	for(x=end/2;x>=1;x/=2)
	{	if(arr[x]>=arr[0])
			break;
		arr[end]=arr[x];
		end=x;
	}
	arr[end]=arr[0];
}
void PriorityQueue::Sink(int beg,int end)
{	int x;
	arr[0]=arr[beg];
	for(x=beg*2;x<=end;x*=2)
	{	if(x<end&&arr[x]<arr[x+1])
			x++;
		if(arr[x]<=arr[0])
			break;
		arr[beg]=arr[x];
		beg=x;
	}
	arr[beg]=arr[0];
}
PriorityQueue::PriorityQueue(int * a,int size)
{	arr.push_back(0);
	arr.insert(arr.end(),a,a+size);
	int x;
	for(x=size/2;x>=1;x--)
		Sink(x,size);
	
}
void PriorityQueue::Push(int n)
{	arr.push_back(n);
	Swim(1,arr.size()-1);
}
int PriorityQueue::Pop(void)
{	if(arr.size()>1)
	{	int temp=arr[1];
		arr[1]=arr[arr.size()-1];
		arr.erase(arr.end()-1);
		Sink(1,arr.size()-1);
		return temp;
	}
	else
		return -114514;
}
#endif
