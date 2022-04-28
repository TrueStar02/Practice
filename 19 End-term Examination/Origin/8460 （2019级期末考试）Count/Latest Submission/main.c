#include<stdio.h>
#include<string.h>
int main(){
	int t, n, i, a;
	int fre[10]={0};
	scanf("%d", &t);
	for(t;t>0;t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			a=i;
			while(a){
				fre[a%10]++;
				a/=10;
			}
		}
		for(a=0;a<10;a++) printf("%d ", fre[a]);
		memset(fre, 0, 10*sizeof(int));
		printf("\n");
	}
}