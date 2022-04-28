#ifndef CD_H_
#define CD_H_
#include<iostream>
#include<cstring>
using namespace std;
class CD
{	private:
		char performers[51];
		char label[21];
		int selections;
		double playtime;
	public:
		CD() {}
		CD(const char *s1,const char *s2,int n,double x);
		virtual ~CD() {}
		virtual void Report() const;
};
class Classic:public CD
{	private:
		char work[51];
	public:
		Classic() {}
		Classic(const char *s3,const char *s1,const char *s2,int n,double x);
		Classic(const char *s,const CD & cd);
		~Classic() {}
		virtual void Report() const;
};
#endif
