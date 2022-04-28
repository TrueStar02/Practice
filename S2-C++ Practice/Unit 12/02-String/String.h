#ifndef STRING_H_
#define STRING_H_
#include<iostream>
#include<cstring>
using namespace std;
class String
{	private:
		char *str;
		int len;
		static int tot_str;
	public:
		String();
		String(const char *s);
		~String();
		String(const String & s);
		String & operator=(const String & s);
		String & operator=(const char * s);
		int length() const;
		char & operator[](int i);
		const char & operator[](int i) const;
		friend bool operator>(const String &s1,const String &s2);
		friend bool operator<(const String &s1,const String &s2);
		friend bool operator==(const String &s1,const String &s2);
		friend bool operator!=(const String &s1,const String &s2);
		friend bool operator>=(const String &s1,const String &s2);
		friend bool operator<=(const String &s1,const String &s2);
		friend ostream & operator<<(ostream & os,const String & s);
		friend istream & operator>>(istream & is,String & s);
		static int HowMany();
};
#endif
