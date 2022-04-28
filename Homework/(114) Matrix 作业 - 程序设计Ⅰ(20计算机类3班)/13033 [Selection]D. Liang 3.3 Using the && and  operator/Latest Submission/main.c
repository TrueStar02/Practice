#include<stdio.h>
#include<stdbool.h>
int main(void)
{   
    int x;
    bool a,b,c,d,e;
    scanf("%d",&x);
    a=(x%5==0);
    b=(x%6==0);
    c=a&b;d=a|b;e=a^b;
    printf("Is %d divisible by 5 and 6? ",x);
	if(c==1) printf("true\n");
	else printf("false\n");
	printf("Is %d divisible by 5 or 6? ",x);
	if(d==1) printf("true\n");
	else printf("false\n");
	printf("Is %d divisible by 5 or 6, but not both? ",x);
	if(e==1) printf("true\n");
	else printf("false\n");
	
    
    return 0;
}