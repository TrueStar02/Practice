#include "DoubleList.h"
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
char menu();
void Add(DList<string,double> & dl);
void Delete(DList<string,double> & dl);
void Search(DList<string,double> & dl);
void Change(DList<string,double> & dl);
void Print(DList<string,double> & dl);
int main()
{	char ch;
	DList<string,double> dl;
	while((ch=menu())!='q')
		switch(ch)
		{	case 'a':Add(dl);
				break;
			case 'b':Delete(dl);
				break;
			case 'c':Search(dl);
				break;
			case 'd':Change(dl);
				break;
			case 'e':cout<<"The list is"<<(dl.empty()?" ":" not ")<<"empty.\n";
				break;
			case 'f':cout<<"List size:"<<dl.size()<<endl;
				break;
			case 'g':Print(dl);
				break;
			case 'h':dl.clear();
				cout<<"Cleared"<<endl;
				break;
		}
	DList<string,double> dl2(dl);
	while((ch=menu())!='q')
		switch(ch)
		{	case 'a':Add(dl2);
				break;
			case 'b':Delete(dl2);
				break;
			case 'c':Search(dl2);
				break;
			case 'd':Change(dl2);
				break;
			case 'e':cout<<"The list is"<<(dl2.empty()?" ":" not ")<<"empty.\n";
				break;
			case 'f':cout<<"List size:"<<dl2.size()<<endl;
				break;
			case 'g':Print(dl2);
				break;
			case 'h':dl2.clear();
				cout<<"Cleared"<<endl;
				break;
		}
	DList<string,double> dl3;
	dl3=dl;
	while((ch=menu())!='q')
		switch(ch)
		{	case 'a':Add(dl3);
				break;
			case 'b':Delete(dl3);
				break;
			case 'c':Search(dl3);
				break;
			case 'd':Change(dl3);
				break;
			case 'e':cout<<"The list is"<<(dl3.empty()?" ":" not ")<<"empty.\n";
				break;
			case 'f':cout<<"List size:"<<dl3.size()<<endl;
				break;
			case 'g':Print(dl3);
				break;
			case 'h':dl3.clear();
				cout<<"Cleared"<<endl;
				break;
		}
	cout<<"Bye~\n";
	return 0;
}
char menu()
{	char v;
	cout<<"A-Add B-Delete C-Search D-Change\n";
	cout<<"E-IsEmpty F-Size G-PrintAll H-Clear\n";
	cout<<"Q-Quit Your Choice:";
	while((v=tolower(cin.get()))&&strchr("abcdefghq",v)==NULL)
	{	cout<<"Error! Your Choice:";
		cin.ignore(999,'\n');
	}
	cin.ignore(999,'\n');
	return v;
}
void Add(DList<string,double> & dl)
{	string k;
	double v;
	cout<<"Enter key:";
	cin>>k;
	cout<<"Enter value:";
	cin>>v;
	cin.ignore(999,'\n');
	if(dl.insert(k,v))
		cout<<"Success!\n";
	else
		cout<<"Failed!\n";
	
}
void Delete(DList<string,double> & dl)
{	string k;
	cout<<"Enter key:";
	cin>>k;
	if(dl.erase(k))
		cout<<"Success!\n";
	else
		cout<<"Failed!\n";
}
void Search(DList<string,double> & dl)
{	string k;
	cout<<"Enter key:";
	cin>>k;
	if(dl.contains(k))
		cout<<"Successfully found "<<dl[k]<<endl;
	else
		cout<<"Failed!\n";
}
void Change(DList<string,double> & dl)
{	string k;
	double v;
	cout<<"Enter key:";
	cin>>k;
	if(dl.contains(k))
	{	cout<<"Successfully found "<<dl[k]<<endl;
		cout<<"Enter value:";
		cin>>v;
		cin.ignore(999,'\n');
		dl[k]=v;
	}
	else
		cout<<"Failed!\n";
}
void Print(DList<string,double> & dl)
{	bool v;
	cout<<"Enter Mode:";
	cin>>v;
	cin.ignore(999,'\n');
	dl.PrintAll(v);
}
