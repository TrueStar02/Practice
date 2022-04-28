#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
char *nbgets(char *st,int n);
void inverseword(char *str);
int main(void)
{	char words[201];
 	nbgets(words,201);
 	inverseword(words);
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
void inverseword(char *str)
{	int x,num=0,p=0;
 	bool inword=0;
 	for(x=0;x<strlen(str);x++)
 	{	if(isalpha(str[x]))
  		{	if(!inword)
   				num++;
   			inword=1;
  		}
  		else
  			inword=0;
 	}
 	char words[num][31];
 	num=-1;
 	inword=0;
 	for(x=0;x<strlen(str);x++)
 	{	if(isalpha(str[x]))
  		{	if(!inword)
   				num++;
   			inword=1;
   			words[num][p]=str[x];
   			p++;
  		}
  		else
 		{	if(inword)
   				words[num][p]='\0';
   			inword=0;
   			p=0;
  		}
 	}
 	if(inword)
 		words[num][p]='\0';
 	for(x=num;x>=0;x--)
 		printf("%s ",words[x]);
 	printf("\n");
}
