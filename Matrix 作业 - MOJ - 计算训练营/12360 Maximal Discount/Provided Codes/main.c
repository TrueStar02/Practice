#include<stdio.h>
int main(void)
{int num,x,y,sum=0;
 scanf("%d",&num);
 int arr[num+1];
 for(x=1;x<=num;x++)
 scanf("%d",arr+x);
 for(x=1;x<=num-1;x++)
 for(y=x+1;y<=num;y++)
 if(arr[x]<arr[y])
 {arr[0]=arr[x];
  arr[x]=arr[y];
  arr[y]=arr[0];
 }
 for(x=3;x<=num;x+=3)
 sum+=arr[x];
 printf("%d",sum);
 return 0;
}
