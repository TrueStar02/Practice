#include<stdio.h>
#include<stdlib.h>
#define SQUARE(X) ((X)*(X))
int main(int argc,char *argv[])
{	int x,num;
	for(x=1;x<argc;x++)
	{	num=atoi(argv[x]);
		printf("%d ",SQUARE(x));
	}
	putchar('\n');
	return 0;	
}
