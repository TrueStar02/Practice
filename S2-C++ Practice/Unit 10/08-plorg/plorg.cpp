#include "plorg.h"
Plorg::Plorg()
{	strcpy(name,"Plorga");
	CI=50;
}
Plorg::Plorg(const char * str)
{	strncpy(name,str,19);
	CI=50;
}
Plorg::~Plorg()
{	cout<<"Bye,"<<name<<"!\n";
}
void Plorg::show() const
{	cout<<"Name:"<<name<<"  CI:"<<CI<<endl;
}
void Plorg::change(int n)
{	CI=n;
}
