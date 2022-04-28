#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char *months[]={"Error","January","February","March","April","May","June","July","August","September","October","November","December"};
const char *monabbr[]={"Err","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
int main(int argc,char *argv[])
{	if(argc!=4)
	{	puts("Invalid input!");
		exit(EXIT_FAILURE);
	}
	int yyyy,mm,dd,x,sum=0;
	yyyy=atoi(argv[3]);
	dd=atoi(argv[2]);
	int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(yyyy%400==0||(yyyy%4==0&&yyyy%100!=0))
		days[2]=29;
	for(x=1;x<=12;x++)
	{if((!strcmp(argv[1],months[x]))||(!strcmp(argv[1],monabbr[x]))||(atoi(argv[1])==x))
		break;
	 sum+=days[x];
	}
	if(x==13)
	{	puts("Invalid month!");
		exit(EXIT_FAILURE);
	}
	sum+=dd;
	printf("%d days\n",sum);
	return 0;	
}

