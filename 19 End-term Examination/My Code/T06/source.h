#ifndef SOURCE_H_
#define SOURCE_H_
#include<stdio.h>
#include<stdlib.h>
double** make_list(double data[], int sizes[])
{	int count=0,m,x,y;
	for(m=0;m<=19;m++)
		if(sizes[m]==0)
			break;
	double **big=(double **)malloc(sizeof(double *)*m);
	for(x=0;x<m;x++)
	{	*(big+x)=(double *)malloc(sizeof(double)*sizes[x]);
		for(y=0;y<sizes[x];y++)
		{	*(*(big+x)+y)=data[count];
			count++;
		}
	}
	return big;
}
void free_lists(double* lists[])
{	int x,num=sizeof(*lists)/sizeof(double *);
	for(x=0;x<num;x++)
		free(lists[x]);
	free(lists);
}
#endif
