#include "complex0.h"
int main(void)
{	Complex c1,c2;
	cin>>c1>>c2;
	cout<<c1<<" "<<c2<<endl;
	cout<<c1.length()<<" "<<c2.length()<<endl;
	cout<<~c1<<" "<<-c2<<endl;
	cout<<c1+c2<<" "<<c1-c2<<endl;
	cout<<c1*c2<<" "<<c1/c2<<endl;
	return 0;
}
