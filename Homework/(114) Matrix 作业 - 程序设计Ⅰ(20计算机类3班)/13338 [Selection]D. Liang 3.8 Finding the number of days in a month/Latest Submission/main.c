#include<stdio.h>
int main(void)
{   
 int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 char name[13][10]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
 int days,y,m;
 scanf("%d%d",&y,&m);
 days=month[m];
 if(m==2&&y%4==0)
 {days++;
  if(y%100==0&&y%400!=0)
  days--;
 }
 printf("%s %d has %d days",name[m],y,days);
 return 0;
}