#include "time2.h"
int main(void)
{	Time t1;
	cout<<t1;
	Time t2(18,27,35);
	cout<<t2;
	t1.Reset(8,42,34);
	cout<<t1;
	Time t3=t1+t2;
	Time t4=t2-t1;
	cout<<t3;
	cout<<t4;
	t3=t3/3;
	t4=5*t4;
	cout<<t3;
	cout<<t4;
	return 0;
}
