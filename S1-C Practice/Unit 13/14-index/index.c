#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{	if(argc<3)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	int x,tasks=0;
	long index,whole;
	FILE *fp;
	char ch;
	for(x=1;x<=(argc-1)/2;x++)
	{	index=atol(argv[2*x]);
		if((fp=fopen(argv[2*x-1],"r"))==NULL)
		{	printf("I can't open the file %s!\n",argv[2*x-1]);
			continue;
		}
		fseek(fp,0L,SEEK_END);
		whole=ftell(fp);
		if((index<0)||(index>whole))
		{	printf("Invalid index to file %s!\n",argv[2*x-1]);
			continue;
		}
		tasks++;
		fseek(fp,index,SEEK_SET);
		printf("Task %2d,file %s,index %ld:\n",tasks,argv[2*x-1],index);
		while(((ch=getc(fp))!='\n')&&(ch!=EOF))
			putchar(ch);
		putchar('\n');
		if(fclose(fp))
		{	printf("I can't close the file %s!\n",argv[2*x-1]);
			exit(EXIT_FAILURE);
		}
	}
	printf("%d task(s) completed!\n",tasks);
	return 0;
}
