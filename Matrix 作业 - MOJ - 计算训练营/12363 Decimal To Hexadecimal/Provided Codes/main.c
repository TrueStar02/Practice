#include<stdio.h>
void hex(int num);
int main()
{int num;
 scanf("%d",&num);
 hex(num);
 return 0;
}
void hex(int num)
{int m;
 m=num%16;
 if(num>=16)
 hex(num/16);
 if(m<=9)
 printf("%d",m);
 else if(m==10)
 printf("A");
 else if(m==11)
 printf("B");
 else if(m==12)
 printf("C");
 else if(m==13)
 printf("D");
 else if(m==14)
 printf("E");
 else if(m==15)
 printf("F");
}
