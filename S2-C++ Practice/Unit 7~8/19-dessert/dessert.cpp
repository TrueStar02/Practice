#include<iostream>
using namespace std;
struct Detail
{	string name;
	double weight;
	int heat;
};
void SetDessert(Detail & s,const char *str="Millennium Munch",const double d=2.85,const int i=350);
void Print(const Detail s);
int main(void)
{	Detail sw1,sw2;
	SetDessert(sw1);
	SetDessert(sw2,"Sweet Circle",1.55,300);
	Print(sw1);
	Print(sw2);
	return 0;
}
void SetDessert(Detail & s,const char *str,const double d,const int i)
{	s.name=str;
	s.weight=d;
	s.heat=i;
}
void Print(const Detail s)
{	cout<<s.name<<" ,"<<s.weight<<" pound(s),"<<"contains "<<s.heat<<" Cal.\n";
}
