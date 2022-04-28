#include "SBtring.h"
int main(void)
{	SBtring sb1;
	cin>>sb1;
	SBtring sb2("I Love U");
	cout<<sb1<<endl<<sb2<<endl;
	SBtring sb3=sb1;
	cout<<sb3<<endl;
	sb3=sb2;
	cout<<sb3<<endl;
	return 0;
}
