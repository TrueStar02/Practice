# [Classes and Object]The Complex Number Class

## Description
Complex is a general format of nmbers, with the real part and imaginary part. Please implement a class for such numbers as below.
``` c++
class Complex

{

double real, imag; 

public:

Complex(double x = 0, double y = 0);  // constructor, set real = x, imag = y

void print();           //output the complex number with proper form. e.g. 1+2i

friend Complex add(const Complex&, const Complex&);   // return sum of two complex numbers 

friend Complex multiply(const Complex&, const Complex&);  // return product of two complex numbers

}
```
## Hint
1.you only need to submit the whole class definition and the implentation of friend function.

2.the display format of a complex is like 1+2i, 3i, 0 ,etc

