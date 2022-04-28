#include "workermi.h"
void Worker::Data() const
{	cout<<"Name:"<<fullname<<endl;
	cout<<"Employee ID:"<<id<<endl;
}
void Worker::Get()
{	cout<<"Enter the name:";
	getline(cin,fullname);
	cout<<"Enter the worker's ID:";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}		
void Waiter::Data() const
{	cout<<"Panache Rating:"<<panache<<endl;
}
void Waiter::Get()
{	cout<<"Enter his/her panache:";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}
void Waiter::Set()
{	cout<<"Add a Waiter:\n";
	Worker::Get();
	Get();
}
void Waiter::Show() const
{	cout<<"Catalogy:Waiter\n";
	Worker::Data();
	Data();
}
void Singer::Data() const
{	cout<<"Vocal Range:"<<style[voice]<<endl;
}
void Singer::Get()
{	cout<<"Enter his/her style in the number below:\n";
	int x;
	for(x=0;x<7;x++)
	{	cout<<x<<":"<<style[x]<<" ";
		if(x%4==3)
			cout<<endl;
	}
	cout<<endl;
	cin>>voice;
	while(cin.get()!='\n')
		continue;
}
void Singer::Set()
{	cout<<"Add a Singer\n";
	Worker::Get();
	Get();
}
void Singer::Show() const
{	cout<<"Catalogy:Singer\n";
	Worker::Data();
	Data();
}
void SingingWaiter::Data() const
{	Waiter::Data();
	Singer::Data();
}
void SingingWaiter::Get()
{	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set()
{	cout<<"Add a SingingWaiter\n";
	Worker::Get();
	Get();
}
void SingingWaiter::Show() const
{	cout<<"Catalogy:SingingWaiter\n";
	Worker::Data();
	Data();
}
