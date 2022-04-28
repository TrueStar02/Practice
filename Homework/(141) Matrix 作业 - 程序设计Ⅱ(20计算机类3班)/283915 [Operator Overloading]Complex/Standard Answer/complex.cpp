#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include "complex.h"
const char charPlusOp = '+';
const char charMinusOp = '-';
const char charIValue = 'i';
Complex::Complex() : real(0.0), imag(0.0) { }
Complex::Complex(double re, double im) : real(re), imag(im) { }
Complex::~Complex() { }
const double Complex::getReal(void) const {
    return real;
}
const double Complex::getImaginary(void) const {
    return imag;
}
void Complex::setReal(double re) {
    real = re;
}
void Complex::setImaginary(double im) {
    imag = im;
}
void Complex::fromString(const std::string& complexString) {
    using namespace std;
    string realString;
    string imagString;
    stringstream stringBufReal;
    stringstream stringBufImag;
 
    int opPos = complexString.find(charPlusOp);
    int iPos;
    if (opPos != complexString.npos) {
        // deal with cases re + im i
        realString = complexString.substr(0, opPos);
        stringBufReal.str(realString);
        stringBufReal >> real;
        imagString = complexString.substr(opPos + 1);
        stringBufImag.str(imagString);
        stringBufImag >> imag;
        if (imag == 0) {
            // case re + i
            imag = 1;
        }
    } else {
        opPos = complexString.find(charMinusOp);
        if (opPos != complexString.npos && opPos > 0) {
            // deal with cases re - im i
            realString = complexString.substr(0, opPos);
            stringBufReal.str(realString);
            stringBufReal >> real;
            imagString = complexString.substr(opPos + 1);
            stringBufImag.str(imagString);
            stringBufImag >> imag;
            if (imag == 0) {
                // case re - i
                imag = 1;
            }
            imag = -imag;
        } else {
            opPos = complexString.find(charIValue);
            if (opPos != complexString.npos) {
                // deal with case im i
                imagString = complexString.substr(0, opPos);
                stringBufImag.str(imagString);
                stringBufImag >> imag;
            } else {
                // deal with case re
                stringBufReal.str(complexString);
                stringBufReal >> real;
            }
        }
    }
}
Complex Complex::operator+(const Complex& theComplex) {
    double r = real + theComplex.getReal();
    double i = imag + theComplex.getImaginary();
    return Complex(r, i);
}
Complex Complex::operator-(const Complex& theComplex) {
    double r = real - theComplex.getReal();
    double i = imag - theComplex.getImaginary();
    return Complex(r, i);
}
Complex Complex::operator*(const Complex& theComplex) {
    double re = real * theComplex.getReal() - imag * theComplex.getImaginary();
    double im = imag * theComplex.getReal() + real * theComplex.getImaginary();
    return Complex(re, im);
}
Complex Complex::operator/(const Complex& theComplex) {
    double c = theComplex.getReal();
    double d = theComplex.getImaginary();
    double denom = c*c + d*d;
    double re;
    double im;
    if (denom == 0) {
        re = 1e100;
        im = 1e100;
    }
    re = (real*c + imag*d) / denom;
    im = (imag*c - real*d) / denom;
    return Complex(re, im);
}
std::ostream& operator<<(std::ostream& out, Complex& theComplex) {
    using namespace std;
    double re = theComplex.getReal();
    double im = theComplex.getImaginary();
    if (im > 0 && re != 0) {
        if (im != 1) {
            out << re << " + " << im << "i";
        } else {
            out << re << " + i";
        }
    } else if (im < 0 && re != 0) {
        if (im != -1) {
            out << re << " - " << fabs(im) << "i";
        } else {
            out << re << " - i";
        }
    } else if (re == 0) {
        out << im << "i";
    } else if (im == 0) {
        out << re;
    }
    return out;
}
