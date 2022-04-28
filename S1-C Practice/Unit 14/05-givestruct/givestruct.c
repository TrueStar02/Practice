#include<stdio.h>
struct money
{	double m;
	double n;
};

double sum(const struct money rmb);
int main(void)
{	struct money rmb={1.99,3.66};
	printf("total:%.2lf\n",sum(rmb));
	return 0;
}
double sum(const struct money rmb)
{	return rmb.m+rmb.n;
}
