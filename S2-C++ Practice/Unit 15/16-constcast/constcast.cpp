#include<iostream>
using namespace std;
int main()
{	int a=100;
	const int * ptr=&a;
	int *ptr2=const_cast<int *>(ptr);
	(*ptr2)++;
	cout<<a<<endl;
}
