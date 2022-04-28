#include<stdio.h>
int main(void)
{int arr[4][3]={{0,1,2},{10,11,12},{20,21,22},{30,31,32}};
 int *ptr1;
 int **ptr2;
 int (*ptr3)[3];
 int **ptr4;
 ptr3=arr;
 ptr1=arr[0];
 ptr2=&ptr1;
 ptr4=&ptr3;
 printf("%p\n%p\n%p\n%p\n",ptr1,ptr2,ptr3,ptr4);
 return 0;
}
