#include<iostream>
#include<initializer_list>
using namespace std;
double sum(initializer_list<double> i1);
double ave(const initializer_list<double> & ri1);
int main()
{	cout<<sum({2,3,4,5})<<endl;
	cout<<ave({1.2,2.6,4.1,5.8})<<endl;
	return 0;
}
double sum(initializer_list<double> i1)
{	double tot=0;
	for(auto p=i1.begin();p!=i1.end();p++)
		tot+=*p;
	return tot;
}
double ave(const initializer_list<double> & ri1)
{	double tot=0;
	for(auto p=ri1.begin();p!=ri1.end();p++)
		tot+=*p;
	return (tot/ri1.size());
}
