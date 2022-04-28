#include<stdio.h>
#define XNAME(m,n) m ## n
#define PRT(m,n) printf(#m #n "=%d\n",m ## n)
int main(void)
{	int XNAME(x,1)=14;
	int XNAME(x,2)=24;
	int x3=30;
	PRT(x,1);
	PRT(x,2);
	PRT(x,3);
	return 0;
}
