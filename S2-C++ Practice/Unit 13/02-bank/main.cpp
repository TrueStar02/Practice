#include "brass.h"
int main(void)
{	Brass Ivy("Ivy",381299,4000.00);
	BrassPlus Vanessa("Vanessa",382288,3000.00);
	Ivy.show();
	cout<<endl;
	Vanessa.show();
	cout<<endl;
	cout<<"Vanessa +1000\n";
	Vanessa.deposit(1000.0);
	cout<<"Vanessa:$"<<Vanessa.amount()<<endl;
	cout<<"Ivy -4200\n";
	Ivy.withdraw(4200.0);
	cout<<"Ivy:$"<<Ivy.amount()<<endl;
	cout<<"Vanessa -4200\n";
	Vanessa.withdraw(4200.0);
	cout<<"Vanessa:$"<<Vanessa.amount()<<endl;
	Vanessa.show();
	return 0;
}
