#include<stdio.h>
void rectangle(int n);
int main(void)
{int tasks,x,n;
 scanf("%d",&tasks);
 for(x=1;x<=tasks;x++)
 {scanf("%d",&n);
  rectangle(n);
 }
 return 0;
}
void rectangle(int n)
{int a[n][2];
 int x,y,l1=0,w1=0,l2=0,w2=0,z,ok=0;
 for(x=0;x<n;x++)
 scanf("%d%d",*(a+x),*(a+x)+1);
 for(x=0;x<n-1;x++)
 for(y=x+1;y<n;y++)
 {if((a[x][1]==a[y][1]&&a[x][0]==a[y][0])||(a[x][1]==a[y][0]&&a[x][0]==a[y][1]))
  {l1=2*a[x][1];
   w1=a[x][0];
   l2=2*a[x][0];
   w2=a[x][1];
  }
  else if(a[x][1]==a[y][1])
  {l1=a[x][1];
   w1=a[x][0]+a[y][0];
  }
  else if(a[x][0]==a[y][0])
  {l1=a[x][0];
   w1=a[x][1]+a[y][1];
  }
  else if(a[x][1]==a[y][0])
  {l1=a[x][1];
   w1=a[x][0]+a[y][1];
  }
  else if(a[x][0]==a[y][1])
  {l1=a[x][0];
   w1=a[x][1]+a[y][0];
  }
  else
  continue;
  for(z=0;z<n;z++)
  {
   if((z!=x&&z!=y)&&(a[z][1]==l1||a[z][0]==l1||a[z][1]==l2||a[z][0]==l2||a[z][1]==w1||a[z][0]==w1||a[z][1]==w2||a[z][0]==w2))
   {printf("Yes\n");
    ok=1;
    break;
   }
  }
  if(ok==0)
  l1=w1=l2=w2=0;
  if(ok==1)
  {x=10000000;
   y=10000000;
  }
 }
 if(ok==0)
 printf("No\n");
}
