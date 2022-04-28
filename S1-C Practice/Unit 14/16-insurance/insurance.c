#include<stdio.h>
#include<string.h>
struct name
{	char fname[31];
	char mname[21];
	char lname[21];
};
struct data
{	unsigned int number;
	struct name person;
};
char *nbgets(char *st,int n);
int main(void)
{	struct data info[5];
	int count,x;
	puts("Enter the first name,enter to quit");
	while(count<5&&nbgets(info[count].person.fname,31)!=NULL&&info[count].person.fname[0]!='\0')
	{	puts("Enter the middle name");
		nbgets(info[count].person.mname,21);
		puts("Enter the last name");
		nbgets(info[count].person.lname,31);
		puts("Enter the social insurance number");
		scanf("%u",&(info[count].number));
		while(getchar()!='\n')
			continue;
		count++;
		if(count<5)
			puts("Enter the first name,enter to quit");
	}
	for(x=0;x<count;x++)
	{	printf("%s, %s ",info[x].person.lname,info[x].person.fname);
		if(info[x].person.mname[0]!='\0')
			printf("%c. ",info[x].person.mname[0]);
		printf("--%09u\n",info[x].number);
	}
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
