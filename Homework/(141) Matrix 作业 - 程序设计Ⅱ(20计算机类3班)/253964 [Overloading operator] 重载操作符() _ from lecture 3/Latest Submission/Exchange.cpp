#include "Exchange.h"
void Exchange::operator()(int&x, int&y)
{   int temp=x;
    x=y;
    y=temp;
}