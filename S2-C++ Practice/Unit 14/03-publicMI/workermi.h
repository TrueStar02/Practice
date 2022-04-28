#ifndef WORKERMI_H_
#define WORKERMI_H_
#include<iostream>
using namespace std;
const string style[7]={"Other","Alto","Contralto","Soprano","Bass","Baritone","Tenor"};
class Worker
{	private:
		string fullname;
		long id;
	protected:
		virtual void Data() const=0;
		virtual void Get()=0;
	public:
		Worker(){fullname="Anonymous",id=0L;}
		Worker(const string & s,long x){fullname=s,id=x;}
		virtual ~Worker(){}
		virtual void Set()=0;
		virtual void Show() const=0;
};
class Waiter:virtual public Worker
{	private:
		int panache;
	protected:
		virtual void Data() const;
		virtual void Get();
	public:
		Waiter():Worker(){panache=0;}
		Waiter(const string & s,long x,int p=0):Worker(s,x){panache=p;}
		Waiter(const Worker & wk,int p=0):Worker(wk){panache=p;}
		~Waiter(){}
		virtual void Set();
		virtual void Show() const;
};
class Singer:virtual public Worker
{	private:
		int voice;
	protected:
		virtual void Data() const;
		virtual void Get();
	public:
		Singer():Worker(){voice=0;}
		Singer(const string & s,long x,int v=0):Worker(s,x){voice=v;}
		Singer(const Worker & wk,int v=0):Worker(wk){voice=v;}
		~Singer(){}
		virtual void Set();
		virtual void Show() const;
};
class SingingWaiter:public Singer,public Waiter
{	protected:
		virtual void Data() const;
		virtual void Get();
	public:
		SingingWaiter(){}
		SingingWaiter(const string & s,long x,int p=0,int v=0):Worker(s,x),Singer(s,x,v),Waiter(s,x,p){}
		SingingWaiter(const Worker & wk,int p=0,int v=0):Worker(wk),Singer(wk,v),Waiter(wk,p){}
		SingingWaiter(const Singer & s,int p=0):Worker(s),Singer(s),Waiter(s,p){}
		SingingWaiter(const Waiter & w,int v=0):Worker(w),Singer(w,v),Waiter(w){}
		virtual void Set();
		virtual void Show() const;
};
#endif
