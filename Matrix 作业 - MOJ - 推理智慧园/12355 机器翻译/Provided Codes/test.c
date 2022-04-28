#include<stdio.h>
int main(void)
{int memory,words,x,y,num=0,lookup,ishdd,usedram=0;
 scanf("%d%d",&memory,&words);
 int ram[memory];
 for(x=1;x<=memory;x++)
 ram[x-1]=-1;
 for(x=1;x<=words;x++)
 {ishdd=1;
  scanf("%d",&lookup);
  for(y=0;y<memory;y++)
  if(ram[y]==lookup)
  {ishdd=0;
   break;
  }
  if(ishdd==1)
  {num++;
   if(usedram<memory)
   {ram[usedram]=lookup;
    usedram++;
   }
   else
   {for(y=1;y<memory;y++)
    ram[y-1]=ram[y];
    ram[memory-1]=lookup;
   }
  }

 }
 printf("%d",num);
 return 0;
}
