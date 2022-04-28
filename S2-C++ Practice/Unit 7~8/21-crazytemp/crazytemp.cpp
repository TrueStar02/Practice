#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
T maxn( T *arr,int n);
template <> char * maxn< char *>( char **str,int n);
int main()
{	int iarr[6]={0,1,2,3,4,5};
	double darr[4]={0.12,1.23,2.34,3.45};
	char *strarr[5]={"Liu","Yuan","Niu","Bi","!"};
	int imax=maxn(iarr,6);
	double dmax=maxn(darr,4);
	char * strmax=maxn(strarr,5);
	cout<<imax<<" "<<dmax<<endl;
	cout<<strmax<<endl;
	return 0;
}
template <typename T>
T maxn( T *arr,int n)
{	T largest=*arr;
	for(int x=1;x<n;x++)
		if(arr[x]>largest)
			largest=arr[x];
	return largest;
}
template <> char * maxn<char *>( char **str,int n)
{	char *largest=*str;
	for(int x=1;x<n;x++)
		if(strlen(str[x])>strlen(largest))
			largest=str[x];
	return largest;
}
