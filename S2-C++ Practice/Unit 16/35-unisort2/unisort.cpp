#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T>
int reduce(T arr[],int n);
int main()
{	int arri[10]={1,5,3,8,5,7,9,3,7,6};
	string arrs[8]={"alter","easter","universe","exhibition","alter","planet","happiness","frozen"};
	double arrd[12]={0.9,3.7,6.6,8.1,4.2,5.8,6.6,4.2,7.5,9.8,2.1,6.6};
	int x,sizei=reduce(arri,10),sizes=reduce(arrs,8),sized=reduce(arrd,12);
	for(x=0;x<sizei;x++)
		cout<<arri[x]<<" ";
	cout<<endl;
	for(x=0;x<sizes;x++)
		cout<<arrs[x]<<" ";
	cout<<endl;
	for(x=0;x<sized;x++)
		cout<<arrd[x]<<" ";
	cout<<endl;
	return 0;
}
template<typename T>
int reduce(T arr[],int n)
{	vector<T> v(arr,arr+n);
	sort(v.begin(),v.end());
	typename vector<T>::iterator iter=unique(v.begin(),v.end());
	int x,size=iter-v.begin();
	for(x=0;x<size;x++)
		arr[x]=v[x];
	return size;
}
