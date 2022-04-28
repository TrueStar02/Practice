#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> Lotto(int all,int out);
void Show(int x){cout<<x<<" ";}
int main()
{	int a,b;
	cin>>a>>b;
	vector<int> winner=Lotto(a,b);
	for_each(winner.begin(),winner.end(),Show);
	cout<<endl;
	return 0;
}
vector<int> Lotto(int all,int out)
{	int x;
	vector<int> list;
	for(x=1;x<=all;x++)
	list.push_back(x);
	random_shuffle(list.begin(),list.end());
	return vector<int>(list.begin(),list.begin()+out);;
}
