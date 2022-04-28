#include "person.h"
const char * suit[4]={"Spade","Heart","Diamond","Club"};
Porker::Porker()
{	type=rand()%4;
	num=rand()%13+1;
}
void Porker::Show() const
{	cout<<"A random porker:\n";
	cout<<"Suit:"<<suit[type]<<endl;
	cout<<"Number:"<<num<<endl;
}
void Person::Data()
{	cout<<"Name:"<<fname<<" "<<lname<<endl;
}
void Person::Get()
{	cout<<"Enter the firstname:";
	getline(cin,fname);
	cout<<"Enter the lastname:";
	getline(cin,lname);
}
void Gunslinger::Data()
{	cout<<"Time:"<<time<<endl;
	cout<<"Number of marks:"<<num<<endl;
}
void Gunslinger::Get()
{	cout<<"Enter the time:";
	cin>>time;
	cout<<"Enter the number of marks on his gun:";
	cin>>num;
	while(cin.get()!='\n')
		continue;
}
