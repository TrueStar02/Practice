#include "head.h"
#include<iostream>
using namespace std;
DERIVED set(int a, int b)
{   DERIVED t;
    t.BASE1::i=a;
    t.BASE2::i=b;
    return t;

}
void get(DERIVED &t)
{
    cout<<"BASE1 i: "<<t.BASE1::i<<endl<<"BASE2 i: "<<t.BASE2::i<<endl;
}