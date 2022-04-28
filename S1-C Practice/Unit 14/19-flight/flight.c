#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
struct seat
{	int number;
	bool isbooked;
	char fname[31];
	char lname[31];
};
struct aircraft
{	int fltno;
	struct seat details[12];
};
char *nbgets(char *st,int n);
char chooseflight(void);
char function(int flight);
void eatline(void);
void showall(struct aircraft *ptr);
void showempty(struct aircraft *ptr);
void bookticket(struct aircraft *ptr);
void cancelbook(struct aircraft *ptr);
int getnumber(void);
bool sure(void);
int main(void)
{	int x,y,flight;
	char ch;
	struct aircraft plane[4];
	struct aircraft *ptr;
	for(x=0;x<4;x++)
	for(y=0;y<12;y++)
	{	plane[x].details[y].number=y+1;
		plane[x].details[y].isbooked=0;
	}
	plane[0].fltno=1001;
	plane[1].fltno=1002;
	plane[2].fltno=5001;
	plane[3].fltno=5002;
	while((flight=(int)chooseflight())!=16)
	{	ptr=plane+flight;
		while((ch=function(plane[flight].fltno))!='q')
		{	switch(ch)
			{	case 'a':showall(ptr);
					break;
				case 'b':showempty(ptr);
					break;
				case 'c':bookticket(ptr);
					break;
				case 'd':cancelbook(ptr);
					break;
			}
		}
	}
	return 0;
}
void showall(struct aircraft *ptr)
{	int y;
	for(y=0;y<12;y++)
	{	printf("No.%02d ",ptr->details[y].number);
		if(ptr->details[y].isbooked)
			printf("Booked by %s %s\n",ptr->details[y].fname,ptr->details[y].lname);
		else
			printf("Available\n");
	}
}
void showempty(struct aircraft *ptr)
{	int y;
	for(y=0;y<12;y++)
		if(!(ptr->details[y].isbooked))
			printf("No.%02d Available\n",(ptr->details[y].number));
}
void bookticket(struct aircraft *ptr)
{	int no;
	while(no=getnumber())
	{	if(ptr->details[no-1].isbooked)
			puts("This seat is already booked!");
		else
		{	puts("Enter your first name");
			nbgets(ptr->details[no-1].fname,31);
			puts("Enter your last name");
			nbgets(ptr->details[no-1].lname,31);
			printf("Are you sure to book the seat %02d for %s %s(y for yes and other for no)?",ptr->details[no-1].number,ptr->details[no-1].fname,ptr->details[no-1].lname);
			if(sure())
				ptr->details[no-1].isbooked=1;
		}
	}
}
void cancelbook(struct aircraft *ptr)
{	int no;
	while(no=getnumber())
	{	if(!(ptr->details[no-1].isbooked))
			puts("This seat is not booked!");
		else
		{	printf("Are you sure to cancel the seat %02d for %s %s(y for yes and other for no)?",ptr->details[no-1].number,ptr->details[no-1].fname,ptr->details[no-1].lname);
			if(sure())
				ptr->details[no-1].isbooked=0;
		}
	}
}
int getnumber(void)
{	int n;
	puts("Enter the number of the seat");
	while(scanf("%d",&n)!=1||n<0||n>12)
	{	eatline();
		printf("Enter a number between 0 and 12\n");
	}
	eatline();
	return n;
}
char chooseflight(void)
{	puts("Welcome to use flight booking system!");
	puts("Please choose the flight");
	puts("A-1001  B-1002");
	puts("C-5001  D-5002");
	puts("Q-quit");
	char ch;
	ch=tolower(getchar());
	while(strchr("abcdq",ch)==NULL)
	{	eatline();
		puts("Enter A,B,C,D or Q!");
		ch=tolower(getchar());
	}
	eatline();
	return (ch-97);
}
char function(int flight)
{	printf("Flight:%d\n",flight);
	puts("A-Show all seats");
	puts("B-Show empty seats");
	puts("C-Book a seat");
	puts("D-Cancel a book");
	puts("Q-quit");
	char ch;
	while((ch=tolower(getchar()))&&strchr("abcdq",ch)==NULL)
	{	eatline();
		puts("Enter A,B,C,D or Q!");
	}
	eatline();
	return ch;
}
bool sure(void)
{	bool yes;
	if(tolower(getchar())=='y')
	{	yes=1;
		puts("Done!");
	}
	else
	{	yes=0;
		puts("Given up!");
	}
	eatline();
	return yes;
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
