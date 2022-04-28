#include<iostream>
#include "ST.h"
using namespace std;
int main()
{	ST<string,double> gpa;
	try
	{	gpa.add("BRH",98.3);
		gpa.add("CYZ",66.0);
		gpa.add("CZY",92.0);
		cout<<gpa["BRH"]<<endl;
		cout<<gpa.size();
		cout<<gpa.contains("CYZ")<<endl;
		gpa.del("CYZ");
		gpa.add("CW",0.5);
		gpa["CW"]=90.5;
		gpa.ShowAll();
		cout<<gpa["CW"]<<endl;
		cout<<gpa["CYZ"]<<endl;
	}
	catch(bad_key<string> & bk)
	{	cout<<bk.what()<<endl;}
	return 0;
}
