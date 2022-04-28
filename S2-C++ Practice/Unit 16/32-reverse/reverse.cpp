#include<iostream>
#include<cctype>
using namespace std;
int main()
{	string t,temp;
	bool rev=1;
	int x;
	cout<<"Enter a string,empty to quit:";
	while(getline(cin,t)&&t!="")
	{	rev=1;
		temp.clear();
		for(x=0;x<t.length();x++)
			if(isalpha(t[x]))
				temp+=tolower(t[x]);
		for(x=0;x<temp.length()/2;x++)
			if(temp[x]!=temp[temp.length()-1-x])
			{	rev=0;
				break;
			}	
		cout<<(rev?"True":"False")<<endl;
		cout<<"Enter the next string,empty to quit:";
	}
	cout<<"Bye~\n";
	return 0;
}
