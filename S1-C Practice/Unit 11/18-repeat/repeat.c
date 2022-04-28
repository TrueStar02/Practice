#include<stdio.h>
int main(int argc,char *argv[]) 
{
	int x;
 	printf("We will repeat %d words\n", argc-1);
 	for(x=1; x<argc; x++)
 		printf("%d:%s\n", x, argv[x]);
 	printf("\n");
 	return 0;
}
