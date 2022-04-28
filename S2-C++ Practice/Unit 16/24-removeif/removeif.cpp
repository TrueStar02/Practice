#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;
template<typename T>
bool TooBig(const T & val){return val>(T)200;}
void Show(int i){cout<<i<<" ";}
int main(void)
{	int arr[10]={104,109,304,553,198,166,219,198,233,150};
	list<int> l1(arr,arr+10);
	for_each(l1.begin(),l1.end(),Show);
	cout<<endl;
	l1.remove_if(TooBig<int>);
	for_each(l1.begin(),l1.end(),Show);
	cout<<endl;
	return 0;
}

