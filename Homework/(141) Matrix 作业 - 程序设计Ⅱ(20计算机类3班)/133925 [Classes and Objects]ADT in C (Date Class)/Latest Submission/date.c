#include "date.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
Date* CreateDate(int year, int month, int day)
{   Date * ptr=malloc(sizeof(Date));
    ptr->year=year;
    ptr->month=month;
    ptr->day=day;
    return ptr;
}
void DestroyDate(Date** p)
{   free(*p);
    *p=NULL;

}
Date* CopyDate(const Date* date)
{   Date * ptr=malloc(sizeof(Date));
     ptr->year=date->year;
    ptr->month=date->month;
    ptr->day=date->day;
    return ptr;
}
int GetYear(const Date* date){return date->year;}
int GetMonth(const Date* date){return date->month;}
int GetDay(const Date* date){return date->day;}
void SetYear(Date* date, int year){date->year=year;}
void SetMonth(Date* date, int month){date->month=month;}
void SetDay(Date* date, int day){date->day=day;}
void SetDate(Date* date, int year, int month, int day)
{   date->year=year;
    date->month=month;
    date->day=day;
}

char* GetDateString(const Date* date)
{   char *str=malloc(11*sizeof(char));
    sprintf(str,"%04d-%02d-%02d",date->year,date->month,date->day);
    return str;
}
void DestroyDateString(char** p)
{   free(*p);
    *p=NULL;
}
void IncreaseDate(Date* date)
{   if(((date->year%4==0&&date->year%100!=0)||date->year%400==0)&&(date->month==2&&date->day==28))
    {   date->month=2;
        date->day=29;
        return;
    }
    date->day++;
    if(arr[date->month]<(date->day))
    {   date->day=1;
        date->month++;
    }
    if(date->month==13)
    {     date->year++;
        date->month=1;
    }
   
}
void DecreaseDate(Date* date)
{     if(((date->year%4==0&&date->year%100!=0)||date->year%400==0)&&(date->month==3&&date->day==1))
     {   date->month=2;
        date->day=29;
        return;
     }
    date->day--;
    if(date->day==0)
    {   date->month--;
        if(date->month==0)
        {   date->year--;
            date->month=12;

        }
        date->day=arr[date->month];
      
    }

}