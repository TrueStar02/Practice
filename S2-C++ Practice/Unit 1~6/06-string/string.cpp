#include<iostream>
using namespace std;
int main(void)
{	string str1,str2,str3;
	str1="You ";
	str2="are ";
	str3="vegetable.";
	cout<<str1<<str2<<str3<<endl;;
	str1+=str2;
	cout<<str1<<str3<<endl;
	str1+=str3;
	cout<<str1<<endl;
	return 0;
}
