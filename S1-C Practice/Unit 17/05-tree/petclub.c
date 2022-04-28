#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "tree.h"
char *nbgets(char *st,int n);
void eatline(void);
void AddPet(Tree *ptr);
void ShowPets(Tree *ptr);
void FindPet(Tree *ptr);
void DeletePet(Tree *ptr);
void PrintItems(Item item);
char menu(void);
int main(void)
{	Tree pets;
	InitializeTree(&pets);
	char ch;
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':AddPet(&pets);
				break;
			case 'l':ShowPets(&pets);
				break;
			case 'f':FindPet(&pets);
				break;
			case 'n':printf("%d pet(s) in this club\n",TreeItemCount(&pets));
				break;
			case 'd':DeletePet(&pets);
				break;
		}
	}
	EmptyTree(&pets);
	puts("Bye~");
	return 0;
}
void AddPet(Tree *ptr)
{	Item temp;
	puts("Enter the name of the pet");
	nbgets(temp.petname,31);
	puts("Enter the kind of the pet");
	nbgets(temp.petkind,31);
	AddItem(temp,ptr);
}
void ShowPets(Tree *ptr)
{	if(TreeIsEmpty(ptr))
		printf("No pets!\n");
	else
		Traverse(ptr,PrintItems);
}
void FindPet(Tree *ptr)
{	Item temp;
	puts("Enter the name of the pet");
	nbgets(temp.petname,31);
	puts("Enter the kind of the pet");
	nbgets(temp.petkind,31);
	bool intree=SearchItem(&temp,ptr);
	printf("%s,a %s is %sin the tree\n",temp.petname,temp.petkind,(intree)?"":"not ");
}
void DeletePet(Tree *ptr)
{	Item temp;
	puts("Enter the name of the pet");
	nbgets(temp.petname,31);
	puts("Enter the kind of the pet");
	nbgets(temp.petkind,31);
	printf("%s,a %s ",temp.petname,temp.petkind);
	if(DeleteItem(&temp,ptr))
		printf("is deleted!\n");
	else
		printf("isn't in the tree!\n");
}
void PrintItems(Item item)
{	printf("%s,a %s\n",item.petname,item.petkind);
}
char menu(void)
{	char ch;
	puts("Apple Pet Club");
	puts("A-Add a pet      L-Show List of pets");
	puts("N-Number of pets F-Find Pets");
	puts("D-Delete a pet   Q-Quit");
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
