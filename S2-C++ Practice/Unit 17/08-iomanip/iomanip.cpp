#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{	cout<<fixed<<right;
	cout<<setw(6)<<"N"<<setw(14)<<"squart root"<<setw(15)<<"fourth root\n";
	int x;
	for(x=10;x<=100;x+=10)
		cout<<setfill('.')<<setw(6)<<x<<setfill(' ')<<setw(12)<<setprecision(3)<<sqrt(x)<<setw(14)<<setprecision(4)<<x<<sqrt(sqrt(x))<<endl;
	return 0;
}
