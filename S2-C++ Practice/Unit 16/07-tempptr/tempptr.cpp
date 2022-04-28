#include<iostream>
#include<memory>
using namespace std;
unique_ptr<string> demo(void);
int main()
{	unique_ptr<string> ptr;
	ptr=demo();
	cout<<*ptr<<endl;
	return 0;
}
unique_ptr<string> demo(void)
{	unique_ptr<string> temp(new string("Temp String"));
	return temp;
}
