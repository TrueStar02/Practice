#include<stdio.h>
long tobase(long num,short base);
int main(void)
{long num;
 short base;
 scanf("%ld%hd",&num,&base);
 if((base<=9&&base>=2)||base==16)
 tobase(num,base);
 else
 printf("Error!");
 printf("\n");
 return 0;
}
long tobase(long num,short base)
{int r;
 r=num%base;
 if(num>base)
 tobase(num/base,base);
 if(r>=0&&r<=9)
 printf("%d",r);
 else if(r==10)
 printf("A");
 else if(r==11)
 printf("B");
 else if(r==12)
 printf("C");
 else if(r==13)
 printf("D");
 else if(r==14)
 printf("E");
 else if(r==15)
 printf("F");
 
}

