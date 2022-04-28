#include<stdio.h>
#define ROW 4
void sumrow(int arr[][3],int n);
void sumcol(int arr[][3],int n);
void sumall(int arr[][3],int n);
int main(void)
{int arr[4][3]={{0,1,2},{10,11,12},{20,21,22},{30,31,32}};
 int tot=0;
 sumrow(arr,ROW);
 printf("\n");
 sumcol(arr,ROW);
 printf("\n");
 sumall(arr,ROW);
 printf("\n");

 return 0;
}
void sumrow(int arr[][3],int n)
{int x,y,sum=0;
 for(x=0;x<n;x++)
 {sum=0;
  for(y=0;y<3;y++)
  sum+=arr[x][y];
  printf("row%d:%d\n",x,sum);
 }
}
void sumcol(int arr[][3],int n)
{int x,y,sum=0;
 for(y=0;y<3;y++)
 {sum=0;
  for(x=0;x<n;x++)
  sum+=arr[x][y];
  printf("col%d:%d\n",y,sum);
 }
}
void sumall(int arr[][3],int n)
{int x,y,sum=0;
 for(y=0;y<3;y++)
 
  for(x=0;x<n;x++)
  sum+=arr[x][y];
  printf("total:%d",sum);
 
}
