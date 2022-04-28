#include "brass.h"
AcctABC::AcctABC(const string & fn,long ac,double mo)
{	fullname=fn;
	account=ac;
	money=mo;
}
void AcctABC::deposit(double mo)
{	if(mo<0)
		cout<<"Money should be positive!\n";
	else
		money+=mo;
}
void AcctABC::withdraw(double mo)
{	money-=mo;
}
void AcctABC::show() const
{	Formatting f=SetFormat();
	cout<<"Client:"<<fullname<<endl;
	cout<<"Account Number:"<<account<<endl;
	cout<<"Balance:$"<<money<<endl;
	Restore(f);
}
AcctABC::Formatting AcctABC::SetFormat() const
{   Formatting f;
    f.flag= cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr=cout.precision(2);
    return f; 
}
void AcctABC::Restore(Formatting & f) const
{   cout.setf(f.flag,ios_base::floatfield);
    cout.precision(f.pr);
}
void Brass::withdraw(double mo)
{	if(mo<0)
		cout<<"Money should be positive!\n";
	else if(mo>amount())
		cout<<"You don't have enough money!\n";
	else
		AcctABC::withdraw(mo);
}
double AcctABC::amount() const
{	return money;
}
void Brass::show() const
{	AcctABC::show();
}
BrassPlus::BrassPlus(const string & fn,long ac,double mo,double lim,double ra):AcctABC(fn,ac,mo)
{	limit=lim;
	rate=ra;
	loan=0;
}
BrassPlus::BrassPlus(const Brass & br,double mo,double lim,double ra):AcctABC(br)
{	limit=lim;
	rate=ra;
	loan=0;
}
void BrassPlus::withdraw(double mo)
{	Formatting f=SetFormat();
	double money=amount();
	if(mo<0)
		cout<<"Money should be positive!\n";
	else if(mo<=money)
		AcctABC::withdraw(mo);
	else if(mo<=money+limit-loan)
	{	double advance=mo-money;
		loan+=advance*(1.0+rate);
		cout<<"Bank advance:$"<<advance<<endl;
		cout<<"Finance charge:$"<<advance*rate<<endl;
		AcctABC::withdraw(mo-advance);
	}
	else
		cout<<"You don't have enough money!\n";
	Restore(f);
}
void BrassPlus::show() const
{	Formatting f=SetFormat();
	AcctABC::show();
	cout<<"Maxium Loan:$"<<limit<<endl;
	cout<<"Owed to bank:$"<<loan<<endl;
	cout.precision(3);
	cout<<"Loan Rate:"<<100*rate<<"%\n";
	Restore(f);
}

