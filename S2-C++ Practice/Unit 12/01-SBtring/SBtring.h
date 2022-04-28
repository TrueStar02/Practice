#ifndef SBTRING_H_
#define SBTRING_H_
#include<iostream>
#include<cstring>
using namespace std;
class SBtring
{	private:
		char *str;
		int len;
		static int tot_str;
	public:
		SBtring();
		SBtring(const char *s);
		~SBtring();
		SBtring(const SBtring & s);
		SBtring & operator=(const SBtring & s);
		friend ostream & operator<<(ostream & os,const SBtring & s);
		friend istream & operator>>(istream & is,SBtring & s);
};
#endif
