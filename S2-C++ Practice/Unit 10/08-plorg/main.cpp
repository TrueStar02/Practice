#include "plorg.h"
int main(void)
{	Plorg a;
	Plorg b("Ivy");
	Plorg c("Abcdefghijklmnopqrstuvwxyz");
	a.show();
	b.show();
	c.show();
	b.change(70);
	b.show();
	return 0;
}
