#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int Print(int num,int len);
char *Print(char *str,int len);
int main(void)
{	int number=1234567890;
	char *str="abcdefghij";
	int x;
	for(x=1;x<=10;x++)
	{	cout<<Print(number,x)<<endl;
		cout<<Print(str,x)<<endl;
	}
	return 0;
}
int Print(int num,int len)
{	while(num>=pow(10,len))
		num/=10;
	return num;
}
char *Print(char *str,int len)
{	char *res=new char [len+1];
	strncpy(res,str,len);
	return res;
}
