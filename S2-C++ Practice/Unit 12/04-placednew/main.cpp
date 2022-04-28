#include "test.h"
int main(void)
{	char *buffer=new char[512];
	Test *pt1,*pt2;
	pt1=new (buffer) Test;
	pt2=new Test("Heap",6);
	cout<<"Buffer:"<<(void *)buffer<<endl;
	cout<<"Heap:"<<pt2<<endl;
	cout<<"pt1:";
	pt1->show();
	cout<<"pt2:";
	pt2->show();
	Test *pt3,*pt4,*pt5;
	pt3=new (buffer) Test("SB",250);
	pt4=new Test("Heap2",10);
	pt5=new (buffer+sizeof(Test)) Test("NB",666);
	cout<<"pt3:";
	pt3->show();
	cout<<"pt4:";
	pt4->show();
	cout<<"pt5:";
	pt5->show();
	delete pt2;
	pt3->~Test();
	delete pt4;
	pt5->~Test();
	delete [] buffer;
	return 0;
}
