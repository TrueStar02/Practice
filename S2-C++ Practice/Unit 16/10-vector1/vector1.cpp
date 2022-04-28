#include<iostream>
#include<vector>
using namespace std;
int main()
{	vector<int> ai(5);
	vector<string> as(5);
	int x;
	for(x=0;x<5;x++)
	{	cout<<"Enter a number:";
		cin>>ai[x];
		cin.get();
		cout<<"Enter a string:";
		getline(cin,as[x]);
	}
	for(x=0;x<5;x++)
		cout<<ai[x]<<":"<<as[x]<<endl;
	return 0;
}
