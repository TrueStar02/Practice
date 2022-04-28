#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Porker
{	private:
		int type;
		int num;
	public:
		Porker();
		void Show() const;
};
class Person
{	private:
		string fname;
		string lname;
	protected:
		virtual void Data();
		virtual void Get();
	public:
		explicit Person(const string & f="Anonymous",const string & l="Null"):fname(f),lname(l) {}
		virtual ~Person(){}
		virtual void Set(){cout<<"Type:Normal Person\n";Person::Get();}
		virtual void Show(){cout<<"Type:Normal Person\n";Person::Data();}
};
class Gunslinger:virtual public Person
{	private:
		double time;
		int num;
	protected:
		virtual void Data();
		virtual void Get();
	public:
		explicit Gunslinger(const string & f="Anonymous",const string & l="Null",double t=0.0,int n=0):Person(f,l),time(t),num(n) {}
		Gunslinger(const Person & p,double t=0.0,int n=0):Person(p),time(t),num(n) {}
		virtual ~Gunslinger(){}
		virtual void Set(){cout<<"Type:Gunslinger\n";Person::Get();Gunslinger::Get();}
		virtual void Show(){cout<<"Type:Gunslinger\n";Person::Data();Gunslinger::Data();}
		double & Draw(){return time;}
};
class PorkerPlayer:virtual public Person
{	public:
		explicit PorkerPlayer(const string & f="Anonymous",const string & l="Null"):Person(f,l) {}
		PorkerPlayer(const Person & p):Person(p) {}
		virtual ~PorkerPlayer(){}
		virtual void Set(){cout<<"Type:PorkerPlayer\n";Person::Get();}
		virtual void Show(){cout<<"Type:PorkerPlayer\n";Person::Data();}
		Porker Draw(){return Porker();}
};
class BadDude:public Gunslinger,public PorkerPlayer
{	public:
		explicit BadDude(const string & f="Anonymous",const string & l="Null",double t=0.0,int n=0):Person(f,l),Gunslinger(f,l,t,n),PorkerPlayer(f,l) {}
		BadDude(const Person & p,double t=0.0,int n=0):Person(p),Gunslinger(p,t,n),PorkerPlayer(p) {}
		BadDude(const Gunslinger & g):Person(g),Gunslinger(g),PorkerPlayer(g) {}
		BadDude(const PorkerPlayer & p,double t=0.0,int n=0):Person(p),Gunslinger(p,t,n),PorkerPlayer(p) {}
		virtual ~BadDude(){}
		double & Gdraw(){return Gunslinger::Draw();}
		Porker Cdraw(){return PorkerPlayer::Draw();}
		virtual void Set(){cout<<"Type:BadDude\n";Person::Get();Gunslinger::Get();}
		virtual void Show(){cout<<"Type:BadDude\n";Person::Data();Gunslinger::Data();}
};
#endif
