#include "vector2.h"
int main(void)
{	Vector v1;
	Vector v2(5,40,1);
	cout<<v1;
	cout<<v2;
	Vector v3(11,14);
	v1=v1+v3;
	cout<<v3;
	v1.switch_mode();
	cout<<v1;
	Vector v4=v3-v2;
	cout<<v4;
	v2=2*v2;
	cout<<v2;
	cout<<(v3^v2)<<" "<<(v3*v2)<<endl;
	return 0;
}
