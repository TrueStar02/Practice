#include<iostream>
#include<array>
using namespace std;
int main(void)
{	array<int,3>running;
	int x;
	for(x=0;x<3;x++)
		running[x]=220-11*x;
	for(x=0;x<=3;x++)
		cout<<running.at(x)<<endl;
	return 0;
}
