#include<iostream>
#include "BoyerMoore.h"
using namespace std;
int main()
{   BoyerMoore a("asdfghjkl");
    cout<<a.match("qwertyuiopmnbvcxzasdfghjklqwertgvbnm,kiuyhg")<<endl;
    cout<<a.match("hsdfhasjfhoaosihfcoliaweefhcajdcndcuiheuibfuvbevnhfjsafhjks")<<endl;
    return 0;
}