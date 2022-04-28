#include "SCHT.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{	SCHT<string,10> ht;
	ifstream fin("task.txt");
	ofstream fout("out.txt");
	int x;
	bool b;
	int k;
	string v;
	for(x=1;x<=100;x++)
	{	fin>>k>>v;
		b=ht.insert(k,v);
		if(b)
			cout<<"Success\n";
		else
			cout<<"Failed\n";
	}
	SCHT<string,10> ht2=ht;
	for(x=101;x<=200;x++)
	{	fin>>k>>v;
		b=ht2.insert(k,v);
		if(b)
			cout<<"Success\n";
		else
			cout<<"Failed\n";
	}
	ht=ht2;
	fin.seekg(0);
	for(x=1;x<=50;x++)
	{	fin>>k>>v;
		b=ht.erase(k);
		if(b)
			cout<<"Success\n";
		else
			cout<<"Failed\n";
	}
	
	cout<<ht.contains(k)<<endl;
	fin>>k>>v;
	cout<<k<<v<<endl;
	cout<<ht.contains(k)<<endl;
	cout<<ht.contains(20020305)<<endl;
	ht.insert(20020305,"B");
	ht.showall(fout);
	cout<<ht.contains(20020305)<<endl;
	cout<<ht[20020305]<<endl;
	ht[20020305]="BRH";
	cout<<ht[20020305]<<endl;
	fin.close();
	fout.close();
	return 0;
}
