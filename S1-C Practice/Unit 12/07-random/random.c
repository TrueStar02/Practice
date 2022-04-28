#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{srand((unsigned int)time(0));
 int arr[100],x,y,temp;
 for(x=0;x<100;x++)
 arr[x]=(rand()%10+1);
 for(x=0;x<100;x++)
 for(y=x+1;y<100;y++)
 if(arr[x]>arr[y])
 {temp=arr[x];
  arr[x]=arr[y];
  arr[y]=temp;
 }
 for(x=0;x<100;x++)
 {printf("%3d",arr[x]);
  if(x%10==9)
  printf("\n");
 }
 return 0;
}
