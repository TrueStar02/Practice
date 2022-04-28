#include<iostream>
using namespace std;
int main(void)
{	char name[21],dessert[20];
	cout<<"Enter your name:";
	cin.get(name,21).get();
	cout<<"Enter the dessert you like:";
	cin.get(dessert,21).get();
	cout<<"Ok,"<<name<<",I will make some "<<dessert<<" for you.\n";
	return 0;
}
