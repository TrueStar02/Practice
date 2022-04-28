# [Functions]D. Liang 5.17 Displaying matrix of 0s and 1s

# Description
Write a function that displays an n by n matrix. Each element in the matrix is 0 or 1. The elements of first row, the elements of the first column and the diagonal elements are 1s, the other are 0s.
# Input
```
The first line is a positive integer (1 <= t <= 10), denoting the number of test cases followed.
In each test case, the input is one single line, containing a positive integer n (1 <= n <= 100) which denotes the width of matrix.
```
# Output
```
For each test case, the output contains n line and each line consists of n integers separated by white spaces.
(There is a white spaces in front of the first integer in each line, no white spaces behind the last integer in each line.)
```
# Sample Input
```
4
1
2
3
10
```
# Sample Output
```
 1
 1 1
 1 1
 1 1 1
 1 1 0
 1 0 1
 1 1 1 1 1 1 1 1 1 1
 1 1 0 0 0 0 0 0 0 0
 1 0 1 0 0 0 0 0 0 0
 1 0 0 1 0 0 0 0 0 0
 1 0 0 0 1 0 0 0 0 0
 1 0 0 0 0 1 0 0 0 0
 1 0 0 0 0 0 1 0 0 0
 1 0 0 0 0 0 0 1 0 0
 1 0 0 0 0 0 0 0 1 0
 1 0 0 0 0 0 0 0 0 1

```
