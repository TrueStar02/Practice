#include "String.h"
int main(void)
{	String str[5],test="Crash";
	int x;
	str[0]="Ivy";
	str[1]=test;
	for(x=2;x<=4;x++)
		cin>>str[x];
	for(x=0;x<=4;x++)
		cout<<str[x].length()<<" ";
	cout<<endl;
	cout<<(str[1]>str[2])<<(str[1]<str[3])<<(str[1]==str[4])<<(str[2]>=str[3])<<(str[2]<=str[4])<<(str[3]!=str[4])<<endl;
	cout<<String::HowMany()<<endl;
	for(x=0;x<=4;x++)
		cout<<str[x][x];
	cout<<endl;
	return 0;
}
