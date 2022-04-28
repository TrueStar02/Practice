#include<stdio.h>
int main(void)
{
 int arr[5]={0,1,2,3,4};
 
 int *ptr;
 int **ptr2;
 int ***ptr3;
 int ***ptr4;
 int **ptr5;
 ptr=arr;
 ptr2=&ptr;
 //ptr3=&(&ptr);
 ptr4=&ptr2;
 ptr5=*ptr4;
 printf("%p %p\n",arr,arr+2);
 printf("%p %p\n",ptr,ptr+2);
 printf("%p %p\n",ptr2,ptr5);
 printf("%p %p\n",ptr4,ptr4);
 return 0;
}
