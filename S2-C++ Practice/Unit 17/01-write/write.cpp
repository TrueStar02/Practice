#include<iostream>
using namespace std;
int main(void)
{	string t;
	cout<<"Enter a string:";
	cin>>t;
	int x;
	for(x=0;x<t.length();x++)
		cout.write(t.c_str(),x+1)<<endl;
	for(x=t.length()-2;x>=0;x--)
		cout.write(t.c_str(),x+1)<<endl;
	return 0;
}
