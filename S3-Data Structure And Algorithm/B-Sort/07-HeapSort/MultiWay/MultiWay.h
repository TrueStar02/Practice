#ifndef MULTIWAY_H_
#define MULTIWAY_H_
#include "IPQ.h"
class MultiWay
{	private:
		vector<vector<string>> streams;
		vector<string> result;
		IPQ sort;
		vector<int> cur;
	public:
		MultiWay();
		void insert(string * arr,int size);
		void insert(vector<string> v);
		vector<string> merge(void);
};
MultiWay::MultiWay()
{	vector<string> e;
	streams.push_back(e);
	cur.push_back(-1);
}
void MultiWay::insert(string * arr,int size)
{	vector<string> s;
	int x;
	for(x=0;x<size;x++)
		s.push_back(arr[x]);
	streams.push_back(s);
	cur.push_back(0);
}
void MultiWay::insert(vector<string> v)
{	streams.push_back(v);
	cur.push_back(0);
}
vector<string> MultiWay::merge(void)
{	int x,i;
	for(x=1;x<cur.size();x++)
		sort.push(streams[x][0],x);
	while(sort.size()>0)
	{	result.push_back(sort.pop(i));
		cur[i]++;
		if(cur[i]<streams[i].size())
			sort.push(streams[i][cur[i]],i);		
	}
	return result;
}
#endif
