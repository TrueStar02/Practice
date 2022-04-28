#include<stdio.h>
int main(void)
{int num,a,b,x=0,y=0;
 scanf("%d",&num);
 int carpet[num][4];
 for(a=0;a<num;a++)
 for(b=0;b<4;b++)
 scanf("%d",&carpet[a][b]);
 scanf("%d%d",&x,&y);

 for(a=num-1;a>=0;a--)
 if(carpet[a][0]<=x&&carpet[a][1]<=y&&(carpet[a][0]+carpet[a][2])>=x&&(carpet[a][1]+carpet[a][3])>=y)
 {printf("%d",a+1);
  break;
 }
 if(a==-1)
 printf("%d",a);
 return 0;
}
