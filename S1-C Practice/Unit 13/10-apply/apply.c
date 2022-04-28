#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void apply(FILE *source,FILE *target);
int main(int argc,char *argv[])
{	if(argc<3)
	{	fprintf(stderr,"Are you kidding?");
		exit(EXIT_FAILURE);
	}
	FILE *target,*source;
	if((target=fopen(argv[1],"a+"))==NULL)
	{	fprintf(stderr,"I can't open the target file %s !\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(target,NULL,_IOFBF,4096))
	{	fprintf(stderr,"I can't create output buffer!\n");
		exit(EXIT_FAILURE);
	}
	int x,num=0;
	char ch;
	for(x=2;x<argc;x++)
	{	if(!strcmp(argv[1],argv[x]))
		{	fprintf(stderr,"I can't apply a file to itself!\n");
			continue;
		}	
		if((source=fopen(argv[x],"r"))==NULL)
		{	fprintf(stderr,"I can't open the source file %s,so it will be skipped.\n",argv[x]);
			continue;
		}
		if(setvbuf(source,NULL,_IOFBF,4096))
		{	fprintf(stderr,"I can't create output buffer for sourse file %s,so it will be skipped.\n",argv[x]);
			continue;
		}
		apply(source,target);
		printf("File %s has been applied!\n",argv[x]);
		num++;
		if(fclose(source))
		{	fprintf(stderr,"I can't close the source file %s !\n",argv[x]);
			exit(EXIT_FAILURE);
		}
	}
	rewind(target);
	printf("Done.%d files applied.\n",num);
	printf("Now %s contains:\n",argv[1]);
	while((ch=getc(target))!=EOF)
		putchar(ch);
	printf("\nDone,Byebye!\n");
	if(fclose(target))
		fprintf(stderr,"I can't close the target file %s !\n",argv[1]);
	return 0;
	
}
void apply(FILE *source,FILE *target)
{	size_t bytes;
	char temp[4096];
	while((bytes=fread(temp,sizeof(char),4096,source))>0)
		fwrite(temp,sizeof(char),bytes,target);
}
