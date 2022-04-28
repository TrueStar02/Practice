#include "bank.h"
int main(void)
{	Account a1("Wang laoYun",6215337788431209,899776.98);
	Account a2;
	Account a3("Bian Runhua",6200987651728394);
	a1.show();
	a2.show();
	a3.show();
	a1.add(-18);
	a1.minus(98722);
	a1.show();
	a2.add(8.99);
	a2.show();
	a2.minus(17.33);
	return 0;
}
