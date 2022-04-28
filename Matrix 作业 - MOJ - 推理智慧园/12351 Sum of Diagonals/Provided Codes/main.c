#include<stdio.h>
void sum(int n);
int main(void)
{int task,x,n;
 scanf("%d",&task);
 for(x=1;x<=task;x++)
 {scanf("%d",&n);
  sum(n);
 }
 return 0;
}
void sum(int n)
{int arr[n][n];
 int x,y,sum=0;
 for(x=0;x<n;x++)
 for(y=0;y<n;y++)
 scanf("%d",&arr[x][y]);
 for(x=0;x<n;x++)
 sum=sum+arr[x][x]+arr[x][n-x-1];
 if(n%2!=0)
 sum-=arr[(n-1)/2][(n-1)/2];
 printf("%d\n",sum);
}
