#ifndef ARRAYTP_H_
#define AREAYTP_H_
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T,int n>
class ArrayTP
{	private:
		T arr[n];
	public:
		ArrayTP(){}
		explicit ArrayTP(const T & v);
		T & operator[](int i);
		T operator[](int i) const;
};
template<class T,int n>
ArrayTP<T,n>::ArrayTP(const T & v)
{	int x;
	for(x=0;x<n;x++)
		arr[x]=v;
}
template<class T,int n>
T & ArrayTP<T,n>::operator[](int i)
{	if(i<0||i>=n)
	{	cerr<<"Error in array limits,"<<i<<" is out of range!\n";
		exit(EXIT_FAILURE);
	}
	else
		return arr[i];
}
template<class T,int n>
T ArrayTP<T,n>::operator[](int i) const
{	if(i<0||i>=n)
	{	cerr<<"Error in array limits,"<<i<<" is out of range!\n";
		exit(EXIT_FAILURE);
	}
	else
		return arr[i];
}
#endif
