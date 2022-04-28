# [Arrays]D. Liang 6.11 Computing standard deviation

<!-- 1091. 6.11 Computing deviation
Time Limit: 1sec Memory Limit:256MB  -->
# Description
Exercise 5.22 computes the standard deviation of numbers. This exercise uses a different but equivalent formula to compute the standard deviation of n numbers.

sum = x1 + x2 + ... + xn

mean = sum / n

deviation = sqrt((x1-mean)^2 + (x2-mean)^2 + ... + (xn-mean)^2)/(n-1))

To compute deviation with this formula, you have to store the individual numbers using an array, so that they can be used after the mean is obtained.
You program should contain the following functions:
```
/* Function for computing mean of an array of double values */
double mean(double x[], int size)

/* Function for computing mean of an array of int values */
double mean(int x[], int size)

/* Function for computing deviation of an array of double values */
double deviation(double x[], int size)

/* Function for computing deviation of an array of int values */
double deviation(int x[], int size)
```
# Hint
You should submit the implementation of the function but do not submit the main() function. 
Problem Source: 程序设计I Chapter6 Arrays
