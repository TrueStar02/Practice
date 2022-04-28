#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{	int x,sum=0;
 	if(argc<2)
 		printf("Error!\n");
 	else
 		{for(x=1;x<argc;x++)
 			 sum+=atoi(argv[x]);
 		 printf("%d\n",sum);
 		}
 	return 0;
}
