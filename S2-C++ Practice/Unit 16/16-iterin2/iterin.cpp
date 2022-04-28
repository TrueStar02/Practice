#include<iostream>
#include<iterator>
using namespace std;
int main()
{	istream_iterator<int,char> in_iter(cin);
	istream_iterator<int,char> err_iter;
	ostream_iterator<int,char> out_iter(cout," ");
	int x;
	int arr[10];
	copy(in_iter,err_iter,arr);
	copy(arr,arr+10,out_iter);
	return 0;
}
