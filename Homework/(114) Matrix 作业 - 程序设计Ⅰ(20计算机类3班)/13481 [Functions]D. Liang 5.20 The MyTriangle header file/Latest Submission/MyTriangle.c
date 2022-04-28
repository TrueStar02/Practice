#include<stdbool.h>
bool isValid(double side1, double side2, double side3)
{   bool x=0;
    if(side1+side2>side3&&side1+side3>side2&&side2+side3>side1)
    x=1;
    return x;
}
double area(double side1, double side2, double side3)
{   double area,s;
     s = (side1 + side2 + side3) / 2; 
     area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
    return area;
}