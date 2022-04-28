#include "tptp.h"
int main(void)
{	Crab<Stack> nb;
	int i,x;
	double d;
	for(x=1;x<=8;x++)
	{	cout<<"Group "<<x<<":";
		cin>>i>>d;
		nb.push(i,d);
	}
	for(x=1;x<=8;x++)
	{	nb.pop(i,d);
		cout<<i<<" and "<<d<<" popped\n";
	}
	return 0;
}
