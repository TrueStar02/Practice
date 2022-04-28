#include "brass.h"
typedef ios_base::fmtflags format;
typedef streamsize precis;
format setformat();
void restore(format f,precis p);
Brass::Brass(const string & fn,long ac,double mo)
{	fullname=fn;
	account=ac;
	money=mo;
}
void Brass::deposit(double mo)
{	if(mo<0)
		cout<<"Money should be positive!\n";
	else
		money+=mo;
}
void Brass::withdraw(double mo)
{	if(mo<0)
		cout<<"Money should be positive!\n";
	else if(mo>money)
		cout<<"You don't have enough money!\n";
	else
		money-=mo;
}
double Brass::amount() const
{	return money;
}
void Brass::show() const
{	format initialState=setformat();
	precis prec=cout.precision(2);
	cout<<"Client:"<<fullname<<endl;
	cout<<"Account Number:"<<account<<endl;
	cout<<"Balance:$"<<money<<endl;
	restore(initialState,prec);
}
BrassPlus::BrassPlus(const string & fn,long ac,double mo,double lim,double ra):Brass(fn,ac,mo)
{	limit=lim;
	rate=ra;
	loan=0;
}
BrassPlus::BrassPlus(const Brass & br,double mo,double lim,double ra):Brass(br)
{	limit=lim;
	rate=ra;
	loan=0;
}
void BrassPlus::withdraw(double mo)
{	format initialState=setformat();
	precis prec=cout.precision(2);
	double money=amount();
	if(mo<0)
		cout<<"Money should be positive!\n";
	else if(mo<=money)
		Brass::withdraw(mo);
	else if(mo<=money+limit-loan)
	{	double advance=mo-money;
		loan+=advance*(1.0+rate);
		cout<<"Bank advance:$"<<advance<<endl;
		cout<<"Finance charge:$"<<advance*rate<<endl;
		Brass::withdraw(mo-advance);
	}
	else
		cout<<"You don't have enough money!\n";
	restore(initialState,prec);
}
void BrassPlus::show() const
{	format initialState=setformat();
	precis prec=cout.precision(2);
	Brass::show();
	cout<<"Maxium Loan:$"<<limit<<endl;
	cout<<"Owed to bank:$"<<loan<<endl;
	cout.precision(3);
	cout<<"Loan Rate:"<<100*rate<<"%\n";
	restore(initialState,prec);
}
void BrassPlus::resetrate(double n)
{	rate=n;
}
void BrassPlus::resetlimit(double n)
{	limit=n;
}
void BrassPlus::pay()
{	loan=0;
}
format setformat()
{	return cout.setf(ios_base::fixed,ios_base::floatfield);
}
void restore(format f,precis p)
{	cout.setf(f,ios_base::floatfield);
	cout.precision(p);
}
