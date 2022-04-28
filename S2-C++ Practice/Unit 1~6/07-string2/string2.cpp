#include<iostream>
using namespace std;
int main(void)
{	string str1,str2,str3;
	getline(cin,str1);
	getline(cin,str2);
	getline(cin,str3);
	cout<<"Size:  "<<str1.size()<<" "<<str2.size()<<" "<<str2.size()<<"\n";
	cout<<"Length:"<<str1.length()<<" "<<str2.length()<<" "<<str2.length()<<"\n";
	cout<<str1<<str2<<str3<<endl;;
	str1+=str2;
	cout<<str1<<str3<<endl;
	str1+=str3;
	cout<<str1<<endl;
	return 0;
}
