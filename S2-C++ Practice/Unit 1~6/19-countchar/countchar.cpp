#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(void)
{	char ch;
	ifstream fin;
	ofstream fout;
	fin.open("countchar.in");
	fout.open("countchar.out");
	int count=-1;
	while(fin.good())
	{	count++;
		ch=fin.get();
	}
	fout<<"Total:"<<count<<" letters.\n";
	fin.close();
	fout.close();
	return 0;
}
