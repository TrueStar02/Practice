# [Arrays]D. Liang 6.20 Computing the weekly hours for each employee

<!-- 1100. 6.20 Computing the weekly hours for each employee
Time Limit: 1sec Memory Limit:256MB  -->
# Description
Suppose the weekly hours for all employee are stored in a two-dimensional array. 

Each row records an employee's seven-day work hous with seven columns. 

For example, the following array stores the work hours for eight employees. 

Write a program that displays employees and their total hours in decreasing 
order of the total hours.

```
              Su  M   T   W   H   F   Sa  
Employee  0   2   4   3   4   5   8   8   
Employee  1   7   3   4   3   3   4   4   
Employee  2   3   3   4   3   3   2   2   
Employee  3   9   3   4   7   3   4   1   
Employee  4   3   5   4   3   6   3   8   
Employee  5   3   4   4   6   3   4   4   
Employee  6   3   7   4   8   3   8   4   
Employee  7   6   3   5   9   2   7   9   
```

# Input
The first line is a positive integer t for the number of test cases.

Each test case contains m+1 lines. The line 1 contains an integer m (0<m<=100). Then followed m lines, each line contains 7 integers seperated by blanks, for one employee's seven-day work hours. 

# Output
For each test case,output each employee's number and their total hours in decreasing order of the totoal hours using the format like the sample output.

# Sample Input
```
2
8
2   4   3   4   5   8   8   
7   3   4   3   3   4   4   
3   3   4   3   3   2   2   
9   3   4   7   3   4   1   
3   5   4   3   6   3   8   
3   4   4   6   3   4   4   
3   7   4   8   3   8   4   
6   3   5   9   2   7   9   
3
2   4   3   4   5   8   8   
7   3   4   3   3   4   4   
3   3   4   3   3   2   2  
``` 
# Sample Output
```
test case 1:
Employee 7: 41
Employee 6: 37
Employee 0: 34
Employee 4: 32
Employee 3: 31
Employee 1: 28
Employee 5: 28
Employee 2: 20
test case 2:
Employee 0: 34
Employee 1: 28
Employee 2: 20
```
Problem Source: 程序设计I Chapter6 Arrays

