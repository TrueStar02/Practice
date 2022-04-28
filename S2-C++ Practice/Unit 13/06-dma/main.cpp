#include "dma.h"
int main(void)
{	baseDMA b1("Bian Runhua",1);
	baseDMA b2("Wang Tianle",2);
	cout<<b1<<b2;
	hasDMA h1("Hardcore Technology",b1);
	hasDMA h2("Normal",b2);
	hasDMA h3("Love","Tao Yinda",3);
	cout<<h1<<h2<<h3;
	hasDMA temp=h1;
	h2=h1;
	cout<<temp<<h2;
	return 0;
}
