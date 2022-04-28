#include<stdio.h>
char *nbgets(char *st,int n);
struct book
{	char title[41];
	char author[41];
	double price;
};
int main(void)
{	struct book library[20];
	int count=0,x;
	printf("Please enter the title,press enter to stop\n");
	while(count<20&&(nbgets(library[count].title,41)!=NULL)&&library[count].title[0]!='\0')
	{	printf("Now enter the author:\n");
		nbgets(library[count].author,41);
		printf("Now enter the price:\n");
		scanf("%lf",&library[count].price);
		while(getchar()!='\n')
			continue;
		count++;
		if(count<20)
			printf("Please enter the title,press enter to stop\n");
	}
	printf("Here is the books in the library:\n");
	for(x=0;x<count;x++)
		printf("Book %d:%s by %s,price:%.2lf\n",x+1,library[x].title,library[x].author,library[x].price);
	printf("Byebye~\n");
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
