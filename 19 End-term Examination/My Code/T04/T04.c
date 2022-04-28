#include<stdio.h>
#include<string.h>
#include "source.h"
int main(void)
{	char str[10];
	scanf("%s",str);
	int x;
	for(x=0;x<=34;x++)
	{	if(!(strcmp(str,student[x].last_name)&&strcmp(str,student[x].first_name)))
			printf("%.0lf %s %s %.0lf %s %.0lf %.0lf %s\n",student[x].student_id,student[x].last_name,student[x].first_name,student[x].age,student[x].sex,student[x].major,student[x].advisor,student[x].city_code);
	}
	return 0;
}
