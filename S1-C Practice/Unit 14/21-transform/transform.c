#include<stdio.h>
#include<math.h>
void transform(double *source,double *target,int size,double(*ptr)(double));
int main(void)
{	int x;
	double source[91],target[91];
	for(x=0;x<=90;x++)
	source[x]=x;
	transform(source,target,91,sin);
	for(x=0;x<=90;x++)
	printf("%3d%11.8lf\n",x,target[x]);
	transform(source,target,91,cos);
	for(x=0;x<=90;x++)
	printf("%3d%11.8lf\n",x,target[x]);
	return 0;
}
void transform(double *source,double *target,int size,double(*ptr)(double))
{	int x;
	for(x=0;x<size;x++)
	target[x]=ptr(source[x]);
}
