#include "sales.h"
Sales::Sales(int yy):year(yy)
{	int x;
	for(x=0;x<12;x++)
		gross[x]=0;
}
Sales::Sales(int yy,const double *gr,int n):year(yy)
{	int x,lim=((n>12)?12:n);
	for(x=0;x<lim;x++)
		gross[x]=gr[x];
	for(;x<12;x++)
		gross[x]=0;
}
double Sales::operator[](int i)const
{	if(i<0||i>=12)
		throw bad_index(i);
	return gross[i];
}
double & Sales::operator[](int i)
{	if(i<0||i>=12)
		throw bad_index(i);
	return gross[i];
}
double LabelSales::operator[](int i)const
{	if(i<0||i>=12)
		throw nbad_index(label,i);
	return Sales::operator[](i);
}
double & LabelSales::operator[](int i)
{	if(i<0||i>=12)
		throw nbad_index(label,i);
	return Sales::operator[](i);
}
