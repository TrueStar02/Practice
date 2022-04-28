#include "complex.h"
using namespace std;
#include<sstream>
 Complex::Complex():real(0),imag(0){}
    Complex::Complex(double re, double im):real(re),imag(im){}
    Complex::~Complex(){}
    const double Complex::getReal(void) const{return real;}
    const double Complex::getImaginary(void) const{return imag;}
    void Complex::setReal(double re){real=re;}
    void Complex::setImaginary(double im){imag=im;}
    void Complex::fromString(const std::string& complexString)
    {
        istringstream sin(complexString);
        sin>>real>>imag;
    }
    Complex Complex::operator+(const Complex& theComplex)
    {   return Complex(real+theComplex.real,imag+theComplex.imag);

    }
    Complex Complex::operator-(const Complex& theComplex)
    {   return Complex(real-theComplex.real,imag-theComplex.imag);

    }
    Complex Complex::operator*(const Complex& theComplex)
    {   return Complex(real*theComplex.real-imag*theComplex.imag,real*theComplex.imag+imag*theComplex.real);
    }
    Complex Complex::operator/(const Complex& theComplex)
    {
        return Complex((real*theComplex.real+imag*theComplex.imag)/(theComplex.real*theComplex.real+theComplex.imag*theComplex.imag),(-real*theComplex.imag+imag*theComplex.real)/(theComplex.real*theComplex.real+theComplex.imag*theComplex.imag));
    }
    std::ostream& operator<<(std::ostream& out, Complex& theComplex)
    {
        out<<theComplex.getReal()<<" ";
        if(theComplex.getImaginary())
        {if(theComplex.getImaginary()>0)
         {    out<<"+";
            out<<" ";
            if(theComplex.getImaginary()!=1)
             out<<theComplex.getImaginary();
             out<<"i";
         }
         else if(theComplex.getImaginary()<0)
         {    out<<"-";
            out<<" ";
            if(theComplex.getImaginary()!=-1)
             out<<-theComplex.getImaginary();
             out<<"i";
         }
        }
        return out;
    }