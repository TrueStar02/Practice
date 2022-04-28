# Modulus of Reverse

# Description

+7 dalao would like to reverse a number, and +C dalao would like to see the remainder (modulus) after division of the reversed number by a second number. So please tell +7 the reversed number and +C the remainder.

# Input

In the first line of the input is a number ``n`` (1 <= n <= 10) representing the number of the test cases.

Each of the following n lines consists of two integers ``a`` and ``b`` (1 <= a, b <= 10000000), where ``a`` is the one to be reversed, and ``b`` is the divisor to be used to get the remainder.


# Sample Input
```
5
12345 10
2345 32
43245 98
83929 231
1 2

```


# Sample Output

```
54321 1
5432 24
54234 40
92938 76
1 1

```

# Hint
In this input:

- There are ``five`` test cases.
- In the first test case, output the reversed number of ``12345``, namely ``54321``, and then output the remainder of ``54321 / 10``, namely ``1``.
- In the second test case, output the reversed number of ``2345``, namely ``5432``, and then output the remainder of ``5432 / 32``, namely ``24``
- ...

Note: the reversed number of ``500`` would be ``005``. Numbers beginning with ``0`` such as ``005`` will not be given in the input for simplicity. 