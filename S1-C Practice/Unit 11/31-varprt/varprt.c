#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc,char *argv[])
{	int x,y;
	if(!strcmp(argv[1],"-p"))
 		for(x=2;x<argc;x++)
 			printf("%s ",argv[x]);
 	else if(!strcmp(argv[1],"-u"))
 		for(x=2;x<argc;x++)
 			{for(y=0;y<strlen(argv[x]);y++)
 			 	argv[x][y]=toupper(argv[x][y]);
 			 printf("%s ",argv[x]);
 			}
 	else if(!strcmp(argv[1],"-l"))
 		for(x=2;x<argc;x++)
 			{for(y=0;y<strlen(argv[x]);y++)
 			 	argv[x][y]=tolower(argv[x][y]);
 			 printf("%s ",argv[x]);
 			}
 	else
 		for(x=1;x<argc;x++)
			printf("%s ",argv[x]);
 	printf("\n");
 	return 0;
}
