#include<iostream>
using namespace std;
int main()
{	char input[255];
	cout<<"Enter a string using getline():";
	cin.getline(input,255,'#');
	cout<<"Here is your input:\n";
	cout<<input<<endl;
	char ch;
	cin.get(ch);
	cout<<"Next character:"<<ch<<endl;
	if(ch!='\n')
		cin.ignore(255,'\n');
	cout<<"Enter a string using get():";
	cin.get(input,255,'#');
	cout<<"Here is your input:\n";
	cout<<input<<endl;
	cin.get(ch);
	cout<<"Next character:"<<ch<<endl;
	return 0;
}
