#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct books
{	char title[41];
	char author[41];
	double price;
};
char *nbgets(char *st,int n);
int main(void)
{	struct books library[50];
	int count=0,filecount,x;
	FILE *fp;
	if((fp=fopen("library.txt","a+b"))==NULL)
	{	fprintf(stderr,"I can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	while(fread(library+count,sizeof(struct books),1,fp)==1)
	{	printf("%s by %s:$%.2lf\n",library[count].title,library[count].author,library[count].price);
		count++;
	}
	filecount=count;
	if(count==50)
	{	printf("The database is full!\n");
		exit(EXIT_SUCCESS);
	}
	printf("Please enter the title,press enter to stop\n");
	while(count<50&&(nbgets(library[count].title,41)!=NULL)&&library[count].title[0]!='\0')
	{	printf("Now enter the author:\n");
		nbgets(library[count].author,41);
		printf("Now enter the price:\n");
		scanf("%lf",&library[count].price);
		while(getchar()!='\n')
			continue;
		count++;
		if(count<50)
			printf("Please enter the title,press enter to stop\n");
	}
	if(count>0)
	{	puts("Here is the content:");
		for(x=0;x<count;x++)
			printf("%s by %s:$%.2lf\n",library[x].title,library[x].author,library[x].price);
		fwrite(library+filecount,sizeof(struct books),count-filecount,fp);
	}
	else
		puts("No books!");
	puts("Bye~");
	if(fclose(fp))
		puts("I can't close the file!");
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
