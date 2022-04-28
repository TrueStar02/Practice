#include<stdio.h>
#include<stdlib.h>
int main(void)
{double *ptr;
 int num,max,i=0,x;
 puts("How many numbers do you need?");
 if(scanf("%d",&max)!=1)
 {puts("You have no brain,SB!");
  exit(EXIT_FAILURE);
 }
 ptr=(double *)malloc(max*sizeof(double));
 if(ptr==NULL)
 {puts("The computer is SB!");
  exit(EXIT_FAILURE);
 }
 puts("Enter the values,letters to quit");
 while((i)<max&&scanf("%lf",ptr+i)==1)
 i++;
 for(x=0;x<i;x++)
 printf("%9.3lf",ptr[x]);
 free(ptr);
 return 0;
}
