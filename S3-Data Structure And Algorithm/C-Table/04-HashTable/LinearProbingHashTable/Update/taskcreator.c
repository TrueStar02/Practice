#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
char * randname(void);
int main()
{	srand((unsigned int)time(0));
	FILE * fp;
	fp=fopen("task.txt","w");
	int x,n;
	char * str;
	scanf("%d",&n); 
	for(x=1;x<=n;x++)
	{	str=randname();
		fprintf(fp,"%s ",str);
		fprintf(fp,"%04d%02d%02d\n",rand()%92+1930,rand()%12+1,rand()%31+1);
		free(str);
	}
	
	fclose(fp);
	return 0;
}
char * randname(void)
{	int x,size1=2+rand()%7,size2=2+rand()%7;
	char * str=(char *)malloc(sizeof(char)*(1+size1+size2));
	for(x=0;x<size1+size2;x++)
		str[x]=rand()%26+97;
	str[0]=toupper(str[0]);
	str[size1]=toupper(str[size1]);
	str[size1+size2]='\0';
	return str;
}
