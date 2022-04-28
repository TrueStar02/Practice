#include<stdio.h>
#include<stdarg.h>
double sum(int lim,...);
int main(void)
{	double a=sum(5,1.0,2.0,3.0,4.0,5.0);
	double b=sum(10,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5);
	printf("%5.1lf%5.1lf\n",a,b);
	return 0;
}
double sum(int lim,...)
{	va_list ap;
	int i;
	double sum=0;
	va_start(ap,lim);
	for(i=0;i<lim;i++)
		sum+=va_arg(ap,double);
	va_end(ap);
	return sum;
}
	
