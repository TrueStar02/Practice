#include<iostream>
#include<memory>
using namespace std;
int main()
{	unique_ptr<double []> arr(new double[5]);
	int x;
	for(x=0;x<5;x++)
		arr[x]=x+1;
	for(x=0;x<5;x++)
		cout<<arr[x]<<" ";
	cout<<endl;
	return 0;
}
