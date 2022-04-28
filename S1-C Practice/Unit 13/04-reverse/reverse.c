#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{	if(argc!=2)
 	{	fprintf(stderr,"Are you kidding?\n");
 	 	exit(EXIT_FAILURE);
 	}
 	FILE *fp;
 	if((fp=fopen(argv[1],"rb"))==NULL)
 	{	fprintf(stderr,"I can't open the file!\n");
 		exit(EXIT_FAILURE);
 	}
 	fseek(fp,0L,SEEK_END);
 	long count,last;
 	char ch;
 	last=ftell(fp);
 	for(count=1L;count<=last;count++)
 	{	fseek(fp,-count,SEEK_END);
 		ch=getc(fp);
 		if(ch!='\032'&&ch!='\r')
 			putc(ch,stdout);
 	}
 	printf("\n");
 	if(fclose(fp))
 		fprintf(stderr,"I can't close the file!\n");
 	return 0;
}
