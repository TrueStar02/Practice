#include<stdio.h>
int main(void)
{int x,y;
  x=0;
  for(y=100;y<=1000;y++)
  {if(y%30==0)
   {printf("%-6d",y);
     x++;
     if(x%10==0)
     printf("\n");
   }
   
  }
  return 0;
}