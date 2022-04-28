#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
char *nbgets(char *st,int n);
struct student
{	char name[21];
	int num;
	double score;
	bool isvalid;
};
typedef struct student Student;
void Add(FILE *fp);
void Delete(FILE *fp);
void Print(FILE *fp);
Student Get(void);
char menu(void);
void eatline(void);
int main(void)
{	int count;
	char ch;
	FILE *fp;
	fp=fopen("data.txt","r+b");
	if(fp==NULL)
	{	fprintf(stderr,"Error in opening the file!\n");
		exit(EXIT_FAILURE);
	}
	while((ch=menu())!='q')
	{	switch(ch)
		{	case 'a':Add(fp);
				break;
			case 'd':Delete(fp);
				break;
			case 'p':Print(fp);
				break;	
		}
	}
	if(fclose(fp))
		fprintf(stderr,"Error in opening the file!\n");
	puts("Bye-bye~");
	return 0;	
}
void Add(FILE *fp)
{	Student temp,data=Get();
	rewind(fp);
	bool flag=1;
	while(fread(&temp,sizeof(Student),1,fp))
		if(!temp.isvalid)
		{	fseek(fp,-sizeof(Student),SEEK_CUR);
			fwrite(&data,sizeof(Student),1,fp);
			flag=0;
			break;
		}
	if(flag)
		fwrite(&data,sizeof(Student),1,fp);
	printf("Success!\n");
}
void Delete(FILE *fp)
{	Student temp,data=Get();
	rewind(fp);
	bool flag=1;
	while(fread(&temp,sizeof(Student),1,fp))
		if((temp.num==data.num)&&!strcmp(temp.name,data.name))
		{	data.isvalid=0;
			fseek(fp,-sizeof(Student),SEEK_CUR);
			fwrite(&data,sizeof(Student),1,fp);
			flag=0;
			printf("Success!\n");
			break;
		}
	if(flag)
		printf("Can't find the student %s,No.%d!\n",data.name,data.num);
}
void Print(FILE *fp)
{	Student temp;
	rewind(fp);
	while(fread(&temp,sizeof(Student),1,fp))
		if(temp.isvalid)
			printf("Name:%21s,No.%8d,Score:%6.2lf\n",temp.name,temp.num,temp.score);
}
Student Get(void)
{	Student temp;
	printf("Enter the name:");
	nbgets(temp.name,21);
	printf("Enter the number:");
	scanf("%d",&temp.num);
	printf("Enter the score:");
	scanf("%lf",&temp.score);
	eatline();
	temp.isvalid=1;
	return temp;
}
char menu(void)
{	printf("Select function:\n");
	printf("A-Add a Detail   D-Delete a Detail\n");
	printf("P-Print Details  Q-Quit\n");
	char ch=tolower(getchar());
	while(NULL==strchr("adpq",ch))
	{	eatline();
		printf("Enter A,D,P or Q!\n");
		ch=tolower(getchar());
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
