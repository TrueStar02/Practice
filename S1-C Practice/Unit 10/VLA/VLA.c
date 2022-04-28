#include<stdio.h>
void enter(int rows,int cols,int arr[rows][cols]);
int sum(int rows,int cols,int arr[rows][cols]);
int main(void)
{int rows,cols,result;
 scanf("%d%d",&rows,&cols);
 int arr[rows][cols];
 enter(rows,cols,arr);
 result=sum(rows,cols,arr);
 printf("%d\n",result);
 return 0;
}
void enter(int rows,int cols,int arr[rows][cols])
{for(int x=0;x<rows;x++)
 for(int y=0;y<cols;y++)
 scanf("%d",&arr[x][y]);
}
int sum(int rows,int cols,int arr[rows][cols])
{int sum=0;
 for(int x=0;x<rows;x++)
 for(int y=0;y<cols;y++)
 sum+=arr[x][y];
 return sum;

}
