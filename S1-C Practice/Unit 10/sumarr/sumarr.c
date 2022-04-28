#include<stdio.h>
#define SIZE 5
int sum(int *arr,int n);
int main()
{int arr[5]={0,1,2,3,4};
 int result;
 result=sum(arr,SIZE);
 printf("%d\n",result);
 return 0;
}
int sum(int *arr,int n)
{int x,sum=0;
 for(x=0;x<n;x++)
 sum+=*(arr+x);
 return sum;
}
