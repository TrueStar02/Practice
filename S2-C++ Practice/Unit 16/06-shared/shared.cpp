#include<iostream>
#include<memory>
using namespace std;
int main()
{	shared_ptr<string> list[5]={shared_ptr<string>(new string("Amy")),shared_ptr<string>(new string("Binary")),
	shared_ptr<string>(new string("Cindy")),shared_ptr<string>(new string("Denny")),shared_ptr<string>(new string("Edward"))};
	shared_ptr<string> temp;
	temp=list[2];
	int x;
	for(x=0;x<5;x++)
		cout<<*list[x]<<endl;
	cout<<*temp<<endl;
	return 0;
}
