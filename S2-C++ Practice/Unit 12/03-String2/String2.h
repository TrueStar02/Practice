#ifndef STRING2_H_
#define STRING2_H_
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
class String
{	private:
		char *str;
		int len;
		static int tot_str;
	public:
		String();
		String(char *s);
		String(const String & s);
		~String();
		int length() const;
		void upper();
		void lower();
		char & operator[](int i);
		const char & operator[](int i) const;
		String & operator=(const String & s);
		String & operator=(const char * s);
		friend bool operator>(const String & s1,const String & s2);
		friend bool operator<(const String & s1,const String & s2);
		friend bool operator==(const String & s1,const String & s2);
		friend bool operator!=(const String & s1,const String & s2);
		friend bool operator>=(const String & s1,const String & s2);
		friend bool operator<=(const String & s1,const String & s2);
		friend String operator+(const String & s1,const String & s2);
		friend istream & operator>>(istream & is,String & s);
		friend ostream & operator<<(ostream & os,const String & s);
		static int HowMany();
};
#endif
