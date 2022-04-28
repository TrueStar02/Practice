#include<stdio.h>
int main(void)
{int num=0;
 char ch;
 while((ch=getchar())!='#')
 {switch(ch)
  {case '.':putchar('!');
            num++;
            break;
   case '!':putchar('!');
            putchar('!');
            num++;
            break;
   default:
            putchar(ch);
  }
 }
 printf("\n%d char(s) have been changed\n",num);
 return 0;
}
