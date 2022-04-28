#include "wine.h"
void Wine::GetBottles()
{	int limit=Pair::value1().size(),x;
	for(x=0;x<limit;x++)
	{	cout<<"Enter year:";
		cin>>(Pair::value1())[x];
		cout<<"Enter bottles for that year:";
		cin>>(Pair::value2())[x];
	}
}
void Wine::Show() const
{	cout<<"Wine"<<(string &)(*this)<<endl;
	cout<<"      Year    Bottles\n";
	int limit=Pair::value1().size(),x;
	for(x=0;x<limit;x++)
		cout<<"    "<<(Pair::value1())[x]<<"    "<<(Pair::value2())[x]<<endl;
}
