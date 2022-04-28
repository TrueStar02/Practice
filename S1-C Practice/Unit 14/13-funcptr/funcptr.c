#include<stdio.h>
#include<ctype.h>
#include<string.h>
char *nbgets(char *st,int n);
char showmenu(void);
void show(void (*ptr)(char *),char *str);
void upper(char *str);
void lower(char *str);
void trans(char *str);
void orign(char *str);
void eatline(void);
int main(void)
{	char str[81],copy[81],ch;
	void (*ptr)(char *);
	printf("Enter a string,empty to quit:\n");
	while(nbgets(str,81)!=NULL&&str[1]!='\0')
	{	while((ch=showmenu())!='n')
		{	switch(ch)
			{	case 'u':ptr=upper;
					break;
				case 'l':ptr=lower;
					break;
				case 't':ptr=trans;
					break;
				case 'o':ptr=orign;
					break;
			}
			strcpy(copy,str);
			show(ptr,copy);
		}
		printf("Enter the next string,empty to quit:\n");
	}
	puts("Bye~");
	return 0;
}
char showmenu(void)
{	puts("Enter your choice:");
	puts("U-Uppercase        L-Lowercase");
	puts("T-Transposed case  O-Original case");
	puts("N-Next string");
	char ch=tolower(getchar());
	eatline();
	while(strchr("ulton",ch)==NULL)
	{	puts("Enter U,L,T,O,N!");
		ch=tolower(getchar());
		eatline();
	}
	return ch;
}
void show(void (*ptr)(char *),char *str)
{	ptr(str);
	puts(str);
}
void upper(char *str)
{	while(*str)
	{	*str=toupper(*str);
		str++;
	}
}
void lower(char *str)
{	while(*str)
	{	*str=tolower(*str);
		str++;
	}
}
void trans(char *str)
{	while(*str)
	{	if(isupper(*str))
			*str=tolower(*str);
		else if(islower(*str))
			*str=toupper(*str);
		str++;
	}
}
void orign(char *str){}
void eatline(void)
{	while(getchar()!='\n')
		continue;
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
