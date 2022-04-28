#include<iostream>
using namespace std;
int main()
{	int temp=63;
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout<<"Temperature:"<<temp<<endl;
	cout.setf(ios_base::uppercase);
	cout.setf(ios_base::showbase);
	cout<<"Hex:"<<hex<<temp<<endl;
	cout<<"Oct:"<<oct<<temp<<endl;
	bool b=true;
	cout.setf(ios_base::boolalpha);
	cout<<b<<" ";
	cout.unsetf(ios_base::boolalpha);
	cout<<b<<endl;
	return 0;
}
