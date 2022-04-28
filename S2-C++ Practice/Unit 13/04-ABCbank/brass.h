#ifndef BRASS_H_
#define BRASS_H_
#include<iostream>
#include<string>
using namespace std;
class AcctABC
{	private:
		string fullname;
		long account;
		double money;
	protected:
		struct Formatting
		{	ios_base::fmtflags flag;
			streamsize pr;
		};
		const string & name() const{return fullname;}
		long acctnum() const{return account;}
		Formatting SetFormat() const;
		void Restore(Formatting & f) const;
	public:
		AcctABC(const string & fn="Anonymous",long ac=620000,double mo=0.0);
		void deposit(double mo);
		virtual void withdraw(double mo) =0;
		double amount() const;
		virtual void show() const=0;
		virtual ~AcctABC() {}
};
class Brass:public AcctABC
{	public:
		Brass(const string & fn="Anonymous",long ac=620000,double mo=0.0):AcctABC(fn,ac,mo){}
		virtual void withdraw(double mo);
		virtual void show() const;
		virtual ~Brass() {}
};
class BrassPlus:public AcctABC
{	private:
		double limit;
		double rate;
		double loan;
	public:
		BrassPlus(const string & fn="Anonymous",long ac=620000,double mo=0.0,double lim=500.0,double ra=0.11125);
		BrassPlus(const Brass & br,double mo=0.0,double lim=500.0,double ra=0.11125);
		virtual void withdraw(double mo);
		virtual void show() const;
		void resetrate(double n){rate=n;}
		void resetlimit(double n){limit=n;}
		void pay(){loan=0;}
};
#endif
