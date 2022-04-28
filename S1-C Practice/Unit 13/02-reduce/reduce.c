#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{	if(argc!=2)
 	{	fprintf(stderr,"Are you kidding?\n");
 	 	exit(EXIT_FAILURE);
 	}
 	FILE *in,*out;
 	if((in=fopen(argv[1],"r"))==NULL)
 	{	fprintf(stderr,"Where is the file %s ?\n",argv[1]);
 		exit(EXIT_FAILURE);
 	}
 	char name[strlen(argv[1])+5],ch;
 	strcpy(name,"rdc-");
 	strcat(name,argv[1]);
 	if((out=fopen(name,"w"))==NULL)
 	{	fprintf(stderr,"Can't create file %s !",name);
 		exit(EXIT_FAILURE);
 	}
 	int i=0;
 	for(i=1;(ch=getc(in))!=EOF;i++)
 		if(i%3==1)
 			putc(ch,out);
 	if(fclose(in)||fclose(out))
 		fprintf(stderr,"Error in closing files\n");
 	return 0;
}
