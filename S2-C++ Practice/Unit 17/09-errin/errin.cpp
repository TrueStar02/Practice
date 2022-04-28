#include<iostream>
#include<exception>
using namespace std;
int main()
{	cin.exceptions(ios_base::failbit);
	int n,sum=0;
	try
	{	while(cin>>n)
			sum+=n;
	}
	catch(ios_base::failure & bf)
	{	cout<<bf.what()<<endl;
		cout<<"BOOM!\n";
	}
	cout<<"Sum="<<sum<<endl;
	return 0;
}
