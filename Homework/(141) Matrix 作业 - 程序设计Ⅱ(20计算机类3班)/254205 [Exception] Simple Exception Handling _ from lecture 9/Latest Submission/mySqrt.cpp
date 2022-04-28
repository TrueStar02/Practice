#include<iostream>
#include "mySqrt.hpp"
#include "MyException.hpp"
#include<cmath>
using namespace std;
double mySqrt(double x)
{   if(x>=0)
        return sqrt(x);
    else
        throw MyException("invalid argument");
}
