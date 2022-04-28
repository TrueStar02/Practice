#include "stock.h"
int main(void)
{	Stock stock1("Apple",100000,18.0);
	stock1.show();
	Stock stock2("Microsoft",50000,33.65);
	stock2.show();
	Stock stock3;
	stock3.show();
	stock3=stock2;
	stock3.show();
	stock3=Stock("Tesla",60000,5.89);
	stock3.show();
	stock1.buy(20000,21.0);
	stock1.show();
	stock2.sell(8000,34.09);
	stock2.show();
	stock3.update(58.9);
	stock3.show();
	return 0;
}
