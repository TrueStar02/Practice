#include<stdio.h>
#include<stdalign.h>
int main(void)
{	double dx;
	char ca;
	char cb;
	double dz;
	char cc;
	char alignas(double) cd;
	printf("char alignment:%zd\n",alignof(char));
	printf("double alignment:%zd\n",sizeof(double));
	printf("&dx:%p\n",&dx);
	printf("&ca:%p\n",&ca);
	printf("&cb:%p\n",&cb);
	printf("&dz:%p\n",&dz);
	printf("&cc:%p\n",&cc);
	printf("&cd:%p\n",&cd);
	return 0;
}
