#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int mycomp(const void *ptr1,const void *ptr2);
int mycompI(const void *ptr1,const void *ptr2);
int main(void)
{	double arr[40];
	int x;
	srand((unsigned int)time(0));
	puts("Before sorting:");
	for(x=0;x<40;x++)
	{	arr[x]=(rand()%100)+((rand()%1000)/1000.0);
		printf("%7.3lf",*(arr+x));
		if(x%8==7)
			printf("\n");
	}
	qsort(arr,40,sizeof(double),mycomp);
	puts("After sorting");
	for(x=0;x<40;x++)
	{	printf("%7.3lf",*(arr+x));
		if(x%8==7)
			printf("\n");
	}
	puts("After inversed sorting");
	qsort(arr,40,sizeof(double),mycompI);
	for(x=0;x<40;x++)
	{	printf("%7.3lf",*(arr+x));
		if(x%8==7)
			printf("\n");
	}
	return 0;
}
int mycomp(const void *ptr1,const void *ptr2)
{	const double *dpt1=(const double *)ptr1;
	const double *dpt2=(const double *)ptr2;
	if(*dpt1<*dpt2)
		return -1;
	else if(*dpt1==*dpt2)
		return 0;
	else
		return 1;
}
int mycompI(const void *ptr1,const void *ptr2)
{	const double *dpt1=(const double *)ptr1;
	const double *dpt2=(const double *)ptr2;
	if(*dpt1>*dpt2)
		return -1;
	else if(*dpt1==*dpt2)
		return 0;
	else
		return 1;
}
