#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[300], rev[300], cln[300];
	int i, j, len, k, wordlen;
	memset(cln, '\0', sizeof cln);
	memset(rev, '\0', sizeof rev);
	fgets(str, 300, stdin);
	len=strlen(str);
	if(str[len-1]=='\n')
	str[len-1]='\0';
	i=0;
	j=0;
	while(str[i]!='\0'){
		if(str[i]!=' '){
			cln[j]=str[i];
			j++;
		}
		else{
			if(i>0&&str[i-1]!=' '){
				cln[j]=' ';
				j++; 
			}
		}
		i++;
	}
	len=strlen(cln);
	k=0;
	j=len-1;
	while(j>=0){
		wordlen=0;
		if(cln[j]!=' '){
			wordlen++;
			while((cln[j-1]!=' ')&&(j!=0)){
			    j--;
			    wordlen++;
		    }
		}
		//printf("j=%d, wordlen=%d", j, wordlen);
		if(wordlen>0){
			for(i=0;i<wordlen;i++){
			    rev[k]=cln[j+i];
			    k++;
		    }
		//    printf("%s\n", rev);
		    rev[k]=' ';
		    k++;
		}
		//printf("j=%d\n", j);
		j--;
	}
	//printf("%s\n", cln);
	len=strlen(rev);
	rev[len-1]='\0';
	printf("%s", rev);
} 