#include<iostream>
using namespace std;
string append1(const string & str1,const string & str2);
const string & append2(string & str1,const string & str2);
int main(void)
{	string source,copy,result;
	getline(cin,source);
	copy=source;
	result=append1(source,"###");
	cout<<"Origin:"<<source<<endl;
	cout<<"Result:"<<result<<endl;
	result=append2(copy,"@@@");
	cout<<"Origin:"<<copy<<endl;
	cout<<"Result:"<<result<<endl;
	return 0;
}
string append1(const string & str1,const string & str2)
{	string temp=str2+str1+str2;
	return temp;
}
const string & append2(string & str1,const string & str2)
{	str1=str2+str1+str2;
	return str1;
}
