#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
void ShowArray(const double ar[],int n);
double *NewDynArr(int n,...);
int main()
{	double *p1,*p2;
	p1=NewDynArr(5,1.2,2.3,3.4,4.5,5.6);
	p2=NewDynArr(4,100.0,20.00,8.08,-1890.00);
	ShowArray(p1,5);
	ShowArray(p2,4);
	free(p1);
	free(p2);
	return 0;
}
void ShowArray(const double ar[],int n)
{	int x;
	for(x=0;x<n;x++)
		printf("%.2lf ",*(ar+x));
	putchar('\n');
}
double *NewDynArr(int n,...)
{	double *ptr=(double *)malloc(n*sizeof(double));
	va_list ap;
	va_start(ap,n);
	int x;
	for(x=0;x<n;x++)
		*(ptr+x)=va_arg(ap,double);
	va_end(ap);
	return ptr;
}
