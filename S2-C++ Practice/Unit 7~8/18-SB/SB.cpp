#include<iostream>
using namespace std;
void SBfunc(string str,int n=0);
int main()
{	SBfunc("You're SB!");
	SBfunc("Your mother died!!");
	SBfunc("You are the BIGGEST SB at ALL!!!!!",5);
	return 0;
}
void SBfunc(string str,int n)
{	static int count=0;
	count++;
	int x=1;
	if(n!=0)
		x=count;
	while(x>0)
	{	cout<<str<<endl;
		x--;
	}
}
