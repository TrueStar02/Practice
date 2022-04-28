#include<iostream>
using namespace std;
int main(void)
{	int x=10;
	int &ref=x;
	cout<<x<<" "<<ref<<endl;
	ref++;
	cout<<x<<" "<<ref<<endl;
	x++;  j     
	cout<<x<<" "<<ref<<endl;
	return 0;
}
