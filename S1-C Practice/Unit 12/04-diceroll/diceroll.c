#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int diceroll(unsigned int dices,unsigned int sides);
unsigned int readint(void);
int main(void)
{unsigned int dices,sides;
 int value;
 srand((unsigned int)time(0));
 while(1)
 {printf("Sides on each dice(0 to exit):");
  sides=readint();
  if(!sides)
  break;
  printf("Number of dices:");
  dices=readint();
  value=diceroll(dices,sides);
  if(value!=-1)
  printf("%u dices %u sides,result:%d\n\n",dices,sides,value);
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
{int result=0,x;
 if(sides<2)
 {printf("At least 2 sides!Try again!\n");
  result=-1;
 }
 if(dices<1)
 {printf("At least 1 dice!Try again!\n");
  result=-1;
 }
 if(!result)
 {for(x=1;x<=dices;x++)
  result+=(rand()%sides+1);
 }
 return result;
}
