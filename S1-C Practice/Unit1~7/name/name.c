#include<stdio.h>
#include<string.h>
int main(void)
{char name[20];
 scanf("%s",name);
 int size,letters;
 size=sizeof(name);
 letters=strlen(name);
 printf("%s\n",name);
 printf("size:%d\nletters:%d\n",size,letters);
 return 0;
}
