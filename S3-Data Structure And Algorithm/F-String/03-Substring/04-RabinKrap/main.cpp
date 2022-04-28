#include<iostream>
#include "RabinKrap.h"
int main()
{   RabinKrap a("asdfghjkl");
    cout<<a.match("qwertyuiopmnbvcxzasdfghjklqwertgvbnm,kiuyhg")<<endl;
    cout<<a.match("hsdfhasjfhoaosihfcoliaweefhcajdcndcuiheuibfuvbevnhfjsafhjks")<<endl;
    return 0;
}