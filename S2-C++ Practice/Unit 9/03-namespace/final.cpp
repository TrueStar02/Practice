#include<iostream>
#include "namesp.h"
void other(void);
void another(void);
int main(void)
{	using debts::Debt;
	using debts::ShowDebt;
	Debt golf={{"Benny","Goatsniff"},120.0};
	ShowDebt(golf);
	other();
	another();
	return 0;
}
void other(void)
{	using std::endl;
	using namespace debts;
	Person dg={"Doogles","Glister"};
	ShowPerson(dg);
	cout<<endl;
	Debt zippy[3];
	int x;
	for(x=0;x<3;x++)
		GetDebt(zippy[x]);
	for(x=0;x<3;x++)
		ShowDebt(zippy[x]);
	cout<<"Total Debt:$"<<sumdebts(zippy,3)<<endl;
}
void another(void)
{	using pers::Person;
	Person collector={"Milo","Rightshift"};
	pers::ShowPerson(collector);
	std::cout<<std::endl;
}
