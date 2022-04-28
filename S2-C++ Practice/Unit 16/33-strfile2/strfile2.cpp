#include<set>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{	ifstream fin("in.txt");
	if(!fin.is_open())
	{	cerr<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	string str;
	set<string> words;
	while(fin>>str)
		words.insert(str);
	cout<<"Enter a string,empty to quit:";
	int count;
	set<string>::iterator iter;
	while(cin>>str&&str!=" ")
	{	count=0;
		for(iter=words.begin();iter!=words.end();iter++)
			if(iter->find(str)!=string::npos)
			{	cout<<*iter<<endl;
				count++;
			}
		cout<<"It is the sub-string of "<<count<<" string(s)\n";
		cout<<"Enter the next string,empty to quit:";
	}
	cout<<"Bye~!";
	return 0;
}
