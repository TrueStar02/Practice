#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int,string> Pair;
typedef multimap<int,string> Map;
void Show(const Pair & p){cout<<p.first<<":"<<p.second<<endl;}
int main(void)
{	int x;
	Pair arr[6]={Pair(305,"Ivy"),Pair(408,"CS"),Pair(305,"Vanessa"),Pair(609,"Peak"),Pair(404,"NotFound"),Pair(120,"Ambulance")};
	Map m(arr,arr+4);
	m.insert(arr+4,arr+6);
	for_each(m.begin(),m.end(),Show);
	cout<<"Numbers of \"305\":"<<m.count(305)<<endl;
	pair<Map::iterator,Map::iterator> itr=m.equal_range(305);
	for_each(itr.first,itr.second,Show);
	return 0;
}
