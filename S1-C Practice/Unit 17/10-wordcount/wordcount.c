#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "tree.h"
char *nbgets(char *st,int n);
void eatline(void);
void AddWord(Tree *ptr);
void ShowWords(Tree *ptr);
void FindWord(Tree *ptr);
void DeleteWord(Tree *ptr);
void PrintItems(Item item);
void ProcessWord(char *str);
void EnWord(char *str,Tree *ptr);
char menu(void);
int main(int argc,char *argv[])
{	if(argc!=2)
	{	fprintf(stderr,"Illegal arguments!\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{	fprintf(stderr,"Error in opening the file!\n");
		exit(EXIT_FAILURE);
	}
	Tree words;
	InitializeTree(&words);
	char temp[31],ch;
	while(fscanf(fp,"%s",temp)==1)
	{	ProcessWord(temp);
		EnWord(temp,&words);
	}
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':AddWord(&words);
				break;
			case 'l':ShowWords(&words);
				break;
			case 'f':FindWord(&words);
				break;
			case 'n':printf("%d different word(s) in this club\n%d words totally\n",TreeItemCount(&words),TotalWords(&words));
				break;
			case 'd':DeleteWord(&words);
				break;
		}
	}
	EmptyTree(&words);
	if(fclose(fp))
		fprintf(stderr,"Error in closing the file\n");
	puts("Bye~");
	return 0;
}
void ProcessWord(char *str)
{	char *ptr;
	int x;
	if((ptr=strpbrk(str,",.?!"))!=NULL)
		*ptr='\0';
	for(x=0;x<strlen(str);x++)
		str[x]=tolower(str[x]);
}
void EnWord(char *str,Tree *ptr)
{	Item temp;
	strcpy(temp.word,str);
	temp.count=0;
	AddItem(temp,ptr);
}
void AddWord(Tree *ptr)
{	char temp[31];
	puts("Enter the word you want to add");
	nbgets(temp,31);
	EnWord(temp,ptr);
}
void ShowWords(Tree *ptr)
{	if(TreeIsEmpty(ptr))
		printf("No words!\n");
	else
		Traverse(ptr,PrintItems);
}
void FindWord(Tree *ptr)
{	Item temp;
	puts("Enter the word you want to look up\n");
	nbgets(temp.word,31);
	temp.count=0;
	bool intree=SearchItem(&temp,ptr);
	if(intree)
		printf("%s is in the tree and it exists %d time(s)\n",temp.word,temp.count);
	else
		printf("%s is not in the tree\n",temp.word);
}
void DeleteWord(Tree *ptr)
{	Item temp;
	puts("Enter the word you want to delete");
	nbgets(temp.word,31);
	temp.count=0;
	printf("%s ",temp.word);
	if(DeleteItem(&temp,ptr))
		printf("is deleted!\n");
	else
		printf("isn't in the tree!\n");
}
void PrintItems(Item item)
{	printf("%s exists %d time(s)\n",item.word,item.count);
}
char menu(void)
{	char ch;
	puts("Word Counting System");
	puts("A-Add a Word      L-Show List of Words");
	puts("N-Number of words F-Find Words");
	puts("D-Delete a word   Q-Quit");
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
