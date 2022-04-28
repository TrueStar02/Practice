#include "shape.h"
int main(void)
{	Circle c(2,2,2);
	Ellipse  e(-1,-2,2,1,30);
	c.print();
	e.print();
	c.move(1,-1);
	c.reset_r(3.5);
	c.print();
	e.move(-2,1);
	e.reset_a(6);
	e.reset_b(2);
	e.twist(-15);
	e.print();
	return 0;
}
