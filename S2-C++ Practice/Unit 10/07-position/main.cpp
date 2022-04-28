#include "position.h"
int main(void)
{	Point x;
	Point y(7.22,9.88);
	x.show();
	y.show();
	x.move(-2.17,5.11);
	Point z=y.copy(-1,1);
	x.show();
	y.show();
	z.show();
	x.reset(9,-6);
	x.show();
	cout<<"Goodbye~\n";
	return 0;
}
