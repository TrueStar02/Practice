#include<stdio.h>
#include<stdlib.h>
struct name
{	char fname[21];
	char lname[21];
};
int CompF(void *ptr1,void *ptr2);
int CompL(void *ptr1,void *ptr2);
char *nbgets(char *st,int n);
int main(void)
{	struct name mates[35];
	int count=0,x;
	puts("Enter the first name,nothing to quit");
	while(count<35&&nbgets(mates[count].fname,21)!=NULL&&mates[count].fname[0]!='\0')
	{	puts("Enter the last name");
		nbgets(mates[count].lname,21);
		count++;
		if(count<35)
			puts("Enter the first name,nothing to quit");
	}
	printf("Original order:\n");
	for(x=0;x<count;x++)
		printf("%s %s\n",mates[x].fname,mates[x].lname);
	qsort(mates,count,sizeof(struct name),CompF);
	printf("Ordered by first name:\n");
	for(x=0;x<count;x++)
		printf("%s %s\n",mates[x].fname,mates[x].lname);
	qsort(mates,count,sizeof(struct name),CompL);
	printf("Ordered by last name:\n");
	for(x=0;x<count;x++)
		printf("%s %s\n",mates[x].fname,mates[x].lname);
}
int CompF(void *ptr1,void *ptr2)
{	const struct name *spt1=(const struct name *)ptr1;
	const struct name *spt2=(const struct name *)ptr2;
	int i;
	if(strcmp(spt1->fname,spt2->fname))
		return strcmp(spt1->fname,spt2->fname);
	else
		return strcmp(spt1->lname,spt2->lname);
}
int CompL(void *ptr1,void *ptr2)
{	const struct name *spt1=(const struct name *)ptr1;
	const struct name *spt2=(const struct name *)ptr2;
	int i;
	if(strcmp(spt1->lname,spt2->lname))
		return strcmp(spt1->lname,spt2->lname);
	else
		return strcmp(spt1->fname,spt2->fname);
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
