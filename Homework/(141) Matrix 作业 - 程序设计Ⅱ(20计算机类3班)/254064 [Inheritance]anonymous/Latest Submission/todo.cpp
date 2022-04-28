#include "todo.h"

void point::Data(){cout<<"point : "<<x<<" "<<y<<endl;}
void point::print(){Data();}
void vector1::Data(){cout<<"length : "<<length()<<endl;}
void vector1::print()
{   Data();
    point::Data();
}
void circle::Data(){cout<<"area : "<<area()<<endl;}
void circle::print()
{   Data();
    point::Data();
}
void todo::Data(){cout<<"volume : "<<area()+2*getr()*length()<<endl;}
void todo::print()
{   Data();
    vector1::Data();
    point::Data();
    circle::Data();
    point::Data();
}