# [Arrays]D. Liang 6.2 Alternative solution to Listing 6.1

# Description
The solution of Listing 6.1, TestArray.cpp counts the occurrences of the largest number by comparing each number with the largest. So you have to use an array to store all the numbers. Another way to solve the problem is to maintain two variables, max and count. max stores the current max number, and count stores its occurrences. Initially, assign the first number to max and 1 to count. Compare each subsequent number with max. If the number is greater than max, assign it to max and reset count to 1. If the number is equal to max, increment count by 1. Use this approach to rewrite Listing 6.1.

# Input
The first line is a positive integer t for the number of test cases.
Each test case contains two lines. The first line is an integer n (0<n<=100). The second line contains n integers.
# Output
For each test case, output the largest number and it's occurrences, seperated by one blank.

# Sample Input
```
2
3
1 2 3
4
2 1 2 1
```
# Sample Output
```
3 1
2 2
```