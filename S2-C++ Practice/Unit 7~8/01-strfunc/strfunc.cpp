#include<iostream>
#include<cctype>
using namespace std;
void GetStr(string *str,int num);
void ToUpper(string *str,int num);
void Print(string *str,int num);
int main(void)
{	cout<<"How many strings:";
	int num;
	cin>>num;
	cin.get();
	string * str=new string[num];
	GetStr(str,num);
	ToUpper(str,num);
	Print(str,num);
	return 0;
}
void Print(string *str,int num)
{	int x;
	for(x=0;x<num;x++)
		cout<<str[x]<<endl;
}
void ToUpper(string *str,int num)
{	int x,y;
	for(x=0;x<num;x++)
	for(y=0;y<str[x].length();y++)
		str[x][y]=toupper(str[x][y]);
}
void GetStr(string *str,int num)
{	int x;
	for(x=0;x<num;x++)
		getline(cin,str[x]);
}
