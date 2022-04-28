#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int main(int argc,char *argv[])
{	if(argc<2)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	FILE *in[argc-1],*out;
	int x,n=argc-1;
	bool valid[argc-1];
	char temp[256],ch,*et;
	for(x=0;x<argc-1;x++)
		valid[x]=1;
	for(x=1;x<argc;x++)
		if((in[x-1]=fopen(argv[x],"r"))==NULL)
		{	printf("I can't open the file %s!",argv[x]);
			valid[x]=0;
			n--;
		}
	if((out=fopen("linecmb.txt","w+"))==NULL)
	{	fprintf(stderr,"I can't create the output file!\n");
		exit(EXIT_FAILURE);
	}
	while(n)
	{	for(x=0;x<argc-1;x++)
		{	if(valid[x])
			{	if(fgets(temp,256,in[x])!=NULL)
				{	et=strchr(temp,'\n');
					if(et!=NULL)
						*et='\0';
					fputs(temp,out);
				}
				else
				{	valid[x]=0;
					n--;
				}
				
			}
		}
		putc('\n',out);
	
	}
	fseek(out,0L,SEEK_SET);
	printf("Now here is the result:\n");
	while((ch=getc(out))!=EOF)
		putchar(ch);
	for(x=0;x<argc-1;x++)
		if(fclose(in[x]))
			fprintf(stderr,"I can't close the file %s!\n",argv[x+1]);
	if(fclose(out))
		fprintf(stderr,"I can't close the result file!\n");		
	return 0;
	
}
