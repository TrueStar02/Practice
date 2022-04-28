#include "CD.h"
CD::CD()
{	performers=new char[1];
	performers[0]='\0';
	label=new char[1];
	label[0]='\0';
	selections=0;
	playtime=0.0;
} 
CD::CD(const char *s1,const char *s2,int n,double x)
{	performers=new char[strlen(s1)+1];
	strcpy(performers,s1);
	label=new char[strlen(s2)+1];
	strcpy(label,s2);
	selections=n;
	playtime=x;
}
CD::CD(const CD & cd)
{	performers=new char[strlen(cd.performers)+1];
	strcpy(performers,cd.performers);
	label=new char[strlen(cd.label)+1];
	strcpy(label,cd.label);
	selections=cd.selections;
	playtime=cd.playtime;
}
CD::~CD()
{	delete [] performers;
	delete [] label;
}
void CD::Report() const
{		cout<<"Performers:"<<performers<<endl;
		cout<<"Label:"<<label<<endl;
		cout<<"Selections:"<<selections<<endl;
		cout<<"Playtime:"<<int(playtime)<<":"<<int(playtime*60-60*int(playtime))<<endl;
}
CD & CD::operator=(const CD & cd)
{	if(this==&cd)
		return *this;
	else
	{	delete [] performers;
		delete [] label;
		performers=new char[strlen(cd.performers)+1];
		strcpy(performers,cd.performers);
		label=new char[strlen(cd.label)+1];
		strcpy(label,cd.label);
		selections=cd.selections;
		playtime=cd.playtime;
		return *this;
	}
}
Classic::Classic():CD()
{	work=new char[1];
	work[0]='\0';
}
Classic::Classic(const char *s3,const char *s1,const char *s2,int n,double x):CD(s1,s2,n,x)
{	work=new char[strlen(s3)+1];
	strcpy(work,s3);
}
Classic::Classic(const char *s,const CD & cd):CD(cd)
{	work=new char[strlen(s)+1];
	strcpy(work,s);
}
Classic::Classic(const Classic & cl):CD(cl)
{	work=new char[strlen(cl.work)+1];
	strcpy(work,cl.work);
}
Classic::~Classic()
{	delete [] work;
}
void Classic::Report() const
{	CD::Report();
	cout<<"Main Work:"<<work<<endl;
}
Classic & Classic::operator=(const Classic & cl)
{	if(this==&cl)
		return *this;
	else
	{	CD::operator=(cl);
		delete [] work;
		work=new char[strlen(cl.work)+1];
		strcpy(work,cl.work);
		return *this;
	}
}
