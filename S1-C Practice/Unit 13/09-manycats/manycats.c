#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{	if(argc<2)
	{	fprintf(stderr,"SB!!!\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	int num=0;
	char ch;
	int x;
	for(x=1;x<argc;x++)
	{	if((fp=fopen(argv[x],"r"))==NULL)
		{	fprintf(stderr,"Error in opening %s !\n\n",argv[x]); 
			continue;
		}
		num++;
		printf("Here is the file %d,%s:\n",num,argv[x]);
		while((ch=getc(fp))!=EOF)
			putchar(ch);
		printf("\nFile %s finished.\n\n",argv[x]);
		if(fclose(fp))
		{	fprintf(stderr,"Error in closing the file %s\n",argv[x]);
			exit(EXIT_FAILURE);
		}	
	}
	printf("Done.%d files presented.\n",num);
	return 0;
}
