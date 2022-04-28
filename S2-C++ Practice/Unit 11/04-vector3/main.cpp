#include "vector3.h"
int main(void)
{	Vector v1(1,0,1);
	Vector v2(0,1,0);
	Vector v3(1,1,1);
	cout<<v1<<v2<<v3;
	cout<<(v1+v2)<<(v1-v2)<<(3*v3);
	cout<<(v3^v3)<<(v1*v2)<<(v3/3.0);
	cout<<(-v2);
	return 0;
}
