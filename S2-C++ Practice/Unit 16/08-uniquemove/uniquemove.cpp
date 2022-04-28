#include<iostream>
#include<memory>
using namespace std;
int main()
{	unique_ptr<string> list[5]={unique_ptr<string>(new string("Amy")),unique_ptr<string>(new string("Binary")),
	unique_ptr<string>(new string("Cindy")),unique_ptr<string>(new string("Denny")),unique_ptr<string>(new string("Edward"))};
	unique_ptr<string> temp;
	temp=move(list[2]);
	list[2]=unique_ptr<string>(new string("Cella"));
	int x;
	for(x=0;x<5;x++)
		cout<<*list[x]<<endl;
	cout<<*temp<<endl;
	return 0;
}
