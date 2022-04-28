#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(int argc,char *argv[])
{	if(argc!=2)
 	{	fprintf(stderr,"SB!\n");
 		exit(EXIT_FAILURE);
 	}
 	FILE *in,*out;
 	if((in=fopen(argv[1],"r"))==NULL)
 	{	fprintf(stderr,"I can't open the file %s !\n",argv[1]);
 		exit(EXIT_FAILURE);
 	}
 	char name[strlen(argv[1]+9)],ch;
 	strcpy(name,"(copyed)");
 	strcat(name,argv[1]);
 	if((out=fopen(name,"w+"))==NULL)
 	{	fprintf(stderr,"I can't open the file %s !\n",name);
 		exit(EXIT_FAILURE);
 	}
 	while((ch=getc(in))!=EOF)
	 	putc(toupper(ch),out);
	if(fclose(in)||fclose(out))
		fprintf(stderr,"Erroe in closing the file!\n");
	return 0;
}
