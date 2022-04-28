#include "stdmove.h"
#include<utility>
int main(void)
{	Useless One(10,'x');
	Useless Two=One+One;
	cout<<"Object One:";
	One.ShowData();
	cout<<"Object Two:";
	Two.ShowData();
	Useless Three,Four;
	cout<<"Three=One\n";
	Three=One;
	cout<<"Object One:";
	One.ShowData();
	cout<<"Object Three:";
	Three.ShowData();
	Four=One+Useless(10,'o');
	cout<<"Four=Three+10*o\n";
	Four.ShowData();
	cout<<"One=move(Two)\n";
	One=move(Two);
	cout<<"Object One:";
	One.ShowData();
	cout<<"Object Two:";
	Two.ShowData();
	return 0;
}
