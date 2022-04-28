#ifndef CD_H_
#define CD_H_
#include<iostream>
#include<cstring>
using namespace std;
class CD
{	private:
		char *performers;
		char *label;
		int selections;
		double playtime;
	public:
		CD(); 
		CD(const char *s1,const char *s2,int n,double x);
		CD(const CD & cd);
		virtual ~CD();
		virtual void Report() const;
		CD & operator=(const CD & cd);
};
class Classic:public CD
{	private:
		char *work;
	public:
		Classic();
		Classic(const char *s3,const char *s1,const char *s2,int n,double x);
		Classic(const char *s,const CD & cd);
		Classic(const Classic & cl);
		~Classic();
		virtual void Report() const;
		Classic & operator=(const Classic & cl);
};
#endif
