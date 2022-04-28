#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{	if(argc!=3)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{	fprintf(stderr,"Error in opening the file %s!\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	char temp[256];
	int lines=0,num=0;
	while((fgets(temp,256,fp))!=NULL)
	{	lines++;
		if((strstr(temp,argv[2]))!=NULL)
		{	num++;
			printf("Task%3d,line%3d:",num,lines);
			fputs(temp,stdout);
		}
	}
	printf("Totally%3d line(s),%3d line(s) were printed.\n",lines,num);
	if(fclose(fp))
		fprintf(stderr,"Error in closing the file %s!\n",argv[1]);
	return 0;
}
