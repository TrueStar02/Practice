#include "IPQ.h"
#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
char menu(void);
void Push(IPQ & i);
void Pop(IPQ & i);
void Search(IPQ & i);
void Delete(IPQ & i);
void Change(IPQ & i);
int main(void)
{	IPQ ipq;
	char ch;
	while((ch=menu())!='q')
	{	ipq.Debug();
		switch(ch)
		{	case 'a':Push(ipq);
				break;
			case 'b':Pop(ipq);
				break;
			case 'c':cout<<"The IPQ is "<<(ipq.empty()?(""):"not ")<<"empty!\n";
				break;
			case 'd':cout<<"IPQ size:"<<ipq.size()<<endl;
				break;
			case 'e':Search(ipq);
				break;
			case 'f':Delete(ipq);
				break;
			case 'g':Change(ipq);
				break;
			default:
				cout<<"You are a SB!\n";
		}
	}
}
void Push(IPQ & i)
{	int x;
	string t;
	cout<<"Name:";
	cin>>t;
	cout<<"Index:";
	cin>>x;
	cin.ignore(999,'\n');
	if(i.push(t,x))
		cout<<"Succeed!\n";
	else
		cout<<"Failed!\n";
	
}
void Pop(IPQ & i)
{	cout<<i.pop()<<endl;
}
void Search(IPQ & i)
{	cout<<"Index:";
	int x;
	cin>>x;
	cin.ignore(999,'\n');
	cout<<i[x];
}
void Delete(IPQ & i)
{	int x;
	cout<<"Index:";
	cin>>x;
	cin.ignore(999,'\n');
	cout<<(i.del(x)?"Succeed":"Failed")<<endl;
}
void Change(IPQ & i)
{	cout<<"Index:";
	int x;
	string temp;
	cin>>x;
	cin.ignore(999,'\n');
	if(i[x]!="")
	{	cout<<"New String:";
		cin>>temp;
		while(temp=="")
			cout<<"No empty!New string:";
		i.change(temp,x);
	}
	else
		cout<<"Cannot find the string!\n";
}
char menu(void)
{	char v;
	cout<<"Enter the function you need:\n";
	cout<<"A-Push B-Pop C-Empty D-Size\n";
	cout<<"E-Search F-Delete G-Change Q-Quit\n";
	while((v=tolower(cin.get()))&&strchr("abcdefgq",v)==NULL)
	{	cout<<"Enter A~F or Q:";
		cin.ignore(999,'\n');
	}
	cin.ignore(999,'\n');
	return v;
}
