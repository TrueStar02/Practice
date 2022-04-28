#include<iostream>
#include<cstring>
using namespace std;
char * part(char *str,int n=1);
int main(void)
{	char temp[81];
	cout<<"Enter a string:\n";
	cin.getline(temp,81);
	cout<<"How many chars do you have:";
	int n;
	cin>>n;
	char *str=part(temp,n);
	cout<<str<<endl;
	delete [] str;
	return 0;
}
char * part(char *str,int n)
{	if(n<0)
		n=0;
	else if(n>strlen(str))
		n=strlen(str);
	char *result=new char[n+1];
	strncpy(result,str,n);
	return result;
}
