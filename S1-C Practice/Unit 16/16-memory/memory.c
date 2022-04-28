#include<stdio.h>
#include<string.h>
_Static_assert(sizeof(double)==2*sizeof(int),"Error!");
int main()
{	int source[10]={0,1,2,3,4,5,6,7,8,9};
	int target[10],x;
	double fun[5];
	memcpy(target,source,10*sizeof(int));
	for(x=0;x<=9;x++)
		printf("%d ",target[x]);
	putchar('\n');
	memcpy(target+2,source,5*sizeof(int));
	for(x=0;x<=9;x++)
		printf("%d ",target[x]);
	putchar('\n');
	memcpy(fun,source,5*sizeof(double));
	for(x=0;x<=4;x++)
		printf("%lf ",fun[x]);
	putchar('\n');
	return 0;
}
