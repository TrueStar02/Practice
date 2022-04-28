# [Functions]D. Liang 5.23 Approximating the square root

# Description
Implementing the sqrt function. The square root of a number n, can be approximated by repeated performing a calculation using the following formula:

nextGuess = (lastGuess + n / lastGuess) /2

When nextGuess and lastGuess are almost identical, nextGuess is the approximated square root.
The initial guess will be the starting value of lastGuess. If the difference between nextGuess and lastGuess is less than a very small number e (such as 0.0001), you can claim that nextGuess is the approximated square root of n.
# Input
The first line is a positive integer t (0<t<=20) for the number of test cases.
Each test case contains an double value n (0<=n<=100000) and a double value e (such as 0.001).
# Output
For each test case, output the square root of n in one line.
You should set the precision to 8 and fixed;
# Sample Input
```
2
4 0.001
2 0.01
```
# Sample Output
```
2.00000009
1.41421569
```