#include <stdio.h>
#include <string.h>
#include<ctype.h>
int main()
{	char total[302],temp[51],word[51];
	fgets(total,302,stdin);
	scanf("%s",word);
	int inword,index=0,x,len=strlen(total),pos,nowlen;
	for(x=0;x<len;x++)
		if(!isspace(total[x]))
		{	sscanf(total+x,"%s",temp);
			if(!strcmp(temp,word))
				printf("%d ",x);
			x+=strlen(temp);
		}
	printf("\n");
	return 0;
}
