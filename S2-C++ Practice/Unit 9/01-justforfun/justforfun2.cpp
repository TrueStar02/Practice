#include<iostream>
using namespace std;
extern int tree;
int side=5;
void Child(void)
{	cout<<"tree in child:"<<tree<<" address:"<<&tree<<endl;
	cout<<"side in child:"<<side<<" address:"<<&side<<endl;
	side++;
	tree++;
	cout<<"tree in child:"<<tree<<" address:"<<&tree<<endl;
	cout<<"side in child:"<<side<<" address:"<<&side<<endl;
}
