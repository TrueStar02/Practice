#include<iostream>
#include "KMP.h"
using namespace std;
int main()
{   KMP a("asdfghjkl");
    cout<<a.match("qwertyuiopmnbvcxzasdfghjklqwertgvbnm,kiuyhg")<<endl;
    cout<<a.match("hsdfhasjfhoaosihfcoliaweefhcajdcndcuiheuibfuvbevnhfjsafhjks")<<endl;
    return 0;
}