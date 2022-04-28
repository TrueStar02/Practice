#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void Show(const int & i){cout<<i<<' ';}
int main()
{	int arr[10]={3,7,4,9,2,1,6,8,4,5};
	list<int> l1(arr,arr+10);
	list<int> l2(arr,arr+10);
	cout<<"Original:\n";
	for_each(l1.begin(),l1.end(),Show);
	cout<<"\nUsing remove method:\n";
	l1.remove(4);
	for_each(l1.begin(),l1.end(),Show);
	cout<<"\nUsing remove function:\n";
	list<int>::iterator iter=remove(l2.begin(),l2.end(),4);
	for_each(l2.begin(),l2.end(),Show);
	l2.erase(iter,l2.end());
	cout<<"\nUsing erase method:\n";
	for_each(l2.begin(),l2.end(),Show);
	cout<<endl;
	return 0;
}
