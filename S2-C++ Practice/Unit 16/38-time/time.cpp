#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<iterator>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{	srand((unsigned int)time(0));
	cout<<"Array size:";
	int size,x;
	cin>>size;
	vector<int> v0;
	for(x=0;x<size;x++)
		v0.push_back(rand()%size);
	list<int> li(v0.begin(),v0.end());
	vector<int> vi(v0.begin(),v0.end());
	clock_t start=clock();
	li.sort();
	clock_t end=clock();
	cout<<"List time:  "<<double(end-start)/CLOCKS_PER_SEC<<"s\n";
	start=clock();
	sort(vi.begin(),vi.end());
	end=clock();
	cout<<"Vector time:"<<double(end-start)/CLOCKS_PER_SEC<<"s\n";
	return 0;
}
