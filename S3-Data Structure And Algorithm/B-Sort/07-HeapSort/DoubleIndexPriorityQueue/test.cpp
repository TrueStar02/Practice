#include "DIPQ.h"
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
char menu(void);
void Push(DIPQ & di);
void PopMax(DIPQ & di);
void PopMin(DIPQ & di);
void Search(DIPQ & di);
void Delete(DIPQ & di);
void Change(DIPQ & di);
int main(void)
{	DIPQ dipq;
	char ch;
	while((ch=menu())!='q')
	{	//ipq.Debug();
		switch(ch)
		{	case 'a':Push(dipq);
				break;
			case 'b':PopMax(dipq);
				break;
			case 'c':PopMin(dipq);
				break;
			case 'd':cout<<"The IPQ is "<<(dipq.empty()?(""):"not ")<<"empty!\n";
				break;
			case 'e':cout<<"IPQ size:"<<dipq.size()<<endl;
				break;
			case 'f':Search(dipq);
				break;
			case 'g':Delete(dipq);
				break;
			case 'h':Change(dipq);
				break;
			default:
				cout<<"You are a SB!\n";
		}
	}
	cout<<"Bye~\n";
}
void Push(DIPQ & di)
{	int x;
	string t;
	cout<<"Name:";
	cin>>t;
	cout<<"Index:";
	cin>>x;
	cin.ignore(999,'\n');
	if(di.push(t,x))
		cout<<"Succeed!\n";
	else
		cout<<"Failed!\n";
	
}
void PopMax(DIPQ & di)
{	cout<<di.popmax()<<endl;
}
void PopMin(DIPQ & di)
{	cout<<di.popmin()<<endl;
}
void Search(DIPQ & di)
{	cout<<"Index:";
	int x;
	cin>>x;
	cin.ignore(999,'\n');
	cout<<di[x];
}
void Delete(DIPQ & di)
{	int x;
	cout<<"Index:";
	cin>>x;
	cin.ignore(999,'\n');
	cout<<(di.del(x)?"Succeed":"Failed")<<endl;
}
void Change(DIPQ & di)
{	cout<<"Index:";
	int x;
	string temp;
	cin>>x;
	cin.ignore(999,'\n');
	if(di[x]!="")
	{	cout<<"New String:";
		cin>>temp;
		while(temp=="")
			cout<<"No empty!New string:";
		di.change(temp,x);
	}
	else
		cout<<"Cannot find the string!\n";
}
char menu(void)
{	char v;
	cout<<"Enter the function you need:\n";
	cout<<"A-Push B-PopMax C-PopMin \n";
	cout<<"D-Empty E-Size F-Search \n";
	cout<<"G-Delete H-Change Q-Quit\n";
	while((v=tolower(cin.get()))&&strchr("abcdefghq",v)==NULL)
	{	cout<<"Enter A~H or Q:";
		cin.ignore(999,'\n');
	}
	cin.ignore(999,'\n');
	return v;
}
