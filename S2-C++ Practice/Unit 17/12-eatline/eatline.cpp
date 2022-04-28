#include<iostream>
using namespace std;
int main()
{	char room1[11],room2[11];
	cout<<"Enter string 1:";
	cin.get(room1,11);
	//if(cin.peek()!='\n')
	{	cout<<"No enough room!\n";
		while(cin.get()!='\n')
			continue;
	}
	cout<<"String 1:"<<room1<<endl;
	cout<<"Enter string 2:";
	cin.get(room2,11);
	//if(cin.peek()!='\n')
	{	cout<<"No enough room!\n";
		while(cin.get()!='\n')
			continue;
	}
	cout<<"String 2:"<<room2<<endl;
	return 0;
}
