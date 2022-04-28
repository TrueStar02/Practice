#include<iostream>
using namespace std;
struct Car
{	string make;
	int year;
};
int main(void)
{	int num,x;
	cout<<"How many cars:";
	cin>>num;
	Car *details=new Car[num];
	for(x=0;x<num;x++)
	{	cin.get();
		cout<<"Enter the car make:";
		getline(cin,details[x].make);
		cout<<"Enter the year it was made:";
		cin>>details[x].year;
	}
	for(x=0;x<num;x++)
		cout<<"#"<<x+1<<":"<<details[x].make<<" made in "<<details[x].year<<endl;
	delete [] details;
	return 0;
}
