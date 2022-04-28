#include<iostream>
using namespace std;
struct Pizza
{	string name;
	double diameter;
	double weight;
};
int main(void)
{	cout<<"How many pizzas:";
	int num,x;
	cin>>num;
	Pizza *details=new Pizza[num];
	for(x=0;x<num;x++)
	{	cin.get();
		cout<<"Pizza name:"<<endl;
		getline(cin,details[x].name);
		cout<<"Pizza's diameter(inch):";
		cin>>details[x].diameter;
		cout<<"Pizza's weight(pound):";
		cin>>details[x].weight;
	}
	for(x=0;x<num;x++)
		cout<<"#"<<x+1<<":"<<details[x].name<<",D="<<details[x].diameter<<"inches,weights "<<details[x].weight<<" pounds"<<endl;
	delete [] details;
	return 0;
}
