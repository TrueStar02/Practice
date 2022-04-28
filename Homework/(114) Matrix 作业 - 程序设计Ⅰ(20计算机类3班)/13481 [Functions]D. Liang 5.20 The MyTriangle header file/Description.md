# [Functions]D. Liang 5.20 The MyTriangle header file

# Description
Please implementation the following two functions in MyTriangle.h. Note that you need not write the main() function.

/* Returns true if the sum of any two sides is
 greater than the third side. */
 
bool isValid(double side1, double side2, double side3) 

/* Returns the area of the triangle. */

double area(double side1, double side2, double side3)

The formula for computing the area is
  s    = (side1 + side2 + side3) / 2;
  area = sqrt(s(s-side1)(s-side2)(s-side3)) 
	
# Example Input1
```
1.0 2.0 3.0
```
# Example Output1
```
Invalid!
```
# Example Input2
```
3.0 4.0 5.0
```
# Example Output2
```
6.00
```
