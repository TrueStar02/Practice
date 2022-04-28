#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main()
{	istream_iterator<int,char> in_iter(cin);
	istream_iterator<int,char> err_iter;
	ostream_iterator<int,char> out_iter(cout," ");
	int x;
	vector<int> arr(10);
	copy(in_iter,err_iter,arr.begin());
	copy(arr.begin(),arr.end(),out_iter);
	return 0;
}
