# Sum of Diagonals

# Description

What is the sum of all the integers (0 <= integer <= 100) that are on the main diagonal or antidiagonal of a given square matrix?

# Input

In the first line of the input is a number ``n`` (1 <= n <= 10) representing the number of the test cases.

Each case contains ``n + 1`` lines, with one line representing the size (1 <= size <= 10) of the square matrix, and the following n lines representing the square matrix.

# Output

The sum of all the integers that are on the main diagonal or antidiagonal of the given square matrices.
# Sample Input

```
2
3
1 0 1
0 1 0
1 0 1
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

```

# Sample Output

```
5
68

```

# Hint
In this input:

- There would be ``two`` test cases.
- In the first test case, the matrix would be of size ``3``, and the sum to output would be ``5 (= 1 + 1 + 1 + 1 + 1)``
- In the second test case, the matrix would be of size ``4``, and the sum to output would be ``68 (= 1 + 4 + 6 + 7 + 10 + 11 + 13 + 16)``