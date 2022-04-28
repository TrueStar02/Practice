# Derivative Of Polynomial

# Description

Some TA was very frustrated forgetting the knowledge about derivatives（导数） until hearing that you are learning the course of Advanced Mathematics so hard as to be able to take the derivative of an arbitrary function without difficulty. Don"t miss the chance to help the TA!

Now the TA hope that you show the derivative value of a given polynomial for another given ``x``.

# Input

In the first line is ``n(0 < n <= 5)``, the number of the terms with a non-zero coefficient, followed by an ``x(-10 <= x <= 10)``, the actual value to substitute for the indeterminate.

Each of the following ``n`` lines contains two numbers ``C(-50 <= C <= 50, C != 0)`` and ``D(0 <= D <= 10)``, where ``C`` is the coefficient and ``D`` is the degree of the term.


# Output

The corresponding result of the polynomial.

# Sample Input

```
3 1
4 3
3 2
5 8

```

# Sample Output

```
58

```

# Hint
In this input:

The given polynominal would be:

``p(x) = 4x^3 + 3x^2 + 5x^8``


The TA would want the result of ``p"(1)``, namely ``58``

Thus the corresponding output would be:

```
58

```
with a new line at the end.


Be careful of overflow 