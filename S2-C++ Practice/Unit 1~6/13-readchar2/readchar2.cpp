#include<iostream>
using namespace std;
int main(void)
{	int num=0;
	char ch;
	while((ch=cin.get())!=EOF)
	{	cout.put(ch);
		num++;
	}
	cout<<"Total:"<<num<<endl;
	return 0;
}
