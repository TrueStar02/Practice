#include "COMPLEX.h"
#include<iostream>
using namespace std;
COMPLEX::COMPLEX(double r , double i ):real(r),image(i){}
COMPLEX::COMPLEX(const COMPLEX &other):real(other.real),image(other.image){}
void COMPLEX::print()
{   cout<<real;
    if(image>0)
        cout<<"+";
    cout<<image<<"i\n";

}						 // 打印复数
										 // 重载加法运算符（二元）
COMPLEX COMPLEX::operator+(const COMPLEX &other)
{   return COMPLEX(real+other.real,image+other.image);}
COMPLEX COMPLEX::operator-(const COMPLEX &other)
{   return COMPLEX(real-other.real,image-other.image);}
	COMPLEX COMPLEX::operator-()
{   return COMPLEX(-real,-image);}
COMPLEX COMPLEX::operator=(const COMPLEX &other)
{   if(&other==this)
        return *this;
    real=other.real;
    image=other.image;
    return *this;
}
COMPLEX & COMPLEX::operator++()
{   
    ++real;
    ++image;
    return *this;
}  
COMPLEX COMPLEX::operator++(int)
{   COMPLEX temp=*this;
    real++;
    image++;
    return temp;
}    
COMPLEX & COMPLEX::operator--()
{   
    real--;
    image--;
    return *this;
}   
COMPLEX COMPLEX::operator--(int)
{   COMPLEX temp=*this;
    real--;
    image--;
    return temp;
}      