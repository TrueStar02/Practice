#include<iostream>
#include "sales.h"
using namespace std;
int main(void)
{	double dx[3]={12.3,45.6,78.9};
	SALES::Sales sale1,sale2,sale3;
	SALES::setSales(sale1,dx,3);
	SALES::setSales(sale2);
	SALES::setSales(sale3);
	SALES::showSales(sale1);
	SALES::showSales(sale2);
	SALES::showSales(sale3);
	return 0;
}
