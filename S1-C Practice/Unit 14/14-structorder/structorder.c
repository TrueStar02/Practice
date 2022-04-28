#include<stdio.h>
#include<string.h>
struct book
{	char title[41];
	char author[41];
	double price;
};
char *nbgets(char *st,int n);
int choice(void);
void ttl(struct book *arr,int num);
void atr(struct book *arr,int num);
void prc(struct book *arr,int num);
void swap(struct book *a,struct book *b);
int main(void)
{	struct book library[20],*copy,backup[20];
	int count=0,x,num;
	printf("Please enter the title,press enter to stop\n");
	while(count<20&&(nbgets(library[count].title,41)!=NULL)&&library[count].title[0]!='\0')
	{	printf("Now enter the author:\n");
		nbgets(library[count].author,41);
		printf("Now enter the price:\n");
		scanf("%lf",&library[count].price);
		while(getchar()!='\n')
			continue;
		backup[count]=library[count];
		count++;
		if(count<20)
			printf("Please enter the title,press enter to stop\n");
	}
	while(num=choice())
	{	for(x=0;x<count;x++)
		library[x]=backup[x];
		copy=library;
		switch (num)
		{	case 1:break;
			case 2:ttl(copy,count);
				break;
			case 3:atr(copy,count);
				break;
			case 4:prc(copy,count);
				break;
		}
		for(x=0;x<count;x++)
		printf("Book %d:%s by %s,price:$%.2lf\n",x+1,copy[x].title,copy[x].author,copy[x].price);
	}
	printf("Byebye~\n");
	return 0;
}
void ttl(struct book *arr,int count)
{	int x,y;
	for(x=0;x<count-1;x++)
	for(y=x+1;y<count;y++)
		if(strcmp(arr[x].title,arr[y].title)>0)
			swap(arr+x,arr+y);
	
}
void atr(struct book *arr,int count)
{	int x,y;
	for(x=0;x<count-1;x++)
	for(y=x+1;y<count;y++)
		if(strcmp(arr[x].author,arr[y].author)>0)
			swap(arr+x,arr+y);
}
void swap(struct book *a,struct book *b)
{	struct book temp;
	temp=*a;
	*a=*b;
	*b=temp;	
}
void prc(struct book *arr,int count)
{	int x,y;
	for(x=0;x<count-1;x++)
	for(y=x+1;y<count;y++)
		if(arr[x].price>arr[y].price)
			swap(arr+x,arr+y);
}
int choice(void)
{	int n;
	printf("How to print?:\n");
	puts("1-Original order  2-By title");
	puts("3-By author       4-By price");
	puts("0-quit");
	while(scanf("%d",&n)!=1||n<0||n>4)
	{	printf("Enter an interger between 0 and 4!\n");
		while(getchar()!='\n')
			continue;
	}
	return n;
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
