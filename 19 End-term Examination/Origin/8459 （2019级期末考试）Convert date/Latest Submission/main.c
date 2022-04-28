#include<stdio.h>
#include<string.h>
struct student{
	char name[20];
	int year;
	int month;
	int date;
}; 
int judgey(int year){
	if((year%4==0)&&(year%100!=0))
	return 1;
	else return 0;
}
int main(){
	struct student stu[10];
	int t, i, result=0;
	char na[20];
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%s", stu[i].name);
		scanf("%d%d%d", &stu[i].year, &stu[i].month, &stu[i].date);
	}
	scanf("%s", na);
	//printf("%s\n", na);
	for(i--;i>=0;i--){
		//printf("%d %s\n", i, stu[i].name);
		if(strcmp(na, stu[i].name)==0){
			//printf("yes"); 
			if(stu[i].month>2){
			result+=judgey(stu[i].year);
		    switch(stu[i].month){
		    	case 3: result+=59; break;
		    	case 4: result+=90; break;
		    	case 5: result+=120; break;
		    	case 6: result+=151; break;
		    	case 7: result+=181; break;
		    	case 8: result+=212; break;
		    	case 9: result+=243; break;
		    	case 10: result+=273; break;
		    	case 11: result+=304; break;
		    	case 12: result+=334; break;
			}
			result+=stu[i].date;
			}
			else {
				if(stu[i].month==1) result=stu[i].date;
				else result=stu[i].date+31;
			}
			printf("%d", result);
			break;
		}
	}
}