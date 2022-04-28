#include "stock.h"
Stock::Stock()
{	cout<<"Default Mode\n";
	company="Anonymous";
	shares=0;
	share_val=0;
	total_val=0;
}
Stock::Stock(const string & co,long n,double pr)
{	company=co;
	if(n<0)
	{	shares=0;
		cout<<"You can't buy negative number of stock,so shares set to 0\n";
	}
	else
		shares=n;
	share_val=pr;
	set_tot();
}
Stock::~Stock()
{	cout<<"Bye,"<<company<<"!\n";
}
void Stock::buy(long num,double price)
{	if(num<=0)
		cout<<"You can't buy negative number of stock\n";
	else
	{	shares+=num;
		share_val=price;
		set_tot();
	}
}
void Stock::sell(long num,double price)
{	if(num<=0)
		cout<<"You can't sell negative number of stock\n";
	else if(num>shares)
		cout<<"You can't sell more than you have!\n";
	else
	{	shares-=num;
		share_val=price;
		set_tot();
	}	
}
void Stock::update(double price)
{	share_val=price;
	set_tot();
}
void Stock::show(void)
{	cout<<"******************************************\n";
	ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
	streamsize prec=cout.precision(3);
	cout<<"Company:"<<company<<endl;
	cout<<"Shares:"<<shares<<endl;
	cout<<"Share Price:$"<<share_val<<endl;
	cout.precision(2);
	cout<<"Total Worth:$"<<total_val<<endl;
	cout.setf(orig,ios_base::floatfield);
	cout.precision(prec);
	cout<<"******************************************\n";
}
