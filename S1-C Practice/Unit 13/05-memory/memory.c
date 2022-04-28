#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{	if(argc!=2)
	{	fprintf(stderr,"Are you kidding?\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if((fp=fopen(argv[1],"a+"))==NULL)
	{	fprintf(stderr,"I can't open the file?\n");
		exit(EXIT_FAILURE);
	}
	fpos_t pos;
	fgetpos(fp,&pos);
	char str[31];
	printf("Enter the words you want to add,# to stop\n");
	while(fgets(str,31,stdin)&&str[0]!='#')
		fputs(str,fp);
	fsetpos(fp,&pos);
	printf("Here are the words you added\n");
	while(fscanf(fp,"%s",str)==1)
		printf("%s ",str);
	rewind(fp);
	printf("\nHere is the whole file\n");
	while(fscanf(fp,"%s",str)==1)
		printf("%s ",str);
	if(fclose(fp))
		fprintf(stderr,"I can't close the file!\n");
	return 0;
}
