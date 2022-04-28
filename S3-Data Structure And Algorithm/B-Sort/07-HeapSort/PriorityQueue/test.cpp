#include "PriorityQueue.h"
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
char menu(void);
int main(void)
{	char ch;
	int n;
	PriorityQueue q;
	while((ch=menu())!='q')
	{	if(ch=='a')
		{	cout<<"Enter a number:";
			cin>>n;
			cin.ignore(999,'\n');
			q.Push(n);
			cout<<"Done!\n";
		}
		else if(ch=='b')
		{	if((n=q.Pop())!=-114514)
				cout<<"Number "<<n<<" poped!\n";
			else
				cout<<"Empty Queue!\n";
		}
		else
			cout<<"Size:"<<q.size()<<endl;
	}
}
char menu(void)
{	char v;
	cout<<"Enter the choice you need:\n";
	cout<<"A-Enqueue B-Dequeue \n";
	cout<<"C-Size Q-Quit\n";
	while((v=tolower(cin.get()))&&strchr("abcq",v)==NULL)
	{	cout<<"Enter A,B,C or Q:";
		cin.ignore(999,'\n');
	}
	cin.ignore(999,'\n');
	return v;
}
