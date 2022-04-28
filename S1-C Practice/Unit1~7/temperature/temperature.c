#include<stdio.h>
int main(void)
{double temp;
 int label;
 printf("Input a temperature:)\n");
 label=scanf("%lf",&temp);
 while(label==1)
 {Temp(temp);
  printf("Input a temperature:)\n");
  label=scanf("%lf",&temp);
 }
 printf("Byebye!\n");
 return 0;
}
void Temp(double f)
{double c,k;
 c=(f-32.0)*5.0/9.0;
 k=c+273.15;
 printf("%8.2lfC %8.2lfK\n",c,k);
}
