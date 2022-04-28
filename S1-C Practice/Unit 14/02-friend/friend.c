#include<stdio.h>
char *nbgets(char *st,int n);
struct name
{	char last[21];
	char first[21];
};
struct guy
{	struct name person;
	char school[41];
	int money;
};
int main(void)
{	struct guy friend[4];
	int x;
	for(x=0;x<4;x++)
	{	printf("Enter your friend's name:\n");
		scanf("%s%s",friend[x].person.last,friend[x].person.first);
		while(getchar()!='\n')
			continue;
		printf("Which is his university?\n");
		nbgets(friend[x].school,21);
		printf("How much is his allowance?\n");
		scanf("%d",&friend[x].money);
		while(getchar()!='\n')
			continue;
	}
	for(x=0;x<4;x++)
		printf("%d,%s %s,in %s,have %d RMB every month.\n",x+1,friend[x].person.last,friend[x].person.first,friend[x].school,friend[x].money);
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
