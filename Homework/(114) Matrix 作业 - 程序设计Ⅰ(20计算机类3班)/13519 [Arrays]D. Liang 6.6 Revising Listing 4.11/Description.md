# [Arrays]D. Liang 6.6 Revising Listing 4.11

# Description
Listing 4.11 determines whether a number n is prime by checking whether 2, 3, 4, 5, 6, ..., n/2 is a divisor. If a divisor is found, n is not prime. A more efficient approach to determine whether n is prime is to check whether any of the prime numbers less than or equal sqrt(n) can divide n evenly. If not, n is prime. Rewrite 4.11 to display the first fifty prime numbers using this approach. You need to use an array to store the prime numbers and later use them to check whether they are possible divisors for n.

# Input
An integer n (1<=n<=10000).
# Output
The first n prime number with one blank to seperate them. Don't output blank after the last prime number, output "\n" instead.

# Sample Input
`12`
# Sample Output
`2 3 5 7 11 13 17 19 23 29 31 37`