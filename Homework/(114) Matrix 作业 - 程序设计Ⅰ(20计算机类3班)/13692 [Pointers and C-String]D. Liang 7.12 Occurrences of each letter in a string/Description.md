# [Pointers and C-String]D. Liang 7.12 Occurrences of each letter in a string

## Description
Write a function that counts the occurrences of each letter in a string using the following header:
```
int * countLetters(const char * const s)
```
The function returns the counts as an array of 26 elements.
For example, after invoking
```
int counts[] = countLetters("ABcaB")
```
``counts[0]`` is 2, ``counts[1]`` is 2, and ``counts[2]`` is 1.

Write another function to pass the count array in a parameter as follows:
```
void countLetters(const char * const s, int * counts, int size)
```
where size is the size of the counts array. In this case, it is 26.

## Hint

Don't submit the main() function
