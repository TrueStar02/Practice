#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct film
{	char title[51];
	int rating;
	struct film *next;
};
char *nbgets(char *st,int n);
int GetRating(void);
int main(void)
{	struct film *head=NULL;
	struct film *now,*prev;
	char temp[51];
	puts("Enter the film's title,empty to stop");
	while(nbgets(temp,51)!=NULL&&temp[0]!='\0')
	{	now=(struct film *)malloc(sizeof(struct film));
		if(head==NULL)
			head=now;
		else
			prev->next=now;
		strcpy(now->title,temp);
		puts("Enter the rate of this film(0~10)");
		now->rating=GetRating();
		now->next=NULL;
		prev=now;
		puts("Enter the next film's title,empty to stop");
	}
	now=head;
	int count=0;
	while(now!=NULL)
	{	count++;
		printf("#%d %s Rate:%2d\n",count,now->title,now->rating);
		now=now->next;
	}
	now=head;
	while(now->next!=NULL)
	{	
		head=now->next;
		free(now);
		now=head;
	}
	return 0;
}
int GetRating(void)
{	int temp;
	while((scanf("%d",&temp)!=1)||temp<0||temp>10)
	{	while(getchar()!='\n')
			continue;
		puts("Enter an interger between 0 and 10!");
	}
	while(getchar()!='\n')
		continue;
	return temp;
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
