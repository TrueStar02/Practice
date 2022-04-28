#include "brass.h"
int main(void)
{	Brass *pb[4];
	pb[0]=new BrassPlus("Bian Runhua",100000,9999.99,1000.00,0.06);
	pb[1]=new Brass("Tao Yinda",100001,777.77);
	pb[2]=new Brass("Wang Tianle",100002,0.01);
	pb[3]=new BrassPlus("Ni Dabao",100003,12345.67,10000.00,0.07);
	int x;
	for(x=0;x<4;x++)
		pb[x]->show();
	for(x=0;x<4;x++)
		delete pb[x];
	return 0;
}
