#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct flex
{	char *name;
	int course;
	double average;
	double scores[];
};
void makeinfo(struct flex **details,int n);
void showinfo(struct flex **details,int n);
char *nbgets(char *st,int n);
int  main(void)
{	printf("How many details do you need to process?\n");
	int num,x,subs,y,scr;
	char temp[41];
	scanf("%d",&num);
	struct flex **details=malloc(num*sizeof(struct flex *));
	for(x=0;x<num;x++)
	{	printf("How many subjects do student %d have?\n",x+1);
		scanf("%d",&subs);
		while(getchar()!='\n')
			continue;
		struct flex *ptr=malloc(sizeof(struct flex)+subs*sizeof(double));
		ptr->course=subs;
		printf("What's his/her name?\n");
		nbgets(temp,41);
		ptr->name=(char *)malloc((strlen(temp)+1)*sizeof(char));
		strcpy(ptr->name,temp);
		for(y=0;y<subs;y++)
		{	printf("Now enter the subject %d of student %d,%s\n",y+1,x+1,temp);
			scanf("%lf",&(ptr->scores[y]));
		}
		*(details+x)=ptr;
	}
	makeinfo(details,num);
	showinfo(details,num);
	printf("Byebye~\n");
	free(details);
	return 0;
}
void makeinfo(struct flex **details,int n)
{	int x,y;
	double sum=0;
	for(x=0;x<n;x++)
	{	sum=0;
		for(y=0;y<(*(details+x))->course;y++)
			sum+=(*(details+x))->scores[y];	
		(*(details+x))->average=sum/((*(details+x))->course);
	}
}
void showinfo(struct flex **details,int n)
{	int x,y;
	for(x=0;x<n;x++)
	{	printf("\n*****************************************\n");
		printf("Number:%03d\n",x+1);
		printf("Name:%s\n",(*(details+x))->name);
		printf("Scores:\n");
		for(y=0;y<(*(details+x))->course;y++)
		{	printf("%5.1lf",(*(details+x))->scores[y]);
			if(y%5==4)
				printf("\n");
		}
		if(y%5)
			printf("\n");
		printf("Average:%6.2lf\n",(*(details+x))->average);
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
