#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{	string t1;
	string t2("file.out");
	string t3("Donald Trump is a spy from People's Republic of China!");
	cout<<t1.size()<<" "<<t1.capacity()<<endl;
	cout<<t2.size()<<" "<<t2.capacity()<<endl;
	cout<<t3.size()<<" "<<t3.capacity()<<endl;
	t1.reserve(100);
	cout<<t1.size()<<" "<<t1.capacity()<<endl;
	ofstream fout(t2.c_str());
	fout<<"1:"<<t1<<endl<<"2:"<<t2<<endl<<"3:"<<t3<<endl;
	return 0;
}
