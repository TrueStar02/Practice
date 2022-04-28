#include<stdio.h>
int main(void)
{unsigned long min=0,max=18446744073709551615,now=9223372036854775807,times=1;
 char ch;
 printf("Now,think about a nunber between %lu and %lu.\n",min,max);
 printf("I will guess what it is.\n");
 printf("Are you ready?\n");
 printf("Attempt %lu\n",times);
 printf("Is %lu the number you want?",now);
 printf("Press y for yes.\nIf it is too big then press b.\nIf it is too small press s\n");
 while((ch=getchar())!='y')
 {if(ch=='b')
  {if(now==min)
   {printf("You must be lying!Tell the truth!\n");
    while(getchar()!='\n')
    continue;
    continue;
   }
   else
   max=now-1;
   
   
  }
  else if(ch=='s')
  {if(now==max)
   {printf("You must be lying!Tell the truth!\n");
    while(getchar()!='\n')
    continue;
    continue;
   }
   else
   min=now+1;
  }
  else
  {while(getchar()!='\n')
   continue;
   printf("Take it seriously.\n");
   printf("Press y for yes.\nIf it is too big then press b.\nIf it is too small press s\n");
   
   continue;
  }
  now=(max+min)/2;
  while(getchar()!='\n')
  continue;
  times++;
  printf("\nNow the range is from %lu to %lu\n",min,max);
  printf("The length of the range is %lu\n",max-min+1);
  printf("Attempt %lu\n",times);
  printf("Is %lu the number you want?",now);
  printf("Press y for yes.\nIf it is too big then press b.\nIf it is too small press s\n");
 }
 printf("Oh,I know I can do it!I get it in %lu times!\n",times);
 return 0;
}
