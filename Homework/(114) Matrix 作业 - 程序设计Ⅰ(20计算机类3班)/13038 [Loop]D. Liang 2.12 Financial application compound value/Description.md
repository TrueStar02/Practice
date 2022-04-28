# [Loop]D. Liang 2.12 Financial application: compound value

# Description
Suppose you have $100 each month into a saving account with the annual interest rate 5%. So, the monthly interest rat is
`0.05 / 12 = 0.00417`.
After the first month, the value in the account becommes
`100 * (1 + 0.00417) = 100.417`
After the second month, the value in the account becomes,
`(100 + 100.417) * (1+0.00417) = 201.252`
After the third month, the value in the account becomes,
`(100 + 201.252) * (1+0.00417) = 302.507`
and so on.
&ensp;
Write a program to display the account value after the sixth month.

# Input

Two numbers a, b in one line, a for amount of money saved each month, b for the annual percentage interest rate.

# Output

The account value after the sixth month in one line.

# Sample Input

```
100 5
```

# Sample Output

```
608.81
```
