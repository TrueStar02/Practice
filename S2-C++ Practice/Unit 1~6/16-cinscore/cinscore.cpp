#include<iostream>
using namespace std;
int main(void)
{	int arr[10],x,tot=0;
	for(x=0;x<10;x++)
	{	cout<<"Enter score #"<<x+1<<":";
		while(!(cin>>arr[x]))
		{	cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"Enter a number:";
		}
	}
	for(x=0;x<10;x++)
		tot+=arr[x];
	cout<<"Total:"<<tot<<endl;
}
