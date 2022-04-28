#include "time0.h"
int main(void)
{	Time t1;
	t1.show();
	Time t2(18,27,35);
	t2.show();
	t1.Reset(8,42,34);
	t1.show();
	Time t3=t1+t2;
	Time t4=t2-t1;
	t3.show();
	t4.show();
	t4=t4*5;
	t4.show();
	return 0;
}
