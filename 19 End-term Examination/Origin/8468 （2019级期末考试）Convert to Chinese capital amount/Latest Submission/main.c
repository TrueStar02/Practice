#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag0=0;
char* findnum(int n){
	switch(n){
		case 0: return "零";
		case 1: return "壹";
		case 2: return "贰";
		case 3: return "叁";
		case 4: return "肆";
		case 5: return "伍";
		case 6: return "陆";
		case 7: return "柒";
		case 8: return "捌";
		case 9: return "玖"; 
	}
}
void getqbs(int num[]){
	int i, cnt0=0, cnt1=0, maxbit;
	if(num[0]==0&&flag0==0) {
		printf("零");
		flag0=1;
	}
	else if(num[0]>0) {
		printf("%s仟", findnum(num[0]));
		flag0=0;
	}
	if(num[1]==0){
		if(!flag0){
			printf("零");
		    flag0=1;
		}
	} 
	else if(num[1]>0) {
		printf("%s佰", findnum(num[1]));
		flag0=0;
	}
	if(num[2]==0&&flag0==0){
		printf("零");
		flag0=1;
	}
	else if(num[2]>1) printf("%s拾", findnum(num[2]));
	else if(num[2]==1){
		if(num[1]==-1) printf("拾");
		else printf("壹拾"); 
	}
	if(num[3]>0) printf("%s", findnum(num[3]));
}
int main(){
	long n, a;
	int bit[6]={0}, i, maxbit, numqbs[4]={0}, numw[4]={-1, -1, -1, -1}, j;
	scanf("%ld", &n);
	printf("人民币");
	if(n==1000000000) printf("拾亿"); 
	a=n;
	i=5;
	while(a){
		if(i==1){
			if(a>=10000){
				bit[1]=a%10000;
				bit[0]=a/10000;
			}
			else bit[i]=a;
			break;
		}
		bit[i]=a%10;
		a/=10;
		i--;
	}
	for(i=0;bit[i]==0;i++)
	    bit[i]=-1;
    maxbit=i;
    j=0;
	for(i=2;i<6;i++){
    	numqbs[j]=bit[i];
    	j++;
	}
    if(maxbit==0){
    	printf("%s亿", findnum(bit[0]));
    	memset(numw, 0, sizeof numw);
	} 
    
    	j=3;
    	a=bit[1];
		while(a){
    		numw[j]=a%10;
    		a/=10;
    		j--;
		}
		getqbs(numw);
		printf("万");
		if(numw[3]==0){
		    printf("零");
			flag0=1;	
		} 
	
	getqbs(numqbs);
    printf("元整"); 
}
