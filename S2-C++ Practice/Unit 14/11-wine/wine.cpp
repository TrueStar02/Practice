#include "wine.h"
void Wine::GetBottles()
{	int limit=details.value1().size(),x;
	for(x=0;x<limit;x++)
	{	cout<<"Enter year:";
		cin>>(details.value1())[x];
		cout<<"Enter bottles for that year:";
		cin>>(details.value2())[x];
	}
}
void Wine::Show() const
{	cout<<"Wine"<<name<<endl;
	cout<<"      Year    Bottles\n";
	int limit=details.value1().size(),x;
	for(x=0;x<limit;x++)
		cout<<"    "<<(details.value1())[x]<<"    "<<(details.value2())[x]<<endl;
}
