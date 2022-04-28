#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int diceroll(unsigned int dices,unsigned int sides);
unsigned int readint(void);
bool test(unsigned int dices,unsigned int sides);
int main(void)
{unsigned int dices,sides,times;
 int value,x;
 bool istrue;
 srand((unsigned int)time(0));
 while(1)
 {printf("Times of game:");
  times=readint();
  if(!sides)
  break;
  printf("Sides on each dice:");
  sides=readint();
  printf("Number of dices:");
  dices=readint();
  istrue=test(dices,sides);
  if(!istrue)
  continue;
  for(x=1;x<=times;x++)
  {printf("Game %d\n",x);
   value=diceroll(dices,sides);
   printf("Final result:%d\n",value);
  }
  printf("\n");
 }
 printf("Good Luck!Byebye~\n");
 return 0;
}
unsigned int readint(void)
{unsigned int num;
 while(scanf("%u",&num)!=1)
 {while(getchar()!='\n')
  continue;
  printf("You should enter a number!Try again!");
 }
 while(getchar()!='\n')
 continue;
 return num;
}
int diceroll(unsigned int dices,unsigned int sides)
{int result=0,x,num;
 printf("Every dice:");
 for(x=1;x<=dices;x++)
 {num=(rand()%sides+1);
  result+=num;
  printf("%d ",num);
 }
 return result;
}
bool test(unsigned int dices,unsigned int sides)
{bool istrue=1;
 if(sides<2)
 {printf("At least 2 sides!Try again!\n");
  istrue=0;
 }
 if(dices<1)
 {printf("At least 1 dice!Try again!\n");
  istrue=0;
 }
 return istrue;
}
