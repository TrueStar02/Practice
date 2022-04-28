#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
struct books
{	char title[41];
	char author[41];
	double price;
	bool lock;
};
char *nbgets(char *st,int n);
char choice(void);
int add(struct books *ptr,int n);
int delete(struct books *ptr,int n);
void print(struct books *ptr,int n);
int main(void)
{	struct books library[50],*ptr;
	char ch;
	ptr=library;
	int count=0,filecount,x;
	for(x=0;x<=49;x++)
	{	strcpy(library[x].author,"");
		strcpy(library[x].title,"");
		library[x].price=0;
		library[x].lock=0;
	}
	FILE *fp;
	if((fp=fopen("library.txt","r+b"))==NULL)
	{	fprintf(stderr,"I can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	puts("Now the database contains:");
	rewind(fp);
	while(fread(library+count,sizeof(struct books),1,fp)==1)
	{	if(library[count].lock)
			printf("%s by %s:$%.2lf\n",library[count].title,library[count].author,library[count].price);
		count++;
	}
	if(count==0)
		puts("Null");
	while((ch=choice())!='q')
	{	switch(ch)
		{	case 'a':count=add(ptr,count);
				break;
			case 'd':count=delete(ptr,count);
				break;
			case 'p':print(ptr,count);
				break;
		}
	}
	if(count>0)
	{	puts("\nDone.Here is the content:\n");
		for(x=0;x<count;x++)
			if(library[x].lock)
				printf("%s by %s:$%.2lf\n",library[x].title,library[x].author,library[x].price);
		rewind(fp);
		fwrite(library,sizeof(struct books),50,fp);
	}
	else
		puts("No books!");
	puts("Bye~");
	if(fclose(fp))
		puts("I can't close the file!");
	return 0;
}
int add(struct books *ptr,int n)
{	int x;
	if(n==50)
		puts("Database is full!");
	else
	{	for(x=0;((ptr+x)->lock!=0);x++)
			continue;	
		printf("Please enter the title\n");
		nbgets(ptr[x].title,41);
		printf("Now enter the author:\n");
		nbgets(ptr[x].author,41);
		printf("Now enter the price:\n");
		scanf("%lf",&ptr[x].price);
		ptr[x].lock=1;
		while(getchar()!='\n')
			continue;
		puts("Success!");
		n++;
	}
	return n;
}
int delete(struct books *ptr,int n)
{	int x;
	puts("Enter the book you want to delete");
	char temp[41];
	nbgets(temp,41);
	if(!n)
		puts("Nothing to delete!");
	else
	{	for(x=0;strcmp(temp,ptr[x].title)||!(ptr[x].lock);x++)
			if(x==50)
				break;
		if(x==50)
			printf("I can't find tle detail %s!\n",temp);
		else
		{	ptr[x].lock=0;
			n--;
			puts("Success!");
		}
		return n;	
	}		
}
void print(struct books *ptr,int n)
{	int x;
	for(x=0;x<=49;x++)
		if(ptr[x].lock)
			printf("%s by %s:$%.2lf\n",ptr[x].title,ptr[x].author,ptr[x].price);
}
char choice(void)
{	puts("Enter your choice");
	puts("A-Add details    D-Delete details");
	puts("P-Print details  Q-Quit");
	char ch=tolower(getchar());
	while(getchar()!='\n')
		continue;
	if(strchr("adpq",ch)==NULL)
	{	puts("Enter A,D,P,or Q!");
		ch=tolower(getchar());
		while(getchar()!='\n')
			continue;
	}
	return ch;
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
