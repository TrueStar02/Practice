#include<stdio.h>
#include<stdlib.h>
#include "list.h"
void ShowMovies(Item item);
char *nbgets(char *st,int n);
void InversePrint(const Node *pnode);
int GetRating(void);
int main(void)
{	List movies;
	Item temp;
	InitializeList(&movies);
	if(ListIsFull(&movies))
	{	fprintf(stderr,"Memory is full!\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter the title of the film(noting to quit)");
	while(nbgets(temp.title,51)!=NULL&&temp.title[0]!='\0')
	{	puts("Enter the rate of this film(0~10)");
		temp.rating=GetRating();
		if(AddItem(temp,&movies)==0)
		{	fprintf(stderr,"Error in adding items!");
			break;
		}
		puts("Enter the next film's title,empty to stop");
	}
	if(ListIsEmpty(&movies))
		printf("No data!\n");
	else
	{	printf("Here is your list:\n");
		Traverse(&movies,ShowMovies);
		printf("Total:%d movies.\n",ListItemCount(&movies));
		puts("Inversed");
		InversePrint(movies);
	}
	EmptyList(&movies);
	puts("Byebye~");
	return 0;
}
void ShowMovies(Item item)
{	printf("%s Rating %d\n",item.title,item.rating);
}
void InversePrint(const Node *pnode)
{	if(pnode->next!=NULL)
		InversePrint(pnode->next);
	ShowMovies(pnode->item);
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
