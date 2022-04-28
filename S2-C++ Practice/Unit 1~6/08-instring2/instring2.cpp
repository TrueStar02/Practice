#include<iostream>
using namespace std;
int main(void)
{	string name,dessert;
	cout<<"Enter your name:";
	getline(cin,name);
	cout<<"Enter the dessert you like:";
	getline(cin,dessert);
	cout<<"Ok,"<<name<<",I will make some "<<dessert<<" for you.\n";
	return 0;
}
