#include<stdio.h>
void enter(int row,int col,double arr[row][col]);
void copy(int row,int col,double arr[row][col],double tar[row][col]);
void delta(int row,int col,double arr[row][col]);
void averow(double *arr,int col);
void aveall(int row,int col,double arr[row][col]);
void twice(int row,int col,double tar[row][col]);
void add(int row,int col,double arr[row][col],double tar[row][col],double sum[row][col]);
void print(int row,int col,double prt[row][col]);
int main(void)
{int row,col,x;
 scanf("%d%d",&row,&col);
 double arr[row][col],tar[row][col],sum[row][col];
 enter(row,col,arr);
 printf("\n");
 copy(row,col,arr,tar);
 printf("\n");
 delta(row,col,arr);
 printf("\n");
 for(x=0;x<row;x++)
 averow(*(arr+x),col);
 printf("\n");
 aveall(row,col,arr);
 printf("\n");
 twice(row,col,tar);
 printf("\n");
 add(row,col,arr,tar,sum);
 printf("\n");
 return 0;
}
void enter(int row,int col,double arr[row][col])
{int x,y;
 for(x=0;x<row;x++)
 for(y=0;y<col;y++)
 scanf("%lf",(*(arr+x)+y));
 printf("Now we have got the array:\n");
 print(row,col,arr);
}
void copy(int row,int col,double arr[row][col],double tar[row][col])
{int x,y;
 for(x=0;x<row;x++)
 for(y=0;y<col;y++)
 tar[x][y]=arr[x][y];
 printf("Now we have copied the array:\n");
 print(row,col,tar);
}
void delta(int row,int col,double arr[row][col])
{double min,max,delta;
 int x,y;
 max=min=arr[0][0];
 for(x=0;x<row;x++)
 for(y=0;y<col;y++)
 {if(arr[x][y]>max)
  max=arr[x][y];
  else if(arr[x][y]<min)
  min=arr[x][y];
 }
 delta=max-min;
 printf("Maxium:%7.2lf\n",max);
 printf("Minium:%7.2lf\n",min);
 printf("Delta :%7.2lf\n",delta);
}
void averow(double *arr,int col)
{int x;
 double sum=0,average;
 for(x=0;x<col;x++)
 sum+=arr[x];
 average=sum/col;
 printf("Row average:%7.2lf\n",average);
}
void aveall(int row,int col,double arr[row][col])
{double average,sum=0;
 int x,y;
 for(x=0;x<row;x++)
 for(y=0;y<col;y++)
 sum+=arr[x][y];
 average=sum/(row*col);
 printf("Average:%7.2lf\n",average);
}
void twice(int row,int col,double tar[row][col])
{int x,y;
 for(x=0;x<row;x++)
 for(y=0;y<col;y++)
 tar[x][y]*=2;
 printf("Now the array is one time bigger:\n");
 print(row,col,tar);
}
void add(int row,int col,double arr[row][col],double tar[row][col],double sum[row][col])
{int x,y;
 for(x=0;x<row;x++)
 for(y=0;y<col;y++)
 sum[x][y]=arr[x][y]+tar[x][y];
 printf("Now we have added the two arrays up:\n");
 print(row,col,sum);
}
void print(int row,int col,double prt[row][col])
{int x,y;
 for(x=0;x<row;x++)
 {for(y=0;y<col;y++)
  printf("%7.2lf",prt[x][y]);
  printf("\n");
 }
}
