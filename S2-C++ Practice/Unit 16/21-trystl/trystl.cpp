#include<iostream> 
#include<queue>
#include<stack>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{	queue<int> q;
	list<int> l(5,2);
	stack<int> s;
	list<int>::iterator li1=l.begin();
	list<int>::iterator li2=l.end();
	//queue<int>::iterator qi1=q.begin();
	//queue<int>::iterator qi2=q.end();
	//stack<int>::iterator si1=s.begin();
	//stack<int>::iterator si2=s.end();
	list<int>::reverse_iterator rli1=l.rbegin();
	list<int>::reverse_iterator rli2=l.rend();
	int arr[10]={4,7,4,8,5,2,6,1,4,9};
	copy(arr,arr+10,insert_iterator<list<int>>(l,l.begin()));
	return 0;
	
}
