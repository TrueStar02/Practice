#include<stdio.h>
#define NB "LiuYuan"
int main(void)
{char nb[]=NB;
 const char *ptr=NB;
 printf("Address of \"LiuYuan\":%p\n","LiuYuan");
 printf("Address of nb[]:%p\n",nb);
 printf("Address of pointer:%p\n",ptr);
 printf("Address of NB:%p\n",NB);
 return 0;
}
