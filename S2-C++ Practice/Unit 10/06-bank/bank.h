#ifndef BANK_H_
#define BANK_H_
#include<iostream>
using namespace std;
class Account
{	private:
		string name;
		long number;
		double money;
	public:
		Account();
		Account(const string & str,long no=0,double mon=0);
		~Account();
		void show(void) const;
		void add(double mon);
		void minus(double mon);
};
#endif
