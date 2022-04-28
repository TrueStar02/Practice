#include<deque>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
void Show(int n);
int main()
{	deque<int> d1(5,2);
	cout<<"Part of Deque 1:";
	for_each(d1.begin()+1,d1.end()-1,Show);
	d1.erase(d1.begin()+1,d1.end()-2);
	cout<<endl<<"Deque 1:";
	for_each(d1.begin(),d1.end(),Show);
	deque<int> d2;
	int arr1[5]={5,3,2,1,4};
	d2.insert(d2.begin(),arr1,arr1+5);
	cout<<endl<<"Deque 2:";
	for_each(d2.begin(),d2.end(),Show);
	deque<int> d3(d2);
	int arr2[7]={5,7,3,1,6,4,2};
	copy(arr2,arr2+7,front_insert_iterator<deque<int>>(d3));
	cout<<endl<<"Deque 3:";
	for_each(d3.begin(),d3.end(),Show);
	d3.insert(d3.begin()+3,2,8);
	cout<<endl<<"Deque 3:";
	for_each(d3.begin(),d3.end(),Show);
	random_shuffle(d3.begin(),d3.end());
	cout<<endl<<"Deque 3:";
	for_each(d3.begin(),d3.end(),Show);
	sort(d3.begin(),d3.end());
	cout<<endl<<"Deque 3:";
	for_each(d3.begin(),d3.end(),Show);
	cout<<endl;
	return 0;
}
void Show(int n)
{	ostream_iterator<int,char> out_iter(cout," ");
	*out_iter=n;
	out_iter++;
}
