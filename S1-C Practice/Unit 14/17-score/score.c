#include<stdio.h>
struct name
{	char fname[31];
	char lname[31];
};
struct student
{	struct name person;
	double score[3];
	double average;
};
char *nbgets(char *st,int n);
void showinfo(struct student *details,int n);
int main(void)
{	struct student info[10];
	int count=0,x;
	double sum=0;
	puts("Enter the first name,enter to quit");
	while(count<10&&nbgets(info[count].person.fname,31)!=NULL&&info[count].person.fname[0]!='\0')
	{	puts("Enter the last name");
		nbgets(info[count].person.lname,31);
		info[count].average=0;
		for(x=0;x<3;x++)		
		{	printf("Enter the score of the subject %d:",x+1);
			scanf("%lf",&(info[count].score[x]));
			info[count].average+=info[count].score[x];
		}
		info[count].average/=3;
		sum+=info[count].average;
		while(getchar()!='\n')
			continue;
		count++;
		if(count<10)
			puts("Enter the first name,enter to quit");
	}
	showinfo(info,count);
	printf("\nTotal average:%10.3lf\n",sum/count);
	return 0;
}
void showinfo(struct student *details,int n)
{	int x,y;
	for(x=0;x<n;x++)
	{	printf("\n*****************************************\n");
		printf("Number:%03d\n",x+1);
		printf("Name:%s %s\n\n",(details+x)->person.fname,(details+x)->person.lname);
		printf("Scores:\n");
		for(y=0;y<3;y++)
		printf("%6.1lf",(details+x)->score[y]);
		printf("\n\nAverage:%7.2lf\n",(details+x)->average);
		printf("*****************************************\n");
	}
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
