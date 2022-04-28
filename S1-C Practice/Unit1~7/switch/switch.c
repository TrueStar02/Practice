#include<stdio.h>
int main(void)
{char v;
 printf("Enter your level(# to quit):");
 while((v=getchar())!='#')
 {if(v=='\n')
  continue;
  switch(v)
  {case 'A':
   case 'a':printf("Ah,NB!You are DALAO!!!\n");
            break;
   case 'B':
   case 'b':printf("Study harder and you will be DALAO soon!\n");
            break;
   case 'C':
   case 'c':printf("You should try to be better!\n");
            break;
   case 'D':
   case 'd':printf("Warning!You have nearly failed!\n");
            break;
   case 'E':
   case 'e':printf("SB!Your fighting force is only five!\n");
            break;
   default:
            printf("Are you kidding?Take it seriously\n");
  }
  while(getchar()!='\n')
  continue;
  printf("Enter your level:");
 }
 printf("Byebye!\n");
 return 0;
}
