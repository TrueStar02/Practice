#include<stdio.h>
int main(){
	int i, b1, e1, b2, e2;
	for(i=0;i<10;i++){
		scanf("%d%d%d%d", &b1, &e1, &b2, &e2);
		if((b1<=b2&&b2<=e1)||(b2<=b1&&b1<=e2)){
			printf("true\n");
		}
		else printf("false\n");
	}
} 