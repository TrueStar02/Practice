#include<iostream>
#include "ST.h"
using namespace std;
int main()
{	ST<double,int> gpa;
	try
	{	gpa.add(0.5,0);
		gpa.add(99.5,1);
		gpa.add(1,2);
		gpa.add(2,3);
		gpa.ShowAll();
	}
	catch(bad_key<string> & bk)
	{	cout<<bk.what()<<endl;}
	return 0;
}
