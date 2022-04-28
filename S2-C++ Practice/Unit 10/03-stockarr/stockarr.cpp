#include "stock2.h"
int main(void)
{	Stock arr[4];
	int x;
	string co;
	long n;
	double val;
	for(x=0;x<=3;x++)
	{	cout<<"Enter the company #"<<x+1<<":";
		getline(cin,co);
		cout<<"Shares of the company:";
		cin>>n;
		cout<<"Price of each share:";
		cin>>val;
		arr[x]=Stock(co,n,val);
		arr[x].show();
		while(cin.get()!='\n')
			continue;
	}
	Stock top=arr[0];
	for(x=1;x<=3;x++)
		top=top.topval(arr[x]);
	top.show();
	return 0;
}
