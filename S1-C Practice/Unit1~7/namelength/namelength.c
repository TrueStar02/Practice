#include<stdio.h>
#include<string.h>
int main(void)
{int firstlength,familylength;
 char first[20],family[20];
 scanf("%s %s",first,family);
 firstlength=strlen(first);
 familylength=strlen(family);
 printf("%s %s\n",first,family);
 printf("%*d ",firstlength,firstlength);
 printf("%*d\n",familylength,familylength);
 printf("%-*d ",firstlength,firstlength);
 printf("%-*d\n",familylength,familylength);
 return 0;
}
