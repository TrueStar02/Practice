#include <stdio.h>
#include <string.h>
#include<ctype.h>
int main()
{	char total[302],str[100][21];
	fgets(total,302,stdin);
	int len=strlen(total),x,inword=1,label=0,pos=0;
	for(x=0;x<len;x++)
	{	if(isspace(total[x])&&inword)
		{	str[label][pos]='\0';
			inword=0;
			pos=0;
			label++;
		}
		else if(!isspace(total[x]))
		{	if(!inword)
				inword=1;
			str[label][pos]=total[x];
			pos++;		
		}
	}
	for(x=label-1;x>=0;x--)
		printf("%s ",str[x]);
	printf("\n");
	return 0;       
}
