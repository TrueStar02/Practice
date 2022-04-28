#include<iostream>
using namespace std;
#define CHECK_MACRO 0
inline int inline_MAX(int a,int b)
{
    return (a>b)?a:b;
}
inline void inline_SWAP(int &a,int &b)
{   int c;
    c=a;
    a=b;
    b=c;
}
