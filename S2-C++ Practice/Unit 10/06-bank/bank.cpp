#include "bank.h"
Account::Account()
{	name="Anonymous";
	number=6200000000000000;
	money=0;
}
Account::Account(const string & str,long no,double mon)
{	name=str;
	number=no;
	money=mon;
}
Account::~Account()
{	cout<<"Bye,"<<name<<"!\n";
}
void Account::show(void) const
{	cout<<"Name:"<<name<<"   Account Number:"<<number<<"   Money:$"<<money<<"\n";
}
void Account::add(double mon)
{	if(mon<0)
		cout<<"Money can't be negative!\n";
	else
		money+=mon;
}
void Account::minus(double mon)
{	if(mon<0)
		cout<<"Money can't be negative!\n";
	else if(mon>money)
		cout<<"You don't have enough money!\n";
	else
		money-=mon;
}
