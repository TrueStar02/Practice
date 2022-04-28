#include <iostream>
#include <string>
#include "swaps.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int i1,i2;
    float f1,f2;
    double d1,d2;
    string s1,s2;
    cin >> i1 >> i2 >> f1 >> f2 >> d1 >> d2 >> s1 >> s2;
    swap(i1,i2);
    swap(f1,f2);
    swap(d1,d2);
    swap(s1,s2);
    cout << i1 << " " << i2 << " " << f1 << " " << f2 << " " << d1 << " " << d2 << endl;
    cout << s1 << " " << s2 << endl;
}