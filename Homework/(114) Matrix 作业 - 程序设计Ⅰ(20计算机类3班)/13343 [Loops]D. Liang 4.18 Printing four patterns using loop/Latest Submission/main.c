#include<stdio.h>
void pat1(int line);
void pat2(int line);
void pat3(int line);
void pat4(int line);
int main(void)
{int type,line;
 scanf("%d%d",&type,&line);
 switch(type)
 {case 1:pat1(line);
         break;
  case 2:pat2(line);
         break;
  case 3:pat3(line);
         break;
  case 4:pat4(line);
         break;
 }
 return 0;
}
void pat1(int line)
{int x,y;
 for(x=1;x<=line;x++)
 {for(y=1;y<=x;y++)
  printf("%3d",y);
  printf("\n");
 }
}
void pat2(int line)
{int x,y;
 for(x=line;x>=1;x--)
 {for(y=1;y<=x;y++)
  printf("%3d",y);
  printf("\n");
 }
}
void pat3(int line)
{int x,y;
 for(x=1;x<=line;x++)
 {for(y=1;y<=line-x;y++)
  printf("   ");
  for(y=1;y<=x;y++)
  printf("%3d",y);
  printf("\n");
 }
}
void pat4(int line)
{int x,y;
 for(x=line;x>=1;x--)
 {for(y=1;y<=line-x;y++)
  printf("   ");
  for(y=1;y<=x;y++)
  printf("%3d",y);
  printf("\n");
 }
}
