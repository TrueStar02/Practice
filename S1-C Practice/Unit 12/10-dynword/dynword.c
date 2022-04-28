#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char **process(int n);
int main(void)
{	int num,x;
	char temp[31];
 	printf("How many words do you need?\n");
 	scanf("%d",&num);
 	printf("Now enter %d words:\n",num);
 	char **ptr=(char **)malloc(num*sizeof(char *));
 	for(x=0;x<num;x++)
 	{	scanf("%s",temp);
 		char *str=(char *)malloc(strlen(temp)*sizeof(char));
 		strcpy(str,temp);
 		*(ptr+x)=str;//Why don't we free(str)?
 	}
 	for(x=0;x<num;x++)
 		puts(*(ptr+x));
 	free(ptr);
 	return 0;
}

