
#include "CD.h" 

void Bravo(const CD & disk);

int main() 
{
    CD c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    CD *pCD = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use CD method
    c2.Report(); // use Classic method
    cout << "Using type CD * pointer to objects:\n";
    pCD->Report(); // use CD method for CD object
    pCD = &c2;
    pCD->Report(); // use Classic method for classic object
    cout << "Calling a function with a CD reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const CD & disk)
{
    disk.Report();
}
