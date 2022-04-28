#include<stdio.h>
#include<ctype.h>
int main(void)
{char ch;
 int words=0,letters=0,inword=0;
 double average;
 while((ch=getchar())!=EOF)
 {if((islower(ch)|isupper(ch)))
  {letters++;
   if(inword==0)
   words++;
   inword=1;
  }
  else if(inword==1)
  inword--;
 }
 average=(double)letters/(double)words;
 printf("words:%d letters:%d average words:%.3lf",words,letters,average);
 return 0;
}
