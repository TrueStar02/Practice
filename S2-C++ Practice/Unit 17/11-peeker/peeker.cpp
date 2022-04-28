#include<iostream>
using namespace std;
int main()
{	char ch;
	while(cin.get(ch))
		if(ch!='#')
			cout<<ch;
		else
		{	cin.putback(ch);
			break;
		}
	cout<<endl;
	if(cin.eof())
	{	cout<<"EOF Reached!\n";
		return 0;
	}
	else
	{	cin.get(ch);
		cout<<"The next character:"<<ch<<endl;
	}
	while(cin.peek()!='#')
	{	cin.get(ch);
		cout<<ch;
	}
	cout<<endl;
	if(cin.eof())
		cout<<"EOF Reached!\n";
	else
	{	cin.get(ch);
		cout<<"The next character:"<<ch<<endl;
	}
	return 0;
}
