#include<cmath>
#include<iostream>

using namespace std;
const double eps = 1e-8;
class Complex {
private:
    double real, imag;
    
public:
    Complex(double x = 0, double y = 0):real(x),imag(y) {} // constructor, set real = x, imag = y
    
    void print() {
        if (fabs(real) < eps && fabs(imag) < eps) cout << 0 << endl;
        else if (fabs(real) < eps) {
            if (fabs(imag - 1) < eps) cout << 'i'<< endl;
            else if (fabs(imag + 1) < eps) cout << "-i"<< endl;
            else cout << imag << 'i'<< endl;
        }
        else if (fabs(imag) < eps) cout << real<< endl;
        else {
            if (imag > 0) cout << real << '+';
            else cout << real;
            if (fabs(imag - 1) < eps) cout << 'i'<< endl;
            else if (fabs(imag + 1) < eps) cout << "-i"<< endl;
            else cout << imag << 'i'<< endl;
        }          //output the complex number with proper form. e.g. 1+2i
    }
    
    friend Complex add(const Complex& a, const Complex& b) {   // return sum of two complex numbers
        return Complex(a.real + b.real,a.imag + b.imag);
    }
    
    friend Complex multiply(const Complex& a, const Complex&b) {// return product of two complex numbers
        return Complex(a.real * b.real - a.imag * b.imag,a.real * b.imag + b.real * a.imag);
    }
};