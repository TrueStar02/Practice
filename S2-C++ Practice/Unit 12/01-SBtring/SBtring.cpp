#include "SBtring.h"
int SBtring::tot_str=0;
SBtring::SBtring()
{	str=new char[1];
	*str='\0';
	len=0;
	tot_str++;
}
SBtring::SBtring(const char *s)
{	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	tot_str++;
}
SBtring::~SBtring()
{	delete [] str;
	tot_str--;
}
SBtring::SBtring(const SBtring & s)
{	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	tot_str++;
}
SBtring & SBtring::operator=(const SBtring & s)
{	if(this==&s)
		return *this;
	delete [] str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	return *this;
	
}
ostream & operator<<(ostream & os,const SBtring & s)
{	os<<s.str;
	return os;
}
istream & operator>>(istream & is, SBtring & s)
{	char temp[101];
	is>>temp;
	delete [] s.str;
	s.len=strlen(temp);
	s.str=new char[s.len+1];
	strcpy(s.str,temp);
	return is;
}
