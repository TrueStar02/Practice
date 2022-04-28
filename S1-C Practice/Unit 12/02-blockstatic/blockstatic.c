#include<stdio.h>
int *stat(void);
int *automatic(void);
int main(void)
{int x,*ptrm,*ptrn;
 for(x=1;x<=5;x++)
 {ptrm=stat();
  
  ptrn=automatic();
  
  (*ptrm)++;
  (*ptrn)++;
  printf("%d %d\n\n",*ptrm,*ptrn);
 }
 return 0;
}
int *stat(void)
{int *ptr;
 static int m=0;
 m++;
 printf("%d ",m);
 ptr=&m;
 return ptr;
}
int *automatic(void)
{int *ptr;
 int n=0;
 n++;
 printf("%d\n",n);
 ptr=&n;
 return ptr;
}
