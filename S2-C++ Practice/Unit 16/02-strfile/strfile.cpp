#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(void)
{	ifstream fin("file.in");
	if(!fin.is_open())
	{	cerr<<"Error in opening the file!\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count=0;
	getline(fin,item,':');
	while(fin.good())
	{	count++;
		cout<<count<<":"<<item<<endl;
		getline(fin,item,':');
	}
	cout<<"Done!\n";
	return 0;
}
