#include<stdio.h>
#include<string.h>
struct namect
{	char lname[31];
	char fname[31];
	int letters;
};
int getinfo(struct namect *arr,int lim);
void makeinfo(struct namect *arr,int n);
void showinfo(const struct namect *arr,int n);
char *nbgets(char *st,int n);
int main(void)
{	struct namect name[50];
	int num;
	num=getinfo(name,50);
	makeinfo(name,num);
	printf("All people are here:\n");
	showinfo(name,num);
	return 0;
}
int getinfo(struct namect *arr,int lim)
{	int count=0;
	printf("Enter your last name,enter to quit.\n");
	while(count<lim&&(nbgets((arr+count)->lname,31))!=NULL&&((arr+count)->lname)[0]!='\0')
	{	printf("Enter your first name.\n");
		nbgets((arr+count)->fname,31);
		count++;
		if(count<lim)
			printf("Enter your last name,enter to quit.\n");
	}
	return count;
}
void makeinfo(struct namect *arr,int n)
{	int x;
	for(x=0;x<n;x++)
		arr[x].letters=strlen(arr[x].fname)+strlen(arr[x].lname);
}
void showinfo(const struct namect *arr,int n)
{	int x;
	for(x=0;x<n;x++)
		printf("%d,%s %s,%d letters\n",x+1,arr[x].lname,arr[x].fname,arr[x].letters);
}
char *nbgets(char *st,int n)
{char *ptr;
 ptr=fgets(st,n,stdin);
 int i=0;
 if(ptr)
 {while(st[i]!='\0'&&st[i]!='\n')
  i++;
  if(st[i]=='\n')
  st[i]='\0';
  else
  while(getchar()!='\n')
  continue;
 }
 return ptr;
}
