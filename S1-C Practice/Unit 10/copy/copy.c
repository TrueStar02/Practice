#include<stdio.h>
void copy_arr(int arr[],int tar[],int n);
void copy_ptr1(int *arr,int *tar,int n);
void copy_ptr2(int *start,int *end,int *tar);
int main(void)
{int arr[5]={0,1,2,3,4};
 int tar1[5],tar2[5],tar3[5];
 copy_arr(arr,tar1,5);
 copy_ptr1(arr,tar2,5);
 copy_ptr2(arr,arr+5,tar3);
 int x;
 for(x=0;x<=4;x++)
 printf("%d ",tar1[x]);
 printf("\n");
 for(x=0;x<=4;x++)
 printf("%d ",tar2[x]);
 printf("\n");
 for(x=0;x<=4;x++)
 printf("%d ",tar3[x]);
 printf("\n");
 return 0;
}
void copy_arr(int arr[],int tar[],int n)
{for(int x=0;x<5;x++)
 tar[x]=arr[x];
}
void copy_ptr1(int *arr,int *tar,int n)
{int *ptr=arr;
 for(int x=0;x<5;x++)
 {*(tar+x)=*ptr;
  ptr++;
 }
}
void copy_ptr2(int *start,int *end,int *tar)
{
 while(start<end)
 {*(tar)=*start;
  start++;
  tar++;
 }
}
