#include<stdio.h>
#define SIZE 5
int sum(int *start,int *end);
int main(void)
{int arr[5]={0,1,2,3,4};
 int result;
 result=sum(arr,arr+SIZE);
 printf("%d\n",result);
 return 0;
}
int sum(int *start,int *end)
{int sum=0;
 while(start<end)
 {sum+=*start;
  start++;
 }
 return sum;
}
