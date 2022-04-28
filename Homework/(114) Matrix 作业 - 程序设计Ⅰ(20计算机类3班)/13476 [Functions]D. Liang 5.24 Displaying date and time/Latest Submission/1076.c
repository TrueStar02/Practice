#include<stdio.h>
int main(void)
{	long tot;
	int day,sec;
	scanf("%ld",&tot);
	sec=tot%86400;
	day=tot/86400+1;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int yyyy=1970,mm=1,hh=0,min=0,ss=0;
	while(day>month[mm])
	{	if(yyyy%4==0&&mm==2&&day==29)
		break;
		if(yyyy%4==0&&mm==2)
		day--;
		day-=month[mm];
		mm++;
		if(mm==13)
		{	mm=1;
			yyyy++;
		}
	}
	hh=sec/3600;
	sec-=hh*3600;
	min=sec/60;
	sec-=min*60;
	printf("%d-%d-%d\n%d:%d:%d",yyyy,mm,day,hh,min,sec);
	return 0;
}