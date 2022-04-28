#include<iostream>
#include "Regex.h"
using namespace std;
int main()
{   Regex reg0("A");
    cout<<reg0.match("A")<<endl;
    Regex reg1("(A+B|AC)D");
    cout<<reg1.match("AAAABD")<<reg1.match("ACD")<<reg1.match("BD")<<reg1.match("AAAC")<<endl;
    Regex reg2(".*AB((C|\\||D)F)*G");
    reg2.debug();
    cout<<reg2.match("ACDAB|FDFG")<<reg2.match("ABDF|G")<<endl;
    return 0;
}