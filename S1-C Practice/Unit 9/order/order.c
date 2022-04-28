#include<stdio.h>
void order(double *ptrx,double *ptry,double *ptrz);
int main()
{double x,y,z;
 scanf("%lf%lf%lf",&x,&y,&z);
 order(&x,&y,&z);
 printf("%lf %lf %lf\n",x,y,z);
 return 0;
}
void order(double *ptrx,double *ptry,double *ptrz)
{double temp;
 if(*ptrx>*ptry)
 {temp=*ptrx;
  *ptrx=*ptry;
  *ptry=temp;
 }
 if(*ptrx>*ptrz)
 {temp=*ptrx;
  *ptrx=*ptrz;
  *ptrz=temp;
 }
 if(*ptry>*ptrz)
 {temp=*ptry;
  *ptry=*ptrz;
  *ptrz=temp;
 }
}
