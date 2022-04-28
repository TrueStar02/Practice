#include "MultiWay.h"
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[])
{	MultiWay s;
	ifstream fin;
	ofstream fout;
	string temp;
	vector<string> str;
	int x;
	for(x=1;x<=argc-1 ;x++)
	{	fin.open(argv[x]);
		while(!fin.eof())
		{	fin>>temp;
			str.push_back(temp);
		}
		fin.close();
		fin.clear();
		str.erase(str.end()-1);
		s.insert(str);
		str.clear();
	}
	str=s.merge();
	vector<string>::iterator iter;
	fout.open("out.txt");
	for(iter=str.begin();iter!=str.end();iter++)
		fout<<*iter<<" ";
	fout.close();
	return 0;
}
