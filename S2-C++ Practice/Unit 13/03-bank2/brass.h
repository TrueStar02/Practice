#ifndef BRASS_H_
#define BRASS_H_
#include<iostream>
using namespace std;
class Brass
{	private:
		string fullname;
		long account;
		double money;
	public:
		Brass(const string & fn="Anonymous",long ac=6200000000000000,double mo=0.0);
		void deposit(double mo);
		virtual void withdraw(double mo);
		double amount() const;
		virtual void show() const;
};
class BrassPlus:public Brass
{	private:
		double limit;
		double rate;
		double loan;
	public:
		BrassPlus(const string & fn="Anonymous",long ac=6200000000000000,double mo=0.0,double lim=500.0,double ra=0.11125);
		BrassPlus(const Brass & br,double mo=0.0,double lim=500.0,double ra=0.11125);
		virtual void withdraw(double mo);
		virtual void show() const;
		void resetrate(double n);
		void resetlimit(double n);
		void pay();
};
#endif
