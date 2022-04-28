#include<stdio.h>
#include<stdbool.h>
int main(void)
{int x=0,y,min,max;
 bool i;
  scanf("%d%d",&min,&max);
  for(y=min;y<=max;y++)
  {i=((y%5==0)^(y%6==0));
    if(i==1)
   {printf("%-6d",y);
     x++;
     if(x%10==0)
     printf("\n");
   }
   
  }
  return 0;
}