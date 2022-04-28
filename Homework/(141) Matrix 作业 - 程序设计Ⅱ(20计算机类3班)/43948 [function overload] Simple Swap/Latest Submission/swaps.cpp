#include "swaps.hpp"
using namespace std;
void swap(int & a,int & b)
{
    int c;
    c=a;
    a=b;
    b=c;
}
void swap(float & a,float & b)
{
    float c;
    c=a;
    a=b;
    b=c;
}
void swap(double & a,double & b)
{
    double c;
    c=a;
    a=b;
    b=c;
}
void swap(string & a,string & b)
{
    string c;
    c=a;
    a=b;
    b=c;
}