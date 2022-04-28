#include<stdio.h>
double add(void);
double substract(void);
double multiply(void);
double divide(void);
double getnumber(void);
char getfirst(void);
int main(void)
{double result;
 int label=1;
 char ch;
 printf("Here is a calculator.\n");
 printf("Please choose the function you need:\n");
 printf("a-add          b-substract\n");
 printf("c-multyply     d-divide\n");
 printf("q-quit\n");
 printf("Enter your choice:");
 while(((ch=getfirst())!='q')&&ch!='Q')
 {switch(ch)
  {case 'A':
   case 'a':result=add();
            break;
   case 'B':
   case 'b':result=substract();
            break;
   case 'C':
   case 'c':result=multiply();
            break;
   case 'D':
   case 'd':result=divide();
            break;
   default :printf("Take it seriously!\n");
            label=0;
  }
 if(label==1)
 printf("The result is %g\n\n",result);
 printf("Please choose the function you need:\n");
 printf("a-add          b-substract\n");
 printf("c-multyply     d-divide\n");
 printf("q-quit\n");
 printf("Enter your choice:");
 label=1;
 while(getchar()!='\n')
 continue;
 }
 printf("Byebye!\n");
 return 0;
}
char getfirst(void)
{char v;
 v=getchar();
 while((getchar())!='\n')
 continue;
 return v;
}
double add(void)
{double a,b,result;
 printf("Enter two numbera a and b.I will calculate a+b.\n");
 printf("Enter a:");
 a=getnumber();
 printf("Enter b:");
 b=getnumber();
 result=a+b;
 return result;
}
double substract(void)
{double a,b,result;
 printf("Enter two numbera a and b.I will calculate a-b.\n");
 printf("Enter a:");
 a=getnumber();
 printf("Enter b:");
 b=getnumber();
 result=a-b;
 return result;
}
double multiply(void)
{double a,b,result;
 printf("Enter two numbera a and b.I will calculate a*b.\n");
 printf("Enter a:");
 a=getnumber();
 printf("Enter b:");
 b=getnumber();
 result=a*b;
 return result;
}
double divide(void)
{double a,b,result;
 printf("Enter two numbera a and b.I will calculate a/b.\n");
 printf("Enter a:");
 a=getnumber();
 printf("Enter b:");
 b=getnumber();
 while(b==0)
 {printf("0 can't be divisor!\n");
  printf("Enter another b:");
  b=getnumber();
 }
 result=a/b;
 return result;
}
double getnumber(void)
{double num;
 char v;
 while(scanf("%lf",&num)!=1)
 {while((v=getchar())!='\n')
  putchar(v);
  printf(" isn't a number!\n");
  printf("Please enter a number:");
 }
 return num;
 
}
