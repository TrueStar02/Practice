#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int reduce(int arr[],int n);
int main()
{	int arr[10]={1,5,3,8,5,7,9,3,7,6};
	int x,size=reduce(arr,10);
	for(x=0;x<size;x++)
		cout<<arr[x]<<" ";
	cout<<endl;
	return 0;
}
int reduce(int arr[],int n)
{	vector<int> vi(arr,arr+n);
	sort(vi.begin(),vi.end());
	vector<int>::iterator iter=unique(vi.begin(),vi.end());
	int x,size=iter-vi.begin();
	for(x=0;x<size;x++)
		arr[x]=vi[x];
	return size;
}
