#include<stdio.h>
#include<string.h>
void killstr(char *str,unsigned int size);
int main(void)
{char str[]="LiuYuan is the NBest person all over the world!He is too NB at all!!!";
 killstr(str,46);
 puts(str);
 puts(str+47);
 return 0;
}
void killstr(char *str,unsigned int size)
{if(strlen(str)>size)
 str[size]='\0';
}
