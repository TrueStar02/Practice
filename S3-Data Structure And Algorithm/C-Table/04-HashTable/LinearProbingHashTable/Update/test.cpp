#include<iostream>
#include<fstream>
#include "LPHT.h"
using namespace std;
int main()
{	ifstream fin("task.txt");
	ofstream fout("out.txt");
	LPHT<int> ht;
	int x,v;
	string k;
	for(x=1;x<=300;x++)
	{	fin>>k>>v;
		ht.insert(k,v);
		cout<<"Size:"<<ht.size()<<endl;
	}
	
	
	fin.seekg(0);
	for(x=1;x<=225;x++)
	{	fin>>k>>v;
		ht.erase(k);
		cout<<"Size:"<<ht.size()<<endl;
	}
	ht.showall(fout);
	return 0;
	
}
