#include<iostream>
using namespace std;
int main()
{	string s1("CGLNB");
	string s2(10,'$');
	string s3(s1);
	string s4;
	s4=s2+s3;
	s4+=s2;
	const char *ptr="Merry Christmas!";
	string s5(ptr,6);
	string s6(ptr+6,ptr+16);
	string s7(s3,3,2);
	cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<s5<<endl<<s6<<endl<<s7<<endl;
	return 0;
}
