#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(int argc,char *argv[])
{	ifstream fin;
	char ch;
	int x,count=0;
	for(x=1;x<=argc-1;x++)
	{	fin.open(argv[x]);
		if(!fin.is_open())
		{	cout<<"Error in opening the file!\n";
			exit(EXIT_FAILURE);	
		}
		while(fin>>ch&&!fin.eof())
			count++;
		fin.close();
		fin.clear();
	}
	cout<<"Total characters:"<<count<<endl;
	return 0;
}
