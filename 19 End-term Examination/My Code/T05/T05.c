#include<stdio.h>
#include<string.h>
int main(void)
{	char sentence[301],word[21],temp[21];
	fgets(sentence,301,stdin);
	scanf("%s",word);
	int index=0,Len=strlen(sentence);
	while(index<Len)
	{	sscanf(sentence+index,"%s",temp);
		if(!strcmp(temp,word))
			printf("%d ",index);
		index+=(strlen(temp)+1);
	}
	return 0;
}
