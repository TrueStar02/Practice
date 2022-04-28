#include<stdio.h>
struct name
{	char last[21];
	char first[21];
};
struct guy
{	struct name person;
	int money;
};
int sum(const struct guy *arr,int n);
int main(void)
{	struct guy friend[3]=
	{{{"Wang","Tianle"},1000},
	 {{"Tao","Yinda"},2000},
	 {{"Ni","Dabao"},3000}
	};
	int x;
	struct guy *ptr;
	ptr=friend;
	
	for(x=0;x<3;x++,ptr++)
	{	printf("Address of struct %d:%p\n",x,ptr);
		printf("%d,%s %s,have %d RMB every month.\n",x+1,ptr->person.last,ptr->person.first,ptr->money);
	}
	ptr=friend;
	printf("They have %d RMB every month(calculated by array)\n",sum(friend,3));
	printf("They have %d RMB every month(calculated by pointer)\n",sum(ptr,3));
	
	return 0;
}
int sum(const struct guy *arr,int n)
{	int m=0,x;
	for(x=0;x<3;x++)
		m+=(arr+x)->money;
	return m;
}
