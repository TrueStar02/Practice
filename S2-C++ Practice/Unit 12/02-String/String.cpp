#include "String.h"
int String::tot_str=0;
String::String()
{	str=new char[1];
	*str='\0';
	len=0;
	tot_str++;
}
String::String(const char *s)
{	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	tot_str++;
}
String::~String()
{	delete [] str;
	tot_str--;
}
String::String(const String & s)
{	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	tot_str++;
}
String & String::operator=(const String & s)
{	if(this==&s)
		return *this;
	delete [] str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	return *this;
}
String & String::operator=(const char * s)
{	delete [] str;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}
int String::length() const
{	return len;
}
char & String::operator[](int i)
{	return str[i];
}
const char & String::operator[](int i) const
{	return str[i];
}
bool operator>(const String &s1,const String &s2)
{	return strcmp(s1.str,s2.str)>0;
}
bool operator<(const String &s1,const String &s2)
{	return strcmp(s1.str,s2.str)<0;
}
bool operator==(const String &s1,const String &s2)
{	return !strcmp(s1.str,s2.str);
}
bool operator!=(const String &s1,const String &s2)	
{	return strcmp(s1.str,s2.str);
}
bool operator>=(const String &s1,const String &s2)
{	return strcmp(s1.str,s2.str)>=0;
}
bool operator<=(const String &s1,const String &s2)
{	return strcmp(s1.str,s2.str)<=0;
}
ostream & operator<<(ostream & os,const String & s)
{	os<<s.str;
	return os;
}
istream & operator>>(istream & is, String & s)
{	char temp[101];
	is>>temp;
	delete [] s.str;
	s.len=strlen(temp);
	s.str=new char[s.len+1];
	strcpy(s.str,temp);
	return is;
}
int String::HowMany()
{	return tot_str;
}
