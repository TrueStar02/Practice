#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{srand((unsigned int)time(0));
 int x,y,temp,arr[11]={0};
 for(x=0;x<1000;x++)
 arr[(rand()%10+1)]++;
 for(x=1;x<=10;x++)
 printf("%2d%4d\n",x,arr[x]);
 return 0;
}
