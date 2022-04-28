#include<iostream>
using namespace std;
int tree=1;
static int side=2;
void Child(void);
int main()
{	cout<<"tree in main:"<<tree<<" address:"<<&tree<<endl;
	cout<<"side in main:"<<side<<" address:"<<&side<<endl;
	side++;
	tree++;
	cout<<"tree in main:"<<tree<<" address:"<<&tree<<endl;
	cout<<"side in main:"<<side<<" address:"<<&side<<endl;
	Child();
	cout<<"tree in main:"<<tree<<" address:"<<&tree<<endl;
	cout<<"side in main:"<<side<<" address:"<<&side<<endl;
	return 0;
}

