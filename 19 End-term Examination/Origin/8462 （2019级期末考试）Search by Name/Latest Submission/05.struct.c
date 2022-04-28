#include<stdio.h>
#include<string.h>
#include "source.h"
int main(){
	char target[10];
	int i;
	scanf("%s", target);
	for(i=0;i<35;i++){
		if(!strcmp(student[i].first_name, target)||!strcmp(student[i].last_name, target)){
			printf("%.0lf\t%s\t%s\t%.0lf\t%s\t%.0lf\t%.0lf\t%s\t\n", student[i].student_id, student[i].last_name, student[i].first_name, student[i].age, student[i].sex, student[i].major, student[i].advisor, student[i].city_code);
		}
	}
}