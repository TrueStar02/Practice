#include<iostream>
#include "namesp.h"
namespace pers
{	using std::cout;
	using std::cin;
	void GetPerson(Person & rp)
	{	cout<<"Enter the first name:";
		cin>>rp.fname;
		cout<<"Enter the last name:";
		cin>>rp.lname;
	}
	void ShowPerson(const Person & rp)
	{	cout<<rp.fname<<" "<<rp.lname;
	}
}
namespace debts
{	using std::cout;
	using std::cin;
	void GetDebt(Debt &rd)
	{	GetPerson(rd.name);
		cout<<"Enter the debt:";
		cin>>rd.amount;
	}
	void ShowDebt(const Debt &rd)
	{	ShowPerson(rd.name);
		cout<<":$"<<rd.amount<<std::endl;
	}
	double sumdebts(const Debt * ar,int n)
	{	double total=0;
		int x;
		for(x=0;x<n;x++)
			total+=(ar+x)->amount;
		return total;
	}
}
