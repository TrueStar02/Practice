#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{	char ch;
 	FILE *fp;
 	unsigned long count=0;
 	if(argc!=2)
 	{	printf("You are SB!\n");
 		exit(EXIT_FAILURE);
 	}
 	if((fp=fopen(argv[1],"r"))==NULL)
 	{	printf("Where is the file %s ?\n",argv[1]);
 		exit(EXIT_FAILURE);
 	}
 	while((ch=getc(fp))!=EOF)
 	{	putc(ch,stdout);
 		count++;
 	}
 	fclose(fp);
 	printf("File %s has %lu characters\n",argv[1],count);
 	return 0;
}
