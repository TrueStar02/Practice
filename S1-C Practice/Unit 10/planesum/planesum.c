#include<stdio.h>
int sum(int *ptr,int n);
int main(void)
{int arr[4][3]={{0,1,2},{10,11,12},{20,21,22},{30,31,32}};
 int tot=0;
 for(int x=0;x<=3;x++)
 tot+=sum(*(arr+x),3);
 printf("%d\n",tot);
 return 0;
}
int sum(int *ptr,int n)
{int sum=0;
 for(int y=0;y<n;y++)
 sum+=*(ptr+y);
 return sum;
}
