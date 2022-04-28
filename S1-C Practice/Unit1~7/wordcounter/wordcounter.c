#include<stdio.h>
#include<ctype.h>
#define STOP '|'
int main(void)
{unsigned long lines=0,words=0,plines=0,chars=0,inword=0,letters=0;
 char ch,prech;
 while((ch=getchar())!=STOP)
 {chars++;
  
  if(isalpha(ch))
  {letters++;
   inword=1;
  }
  else
  {if(inword==1)
   {words++;
    inword=0;
   
   }
   if(ch=='\n')
   lines++;
  }
  prech=ch;
 }
 if(inword==1)
 words++;
 if(prech!='\n')
 plines++;
 printf("%ldletters %ldchars %ldwords %ldlines %ldincompete lines\n",letters,chars,words,lines,plines);
 return 0;
}
