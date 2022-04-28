#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;
auto Show=[](int x){cout<<x<<" ";};
int main(void)
{	int arr[10]={104,109,304,553,198,166,219,198,233,150};
	list<int> l1(arr,arr+10);
	list<int> l2(arr,arr+10);
	for_each(l1.begin(),l1.end(),Show);
	cout<<endl;
	l1.remove_if([](int x){return x>200;});
	for_each(l1.begin(),l1.end(),Show);
	cout<<endl;
	l2.remove_if([](int x){return x>300;});
	for_each(l2.begin(),l2.end(),Show);
	cout<<endl;
	return 0;
}

