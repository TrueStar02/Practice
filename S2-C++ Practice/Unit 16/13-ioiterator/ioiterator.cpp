#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(void)
{	int x;
	vector<int> dice(10);
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	copy(arr,arr+10,dice.begin());
	ostream_iterator<int,char> out_iter(cout," ");
	copy(dice.begin(),dice.end(),out_iter);
	cout<<endl;
	vector<int>::reverse_iterator ri;
	for(ri=dice.rbegin();ri<dice.rend();++ri)
	{	*out_iter=*ri;
		out_iter++;
	}
	cout<<endl;
	copy(dice.rbegin(),dice.rend(),out_iter);
	cout<<endl;
}
