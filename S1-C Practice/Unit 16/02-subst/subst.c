#include<stdio.h>
#include<stdlib.h>
#define PRTS(x) printf("The square of " #x " is %d.\n",((x)*(x)))	//niyinglexingleba
int main(int argc,char *argv[])
{	int x,num;
	for(x=1;x<argc;x++)
	{	num=atoi(argv[x]);
		PRTS(num);
	}
	return 0;	
}
