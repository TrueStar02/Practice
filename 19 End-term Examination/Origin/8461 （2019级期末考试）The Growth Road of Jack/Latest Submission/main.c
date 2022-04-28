#include<stdio.h>
int fin(int a, int b){
	int temp;
	if(b>a){
		temp=b;
		b=a;
		a=temp;
	}
	if(a%b) fin(b, a%b);
	else return b;
}
int main(){
	int a, t, mons, b;
	scanf("%d", &t);
	for(t;t>0;t--){
		scanf("%d%d", &mons, &a);
		for(mons;mons>0;mons--){
			scanf("%d", &b);
			if(b<=a) a+=b;
			else a+=fin(a, b);
		}
		printf("%d\n", a);
	}
}