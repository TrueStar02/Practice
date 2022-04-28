#include<iostream>
#include<sstream>
using namespace std;
int main()
{	ostringstream sout;
	string str;
	cout<<"What's your name?\n";
	getline(cin,str);
	sout<<"Hello,"<<str<<endl;
	cout<<sout.str();
	return 0;
}
