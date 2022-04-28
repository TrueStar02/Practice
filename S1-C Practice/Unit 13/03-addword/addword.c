#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{	FILE *fp;
 	char words[41];
 	if(argc!=2)
 	{	fprintf(stderr,"Are you kidding?\n");
 		exit(EXIT_FAILURE);
 	}
 	if((fp=fopen(argv[1],"a+"))==NULL)
 	{	fprintf(stderr,"I can't open the file\n");
 		exit(EXIT_FAILURE);
 	}
 	puts("Enter the words you want to add;press # to stop");
 	while((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))
 		fprintf(fp,"%s\n",words);
 	puts("File Contains");
 	rewind(fp);
 	int n=0;
 	while((fscanf(fp,"%s",words))==1)
 	{	n++;
 		printf("%d:%s\n",n,words);
 	}
 	printf("Done.%d words totally\n",n);
 	if(fclose(fp))
 		fprintf(stderr,"Error closing file.\n");
 	return 0;
}
