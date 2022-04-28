#include "CD.h"
CD::CD(const char *s1,const char *s2,int n,double x)
{	strcpy(performers,s1);
	strcpy(label,s2);
	selections=n;
	playtime=x;
}
void CD::Report() const
{		cout<<"Performers:"<<performers<<endl;
		cout<<"Label:"<<label<<endl;
		cout<<"Selections:"<<selections<<endl;
		cout<<"Playtime:"<<int(playtime)<<":"<<int(playtime*60-60*int(playtime))<<endl;
}
Classic::Classic(const char *s3,const char *s1,const char *s2,int n,double x):CD(s1,s2,n,x)
{	strcpy(work,s3);
}
Classic::Classic(const char *s,const CD & cd):CD(cd)
{	strcpy(work,s);
}
void Classic::Report() const
{	CD::Report();
	cout<<"Main Work:"<<work<<endl;
}
