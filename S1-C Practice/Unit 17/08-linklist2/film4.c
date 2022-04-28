#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "list.h"
void ShowItems(Item item);
char *nbgets(char *st,int n);
int GetRating(void);
char menu(void);
void eatline(void);
void AddMovie(List *plist);
void ShowMovies(List *plist);
void FindMovie(List *plist);
void DeleteMovie(List *plist);
int main(void)
{	List movies;
	InitializeList(&movies);
	char ch;
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':AddMovie(&movies);
				break;
			case 'l':ShowMovies(&movies);
				break;
			case 'f':FindMovie(&movies);
				break;
			case 'n':printf("%d movie(s) in this list\n",ListItemCount(&movies));
				break;
			case 'd':DeleteMovie(&movies);
				break;
		}
	}
	EmptyList(&movies);
	puts("Byebye~");
	return 0;
}
void AddMovie(List *plist)
{	Item temp;
	printf("Enter movie title:");
	nbgets(temp.title,51);
	printf("Enter the movie rating(0~10):");
	temp.rating=GetRating();
	if(AddItem(temp,plist))
		puts("Succeed");
	else
		puts("Failed");
}
void ShowMovies(List *plist)
{	Traverse(plist,ShowItems);
}
void FindMovie(List *plist)
{	Item temp;
	printf("Enter movie title:");
	nbgets(temp.title,51);
	temp.rating=-1;
	if(SearchItem(&temp,plist))
		printf("%s is in the list,and its rating is %d\n",temp.title,temp.rating);
	else
		printf("%s is not in the list\n",temp.title);
}
void DeleteMovie(List *plist)
{	Item temp;
	printf("Enter movie title:");
	nbgets(temp.title,51);
	temp.rating=-1;
	if(DeleteItem(&temp,plist))
		puts("Succeed");
	else
		puts("Failed");
}
void ShowItems(Item item)
{	printf("%s Rating %d\n",item.title,item.rating);
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
char menu(void)
{	char ch;
	puts("Movie Rating System");
	puts("A-Add a movie      L-Show List of movies");
	puts("N-Number of movies F-Find movies");
	puts("D-Delete a movie   Q-Quit");
	while((ch=tolower(getchar()))&&strchr("alnfdq",ch)==NULL)
	{	eatline();
		puts("Enter A,L,N,F,D or Q!");
	}
	eatline();
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
void eatline(void)
{	while(getchar()!='\n')
		continue;
}
