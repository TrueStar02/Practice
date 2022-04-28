#ifndef DIPQ_H_
#define DIPQ_H_
#include<vector>
#include<string>
using namespace std;
class DIPQ
{	private:
		vector<int>	minheap;
		vector<int> maxheap;
		vector<int> minindex;
		vector<int> maxindex;
		vector<string> ele;
		void maxSink(int beg,int end);
		void minSink(int beg,int end);
		void maxSwim(int beg,int end);
		void minSwim(int beg,int end);
	public:
		DIPQ();
		string popmax();
		string popmin();
		bool push(const string & s,int i);
		int size() const{return maxheap.size()-1;}
		int empty() const{return maxheap.size()==1;}
		string operator[](int i) const{return ele[i];}
		void change(string s,int i);
		bool del(int i);
};
void DIPQ::maxSink(int beg,int end)
{	int x;
	maxheap[0]=maxheap[beg];
	for(x=beg*2;x<=end;x*=2)
	{	if(x<end&&ele[maxheap[x]]<ele[maxheap[x+1]])
			x++;
		if(ele[maxheap[beg]]>=ele[maxheap[x]])
			break;
		maxheap[beg]=maxheap[x];
		maxindex[maxheap[beg]]=beg;
		beg=x;
	}
	maxheap[beg]=maxheap[0];
	maxindex[maxheap[beg]]=beg;
}
void DIPQ::minSink(int beg,int end)
{	int x;
	minheap[0]=minheap[beg];
	for(x=beg*2;x<=end;x*=2)
	{	if(x<end&&ele[minheap[x]]>ele[minheap[x+1]])
			x++;
		if(ele[minheap[beg]]<=ele[minheap[x]])
			break;
		minheap[beg]=minheap[x];
		minindex[minheap[beg]]=beg;
		beg=x;
	}
	minheap[beg]=minheap[0];
	minindex[minheap[beg]]=beg;
}
void DIPQ::maxSwim(int beg,int end)
{	int x;
	maxheap[0]=maxheap[end];
	for(x=end/2;x>=1;x/=2)
	{	if(ele[maxheap[end]]<=ele[maxheap[x]])
			break;
		maxheap[end]=maxheap[x];
		maxindex[maxheap[end]]=end;
		end=x;
	}
	maxheap[end]=maxheap[0];
	maxindex[maxheap[end]]=end;
}
void DIPQ::minSwim(int beg,int end)
{	int x;
	minheap[0]=minheap[end];
	for(x=end/2;x>=1;x/=2)
	{	if(ele[minheap[end]]>=ele[minheap[x]])
			break;
		minheap[end]=minheap[x];
		minindex[minheap[end]]=end;
		end=x;
	}
	minheap[end]=minheap[0];
	minindex[minheap[end]]=end;
}
DIPQ::DIPQ()
{	minheap.push_back(0);
	maxheap.push_back(0);
	ele.resize(100,"");
	minindex.resize(100,0);
	maxindex.resize(100,0);
}
string DIPQ::popmax()
{	string s=ele[maxheap[1]];
	if(s!="")
		del(maxheap[1]);
	else
		s="Empty Queue!";
	return s;
}
string DIPQ::popmin()
{	string s=ele[minheap[1]];
	if(s=="")
		del(minheap[1]);
	else
		s="Empty Queue!";
	return s;
}
bool DIPQ::push(const string & s,int i)
{	if(maxindex[i])
		return 0;
	ele[i]=s;
	minheap.push_back(i);
	maxheap.push_back(i);
	minindex[i]=maxindex[i]=minheap.size()-1;
	maxSwim(1,minheap.size()-1);
	minSwim(1,maxheap.size()-1);
	return 1;
}
void DIPQ::change(string s,int i)
{	ele[i]=s;
	if(maxindex[i]>1&&ele[i]>ele[maxheap[maxindex[i]/2]])
		maxSwim(1,maxindex[i]);
	else
		maxSink(maxindex[i],maxheap.size()-1);
	if(minindex[i]>1&&ele[i]<ele[minheap[minindex[i]/2]])
		minSwim(1,minindex[i]);
	else
		minSink(minindex[i],minheap.size()-1);	
}
bool DIPQ::del(int i)
{	if(!maxindex[i])
		return 0;
	int maxtemp=maxindex[i];
	int mintemp=minindex[i];
	maxindex[i]=0;
	minindex[i]=0;
	ele[i]="";
	if(maxheap.size()!=maxtemp+1)
	{	maxheap[maxtemp]=maxheap[maxheap.size()-1];
		maxindex[maxheap[maxtemp]]=maxtemp;
	}	
	if(minheap.size()!=mintemp+1)
	{	minheap[mintemp]=minheap[minheap.size()-1];
		minindex[minheap[mintemp]]=mintemp;
	}
	maxheap.erase(maxheap.end()-1);
	minheap.erase(minheap.end()-1);
	if(maxheap.size()!=maxtemp)
	{	
		if(maxtemp>1&&ele[maxheap[maxtemp]]>ele[maxheap[maxtemp/2]])
			maxSwim(1,maxtemp);
		else
			maxSink(maxtemp,maxheap.size()-1);
	}
	if(minheap.size()!=mintemp)
	{	if(mintemp>1&&ele[minheap[mintemp]]<ele[minheap[mintemp/2]])
			minSwim(1,mintemp);
		else
			minSink(mintemp,minheap.size()-1);
	}
	return 1;
}
#endif
