#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{	if(argc<=1)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	char v=argv[1][0],ch;
	int x,num=0,file=0;
	FILE *fp;
	if(argc==2)
	{	while((ch=getchar())!='\n')
			if(ch==v)
				num++;
		printf("Task  1,You have entered %d \"%c\"(s).\n",num,v) ;
		file++;
	}
	else
		for(x=2;x<argc;x++)
		{	if((fp=fopen(argv[x],"r"))==NULL)
			{	fprintf(stderr,"I can't open the file %s!\n",argv[x]);
				continue;
			}
			else
			{	file++;
				num=0;
				while((ch=getc(fp))!=EOF)
					if(ch==v)
						num++;
				printf("Task%3d,file %s has %d \"%c\"(s).\n",file,argv[x],num,v) ;
				if(fclose(fp))
				{	fprintf(stderr,"I can't close the file %s!",argv[x]);
					exit(EXIT_FAILURE);
				}
			}
		}
	printf("%d tasks completed.\n",file);
	return 0;
}
