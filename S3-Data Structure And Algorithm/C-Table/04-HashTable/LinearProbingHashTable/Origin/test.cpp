#include<iostream>
#include<fstream>
#include "LPHT.h"
using namespace std;
int main()
{	ifstream fin("task.txt");
	ofstream fout("out.txt");
	LPHT<int,200> ht;
	int x,v;
	string k;
	for(x=1;x<=160;x++)
	{	fin>>k>>v;
		ht.insert(k,v);
		cout<<"Size:"<<ht.size()<<endl;
	}
	ht.showall(fout);
	cout<<ht.contains(k)<<endl;
	cout<<ht[k]<<endl;
	ht[k]=20030405;
	cout<<ht[k]<<endl;
	fin>>k>>v;
	cout<<ht.contains(k)<<endl;
	fin.seekg(0);
	fout<<endl<<endl<<endl;
	for(x=1;x<=5;x++)
	{	fin>>k>>v;
		ht.erase(k);
		cout<<"Size:"<<ht.size()<<endl;
	}
	for(x=6;x<=160;x++)
	{	fin>>k>>v;
		fout<<"ELE "<<x<<" "<<ht.contains(k)<<endl;
	}
	return 0;
	
}
