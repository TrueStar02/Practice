#include "String2.h"
int String::tot_str=0;
String::String()
{	tot_str++;
	str=new char[1];
	len=0;
}
String::String(char *s)
{	tot_str++;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
}
String::String(const String & s)
{	tot_str++;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
}
String::~String()
{	tot_str--;
	delete [] str;
}
int String::length() const
{	return len;
}
void String::upper()
{	int x;
	for(x=0;x<len;x++)
	str[x]=toupper(str[x]);
}
void String::lower()
{	int x;
	for(x=0;x<len;x++)
	str[x]=tolower(str[x]);
}
char & String::operator[](int i)
{	return str[i];
}
const char & String::operator[](int i) const
{	return str[i];
}
String & String::operator=(const String & s)
{	if(this==&s)
		return *this;
	else
	{	len=s.len;
		str=new char[len+1];
		strcpy(str,s.str);
		return *this;
	}	
}
String & String::operator=(const char * s)
{	delete [] str;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}
bool operator>(const String & s1,const String & s2)
{	return (strcmp(s1.str,s2.str)>0);
}
bool operator<(const String & s1,const String & s2)
{	return (strcmp(s1.str,s2.str)<0);
}
bool operator==(const String & s1,const String & s2)
{	return (strcmp(s1.str,s2.str)==0);
}
bool operator!=(const String & s1,const String & s2)
{	return (strcmp(s1.str,s2.str)!=0);
}
bool operator>=(const String & s1,const String & s2)
{	return (strcmp(s1.str,s2.str)>=0);
}
bool operator<=(const String & s1,const String & s2)
{	return (strcmp(s1.str,s2.str)<=0);
}
String operator+(const String & s1,const String & s2)
{	String temp;
	temp.len=s1.len+s2.len;
	temp.str=new char[temp.len+1];
	strcpy(temp.str,s1.str);
	strcat(temp.str,s2.str);
	return temp;
}
istream & operator>>(istream & is,String & s)
{	delete [] s.str;
	char temp[101];
	is>>temp;
	s.len=strlen(temp);
	s.str=new char[s.len+1];
	strcpy(s.str,temp);
	return is;
}
ostream & operator<<(ostream & os,const String & s)
{	os<<s.str;
	return os;
}
int String::HowMany()
{	return tot_str;
}
