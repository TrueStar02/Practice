#include "swaps.hpp"


void swap(int & i1,int & i2) {
    int t = i1;
    i1 = i2;
    i2 = t;
}

void swap(float & f1,float & f2) {
    float t = f1;
    f1 = f2;
    f2 = t;
}

void swap(double & d1,double & d2) {
    double t = d1;
    d1 = d2;
    d2 = t;
}

void swap(string & s1,string & s2) {
    string t = s1;
    s1 = s2;
    s2 = t;
}