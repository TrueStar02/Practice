#include<stdio.h>
#include<ctype.h>
int location(char v);
int main(void)
{char ch;
 int loc,i=0;
 while((ch=getchar())!=EOF)
 {i++;
  loc=location(ch);
  printf("%2d ",loc);
  if(i%10==0)
  printf("\n");
 }
  if(i%10)
  printf("\n");
  printf("%d chars\n",i);
  return 0;
}
int location(char v)
{int loc;
 if(isupper(v))
 loc=v-64;
 else if(islower(v))
 loc=v-96;
 else
 loc=-1;
 return loc;
}
