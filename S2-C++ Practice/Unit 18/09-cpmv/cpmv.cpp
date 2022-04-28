#include "cpmv.h"
int main(void)
{	Cpmv cp1("C ","++ ");
	cout<<"cp1:\n";
	cp1.Display();
    Cpmv cp2("Computer ", "Science ");
    cout<<"cp2:\n";
    cp2.Display();
    Cpmv cp3 = cp2;
    cout<<"cp3:\n";
    cp3.Display();
    cp2 = cp1;
    cout<<"cp2:\n";
    cp2.Display();
    cp1 = cp2 + cp3;
    cout<<"cp1:\n";
	cp1.Display();
    Cpmv cp4 (cp1 + cp2);
    cout<<"cp4:\n";
	cp4.Display();
	return 0;
}
