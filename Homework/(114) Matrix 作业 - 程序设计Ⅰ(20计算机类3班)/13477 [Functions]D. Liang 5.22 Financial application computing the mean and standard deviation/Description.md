# [Functions]D. Liang 5.22 Financial application: computing the mean and standard deviation

# Description
In business applications, you are often asked to compute the mean and standard deviation of data.
The mean is simply the average of the numbers. The standard deviation is a statist that tells you how tightly all the various data are clustered around the mean in a set of data. 
For example, what is the average age of the students in a class? How close are the ages? If all the students are the same age, the deviation is 0. 
Write a program that reads data set from input and computes the mean and 
standard deviations of these numbers using the following formula:
sum(n) = x1 + x2 + ... + xn
mean(n) = sum(n)/n 
squaresum(n) = x1^2 + x2^2 + ... + xn^2
deviation(n) = sqrt( (squaresum(n) - sum(n)*sum(n)/n) / (n-1) ) 
# Input
The first line is a positive number t (0<t<=20). It mean that there are t test cases.
Each test case include two lines. The first line is a positive number n for data numbers in this test case, and the second line is n numbers seperated by one blank.
# Output
For each test case, output the mean and standard deviation in seperated by one blank in one line.
You should set the precision of floating-point numbers to 2 and fixed.
# Sample Input
```
2
3
1 2 3
4
4 2 2 4
```
# Sample Output
```
2.00 1.00
3.00 1.15
```
