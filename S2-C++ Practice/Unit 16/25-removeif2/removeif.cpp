#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;
template<typename T>
bool toobig(const T & v1,const T & v2){return v1>v2;}
template<class T>
class TooBig
{	private:
		T base;
	public:
		TooBig(const T & b):base(b){}
		bool operator()(const T & val){return toobig<T>(val,base);}
};
void Show(int i){cout<<i<<" ";}
int main(void)
{	int arr[10]={104,109,304,553,198,166,219,198,233,150};
	list<int> l1(arr,arr+10);
	list<int> l2(arr,arr+10);
	for_each(l1.begin(),l1.end(),Show);
	cout<<endl;
	l1.remove_if(TooBig<int>(200));
	for_each(l1.begin(),l1.end(),Show);
	TooBig<int> tb(300);
	cout<<endl;
	l2.remove_if(tb);
	for_each(l2.begin(),l2.end(),Show);
	cout<<endl;
	return 0;
}

