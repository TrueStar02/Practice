#include "workermi.h"
#include<cstring>
#include<cctype>
char menu(void);
int main(void)
{	cout<<"How many staffs:";
	int n,x;
	cin>>n;
	while(cin.get()!='\n')
		continue;
	char ch;
	Worker *pw[n];
	for(x=0;x<n;x++)
	{	ch=menu();
		switch(ch)
		{	case 'w':pw[x]=new Waiter;
				break;
			case 's':pw[x]=new Singer;
				break;
			case 't':pw[x]=new SingingWaiter;
				break;
		}
		pw[x]->Set();
	}
	for(x=0;x<n;x++)
		pw[x]->Show();
	for(x=0;x<n;x++)
		delete pw[x];
	return 0;
}
char menu(void)
{	cout<<"What kind of staff?\n";
	cout<<"W-Waiter S-Singer T-SingingWaiter\n";
	cout<<"Your choice:";
	char v;
	v=tolower(cin.get());
	while(NULL==strchr("wst",v))
	{	while(cin.get()!='\n')
			continue;
		cout<<"Enter W,S or T:";
		v=tolower(cin.get());
	}
	while(cin.get()!='\n')
		continue;
	return v;
}
