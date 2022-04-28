#include<stdio.h>
#include<string.h>
struct namect
{	char lname[31];
	char fname[31];
	int letters;
};
struct namect getinfo(void);
struct namect makeinfo(struct namect info);
void showinfo(struct namect info,int n);
char *nbgets(char *st,int n);
int main(void)
{	struct namect name[50];
	int count,x;
	for(count=0;count<50;count++)
	{	name[count]=getinfo();
		if(name[count].lname[0]=='\0'||name[count].fname[0]=='\0')
			break;
		name[count]=makeinfo(name[count]);
	}
	for(x=0;x<count;x++)
		showinfo(name[x],x);
	return 0;
	
}
struct namect getinfo(void)
{	struct namect name;
	printf("Enter your last name,enter twice to quit.\n");
	nbgets(name.lname,31);
	printf("Enter your first name,enter to quit.\n");
	nbgets(name.fname,31);
	return name;
}
struct namect makeinfo(struct namect info)
{	struct namect name;
	info.letters=strlen(info.fname)+strlen(info.lname);
	return info;
}
void showinfo(struct namect info,int n)
{	printf("%d,%s %s,%d letters\n",n+1,info.lname,info.fname,info.letters);
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
