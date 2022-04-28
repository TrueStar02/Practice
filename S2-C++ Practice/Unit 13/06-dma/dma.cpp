#include "dma.h"
baseDMA::baseDMA(const char * str,int r)
{	label=new char[strlen(str)+1];
	strcpy(label,str);
	rating=r;
}
baseDMA::baseDMA(const baseDMA & b)
{	label=new char[strlen(b.label)+1];
	strcpy(label,b.label);
	rating=b.rating;
}
baseDMA::~baseDMA()
{	delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & b)
{	if(&b==this)
		return *this;
	else
	{	delete [] label;
		label=new char[strlen(b.label)+1];
		strcpy(label,b.label);
		rating=b.rating;
		return *this;	
	}
}
ostream & operator<<(ostream & os,const baseDMA & b)
{	os<<"Label"<<b.label<<endl;
	os<<"Rating:"<<b.rating<<endl;
	return os;
}
hasDMA::hasDMA(const char * sty,const char * str,int r):baseDMA(str,r)
{	style=new char[strlen(sty)+1];
	strcpy(style,sty);
}
hasDMA::hasDMA(const char * sty,const baseDMA & b):baseDMA(b)
{	style=new char[strlen(sty)+1];
	strcpy(style,sty);
}
hasDMA::hasDMA(const hasDMA &h):baseDMA(h)
{	style=new char[strlen(h.style)+1];
	strcpy(style,h.style);
}
hasDMA::~hasDMA()
{	delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & h)
{	if(&h==this)
		return *this;
	else
	{	baseDMA::operator=(h);
		delete [] style;
		style=new char[strlen(h.style)+1];
		strcpy(style,h.style);
		return *this;	
	}
}
ostream & operator<<(ostream & os,const hasDMA & h)
{	os<<(const baseDMA &)h;
	os<<"Style:"<<h.style<<endl;
	return os;
}
