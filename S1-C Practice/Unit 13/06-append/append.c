#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *nbgets(char *st,int n);
void append(FILE *source,FILE *target);
int main(int argc,char *argv[])
{	if(argc!=2)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	FILE *target,*source;
	if((target=fopen(argv[1],"a+"))==NULL)
	{	fprintf(stderr,"I can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	if(setvbuf(target,NULL,_IOFBF,4096))
	{	fprintf(stderr,"I can't create an output buffer!\n");
		exit(EXIT_FAILURE); 
	}
	printf("Let's add some file to this file.\n");
	printf("Enter name of the sourse file,enpty to quit.\n");
	char filename[31],ch;
	int num=0;
	while(nbgets(filename,31)&&filename[0]!='\0')
	{	if(!strcmp(filename,argv[1]))
			printf("You can't add a file to itself!\n");
		else if((source=fopen(filename,"r"))==NULL)
			printf("I can't open the file %s !\n",filename);
		else
		{	if(setvbuf(source,NULL,_IOFBF,4096))
			{	fprintf(stderr,"I can't open the file!\n");
				continue;
			}
			append(source,target);
			if(ferror(source))
				fprintf(stderr,"Error in reading file %s !\n",filename);
			if(ferror(target))
				fprintf(stderr,"Error in writing file %s !\n",argv[1]);
			if(fclose(source))
			{	fprintf(stderr,"I can't close the file %s !\n",filename);
				exit(EXIT_FAILURE); 
			}
			num++;
			printf("File %s appended!\n",filename);
		}
		printf("Enter name of the sourse file,empty to quit.\n");
	}
	printf("Done.%d file appended\n",num);
	printf("Now %s contains:\n",argv[1]);
	rewind(target);
	while((ch=getc(target))!=EOF)
		putchar(ch);
	printf("Done!\n");
	if(fclose(target))
		fprintf(stderr,"I can't close the file %s !\n",argv[1]);
 	return 0;
}
char *nbgets(char *st,int n)
{	char *ptr;
 	ptr=fgets(st,n,stdin);
 	int i=0;
 	if(ptr)
 	{	while(st[i]!='\0'&&st[i]!='\n')
  			i++;
  		if(st[i]=='\n')
  			st[i]='\0';
  		else
  			while(getchar()!='\n')
  				continue;
	}
	return ptr;
}
void append(FILE *source,FILE *target)
{	size_t bytes;
	static char temp[4096];
	while((bytes=fread(temp,sizeof(char),4096,source))>0)
		fwrite(temp,sizeof(char),bytes,target);
}
