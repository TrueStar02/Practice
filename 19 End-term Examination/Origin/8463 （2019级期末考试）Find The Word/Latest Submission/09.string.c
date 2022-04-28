#include<stdio.h>
#include<string.h>
int main(){
	int i, j, strl, keylen, cnt;
	char str[305];
	char key[25];
	fgets(str, 304, stdin);
	fgets(key, 24, stdin);
	strl=strlen(str);
	str[strl]='\0';
	strl--;
	keylen=strlen(key);
	key[keylen]='\0';
	keylen--;
	for(i=0;i<strl;i++){
		if((str[i]==key[0])&&((str[i-1]==' ')||(i==0))){
			cnt=0;
			for(j=0;j<keylen;j++){
				if(str[i+j]==key[j])
				cnt++;
			}
			if((cnt==keylen)&&(str[i+j]==' '||str[i+j]=='\0')){
				printf("%d ", i);
			}
		}
	}
}