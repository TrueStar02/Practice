#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>
using namespace std;
void Show(int x){cout<<x<<" ";}
int main(void)
{	list<int> l1(5,2);
	int arr1[5]={4,1,5,3,2};
	list<int> l2;
	l2.insert(l2.begin(),arr1,arr1+5);
	int arr2[6]={1,6,3,5,2,4};
	list<int> l3(l2);
	l3.insert(l3.end(),arr2,arr2+6);
	cout<<"List 1:";
	for_each(l1.begin(),l1.end(),Show);
	cout<<endl<<"List 2:";
	for_each(l2.begin(),l2.end(),Show);
	cout<<endl<<"List 3:";
	for_each(l3.begin(),l3.end(),Show);
	l3.remove(2);
	cout<<endl<<"List 3:";
	for_each(l3.begin(),l3.end(),Show);
	l3.splice(l3.begin(),l1);
	cout<<endl<<"List 3:";
	for_each(l3.begin(),l3.end(),Show);
	l3.unique();
	cout<<endl<<"List 3:";
	for_each(l3.begin(),l3.end(),Show);
	l3.sort();
	cout<<endl<<"List 3:";
	for_each(l3.begin(),l3.end(),Show);
	l2.sort();
	cout<<endl<<"List 2:";
	for_each(l2.begin(),l2.end(),Show);
	l3.merge(l2);
	cout<<endl<<"List 3:";
	for_each(l3.begin(),l3.end(),Show);
	return 0;
}
