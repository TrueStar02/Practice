#include<stdio.h>
#include<string.h>
struct detail
{	char name[21];
	int year;
	int month;
	int day;
};
const int months[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int main(void)
{	int num,x,y,total;
	scanf("%d",&num);
	struct detail person[num];
	for(x=0;x<num;x++)
		scanf("%s%d%d%d",person[x].name,&person[x].year,&person[x].month,&person[x].day);
	char required[21];
	scanf("%s",required);
	for(x=0;x<num;x++)
		if(!strcmp(required,person[x].name))
			break;
	total=person[x].day+months[person[x].month];
	if(person[x].month>2&&person[x].year%4==0)
	{	total++;
		if(person[x].year%100==0&&person[x].year%400!=0)
			total--;
	}
	printf("%d",total);
	return 0;
}
